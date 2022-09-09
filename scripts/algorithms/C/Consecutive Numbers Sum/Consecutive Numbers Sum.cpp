// Runtime: 6 ms (Top 49.82%) | Memory: 5.8 MB (Top 96.45%)
class Solution {
public:
    int consecutiveNumbersSum(int n) {
        int count = 0;
        for(int i = 2 ; i < n ; i++){
            int sum_1 = i*(i+1)/2;
            if(sum_1 > n)
                break;
            if((n-sum_1)%i == 0)
                count++;
        }
        return count+1;
    }
};