class Solution
{
public:
    string getHint(string secret, string guess)
    {
        int bulls = 0;
        vector<int> v1(10, 0);
        vector<int> v2(10, 0);
        for (int i = 0; i < secret.size(); ++i)
        {
            if (secret[i] == guess[i])
            {
                ++bulls;
            }
            else
            {
                ++v1[secret[i] - '0'];
                ++v2[guess[i] - '0'];
            }
        }
        int cows = 0;
        for (int i = 0; i < 10; ++i)
        {
            cows += min(v1[i], v2[i]);
        }
        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};

