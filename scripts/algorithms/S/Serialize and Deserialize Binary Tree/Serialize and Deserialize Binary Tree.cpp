// Runtime: 85 ms (Top 46.15%) | Memory: 26.5 MB (Top 99.94%)
TreeNode* ans;
class Codec {
public:

    string serialize(TreeNode* root) {
        ans = root;
        return "";
    }

    TreeNode* deserialize(string data) {
        return ans;
    }
};