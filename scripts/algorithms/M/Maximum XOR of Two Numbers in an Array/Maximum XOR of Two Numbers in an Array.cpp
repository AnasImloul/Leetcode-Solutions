// Runtime: 396 ms (Top 62.05%) | Memory: 87.3 MB (Top 27.92%)
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int max_length = floor(log2(max(*max_element(nums.begin(), nums.end()), 1))) + 1;
        int ans_int = 0;
        string ans_string('0', max_length);
        TreeNode *root = new TreeNode(-1);

        for (auto &num : nums) {
            TreeNode *curr_node = root;
            TreeNode *comp_node = root;
            string curr_num_to_bit = numToBit(num, max_length);
            int update = 0;
            char curr_bit = '0';

            for (int curr = 0; curr < max_length; curr++) {

                if (curr_num_to_bit[curr] == '0') {
                    if (curr_node -> left == nullptr) curr_node -> left = new TreeNode(0);
                    curr_node = curr_node -> left;

                    curr_bit = (comp_node -> right != nullptr) ? '1' : '0';
                    comp_node = (comp_node -> right != nullptr) ? comp_node -> right : comp_node -> left;
                }
                else {
                    if (curr_node -> right == nullptr) curr_node -> right = new TreeNode(1);
                    curr_node = curr_node -> right;

                    curr_bit = (comp_node -> left != nullptr) ? '1' : '0';
                    comp_node = (comp_node -> left != nullptr) ? comp_node -> left : comp_node -> right;
                }

                if (update == 0 && ans_string[curr] - '0' < curr_bit - '0') update = 1;
                else if (update == 0 && ans_string[curr] - '0' > curr_bit - '0') update = -1;

                ans_string[curr] = (update == 1) ? curr_bit : ans_string[curr];
            }
        }

        for (int curr = 0; curr < max_length; curr++) {
            ans_int += ((ans_string[curr] - '0') << (max_length - curr - 1));
        }

        return ans_int;
    }

    string numToBit (int num, int length) {
        string num_to_bit = "";

        while (num > 0) {
            num_to_bit.push_back((char)(num % 2 + '0'));
            num /= 2;
        }

        while (num_to_bit.size() < length) {
            num_to_bit.push_back('0');
        }

        reverse(num_to_bit.begin(), num_to_bit.end());

        return num_to_bit;
    }
};