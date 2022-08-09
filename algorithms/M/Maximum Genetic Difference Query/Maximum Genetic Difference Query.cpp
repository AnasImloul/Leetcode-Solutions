struct Trie{
    Trie* ptr[2];
    Trie(){
        ptr[0] = NULL;
        ptr[1] = NULL;
    }
};
typedef Trie* bptr;
void clear(bptr &t){
    if(!t)return;
    clear(t->ptr[0]);
    clear(t->ptr[1]);
    delete t;
}
void insert(bptr &T,int n){
    bptr t = T;
    for(int i=31;i>=0;i--){
        int b = ((n>>i)&1);
        if(!t->ptr[b])t->ptr[b] = new Trie();
        t = t->ptr[b];
    }
}
int findMaxXorOfN(bptr &T,int n){
    bptr t = T;
    int ans = 0;
    for(int i=31;i>=0;i--){
        int b = ((n>>i)&1);
        ans = ans<<1;
        if(t->ptr[!b]){
            t = t->ptr[!b];
            ans|=1;
        }else{
            t = t->ptr[b];
            ans|=0;
        }
    }
    return ans;
}
bptr remove(bptr &t,int num,int i){
    if(!t)return NULL;
    if(i==-1)return NULL;
    int b = ((1<<i) & num)>0;
    t->ptr[b] = remove(t->ptr[b],num,i-1);
    if(t->ptr[1-b] || t->ptr[b])return t;
    else return NULL;
}

class Solution {
public:
    unordered_map<int,vector<pair<int,int>>>q;
    vector<int>ans;
    void dfs(vector<int>g[],int u,bptr t){
        insert(t,u);
        for(auto [val,idx] : q[u]){
            ans[idx] = findMaxXorOfN(t,val);
        }
        for(int v : g[u]){
            dfs(g,v,t);
        }
        t = remove(t,u,31);
    }
    vector<int> maxGeneticDifference(vector<int>& parents, vector<vector<int>>& queries) {
        int m = queries.size();
        ans.resize(m);
        for(int i=0;i<m;i++){
            q[queries[i][0]].emplace_back(queries[i][1],i);
        }
        int n = parents.size();
        vector<int>g[n];
        int root = 0;
        for(int i=0;i<n;i++){
            if(parents[i]==-1)root = i;
            else g[parents[i]].emplace_back(i);
        }
        bptr t = new Trie();
        dfs(g,root,t);
		
		clear(t);
        return ans;
    }
};
