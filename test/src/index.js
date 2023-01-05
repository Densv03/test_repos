import recountCodeLines from "./js/recount-code-lines";

document.querySelector('.code').addEventListener('input', e => {
    recountCodeLines(e.path[0].children.length)
})