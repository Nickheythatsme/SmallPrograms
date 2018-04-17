function doMarkdown() {
    var input = document.getElementById('input').value;
    markdown({
        text: input,
        id: 'output'
    });
}
