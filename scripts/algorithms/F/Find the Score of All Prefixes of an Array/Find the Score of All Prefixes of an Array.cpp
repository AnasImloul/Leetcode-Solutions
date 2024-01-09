// Runtime: 76 ms (Top 91.84%) | Memory: 64.00 MB (Top 5.14%)

class Solution {
public:
    vector<long long> findPrefixScore(vector<int>& nums) {
        vector<long long> b;  
        vector<long long> ans;
        int n = nums.size();
        int mm= INT_MIN;
        long long aa = 0;
        for(int  i = 0 ; i < n; i++){        //0, 1...
            long long a  = 0;
            mm = max(mm, nums[i]);        // 2 , 3...
            a = nums[i] + mm;             //2+2 = 4, 3+3  = 6, ..
            b.push_back(a);               // b=[4,6,]...
            aa += b[i];                   //0+4 = 4, 4+6 = 10,...  
            ans.push_back(aa);            //ans = [4,10,...]
        }
        return ans;                      
    }
};

