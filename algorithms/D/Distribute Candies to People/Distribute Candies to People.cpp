class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> Candies (num_people, 0);
        int X = 0;
        while (candies)
        {
            for (int i = 0; i < num_people; ++i)
            {
                int Num = X * num_people + i + 1;
                if (candies >= Num)
                {
                    Candies[i] += Num;
                    candies -= Num;
                }
                else
                {
                    Candies[i] += candies;
                    candies = 0;
                    break;
                }
            }
            ++X;
        }
        return Candies;
    }
};
