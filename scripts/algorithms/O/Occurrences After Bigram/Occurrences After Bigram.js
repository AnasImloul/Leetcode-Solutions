var findOcurrences = function(text, first, second) {
    let result = [];
    let txt = text.split(' ');
    for(let i = 0; i<txt.length - 2; i++) {
        if(txt[i] === first && txt[i+1] === second) result.push(txt[i+2]);
    }
    return result;
};
