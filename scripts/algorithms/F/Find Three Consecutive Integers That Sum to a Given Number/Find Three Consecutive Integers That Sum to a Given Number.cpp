// Runtime: 0 ms (Top 100.00%) | Memory: 6.1 MB (Top 19.77%)
class Solution {
public:
    vector<long long> sumOfThree(long long num) {
        //binary Search

        long long lo = -1;// -1 becoz we have num == 0 as well if we put lo=0 then it will fail in 1 testcase
        long long hi = num;
        while(lo<=hi){
            long long mid = lo +(hi-lo)/2;
            long long val = 3*mid+3;//mid+mid+1mid+2 == num
            if(val == num){
                return {mid,mid+1,mid+2};
            }
            else if(val>num){
                hi = mid-1;
            }
            else{
                lo = mid+1;
            }
        }

        return {};
    }
};