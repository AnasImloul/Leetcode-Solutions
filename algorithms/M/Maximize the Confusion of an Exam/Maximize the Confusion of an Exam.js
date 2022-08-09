var maxConsecutiveAnswers = function(answerKey, k) {
    let [left, right, numOfTrue, numOfFalse, max] = new Array(5).fill(0);
    const moreChanges = () => numOfTrue > k && numOfFalse > k;
    while (right < answerKey.length) {
        if(answerKey[right] === 'T') numOfTrue++;
        if(answerKey[right] === 'F') numOfFalse++;
        while(moreChanges()) {
            if(answerKey[left] === 'T') numOfTrue--;
            if(answerKey[left] === 'F') numOfFalse--;    
            left++;    
        }
        max = Math.max(max, right - left + 1);
        right++;
    }
    return max;
};
