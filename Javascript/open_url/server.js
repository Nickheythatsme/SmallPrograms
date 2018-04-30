const http = require('http');
const { spawn } = require('child_process');
const body_parser = require('body-parser');
const express = require('express');
const app = express();
const PORT = 8080;

app.use(body_parser.urlencoded({extended: false}));
app.use(express.static('public'));


// Catch requests, use query to open page
app.get('*', (req, res) => {
    console.log('get request')
    res.sendFile(__dirname + '/public/index.html')
});

app.post('*', (req, res) => {
    if (req.body.url)
    {
        openBrowser(req.body.url)
        console.log("Opening: ", req.body.url)
    }
    res.sendFile(__dirname + '/public/index.html')
});

// Create server, start listening
app.listen(PORT, () => {
    console.log("Listening on port: ", PORT);
});


function openBrowser(url)
{
    url = make_valid(url)
    // Use python so we support multiple platforms
    const browser = spawn('python', ['-m','webbrowser',url]);
    console.log("child process started");

    browser.stdout.on('data', (data) => {
        console.log("stdout:", String(data));
    });

    browser.stderr.on('data', (data) => {
        console.log('stderr: ', data.toString('utf-8'));
    });

    browser.on('close', (code) => {
        console.log("child process ended with code: ", code);
    });
}

function make_valid(url)
{
    if (url.search(' ') != -1)
    {
        start = 'https://www.google.com/search?q='
        start += url.replace(/ /g, "+")
        return start
    }
    return url
}
