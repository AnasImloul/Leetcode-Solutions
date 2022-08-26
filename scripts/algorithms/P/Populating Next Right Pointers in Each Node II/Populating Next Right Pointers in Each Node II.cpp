// Runtime: 15 ms (Top 85.31%) | Memory: 17.5 MB (Top 45.64%)
// method-1
class Solution {
public:
    Node* connect(Node* root) {
        if(!root)
            return NULL;
        queue<Node*> q;
        q.push(root);
        root->next=NULL;

        while(!q.empty()){

            int size=q.size();
            Node* prev=NULL;

            for(int i=0;i<size;i++){
                Node* temp=q.front();
                q.pop();

                if(prev)
                    prev->next=temp;

                if(i==size-1){
                    temp->next=NULL;
                }

                if(temp->left)
                    q.push(temp->left);

                if(temp->right)
                    q.push(temp->right);

                prev=temp;

            }
        }

        return root;
    }
};