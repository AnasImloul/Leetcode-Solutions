// Runtime: 1907 ms (Top 31.92%) | Memory: 277.9 MB (Top 71.08%)
class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions){
        unordered_map<int, TreeNode*> getNode; //to check if node alredy exist
        unordered_map<int, bool> isChild; //to check if node has parent or not
        for(auto &v: descriptions){
            if(getNode.count(v[0])==0){
                TreeNode* par = new TreeNode(v[0]);
                getNode[v[0]] = par;
            }
            if(getNode.count(v[1])==0){
                TreeNode* child = new TreeNode(v[1]);
                getNode[v[1]] = child;
            }
            if(v[2]==1) getNode[v[0]]->left = getNode[v[1]]; //left-child
            else getNode[v[0]]->right = getNode[v[1]]; //right-child
            isChild[v[1]] = true;
        }
        TreeNode* ans = NULL;
        for(auto &v: descriptions){
            if(isChild[v[0]] != true){ //if node has no parent then this is root node
                ans = getNode[v[0]];
                break;
            }
        }
        return ans;
    }
};