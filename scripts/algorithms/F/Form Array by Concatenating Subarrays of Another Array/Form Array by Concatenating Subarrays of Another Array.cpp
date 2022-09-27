// Runtime: 30 ms (Top 53.45%) | Memory: 14 MB (Top 39.66%)
class Solution {
public:
    //Idea is to use KMP Longest Prefix Suffix array to match if one array is subarray of another array.
    bool canChoose(vector<vector<int>>& groups, vector<int>& nums) {
        int m = nums.size();
        int index = 0;
        for(auto group : groups){
            int n = group.size();
            //Step-1 Generate LPS
            vector<int>lps(n,0);
            for(int i = 1;i<n; i++){
                int j = lps[i-1];
                while(j>0 && group[i] != group[j]){
                    j = lps[j-1];
                }
                if(group[i] == group[j]){
                    j++;
                }
                lps[i] = j;
            }

            //Step 2 - Matching
            int j = 0;
            while(index<m){
                if(nums[index]==group[j]){
                    j++;
                    index++;
                }
                if(j==n)
                    break;
                else
                 if(index <m && nums[index] != group[j]){
                    if(j >0){
                        j=lps[j-1];
                    }else{
                        index++;
                    }
                }
            }
            if(j != n)
                return false;
        }

        return true;
    }
};