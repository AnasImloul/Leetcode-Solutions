class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        //it looks a quite complicated problem but actually it is not
        //the main observation here is when a element is deleted the odd sum after the element becomes the evensum and vice versa
        //so we maintain two vectors left and right
        vector<int> left(2,0);
        vector<int> right(2,0);
        
        //left[0],right[0] stores the sum of even indices elements to the left and right side of the element respectively
        //left[1] right[1] stores the sum of odd indices elements to the left and right side of the element respectively
        
        int ans=0; //stores the result
        //first store the odd sum and even sum in right
        for(int i=0;i<nums.size();i++)
        {
            if(i%2)
            {
                //odd index 
                right[1]+=nums[i];
            }
            else{
                //even index 
                right[0]+=nums[i];
            }
        }
        
        //now traverse through every element in the array and try to remove the element  and check does it makes a fair array
        for(int i=0;i<nums.size();i++)
        {
            //try to remove the element
            int currOdd=right[1];
            int currEven=right[0];
            if(i%2)
            {
                //odd index , remove it from currOdd
                currOdd-=nums[i];
                right[1]-=nums[i]; //since it would be no longer to the right
            }
            else{
                //even index , remove it from currEven
                currEven-=nums[i];
                right[0]-=nums[i];
            }
            //now check whether the total oddSum and the evenSum in the array are equal ?
            //since we are deleting this element oddSum becomes evenSum and evenSum becomes oddSum
            //check leftOdd+rightOdd==rightEven+leftEven
            //left[0] is even sum to left of i 
            //left[1] is the odd sum to left of i
            if(left[0]+currOdd==left[1]+currEven)
                ans++;
            //since we traverse to right add this value to the left array
            (i%2) ? left[1]+=nums[i] : left[0]+=nums[i];
        }
        
        return ans;
    }
};
