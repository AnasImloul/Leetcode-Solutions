// Runtime: 354 ms (Top 5.04%) | Memory: 75.8 MB (Top 46.03%)
class Solution {
    int cnt;
    public int reversePairs(int[] nums) {
        int n = nums.length;
        cnt = 0;
        sort(0 , n - 1 , nums);
        return cnt;
    }
    void sort(int l , int r , int nums[]){
        if(l == r){
            return;
        }
        int mid = l + (r - l) / 2;
        sort(l , mid , nums);
        sort(mid + 1 , r , nums);
        merge(l , mid , r , nums);
    }
    void merge(int l , int mid , int r , int nums[]){
        int n1 = mid - l + 1;
        int n2 = r - mid;
        int a[] = new int[n1];
        int b[] = new int[n2];
        for(int i = 0; i < n1; i++){
            a[i] = nums[l + i];
        }
        for(int j = 0; j < n2; j++){
            b[j] = nums[mid + 1 + j];
            int idx = upperBound(a , 0 , n1 - 1 , 2L * (long)b[j]);
            if(idx <= n1) {
                cnt += n1 - idx;
            }
        }
        int i = 0;
        int j = 0;
        int k = l;
        while(i < n1 && j < n2){
            if(b[j] <= a[i]){
                nums[k++] = b[j++];
            }
            else{
                nums[k++] = a[i++];
            }
        }
        while(i < n1){
            nums[k++] = a[i++];
        }
        while(j < n2){
            nums[k++] = b[j++];
        }
    }
    int upperBound(int a[] , int l , int r , long x){
        int ans = r + 1;
        while(l <= r){
            int mid = l + (r - l) / 2;
            if((long)a[mid] > x){
                ans = mid;
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        return ans;
    }
}