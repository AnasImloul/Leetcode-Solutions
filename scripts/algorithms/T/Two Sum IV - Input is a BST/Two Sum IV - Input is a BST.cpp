// Runtime: 41 ms (Top 92.71%) | Memory: 36.9 MB (Top 41.87%)

class Solution {
public:
    int countNodes(TreeNode *root) {
        if (root == NULL) {
            return 0;
        }
        return countNodes(root->left) + countNodes(root->right) + 1;
    }

    bool findTarget(TreeNode* root, int k) {
        int totalCount = countNodes(root);
        int count = 0;
        stack<TreeNode*> inorder;
        stack<TreeNode*> revInorder;

        TreeNode* currNode = root;
        while(currNode != NULL){
            inorder.push(currNode); //Store all elements in left of tree
            currNode = currNode->left;
        }

        currNode = root;
        while(currNode != NULL){
            revInorder.push(currNode); //Store all elements in right of tree
            currNode = currNode->right;
        }

        while(count < totalCount-1){
            TreeNode* inordertop = inorder.top();
            TreeNode* revinordertop = revInorder.top();
            if(inordertop->val + revinordertop->val == k){ // If inordertop + revinordertop is equal to k, we have found a pair, so return true
                return true;
            }
            else if(inordertop->val + revinordertop->val > k){ //If they are greater than k, we have to found a value
            //which is just smaller than revinordertop, which means we have to find predecessor of revinordertop, as
            //we have to reduce the sum to make it equal to k
                TreeNode* currtop = revinordertop;
                count++;
                revInorder.pop();
                if(currtop->left){
                    currtop = currtop->left;
                    while(currtop){
                        revInorder.push(currtop);
                        currtop = currtop->right;
                    }
                }
            }
            else{
            //If they are smaller than k, we have to found a value which is just larger than inordertop, which means
            //we have to find successor of revinordertop, as we have to increase the sum to make it equal to k
                TreeNode* currtop = inordertop;
                count++;
                inorder.pop();
                if(currtop->right){
                    currtop = currtop->right;
                    while(currtop){
                        inorder.push(currtop);
                        currtop = currtop->left;
                    }
                }
            }
        }
        return false;
    }
};