class Solution {
    public int subtractProductAndSum(int n) {
        int mul=1,sum=0;
        while(n!=0){
            sum=sum+n%10;
            mul=mul*(n%10);
            n=n/10;
        }
        return mul-sum;
    }
}
