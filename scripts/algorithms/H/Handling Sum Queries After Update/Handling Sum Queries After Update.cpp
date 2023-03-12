typedef long long ll;
class Solution {
public:
    static const ll maxn=1e5+6;
    ll seg[maxn<<2];
    bool lzy[maxn<<2];
    void seg_init(int cur,int l,int r,vector<int> &nums)
    {
        if(l+1==r)
        {
            seg[cur]=nums[l];
            lzy[cur]=0;
            return;
        }
        int mid=(l+r)>>1;
        seg_init(cur<<1,l,mid,nums);
        seg_init(cur<<1|1,mid,r,nums);
        seg[cur]=seg[cur<<1]+seg[cur<<1|1];
        lzy[cur]=0;
        return;
    }
    void pushdown(int cur,int l,int r)
    {
        if(lzy[cur])
        {
            lzy[cur]^=1;
            int mid=(l+r)>>1;
            lzy[cur<<1]^=1;
            lzy[cur<<1|1]^=1;
            seg[cur<<1]=mid-l-seg[cur<<1];
            seg[cur<<1|1]=r-mid-seg[cur<<1|1];
        }
        return;
    }
    void update(int cur,int l,int r,int tl,int tr)
    {
        if(tl>=r||tr<=l)return;
        if(tl<=l&&r<=tr)
        {
            seg[cur]=r-l-seg[cur];
            lzy[cur]^=1;
            return;
        }
        pushdown(cur,l,r);
        int mid=(l+r)>>1;
        update(cur<<1,l,mid,tl,tr);
        update(cur<<1|1,mid,r,tl,tr);
        seg[cur]=seg[cur<<1]+seg[cur<<1|1];
        return;
    }
    vector<long long> handleQuery(vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& queries) 
    {
        int n=nums1.size();
        seg_init(1,0,n,nums1);
        ll val=0;
        for(auto &x:nums2)val+=x;
        vector<ll>res;
        for(auto &x:queries)
        {
            if(x[0]==1)
            {
                update(1,0,n,x[1],x[2]+1);
            }else if(x[0]==2)
            {
                val+=seg[1]*x[1];
            }else res.push_back(val);
        }
        return res;
    }
};