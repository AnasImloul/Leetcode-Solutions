class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        long long low = 0;
        long long res =0;
        long long high = 1000000005;
        while(low<=high){
            long long mid = (low+high)/2;
            int cnt = 1;
            long long current_sum = 0;
            int can = 1;
            for(auto num: nums){
                if(num > mid){
                    can = 0;
                    break;
                }
                if(current_sum+num>mid){
                    cnt ++;
                    current_sum = 0;
                }
                current_sum += num;
            }
            if(can==1){
                if(cnt>m){
                    low = mid+1;
                }
                else{
                    res = mid;
                    high = mid-1;
                }
            }
            else{
                low = mid+1;
            }
        }
        return res;
    }
};