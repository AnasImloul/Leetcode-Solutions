// Runtime: 0 ms (Top 100.00%) | Memory: 39.3 MB (Top 90.51%)
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