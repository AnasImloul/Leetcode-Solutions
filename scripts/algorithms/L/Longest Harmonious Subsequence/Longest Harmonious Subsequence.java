// Runtime: 26 ms (Top 74.55%) | Memory: 54.5 MB (Top 74.21%)
class Solution {
    public static int firstOccurence(int[] arr,int target)
    {
        int res=-1;
        int start=0;
        int end=arr.length-1;
        while(start<=end)
        {
            int mid=start + (end-start)/2;
            if(arr[mid]==target)
            {
                res=mid;
                end=mid-1;
            }
            else if(arr[mid]<target)
            {
                start=mid+1;
            }
            else
            {
                end=mid-1;
            }
        }
        return res;
    }
    public static int lastOccurence(int[] arr,int target)
    {
        int res=-1;
        int start=0;
        int end=arr.length-1;
        while(start<=end)
        {
            int mid=start + (end-start)/2;
            if(arr[mid]==target)
            {
                res=mid;
                start=mid+1;
            }
            else if(arr[mid]<target)
            {
                start=mid+1;
            }
            else
            {
                end=mid-1;
            }
        }
        return res;
    }
    public int findLHS(int[] nums) {
        Arrays.sort(nums);
        int maxLen=0;
        for(int i=0;i<nums.length-1;i++)
        {
            if(nums[i+1]==nums[i]+1)
            {
            int a=firstOccurence(nums,nums[i]);
            int b=lastOccurence(nums,nums[i]+1);
            if(b-a+1>maxLen)
                maxLen=b-a+1;
            }
        }
        return maxLen;
    }
}