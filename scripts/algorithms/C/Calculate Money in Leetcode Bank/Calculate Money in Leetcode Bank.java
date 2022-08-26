// Runtime: 0 ms (Top 100.00%) | Memory: 39.1 MB (Top 94.89%)
class Solution {
    public int totalMoney(int n) {
        int m=n/7; //(no.of full weeks)
        // first week 1 2 3 4 5 6 7 (sum is 28 i.e. 7*(i+3) if i=1)
        // second week 2 3 4 5 6 7 8 (sum is 35 i.e. 7*(i+3) if i=2)
        //.... so on
        int res=0; //for result
        //calculating full weeks
        for(int i=1;i<=m;i++){
            res+=7*(i+3);
        }
        //calculating left days
        for(int i=7*m;i<n;i++){
            res+=++m;
        }
        return res;
    }
}