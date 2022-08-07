class Solution {
    public int search(int[] nums, int target) {
        int minIndex = findMinIndex(nums);
        int left = find(nums, target, 0, minIndex - 1);
        int right = find(nums, target, minIndex, nums.length-1);
        return left == -1?right:left;
    }
    public int findMinIndex(int[] arr){
        int n = arr.length;
        int start = 0;
        int end = n-1;
        int prev, next;
        
        while(start <= end){
            int mid = start + (end - start)/2;
            next = (mid + 1) % n;
            prev = (mid + n-1) % n;
            if(arr[mid] <= arr[prev] && arr[mid] <= arr[next])
                return mid;
            else{
                if(arr[start] <= arr[mid] && arr[mid] <= arr[end])
                    return start;
                else if(arr[start] <= arr[mid])
                    start = mid + 1;
                else if(arr[mid] <= arr[end])
                    end = mid - 1;
            }
        }
        return -1;
    }
    public int find(int[] arr, int target, int start, int end){
        while(start <= end){
            int mid = start + (end - start)/2;
            if(arr[mid] == target)
                return mid;
            else if(arr[mid] <= target)
                start = mid + 1;
            else
                end = mid - 1;
        }
        return -1;
    }
}
