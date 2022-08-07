/**
 * @param {string} s
 * @return {string}
 */
var reverseVowels = function(s) {
    const vowels = new Map(); 
    vowels.set('a');
    vowels.set('e');
    vowels.set('i');
    vowels.set('o');
    vowels.set('u');
    
    let start = 0;
    let end = s.length - 1;
    
    const sArr = s.split('');
    
    while (start < end) {
        if (vowels.has(sArr[start].toLowerCase()) && vowels.has(sArr[end].toLowerCase())) {
            [sArr[start], sArr[end]] = [sArr[end], sArr[start]];
            start++;
            end--;
            continue;
        }
        
        if (!vowels.has(sArr[start].toLowerCase())) {
            start++;    
        } else if (!vowels.has(sArr[end].toLowerCase())) {
            end--;
        } else {
            start++;    
            end--;
        }
    }
    
    return sArr.join('');
};
