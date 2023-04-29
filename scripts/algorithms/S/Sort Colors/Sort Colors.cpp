class Solution {
public:
    void sortColors(vector<int>& nums) {
        int a =0; int b=0,c=0;int i;
        for(i=0;i<nums.size();i++){
            if(nums[i]==0){
                a++;
            }
            if(nums[i]==1){
                b++;
            }
            else c++;
            
        }
        for(i=0;i<nums.size();i++){
            if(i<a){
                nums[i]=0;
            }
            else if(i<a+b){
                nums[i]=1;
            }
            else nums[i]=2;
        }
      
    }
};