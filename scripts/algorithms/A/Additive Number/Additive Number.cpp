// Runtime: 4 ms (Top 35.88%) | Memory: 6.5 MB (Top 9.47%)

class Solution
{
public:
    bool isAdditiveNumber(string num)
    {
        vector<string> adds;
        return backtrack(num, 0, adds);
    }

private:
    bool backtrack(string num, int start, vector<string> &adds)
    {
        if (start >= num.size() && adds.size() >= 3)
            return true;

        int maxSize = num[start] == '0' ? 1 : num.size() - start;
        for (int i = 1; i <= maxSize; i++)
        {
            string current = num.substr(start, i);

            if (adds.size() >= 2)
            {
                string num1 = adds[adds.size() - 1], num2 = adds[adds.size() - 2];
                string sum = add(num1, num2);
                if (sum != current)
                    continue;
            }

            adds.push_back(current);
            if (backtrack(num, start + i, adds))
                return true;
            adds.pop_back();
        }
        return false;
    }

    string add(string num1, string num2)
    {
        string sum;
        int i1 = num1.size() - 1, i2 = num2.size() - 1, carry = 0;
        while (i1 >= 0 || i2 >= 0)
        {
            int current = carry + (i1 >= 0 ? (num1[i1--] - '0') : 0) + (i2 >= 0 ? (num2[i2--] - '0') : 0);
            carry = current / 10;
            sum.push_back(current % 10 + '0');
        }
        if (carry)
            sum.push_back(carry + '0');
        reverse(begin(sum), end(sum));
        return sum;
    }
};