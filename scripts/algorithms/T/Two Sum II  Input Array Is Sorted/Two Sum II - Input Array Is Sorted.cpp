// Runtime: 29 ms (Top 21.83%) | Memory: 15.7 MB (Top 43.77%)
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int low = 0;
        int high = numbers.size()-1;
        vector<int> ans;
        while(low<=high)
        {
            int sum =numbers[low] + numbers[high] ;

            if(sum == target)
                return vector<int>{ low+1, high+1};

            else if(sum>target)
                high=high-1;

            else
                low=low+1;
        }
         return vector<int>{ };;
    }

};