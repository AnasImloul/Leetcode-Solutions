class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int>ans;
        stack<Node*>st;
        st.push(root);
        while(!st.empty()){
            auto frnt=st.top();
            st.pop();
            ans.push_back(frnt->val);
            for(int i=frnt->children.size()-1;i>=0;i--){
                st.push(frnt->children[i]);
            }
        }
        return ans;
    }
};
