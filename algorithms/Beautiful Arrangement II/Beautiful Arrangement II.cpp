class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> nums = {1}; 
        int st = 1, last = 1, t = k;
        while(k){
            last = last+k*st; 
            nums.push_back(last); st = st*-1; k--;
        }
        for(int i = t+2; i<=n;++i) nums.push_back(i);
        return nums;
    }
};
