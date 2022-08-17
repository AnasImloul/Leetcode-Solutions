class Solution {
    public double calculateTax(int[][] brackets, int income) {
        double ans=0;
        int pre=0;
        for(int[] arr : brackets){
            int val=arr[0]; arr[0]-=pre;  pre=val;
            ans+=(double)(Math.min(income,arr[0])*arr[1])/100;
            income-=arr[0];
            if(income<=0){ break; }
        }
        return ans;
    }
}
