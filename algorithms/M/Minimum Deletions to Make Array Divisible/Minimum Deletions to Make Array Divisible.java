class Solution {
    public int minOperations(int[] nums, int[] numsDivide) {
        int gcdOfnums = numsDivide[0];
        for(int i =1;i<numsDivide.length;i++){
            gcdOfnums = gcd(gcdOfnums,numsDivide[i]);
        }
        int remove = 0;
        boolean isFound = false;
        for(int num: nums){
            if(gcdOfnums%num == 0){
                gcdOfnums= Math.min(num, gcdOfnums);
            }
        }
        for(int num: nums){
            if(num == gcdOfnums) isFound = true;
            else if(num < gcdOfnums) remove++;
        }
        return (isFound ? remove:-1);
    }
    private int gcd(int num1, int num2){
        int div, rem, num;
        if(num1<num2){
            div = num2/num1;
            rem = num2%num1;
            num = num1;
        }
        else{
            div = num1/num2;
            rem = num1%num2;
            num= num2;
        }
        if(rem == 0) return num;
        return gcd(num, rem);
    }
}
