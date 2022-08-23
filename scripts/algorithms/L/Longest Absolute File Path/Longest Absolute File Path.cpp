// Runtime: 0 ms (Top 100.00%) | Memory: 6.5 MB (Top 50.23%)
// Using Map O(300 + N)

class Solution {
    public:
    int lengthLongestPath(string input) {
        input.push_back('\n');
        vector<int> levels(301, 0);
        int ans = 0;
        int curr_tabs = 0;
        bool is_file = false;
        int curr_word_len = 0;
        int total_len = 0;

        for(char c : input)
        {
            if(c == '\t')
            {
                curr_tabs++;
            }
            else if(c == '\n')
            {
                if(curr_tabs == 0)
                {
                    levels[0] = curr_word_len;
                }
                else
                {
                    levels[curr_tabs] = levels[curr_tabs-1] + curr_word_len;
                }

                if(is_file)
                {
                    ans = max(ans, levels[curr_tabs] + curr_tabs);
                    // levels[curr_tabs] = 0;
                }
                curr_tabs = 0;
                is_file = false;
                curr_word_len = 0;
            }
            else if(c == '.')
            {
                is_file = true;
                curr_word_len++;
            }
            else
            {
                curr_word_len++;
            }
        }
        return ans;
    }
};
