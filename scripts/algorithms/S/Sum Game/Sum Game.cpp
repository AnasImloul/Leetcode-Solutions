class Solution {
public:
    bool sumGame(string num) {
        const int N = num.length();
        
        int lDigitSum = 0;
        int lQCount = 0;
        int rDigitSum = 0;
        int rQCount = 0;
        
        for(int i = 0; i < N; ++i){
            if(isdigit(num[i])){
                if(i < N / 2){
                    lDigitSum += (num[i] - '0');
                }else{
                    rDigitSum += (num[i] - '0');
                }
            }else{
                if(i < N / 2){
                    ++lQCount;
                }else{
                    ++rQCount;
                }
            }
        }
        
        // Case 0: Only digits (without '?')
        if((lQCount + rQCount) == 0){
            return (lDigitSum != rDigitSum);
        }
        
        // Case 1: Odd number of '?'
        if((lQCount + rQCount) % 2 == 1){
            return true;
        }
        
        // Case 2: Even number of '?'
        int minQCount = min(lQCount, rQCount);
        lQCount -= minQCount;
        rQCount -= minQCount;
        return (lDigitSum + 9 * lQCount / 2 != rDigitSum + 9 * rQCount / 2);
    }
};
