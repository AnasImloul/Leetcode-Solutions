// Runtime: 45 ms (Top 87.77%) | Memory: 32.20 MB (Top 98.08%)

class Solution {
public:int k,ans=0;
    int countPairs(TreeNode* root, int distance) {
        k=distance;
        cp(root,0);
        return ans;
    }
	
    vector<int> cp(TreeNode* root,int level)
    {   vector<int>v1;
        if(root==NULL){return v1;}
        if(root->left==NULL&&root->right==NULL){v1.push_back(level);return v1;}
     
        v1 =cp(root->left,level+1);
        vector<int>v2 =cp(root->right,level+1);
        int a=v1.size();
        int b=v2.size();
        
        for(int i=0;i<a;i++)
        {for(int j=0;j<b;j++)
        { if(abs(v1[i]+v2[j]-(2*level))<=k){ans++;} }}
        
        
        int l=v2.size();
        while(l--){v1.push_back(v2.back());
		v2.pop_back();}
        return v1;
    }
    
};
