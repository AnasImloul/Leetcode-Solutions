class Solution {
    vector<int> st;
public:
    void update(int tind,int tl,int tr,int ind,int val){
        if(tl>tr)
            return;
        if(tl==tr){
            st[tind]+=val;
            return;
        }
        int tm=tl+((tr-tl)>>1),left=tind<<1;
        if(ind<=tm)
            update(left,tl,tm,ind,val);
        else
            update(left|1,tm+1,tr,ind,val);
        st[tind]=st[left]+st[left|1];
    }
    
    int query(int tind,int tl,int tr,int ql,int qr){
        if(tl>tr or qr<tl or ql>tr)
            return 0;
        if(ql<=tl and tr<=qr)
            return st[tind];
        int tm=tl+((tr-tl)>>1),left=tind<<1;
        return query(left,tl,tm,ql,qr)+query(left|1,tm+1,tr,ql,qr);
    }
    
    vector<int> countPairs(int n,vector<vector<int>>& a,vector<int>& q) {
        vector<int> f(n+2,0);
        vector<unordered_map<int,int>> mp(n+2); // using a normal map gives TLE
        
        for(auto v:a){
            int mx=max(v[0],v[1]),mn=min(v[1],v[0]);
            f[mx]++;
            f[mn]++;
            mp[mx][mn]++;
        }
        
        vector<int> ans(q.size(),0);
        int m=a.size();
        st.resize(4*m+40,0);
        
        for(int i=n;i;i--){
			// reducing the common edges between current node and its adjacent
            for(auto e:mp[i]){
                update(1,0,m,f[e.first],-1);
                update(1,0,m,f[e.first]-e.second,1);
            }
            
            int curr=f[i];
            for(int j=0;j<q.size();j++)
                ans[j]+=query(1,0,m,max(0,q[j]-curr+1),m);
            
			// reversing the changes made initially
            for(auto e:mp[i]){
                update(1,0,m,f[e.first],1);
                update(1,0,m,f[e.first]-e.second,-1);
            }
            
            update(1,0,m,f[i],1);
        }
        return ans;
    }
};