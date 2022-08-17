class Solution {
public:
    bool judgeSquareSum(int c) {
        long long start=0,end=0;
        while(end*end<c){
            end++;
        }
        long long target=c;
        while(start<=end){
            long long product=start*start+end*end;
            if(product==target){
                return true;
            } else if(product>c){
                end--;
            } else {
                start++;
            }
        }
        return false;
    }
};