// Runtime: 124 ms (Top 20.83%) | Memory: 44.3 MB (Top 68.23%)
var hasGroupsSizeX = function(deck) {
    let unique = [...new Set(deck)], three = 0, two = 0, five = 0, size = 0, same = 0, s = 0;

    for(let i = 0; i<unique.length; i++){
        for(let y=0; y<deck.length; y++){
            if(unique[i] === deck[y]){
                size++;
            }
        }
        if(size<2) return false;
        if(size%2===0) two++;
        if(size%3===0) three++;
        if(size%5===0) five++;
        if(s === size) same++;
        s = size;
        size = 0;
    }

    if(Math.max(two,three,five) !== unique.length && same !== unique.length-1) return false;
    return true;
};