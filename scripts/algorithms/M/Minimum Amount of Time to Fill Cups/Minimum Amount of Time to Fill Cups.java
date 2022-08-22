// Runtime: 2 ms (Top 59.66%) | Memory: 41.5 MB (Top 48.39%)
class Solution {
    public int fillCups(int[] amount) {
         Arrays.sort(amount);
        int x=amount[0];
         int y=amount[1];
         int z=amount[2];
        int sum=x+y+z;
        if(x+y>z){return sum/2 +sum%2;}
        if(x==0&&y==0){return z;}
        else{return z;}
    }
}