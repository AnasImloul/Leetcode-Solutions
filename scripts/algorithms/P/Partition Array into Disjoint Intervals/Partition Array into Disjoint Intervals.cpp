// Runtime: 241 ms (Top 56.54%) | Memory: 102.3 MB (Top 15.65%)
class Solution {
public:
    vector<int> tree;
    void build(vector<int> &nums) {
        int n=nums.size();
        for(int i=0 ; i<nums.size(); i++) tree[i+n]=nums[i];
        for(int i=n-1 ; i>0 ; i--) tree[i] = min(tree[i<<1],tree[i<<1|1]);
    }

    int query(int l, int r, int n) {
        l+=n,r+=n;
        int ans = INT_MAX;
        while(l<r) {
            if(l&1) ans = min(ans,tree[l++]);
            if(r&1) ans = min(ans,tree[--r]);
            l>>=1; r>>=1;
        }
        return ans;
    }

    int partitionDisjoint(vector<int>& nums) {
        int n=nums.size();
        int mx=-1 ;
        tree.resize(2*n,INT_MAX); build(nums);
        for(int left=0; left<n ; left++) {
            mx = max(mx,nums[left]);
            if(query(left+1,n,n) >= mx) return left+1;
        }
        return n;
    }
};