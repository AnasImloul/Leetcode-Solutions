// Runtime: 8 ms (Top 8.75%) | Memory: 7.5 MB (Top 7.30%)
class Solution {
public:
    int countOperations(int num1, int num2) {
        if(num1==0 || num2==0) return 0;
        if(num1>=num2) num1=num1-num2;
        else if(num2>num1) num2=num2-num1;
        return 1+countOperations(num1,num2);
    }
};