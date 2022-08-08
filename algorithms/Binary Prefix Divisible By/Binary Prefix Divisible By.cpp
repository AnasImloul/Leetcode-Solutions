class Solution {
public:
    /*
    1. We notice that 1 = 1; 10 = 1*2 + 0 = 2; 101 = 2*2 + 1 = 5; .Therefore, the current_decimal form of number = previous sum * 2 + nums[i];
    2. It means: current_number = current_number * 2 + nums[i] (i = current index)
    3. If we did that, the current_number will exceed integer limit => Therefore, we modulo the current_number by 5. We check if the remainder equals to 0 or not. By doing that, we can keep our current_number from 0 to 4, which will not exceed integer range.    
    */
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        vector<bool> answer;
        int current_number = 0;
        for(int i = 0; i < nums.size(); i++){
            current_binary = (current_number *2 + nums[i])%5;
            if(current_number == 0) answer.push_back(true);
            else answer.push_back(false);
        }
        return answer;
    }
};
