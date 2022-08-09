class Solution 
{
public:
    int search(vector<int>& nums, int target) 
    {
        int n=nums.size()-1;
        if(nums[0]==target)
            return 0;
        if(nums.size()==1)
           return -1; 
        // find the index of the minimum element ie pivot
        int pivot=-1;
        int low=0;
        int high=n;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(mid==0)
            {
                if(nums[mid]< nums[mid+1] && nums[mid]< nums[n])
                {
                    pivot=mid;
                    break;
                }
                else
                {
                    low=mid+1;
                }
            }
            
            else if(mid==n)
            {
                if(nums[mid] < nums[0] && nums[mid] < nums[mid-1])
                {
                    pivot=mid;
                    break;
                }
                else 
                {
                    high=mid-1;
                }
            }
            else if(nums[mid]<nums[mid+1] && nums[mid]<nums[mid-1])
            {
                pivot=mid;
                break;
            }
            else if(nums[mid]>=nums[0] && nums[mid]<=nums[n])
                high=mid-1;
            else if(nums[mid] >= nums[0])
                low=mid+1;
            else if(nums[mid] < nums[0])
                high=mid-1;
        }
        cout<<pivot<<endl;
        if(target < nums[0])
        {
            int low1=pivot;
            int high1=n;
            while(low1<=high1)
            {
                int mid1=(low1+high1)/2;
                if(nums[mid1]==target)
                    return mid1;
                else if(nums[mid1] > target)
                    high1=mid1-1;
                else if(nums[mid1]<target)
                    low1=mid1+1;
            }
            
        }
        if(target > nums[0])
        {
            int low2=0;
            int high2=pivot-1;
            if(pivot==0)
            {
                low2=0;
                high2=n;
            }
            while(low2<=high2)
            {
                int mid2=(low2+high2)/2;
                if(nums[mid2]==target)
                    return mid2;
                else if(nums[mid2] > target)
                    high2=mid2-1;
                else if(nums[mid2]<target)
                    low2=mid2+1;
            }
        }
        return -1;
    }
};
