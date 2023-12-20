// Runtime: 12 ms (Top 11.87%) | Memory: 11.00 MB (Top 18.16%)

class Solution {
public:
 int thirdMax(vector<int>& nums) {
           set<int>s;
        for(int i=0;i<nums.size();i++){
            s.insert(nums[i]);
        }
        if(s.size()>=3){   // when set size >=3 means 3rd Maximum exist(because set does not contain duplicate element)
            int Third_index_from_last=s.size()-3;
            auto third_maximum=next(s.begin(),Third_index_from_last);
            return *third_maximum;
        }
            return *--s.end(); // return maximum if 3rd maximum not exist
    }
};
