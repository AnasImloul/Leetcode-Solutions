// Runtime: 8 ms (Top 29.27%) | Memory: 8 MB (Top 33.77%)
class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> ans;
        string hehe;
        for (int i = 1; i <= n; i++) {
            if (i % 3 == 0 and i % 5 == 0) hehe += "FizzBuzz";
            else if (i % 3 == 0) hehe += "Fizz";
            else if (i % 5 == 0) hehe += "Buzz";
            else hehe = to_string(i);
            ans.push_back(hehe);
            hehe = "";
        }
        return ans;
    }
};