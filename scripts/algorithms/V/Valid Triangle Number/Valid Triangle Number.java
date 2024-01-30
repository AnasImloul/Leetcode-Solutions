// Runtime: 23 ms (Top 95.13%) | Memory: 43.50 MB (Top 23.38%)

class Solution {
    public int triangleNumber(int[] a) {
        Arrays.sort(a);
        int n=a.length;
        int count=0;
        for(int i=n-1;i>=1;i--){
            int left=0,right=i-1;
            while(left<right){
                if(a[left]+a[right]>a[i]){
                    count+=right-left;
                    right--;
                }
                else
                left++;
            }
        }
        return count;
    }
}
