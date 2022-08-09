class Solution {
    private static int gcd(int a,int b){
        if(b==0)return a;
        return gcd(b,a%b);
    }
    public boolean canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity) {
        if(targetCapacity>jug1Capacity+jug2Capacity){
            return false;
        }
        int g=gcd(jug1Capacity,jug2Capacity);
        return (targetCapacity%g==0);
    }
}
