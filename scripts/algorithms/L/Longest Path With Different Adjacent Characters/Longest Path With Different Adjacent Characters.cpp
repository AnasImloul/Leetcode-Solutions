class Solution {
public:
    vector<vector<int>>g;
    int ans=0;
   int dfs(int node,int par, string &s){
       // vector to store max length & second max length that we get from children of node at v[1] & v[0] respectively
        vector<int>v(2,0);
       for(auto child:g[node]){
           if(child != par){
               int x = dfs(child,node,s);
			   // if char at node != char at child then node can be included in our ans
               if(s[node] != s[child]){
                   if(v[1]<x){
                       v[0]=v[1];
                       v[1]=x;
                       
                   }else{
                       v[0]=max(v[0],x);
                   }
               }
               
           }
       }
       // update our ans every time we return to node
       ans = max(ans, v[0]+v[1]+1);
	   //return the max length up till here including node
       return max(v[0],v[1])+1;
        
    }
    int longestPath(vector<int>& parent, string s) {
        int n = s.size();
        
        ans =0;
        g.assign(n+1,{});
        for(int i=1;i<parent.size();i++){
           g[parent[i]].push_back(i);
           g[i].push_back(parent[i]);
        }
		// run dfs and calculate max 
        ans = max(ans, dfs(0,-1,s));
        return ans;
        
    }
};
