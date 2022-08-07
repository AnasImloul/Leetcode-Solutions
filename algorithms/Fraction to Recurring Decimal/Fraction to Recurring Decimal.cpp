class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        unordered_map<int, int> umap;
        string result = "";
        if ((double) numerator / (double) denominator < 0) result.push_back('-');
        long long l_numerator = numerator > 0 ? numerator : -(long long) numerator;
        long long l_denominator = denominator > 0 ? denominator : -(long long) denominator;
        long long quotient = l_numerator / l_denominator;
        long long remainder = l_numerator % l_denominator;
        result.append(to_string(quotient));
        if (remainder == 0) return result;
        result.push_back('.');
        int position = result.size();
        umap[remainder] = position++;
        while (remainder != 0) {
            l_numerator = remainder * 10;
            quotient = l_numerator / l_denominator;
            remainder = l_numerator % l_denominator;
            char digit = '0' + quotient;
            result.push_back(digit);
            if (umap.find(remainder) != umap.end()) {
                result.insert(umap[remainder], 1, '(');
                result.push_back(')');
                return result;
            }
            umap[remainder] = position++;
        }
        return result;
    }
};
