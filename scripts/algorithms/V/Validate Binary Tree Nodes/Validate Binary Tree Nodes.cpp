class Solution {
public:
    int find_parent(vector<int>&parent,int x){
        if(parent[x]==x)
        return x;
        return parent[x]=find_parent(parent,parent[x]);
    }
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<int> parent(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            int y=find_parent(parent,i);
            if(leftChild[i]!=-1){
                int x=find_parent(parent,leftChild[i]);
                if(x!=leftChild[i]||y==x)
                return false;
                parent[leftChild[i]]=y;
            }
            if(rightChild[i]!=-1){
                int x=find_parent(parent,rightChild[i]);
                if(x!=rightChild[i]||y==x)
                return false;
                parent[rightChild[i]]=y;
            }
        }
        int x=find_parent(parent,0);
        for(int i=1;i<n;i++){
            if(find_parent(parent,i)!=x)
            return false;
        }
        return true;
    }
};