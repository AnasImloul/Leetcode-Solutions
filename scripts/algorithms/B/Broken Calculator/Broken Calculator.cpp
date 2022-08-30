// Runtime: 5 ms (Top 18.81%) | Memory: 5.9 MB (Top 70.20%)
class Solution {
public:
    int brokenCalc(int startValue, int target) {
        int result=0;
        while(target>startValue)
        {
            result++;
            if(target%2==0)
                target=target/2;
            else
                target+=1;
        }
        result=result+(startValue-target);
        return result;
    }
};