// Runtime: 28 ms (Top 84.21%) | Memory: 14.9 MB (Top 67.84%)
class Solution {
public:
    string largestOddNumber(string num) {
        // Length of the given string
        int len = num.size();
        // We initialize an empty string for the result
        string res = "";
        // We start searching digits from the very right to left because we want to find the first odd digit
        // Which will be the last digit of our biggest odd number
        for (int i = len - 1; i >= 0; i--) {
            // Here we just convert char to an integer in C++
            // We can also do the reverse operation by adding '0' to an int to get char from an int
            int isOdd = num[i] - '0';
            // We check if the current digit is odd, if so this is the position we want to find
            if (isOdd % 2 == 1) {
                // Since we have found the correct spot, let's create our result string
                // We can basically extract the part starting from 0th index to right most odd digit's index
                // Like this:
                // 0123456 -> indices
                // 1246878 -> digits
                // ^....^ -> The part we extracted [0 to 5]
                res = num.substr(0, i + 1); // i+1 is length of substring
                // Because we know this would be the largest substring as we are starting from last
                // We can terminate the loop and return the result
                break;
            }
        }
        return res;
    }
};