// Runtime: 3 ms (Top 38.53%) | Memory: 5.8 MB (Top 74.06%)
class Solution {
public:
    int numberOfSteps(int num) {
        int count = 0;
        while (num > 0)
        {
            if (num % 2==0)
            {
                num = num/2;
                count++;
            }
            else
            {
                if(num > 1)
                {
                    num -= 1;
                    count++;
                }
                else
                {
                    count++;
                    break;
                }
            }
        }
        return count;
    }
};