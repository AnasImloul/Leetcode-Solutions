function getPrefixSumArray(s) {
    const prefixSumOfOnes = Array(s.length).fill(0);
    
    let currentSum = 0;
    for (let x = 0; x < s.length; x++) {
        if (s[x] === '1')
            currentSum++;
        
        prefixSumOfOnes[x] = currentSum;
    }
    
    return prefixSumOfOnes;
}

var minFlipsMonoIncr = function(s) {
    const prefixSumOfOnes = getPrefixSumArray(s);
    
    let answer = prefixSumOfOnes[s.length - 1]; // Case where we want to change to '0000'
    
    for (let x = 0; x < s.length; x++) {
        const sizeOfRightHandSide = s.length - x;
        let numChangesRequired = null;
        
        if (x === 0) { 
            // Case where we want to change to '1111'
            const numOfOnesToChangeToZero = 0;
            
            const numOfOnesOnRightHandSide = prefixSumOfOnes[s.length - 1];
            const numOfZerosToChangeToOne = sizeOfRightHandSide - numOfOnesOnRightHandSide;
            
            numChangesRequired = numOfOnesToChangeToZero + numOfZerosToChangeToOne;
        }
        else { 
            // Cases like '0111', '0011', '0001'
            const numOfOnesToChangeToZero = prefixSumOfOnes[x - 1];
            
            const numOfOnesOnRightHandSide = prefixSumOfOnes[s.length - 1] - prefixSumOfOnes[x - 1];
            const numOfZerosToChangeToOne = sizeOfRightHandSide - numOfOnesOnRightHandSide;
            
            numChangesRequired = numOfOnesToChangeToZero + numOfZerosToChangeToOne;
        }
        
        answer = Math.min(answer, numChangesRequired);
    }
    
    return answer;
};
