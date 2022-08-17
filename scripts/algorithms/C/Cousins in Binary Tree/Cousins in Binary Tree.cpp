class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        if(root -> left == NULL || root -> right == NULL) return false;
        //to store node with parent
        queue<pair<TreeNode*, TreeNode*> > q;
        //push root
        q.push({root, NULL});
        //push NULL for level seperation
        q.push({NULL, NULL});
        //boolean val to know if we found x or y yet during traversal of tree
        pair<bool, TreeNode*> foundx = {false, NULL}, foundy = {false, NULL};
        
        //start the level order traversal
        while(!q.empty()){
            TreeNode* top = q.front().first;
            TreeNode* parent = q.front().second;
            q.pop();
            
            //when a level is completely traversed
            if(top == NULL){
                //if we found both x and y and if their parent are not same we found cousins
                if(foundx.first && foundy.first && foundx.second != foundy.second) return true;
                //if one of them found when other not, or when both were found and their parent were equal
                if(foundx.first || foundy.first) return false;
                //push another NULL for further level seperation, if there are any.
                if(!q.empty()) q.push({NULL, NULL});
            }
            else{
                //find x and y
                if(top -> val == x) foundx = {true, parent};
                if(top -> val == y) foundy = {true, parent};
                
                //push current node's childs with parent as current node.
                if(top -> left) q.push({top -> left, top});
                if(top -> right) q.push({top -> right, top});
            }
        }
        return false;
    }
};
