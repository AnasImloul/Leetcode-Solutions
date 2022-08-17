/**
 * @param {character[]} letters
 * @param {character} target
 * @return {character}
 */
var nextGreatestLetter = function(letters, target) {
    let result=[]
    for (letter of letters){
        if (letter>target){
            result.push(letter);
        }
    }
    if (result.length){
        return result[0];
    }
    else{
        return letters[0];
    }
    
};
