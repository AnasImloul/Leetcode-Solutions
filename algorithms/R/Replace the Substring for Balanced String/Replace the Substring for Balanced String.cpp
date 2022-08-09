class Solution {
public:
    int balancedString(string s) {
      int n=s.length();
      unordered_map<char,int>umap;
      for(auto x:s)
      {
         umap[x]++;   
      }
        umap['Q']=umap['Q']-n/4>0?umap['Q']-n/4:0;
        umap['W']=umap['W']-n/4>0?umap['W']-n/4:0;
        umap['E']=umap['E']-n/4>0?umap['E']-n/4:0;
        umap['R']=umap['R']-n/4>0?umap['R']-n/4:0;
        int count=umap['Q']+umap['W']+umap['E']+umap['R'];
        if(count==0)
            return 0;
        int i=0,ans=INT_MAX;
        unordered_map<char,int>newMap;
        for(int j=0;j<n;j++)
        {
            newMap[s[j]]++;
            if(newMap[s[j]]<=umap[s[j]])
            {
                count--;
                while(count==0)
                {
                    newMap[s[i]]--;
                    if(newMap[s[i]]<umap[s[i]])
                    {
                        count++;
                        ans=min(ans,j-i+1);
                    }
                    i++;
                }
            }
        }
        return ans;
    }
};