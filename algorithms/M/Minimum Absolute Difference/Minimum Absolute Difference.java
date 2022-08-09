class Solution {
    public boolean isPresent(int arr[], int k ,int start, int end){ // log(n) for binary search
        while(start<=end){
            int mid = start + (end-start)/2;
            if(arr[mid] == k)
                return true;
            if(k > arr[mid])
                start = mid+1;
            else
                end = mid-1;
        }
        return false;
    }
    public List<List<Integer>> minimumAbsDifference(int[] arr) {
        Arrays.sort(arr);
        int min_diff = Integer.MAX_VALUE;
        for(int i=0; i<arr.length-1; i++) -- 0(n)
            min_diff = Math.min(min_diff,arr[i+1]-arr[i]);
        
        
        List<List<Integer>> res = new ArrayList<List<Integer>>();
        int start = 0;
        int end = arr.length-1;
        for(int i=0; i<arr.length-1; i++){  // --- o(n)
            int curr = arr[i];
            int target = min_diff+curr;
            
            if(isPresent(arr,target,i+1,arr.length-1)) --- 0(logn)
                res.add(Arrays.asList(curr,target));
            
        }
        return res;
        
    }
}
// overall time complexity  = 0(nlogn)