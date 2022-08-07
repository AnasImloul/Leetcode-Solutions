var findWords = function(words) {
const firstRow = {"q":true,"w":true,"e":true,"r":true,"t":true,"y":true,"u":true,"i":true,"o":true,"p":true }
const secondRow = {"a":true,"s":true,"d":true,"f":true,"g":true,"h":true,"j":true,"k":true,"l":true }
const thirdRow = {"z":true,"x":true,"c":true,"v":true,"b":true,"n":true,"m":true }
let result = [];

const helperFunc= (word)=>{
    let targetRow;
        //Determine in which row the word should be;
        if(firstRow[word[0].toLowerCase()]) targetRow = firstRow;
        if(secondRow[word[0].toLowerCase()]) targetRow = secondRow;
        if(thirdRow[word[0].toLowerCase()]) targetRow = thirdRow;
    
    for(let i = 1;i<word.length;i++) {
        if(!targetRow[word[i].toLowerCase()]) {
            return false;
        }
    }
    return true;
    }

    for(let i =0;i<words.length;i++) {
        if(helperFunc(words[i])) {
            result.push(words[i])
        }
    }
    return result;
};
