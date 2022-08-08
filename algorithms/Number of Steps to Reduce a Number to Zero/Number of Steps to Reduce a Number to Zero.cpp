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
