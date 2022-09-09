// Runtime: 21 ms (Top 47.05%) | Memory: 7 MB (Top 42.13%)
/*
    https://leetcode.com/problems/longest-substring-with-at-least-k-repeating-characters/

    TC: O(26 * n) ~ O(n)
    SC: O(26)

    At a glance even though it seems like it can be solved with sliding window, it's hard to come
    up with window condition with the traditional sliding window approach.
    Problem is what will be your valid window criteria? Since we dont know how many unique chars might
    come up in the window, we dont know whether we should shrink the window or even though few of the
    unique chars have at least k instances.

    So we change the problem a bit. We change the window criteria:
    Find the max length window with atmost X unique chars. This is easier problem to deal with.
    The shrinking window criteria is clear, also we also keep track of chars in the window
    with frequency >= k while solving this problem.

    Now since we are limiting the no. of unique chars, we need to run the above |unique chars in s| times.
*/
class Solution {
public:
    int uniqueChars(string& s) {
        unordered_set<char> chars(s.begin(), s.end());
        return chars.size();
    }

    int longestSubstring(string s, int k) {
        // find the no. of unique chars in string
        int max_unique_chars = uniqueChars(s);
        int max_len = 0, n = s.size();

        for(int curr_unique_chars = 1; curr_unique_chars <= max_unique_chars; curr_unique_chars++) {
            int start = 0, end = 0;
            int atleast_k = 0;
            unordered_map<char, int> freq;

            // Process the max length window with at max curr_unique_chars unique chars
            while(end < n) {
                // attempt window expansion
                if(++freq[s[end]] == k)
                    ++atleast_k;
                ++end;

                // shrink the window if unique chars exceeds the limit
                while(freq.size() > curr_unique_chars && start <= end) {
                    // Current char contributed to atleast_k count, so it's count will be lesser than k now
                    if(freq[s[start]] == k)
                        --atleast_k;
                    if(--freq[s[start]] == 0)
                        freq.erase(s[start]);
                    ++start;
                }
                // If the current window has required no. of chars and it also each unique
                // chars have atleast k instances
                if(freq.size() == curr_unique_chars && atleast_k == freq.size())
                    max_len = max(max_len, end - start);
            }
        }
        return max_len;
    }
};