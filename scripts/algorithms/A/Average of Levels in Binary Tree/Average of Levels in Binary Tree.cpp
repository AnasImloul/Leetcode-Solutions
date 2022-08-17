/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    // Pre-Requisite for this solution: Level order traversal of a BT Line by Line
    
    vector<double> averageOfLevels(TreeNode* root) {
        // vector to store the result
        vector<double> avgVal;
        avgVal.push_back(root->val);
        
        // Queue for level order traversal Line by Line
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        
        // To store values for levels
        double levelSum = 0;
        double levelCount = 0;
        
        // Standard Level order traversal Line by Line code
        while(q.empty() == false){
            TreeNode* curr = q.front(); q.pop();
            
            if(curr == NULL){
                if(q.empty()==true){
                    break;
                }
                else{   // Here we know that we are at the end of a line
                    
                    // So we push the result into the vector
                    avgVal.push_back(levelSum/levelCount);
                    
                    // Reset the counters and push End of Level into the queue.
                    levelSum = 0;
                    levelCount = 0;
                    q.push(NULL);
                    continue;
                }
            }
            
            // Note that when we are traversing one level
            // we are getting sum and count of the next level
            // Hence, we are moving one level ahead
            if(curr->left){
                q.push(curr->left);
                levelSum += curr->left->val;
                levelCount++;
            }
            if(curr->right){
                q.push(curr->right);
                levelSum += curr->right->val;
                levelCount++;
            }
        }
        return avgVal;
    }
};
