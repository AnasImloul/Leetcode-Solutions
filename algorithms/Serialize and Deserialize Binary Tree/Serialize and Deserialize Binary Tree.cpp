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
