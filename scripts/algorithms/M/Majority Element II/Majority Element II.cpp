// Runtime: 36 ms (Top 22.99%) | Memory: 15.8 MB (Top 91.31%)
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {

        int n = nums.size();

        vector<int> result;

        int num1 = -1 , num2 = -1 , count1 = 0 , count2 = 0;

        for(auto it : nums){

            if(num1 == it) ++count1;
            else if(num2 == it) ++count2;
            else if(count1 == 0){
                num1 = it;
                count1 = 1;
            }
            else if(count2 == 0){
                num2 =it;
                count2 = 1;
            }
            else{
                --count1;
                --count2;
            }

        }

        count1 = 0;
        count2 = 0;

        for(auto it : nums){

            if(it == num1) ++count1;
            else if(it == num2) ++count2;

        }

        if(count1>(n/3)) result.push_back(num1);
        if(count2>(n/3)) result.push_back(num2);

        return result;

    }
};