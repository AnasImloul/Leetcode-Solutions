// Runtime: 340 ms (Top 55.43%) | Memory: 310.90 MB (Top 5.43%)

class Solution {
public:
    typedef long long ll;
    vector<ll> a, tree, lazy;

    void build(int node,int start,int end)
    {
        if(start == end)
        {
            tree[node] = a[start];
            return;
        }

        int mid = (start + end) / 2;
        build(2*node,start,mid);
        build(2*node+1,mid+1,end);

        tree[node] = tree[2*node] + tree[2*node+1];
    }

    ll query(int node,int start,int end,int l,int r)
    {
        if(lazy[node]%2==1)
        {
            int k = lazy[node];
          
            lazy[node] = 0;               
            tree[node] =  (end - start + 1) - tree[node]; 

            if(start!=end) 
            {
                lazy[2*node] += k ;
                lazy[2*node+1] += k;
            }
        }

        if(start>r || end<l)
        return 0;

        if(start>=l && end<=r)
        return tree[node];

        ll mid = (start + end) / 2;

        ll left = query(2*node,start,mid,l,r);
        ll right = query(2*node+1,mid+1,end,l,r);
        return left + right;
    }

    void update(int node,int start,int end,int l,int r,int val)
    {
        if(lazy[node]%2==1)
        {
            int k = lazy[node];
            lazy[node] = 0;
            tree[node]  =(end - start + 1)  - tree[node] ;

            if(start!=end)
            {
                lazy[2*node] += k ;
                lazy[2*node+1] += k;
            }
        }
        

        if(start>r || end<l)
        return;

        if(start>=l && end<=r)
        {
            int k = (end - start + 1)  - tree[node];
            tree[node] = k;

            if(start!=end)  
            {
                lazy[2*node] += val;
                lazy[2*node+1] += val;
            }

            return;
        }

        int mid = (start + end) / 2;

        update(2*node,start,mid,l,r,val);
        update(2*node+1,mid+1,end,l,r,val);

        tree[node] = tree[2*node+1] + tree[2*node];
    }

    vector<long long> handleQuery(vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& queries) {
        ll sum2 = 0;
        int nn = 100005;
        a.resize(nn,0);
        tree.resize(4*nn,0);
        lazy.resize(4*nn,0);
        
        int n = nums1.size();
        for(auto &i:nums2){
            sum2+=i;
        }
        
        for(int i = 0;i<n;i++){
            a[i+1] = nums1[i];
        }
        vector<ll>ans;
        build(1,1,n);
        for(auto &i:queries){
            if(i[0]==1){
                update(1,1,n,i[1]+1,i[2]+1,1);
            }
            else if(i[0]==2){
                ll p = i[1];
                sum2+= p*query(1,1,n,1,n);
            }
            else if(i[0]==3){
                ans.push_back(sum2);
            }
        }
        
        return ans;
        
    }
};
