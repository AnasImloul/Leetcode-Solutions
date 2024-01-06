// Runtime: 19 ms (Top 71.45%) | Memory: 27.40 MB (Top 28.07%)

class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int cnt = 0; //to store the count of modifications                   
        for(int i = 1; i < nums.size(); i++){

            //decreasing sequence found
            if(nums[i] < nums[i-1]){

                //if count after increasing becomes more than 1 then false
                if(++cnt > 1) return false;
                
                //in case of the 2nd element as i[1] < i[0] so make i[0] = i[1]
                //if prev of prev element of curr is less than or equal to it then only the we can make it non decreasing by making the greater equal to lesser (prev = curr).
                if(i == 1 || nums[i-2] <= nums[i])
                    nums[i-1] = nums[i];    
                
                //if prev of prev is greater than curr then we have to make the lesser equal to greater (curr = prev)
                else 
                    nums[i] = nums[i-1];
            }
        }
        
        //this command will only run if the loop is totally traversed and count <= 1 so return true.
        return true;
    } 
};
