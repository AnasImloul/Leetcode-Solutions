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
    TreeNode* canMerge(vector<TreeNode*>& trees) {
        //store the leaves of every node

        unordered_map<int,TreeNode*> mp;
        
        //store the current min and current max nodes in the current tree
        unordered_map<TreeNode*,pair<int,int>> mini;
        for(int i=0;i<trees.size();i++)
        {
            pair<int,int> ans={trees[i]->val,trees[i]->val};
            if(trees[i]->left)
            {
                
                mp[trees[i]->left->val]={trees[i]};
                ans.first=trees[i]->left->val;
            }
            if(trees[i]->right)
            {
                mp[trees[i]->right->val]=trees[i];
                ans.second=trees[i]->right->val;
            }
            mini[trees[i]]=ans;
        }
        
        //store the number of merging operations we will be doing
        int count=0;
        int rootCount=0;
        TreeNode* root=NULL;
        //now for every node get the root
        for(int i=0;i<trees.size();i++)
        {
            
            //if the current tree can be merged into some other tree
            if(mp.find(trees[i]->val)!=mp.end())
            {
                count++;
                //merge them
                TreeNode* parent=mp[trees[i]->val];
                if(trees[i]->val < parent->val)
                {
                    //left child 
                    
                    //if the maximum of the current sub tree is greater than the parent value 
                    //then return NULL
                    if(parent->val <= mini[trees[i]].second)
                        return NULL;
                    //change the minimum value of the parent tree to the current min value of the tree
                    mini[parent].first=mini[trees[i]].first;
                    //merge the trees
                    parent->left=trees[i];
                }
                else  if(trees[i]->val > parent->val)
                {
                    //right child
                    
                    //if the minimum of the current tree is lesser than the parent value
                    //we cannot merge 
                    //so return NULL
                    if(parent->val >= mini[trees[i]].first)
                        return NULL;
                    
                    //change the parent tree maximum to the current tree maximum
                    mini[parent].second=mini[trees[i]].second;
                    //merge the trees
                    parent->right=trees[i];
                }
                //erase the current tree value
                mp.erase(trees[i]->val);
            }
            else{
                //it has no other tree to merge 
                //it is the root node we should return 
                if(rootCount==1)
                    return NULL;
                else 
                {
                    rootCount++;
                    root=trees[i];
                }
            }
        }
        //if we are not able to merge all trees return NULL
        if(count!=trees.size()-1)
            return NULL;
        return root;
        
    }
};
