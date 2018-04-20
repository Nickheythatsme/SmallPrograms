const markdown_key = {
    "###":["<h1>","</h1>"],
    "##":["<h2>","</h2>"],
    "#":["<h3>","</h3>"]
}


function markdown() {
    var input = document.getElementById('input');
    var raw_output = document.getElementById('raw_output');

    raw_output.value = input.value;
    markdown_output.innerHTML = '<h1>test</h1>';
    addMarkup();
}

function addMarkup(text="TEsting this"){
    var t = /[a-z]/g;
    var match = text.search(t);
    console.log('Matches: ' + match);
}