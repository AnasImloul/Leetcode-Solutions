class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        map<string,int>stop;
        map<int,string>name;
        int count=0;
        vector<int>par(1005,0),sz(1005,1);
        for(int i=1;i<=1000;i++)
        {
            par[i]=i;
        }
        function<int(int)> findpar = [&](int a) -> int {
            if(a==par[a])return par[a];
            return par[a]=findpar(par[a]);
        };
        function<void(int,int)> dounion =[&](int a,int b) ->void {
            a=findpar(a);
            b=findpar(b);
            if(a!=b)
            {
                if(sz[a]<sz[b]) swap(a,b);
                par[b]=a;
                sz[a]+=sz[b];
            }
        };
        
        for(auto it:accounts){
            
            int n=it.size();
            vector<int>curpar;
            for(int i=1;i<n;i++)
            {
                if(stop[it[i]])
                    curpar.push_back(stop[it[i]]);
            }
            if(curpar.size()==0) // if no par present 
            {
                count++;
                for(int i=1;i<n;i++)
                {
                    stop[it[i]]=count;
                }
                name[count]=it[0];
            }
            else{ // if par present then do union
                int first=curpar[0];
                for(int i=1;i<n;i++) 
                {
                    stop[it[i]]=first;
                }
                
                for(int j=1;j<curpar.size();j++) // union for all child
                {
                    int id=curpar[j];
                    dounion(first,id);
                }
            }
        }
        
        vector<vector<string>>ans;
        
        for(int i=1;i<=1000;i++)
        {
            vector<string> cur;
            if(findpar(i)==i)
            {
                for(auto it:stop)
                {
                    if(findpar(it.second)==i){
                        cur.push_back(it.first);
                    }
                }
            }
            if(cur.size()>0)
            {
                cur.insert(cur.begin(),name[i]);
                ans.push_back(cur);
            }
        }
        return ans;
    }
};
