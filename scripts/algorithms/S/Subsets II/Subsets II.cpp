// Runtime: 25 ms (Top 5.31%) | Memory: 8.3 MB (Top 35.96%)
class Solution {
public:
    vector<vector<int>> ans;
    void recur(vector<int>& nums, int i, vector<int> vec){
        if(i > nums.size()){
            return;
        }
        for(int j = i; j < nums.size(); j++){
            vec.push_back(nums[j]);

            vector<int> temp = vec;
            sort(vec.begin(), vec.end());

            if(find(ans.begin(), ans.end(), vec) == ans.end()){
                ans.push_back(vec);
            }

            recur(nums, j + 1, vec);

            //can't just pop_back any need to pop_back the one we added
            vec = temp;
            vec.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> vec;
        ans.push_back(vec);
        recur(nums, 0, vec);

        return ans;
    }
};