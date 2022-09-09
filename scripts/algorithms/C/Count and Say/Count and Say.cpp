// Runtime: 7 ms (Top 81.50%) | Memory: 6.6 MB (Top 78.80%)
class Solution {
public:
    string countAndSay(int n) {
        if(n == 1)
            return "1";
        else
        {
            string ans = "";
            string temp = countAndSay(n-1);
            int count = 1, curr = temp[0], i = 1;
            while(i < temp.length())
            {
                if(temp[i] == curr)
                    count++;
                else
                {
                    ans += to_string(count);
                    ans += curr;
                    count = 1;
                    curr = temp[i];
                }
                i++;
            }
            ans += to_string(count);
            ans += curr;

            return ans;
        }

    }
};