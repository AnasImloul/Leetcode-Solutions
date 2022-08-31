// Runtime: 0 ms (Top 100.00%) | Memory: 40.8 MB (Top 69.19%)
class Solution {
    public int countOperations(int num1, int num2) {
        int count=0;
        while(num1!=0 && num2!=0){
            if(num1<num2){
                count+=num2/num1;
                num2=num2%num1;
            }else{
                count+=num1/num2;
                num1=num1%num2;
            }
        }
        return count;
    }
}