// Runtime: 63 ms (Top 28.88%) | Memory: 6.7 MB (Top 20.04%)
class Solution {
public:

    // GREEDY APPROACH
    // min steps to make strings equal

    int minSteps(string s1, string s2) {
        int size = s1.length();
        int i = 0, j = 0;
        int result = 0;

        while (i < size) {
            j = i;
            while (s1[j] != s2[i]) j++;

            while (i < j) {
                swap(s1[j], s1[j-1]);
                j--;
                result++;
            }
            i++;
        }
        return result;
    }

    int getMinSwaps(string num, int k) {
        string original = num;

        while(k--) {
            next_permutation(num.begin(), num.end());
        }

        return minSteps(original, num);
    }
};