class Solution {
    public int sumSubarrayMins(int[] arr) {
      int n = arr.length;
      int ans1[] = nsl(arr);
      int ans2[] = nsr(arr);
      long sum=0;
      for(int i=0;i<n;i++){
        sum=(sum + (long)(arr[i]*(long)(ans1[i]*ans2[i])%1000000007)%1000000007)%1000000007;
      }
      return (int)sum;
	}
    public static int[] nsl(int arr[]){
      Stack<Integer> s = new Stack<>();
      int ans[] = new int[arr.length];
      for(int i=0;i<arr.length;i++){
        while(!s.isEmpty() && arr[i]<arr[s.peek()]){
          s.pop();
        }
        if(s.isEmpty()){
          ans[i] = i-(-1);
          s.push(i);
        }
        else{
          ans[i] = i-s.peek();
          s.push(i);
        }
      }
      return ans;
    }
  public static int[] nsr(int arr[]){
      Stack<Integer> s = new Stack<>();
      int ans[] = new int[arr.length];
      for(int i=arr.length-1;i>=0;i--){
        while(!s.isEmpty() && arr[s.peek()]>=arr[i]){
          s.pop();
        }
        if(s.isEmpty()){
          ans[i] = arr.length-i;
          s.push(i);
        }
        else{
          ans[i] = s.peek()-i;
          s.push(i);
        }
      }
      return ans;
    }
}
