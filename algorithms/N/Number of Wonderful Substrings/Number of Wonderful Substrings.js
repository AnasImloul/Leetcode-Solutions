/**
 * @param {string} word
 * @return {number}
 */
var wonderfulSubstrings = function(word) {
    let hashMap={},ans=0,binaryRepresentation=0,t,pos,number,oneBitToggled;
    hashMap[0]=1;
    for(let i=0;i<word.length;i++){
        pos = word[i].charCodeAt(0)-"a".charCodeAt(0);//Let's use position 0 for a, 1 for b .... 9 for j
        t = (1 << pos);
        binaryRepresentation = (binaryRepresentation^t);//Toggle the bit at pos in the current mask(pattern)
        //This loop will check same binaryRepresentation and all the other binaryRepresentation with difference of 1 bit
        for(let i=0;i<10;i++){//Check all the numbers by changing 1 position
            number = (1<<i);//Change 1 bit at a time 
            oneBitToggled = (binaryRepresentation^number);
            if(hashMap[oneBitToggled]!==undefined){
                ans += hashMap[oneBitToggled];
            }
        }
        if(hashMap[binaryRepresentation]===undefined){
            hashMap[binaryRepresentation]=1;
        }else{
            ans += hashMap[binaryRepresentation];
            hashMap[binaryRepresentation]++;
        }
    }
    return ans;
};
