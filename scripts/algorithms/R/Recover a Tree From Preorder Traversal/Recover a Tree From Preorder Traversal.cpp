// Runtime: 58 ms (Top 18.82%) | Memory: 19.5 MB (Top 93.82%)

class Solution {
public:

    // Returns the index of '-' if present otherwise returns the string length
    int findIndex(int ind, string &traversal){
        int req = traversal.size();
        for(int i=ind; i<traversal.size(); i++){
            if(traversal[i] == '-'){
                req = i;
                break;
            }
        }
        return req;
    }

    TreeNode* recoverFromPreorder(string traversal) {
        // Pushing the node along with its depth into the stack
        int depth = 0;
        stack<pair<TreeNode*,int>> st;

        // Finding the root node
        int ind = findIndex(0, traversal);
        string str = traversal.substr(0, ind);
        TreeNode *root = new TreeNode(stoi(str));

        // Pushing the root node along with its depth
        st.push({root, 0});

        // Starting from 'ind' as it has the next '-' character
        int i = ind;

        while(i<traversal.size()){
            // Increment the depth
            if(traversal[i] == '-'){
                depth++;
                i++;
                continue;
            }

            // Find the complete number as no.of digits can be > 1
            int ind = findIndex(i, traversal);
            string str = traversal.substr(i, ind-i);
            TreeNode *node = new TreeNode(stoi(str));

            // Finding its appropriate parent, whose depth is one less than current depth
            while(!st.empty() && st.top().second != depth-1){
                st.pop();
            }

            // There is already left child for the parent
            if(st.top().first->left){
                st.top().first->right = node;
            }
            else{
                st.top().first->left = node;
            }

            // Pushing that node and its depth into stack
            st.push({node, depth});
            depth = 0;
            i = ind;
        }

        return root;
    }
};