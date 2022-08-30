// Runtime: 11 ms (Top 84.52%) | Memory: 6.1 MB (Top 75.30%)
class Solution {
public:
    int countBalls(int lowLimit, int highLimit) {

        vector<int> box (46,0);
        for(int i = lowLimit;i<=highLimit;i++)
        {
            int sum = 0;
            int temp = i;
            while(temp)
            {
                sum = sum + temp%10;
                temp = temp/10;
            }
            box[sum]++;
        }

        return *max_element(box.begin(),box.end());
    }
};