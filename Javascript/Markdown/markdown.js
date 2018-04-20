'use strict';

const headers = {
    "###":["<h1>","</h1>"],
    "##":["<h2>","</h2>"],
    "#":["<h3>","</h3>"]
}

const font_style = {
    "**":["<b>","</b>"],
    "^^":["<i>","</i>"],
}

function replaceHeaders(text) {

    for(var h in headers){
        while(text.search(h) >= 0)
            text = text.replace(h,headers[h][0])
                    .replace('\n',headers[h][1]+'<br>');
    }
    console.log(text);
    return text;
}

function markdown({text, id}) {
    var output = document.getElementById(id);
    if (!output) return null;
    text = text.toString();

    if (text[text.length - 1] != '\n')
        text += '\n';

    console.log(text);

    output.innerHTML = replaceHeaders(text);
}