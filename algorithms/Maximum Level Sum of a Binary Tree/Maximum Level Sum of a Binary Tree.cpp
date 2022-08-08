class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        int maxSum = INT_MIN;
        int minLevel = 1;
        
        int level = 1;
        queue<TreeNode*> qq;
        qq.push(root);
		// level order traversal
        while(!qq.empty()){
            int size = qq.size();
            int currSum  = 0;
            while(size--){
                auto node = qq.front();
                qq.pop();
                currSum += node->val;
                if(node->left)qq.push(node->left);
                if(node->right)qq.push(node->right);
            }
            if(currSum>maxSum){
                maxSum = currSum;
                minLevel = level;
            }
            level++;
        }
        
        return minLevel;
    }
};