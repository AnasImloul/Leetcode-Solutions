class Solution {
    public int[] prevPermOpt1(int[] arr) {
        int n=arr.length;
        int small=arr[n-1];
        int prev=arr[n-1];
        for(int i=n-2;i>=0;i--){
            if(arr[i]<=prev){
                prev=arr[i];
            }
            else{
                int indte=i;
                int te=0;
                    for(int j=i+1;j<n;j++){
                        if(arr[j]<arr[i]&&arr[j]>te){
                            te=arr[j];
                            indte=j;
                        }
                }
                int tem=arr[indte];
                arr[indte]=arr[i];
                arr[i]=tem;
                return arr;
            }
        }
        return arr;
    }
}
