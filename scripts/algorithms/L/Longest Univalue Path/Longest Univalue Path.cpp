// Runtime: 168 ms (Top 78.52%) | Memory: 72 MB (Top 11.12%)
class Solution {
public:
    int maxlen=0;
    pair<int,int> util(TreeNode* root,int val ){
        if(!root)
            return {0,-1001};

        // in pair we will the first part will return the no nodes ,
        //and in the second part we will return the value associated with it

        pair<int,int> l=util(root->left,root->val);
        pair<int,int> r=util(root->right,root->val);

        /* now we will check whether the value coming from
        the left subtree or(&) right subtree is equal to the
        value of the current node

         if equal to both the left && right subtree, then the length returned
        will be max of the left & right subtree , becuase ATQ, we have to
        return the longest path where each node in the path has the same
        value , therefore from the current node we can travel to either the
        left or right subtree , but the maxlength can be l.first+r.first+1 ,
        because we can travel from the leftmost node through the current
        node to the rightmost node , which will be a valid path , therefore
        we will compare this with the maxlength

        */
        if(l.second==root->val && r.second==root->val){
          maxlen=max(maxlen,l.first+r.first+1);
          return {max(l.first,r.first)+1,root->val};

        }

        // now similary checking for all the other nodes:

        else if(l.second==root->val){
            maxlen=max(maxlen,l.first+1);
            return {l.first+1,root->val};
        }
        else if(r.second==root->val){
            maxlen=max(maxlen,r.first+1);
            return {r.first+1,root->val};
        }
        else{
            return {1,root->val};
        }

    }
    int longestUnivaluePath(TreeNode* root) {
        if(!root)
            return 0;
        util(root,root->val);
        return max(maxlen-1,0);

    }
};