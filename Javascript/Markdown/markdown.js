const markdown_key = {
    "###":["<h1>","</h1>"],
    "##":["<h2>","</h2>"],
    "#":["<h3>","</h3>"]
}

function replaceHeaders(text) {
    const headers = {
        "###":["<h1>","</h1>"],
        "##":["<h2>","</h2>"],
        "#":["<h3>","</h3>"]
    }

    for(h in headers) {
        while(text.search(h) >= 0)
            text = text.replace(h,headers[h][0])
                    .replace('\n',headers[h][1]+'<br>');
    }
    return text;
}

function markdown() {
    var input = document.getElementById('input');
    var output = document.getElementById('output');

    output.innerHTML = replaceHeaders(input.value);
}
