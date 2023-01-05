import * as constants from './constants'

export default function recountCodeLines(generalCodeLines) {
    const linesElement = document.querySelector('.' + constants.LINE_NUMBERS_COLUMN_CLASSNAME)
    linesElement.innerHTML = '';
    for(let i = 1; i <= generalCodeLines; ++i) {
        const p = document.createElement('p');
        p.textContent = i;
        linesElement.appendChild(p);
    }
}