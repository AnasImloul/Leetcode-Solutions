class Solution {
public:
	// ranking each element to make segment tree of small size
    void compress(vector<int>& a){
        vector<int> b=a;
        sort(b.begin(),b.end());
        map<int,int> mp;
        int prev=b[0],rnk=0,n=a.size();
        for(int i=0;i<n;i++){
            if(b[i]!=prev){
                prev=b[i];
                rnk++;
            }
            mp[b[i]]=rnk;
        }
        for(int i=0;i<n;i++)
            a[i]=mp[a[i]];
    }
    
    void update(int st[],int tind,int ind,int val,int tl,int tr){
        if(tl>tr)
            return;
        if(tl==tr){
            st[tind]=val;
            return;
        }
        int m=tl+(tr-tl)/2,left=tind<<1;
        if(ind<=m)
            update(st,left,ind,val,tl,m);
        else
            update(st,left+1,ind,val,m+1,tr);
        st[tind]=max(st[left],st[left+1]);
    }
    
    int query(int st[],int tind,int tl,int tr,int ql,int qr){
        if(tl>tr or ql>tr or qr<tl)
            return 0;
        if(ql<=tl and tr<=qr)
            return st[tind];
        int m=tl+(tr-tl)/2,left=tind<<1;
        return max(query(st,left,tl,m,ql,qr),query(st,left+1,m+1,tr,ql,qr));
    }

    vector<int> longestObstacleCourseAtEachPosition(vector<int>& a) {
        compress(a);
        int i,n=a.size();
        int st[4*n+10];
        memset(st,0,sizeof(st));
        update(st,1,a[0],1,0,n-1);
        vector<int> dp(n);
        dp[0]=1;
        
        for(i=1;i<n;i++){
            int mx=query(st,1,0,n-1,0,a[i]);
            dp[i]=1+mx;
            update(st,1,a[i],dp[i],0,n-1);
        }
        
        return dp;
    }
};