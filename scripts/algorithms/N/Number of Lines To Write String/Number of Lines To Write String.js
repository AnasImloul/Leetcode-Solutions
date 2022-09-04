// Runtime: 110 ms (Top 27.73%) | Memory: 43.1 MB (Top 24.37%)
var numberOfLines = function(widths, s) {
    let pixel=100, line=1;
    for(let i=0; i<s.length; i++){
        if(pixel>=widths[s[i].charCodeAt()-97]){
            pixel-=widths[s[i].charCodeAt()-97];
        }else{
            // this word should be written in NEXT line, so it CANNOT count.
            i--; line++; pixel=100;
        }
    }
    // 100-pixel = space used in this line.
    return [line, 100-pixel];
};