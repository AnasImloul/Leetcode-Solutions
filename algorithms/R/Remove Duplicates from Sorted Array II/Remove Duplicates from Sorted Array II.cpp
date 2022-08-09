class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
       int l = 1;
        int last_selected = nums[0];
        int count = 1;
        int n = nums.size();
        for(int i = 1;i<n;i++)
        {
            if(nums[i]!=last_selected){
                count = 1;
                last_selected = nums[i];
                nums[l] = nums[i];
                l++;
            }
            else if(count == 2){
                continue;
            }
            else{
                nums[l] = nums[i];
                l++;
                count++;
            }
        }
        return (l);
    }
};
