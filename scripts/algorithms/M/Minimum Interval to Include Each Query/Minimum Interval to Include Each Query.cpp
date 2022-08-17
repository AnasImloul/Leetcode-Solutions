class Solution {
public:
    void update(int *tree, int *lazy, int treeidx, int left, int right, int lo, int hi, int val){
        int lidx = 2*treeidx + 1;
        int ridx = 2*treeidx + 2;
        int mid = (lo + hi)/2;
        if(lazy[treeidx] != INT_MAX){
            if(lazy[treeidx] < tree[treeidx]){
                tree[treeidx] = lazy[treeidx];
                if(lo != hi){
                    lazy[lidx] = min(lazy[treeidx] , lazy[lidx]);
                    lazy[ridx] = min(lazy[treeidx] , lazy[ridx]);
                }
            }
            lazy[treeidx] = INT_MAX;
        }
        
        // completely outside
        if(lo > right || hi < left){
            return;
        }
        // completely inside
        if(lo >= left && hi <= right){
            lazy[treeidx] = min(lazy[treeidx] , val);
            return;
        }
        // partial
        update(tree, lazy, lidx, left, right, lo, mid, val);
        update(tree, lazy, ridx, left, right, mid + 1, hi, val);
    }
    
    int query(int *tree, int *lazy, int treeidx, int lo, int hi, int idx){
        int lidx = 2*treeidx + 1;
        int ridx = 2*treeidx + 2;
        int mid = (lo + hi)/2;
        if(lazy[treeidx] != INT_MAX){
            if(lazy[treeidx] < tree[treeidx]){
                tree[treeidx] = lazy[treeidx];
                if(lo != hi){
                    lazy[lidx] = min(lazy[treeidx] , lazy[lidx]);
                    lazy[ridx] = min(lazy[treeidx] , lazy[ridx]);
                }
            }
            lazy[treeidx] = INT_MAX;
        }
        if(lo == hi){
            return tree[treeidx];
        }
        if(idx <= mid){
            return query(tree, lazy, lidx, lo, mid, idx);
        } else {
            return query(tree, lazy, ridx, mid + 1, hi, idx);
        }
    }
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        int n = 0;
        for(int i=0;i<intervals.size();i++){
            n = max(n,intervals[i][1]);
        }
        for(int i=0;i<queries.size();i++){
            n = max(n,queries[i]);
        }
        n++;
        int *tree = new int[4*n];
        int *lazy = new int[4*n];
        for(int i=0;i<4*n;i++){
            tree[i] = INT_MAX;
            lazy[i] = INT_MAX;
        }
        for(int i=0;i<intervals.size();i++){
            int val = intervals[i][1] - intervals[i][0] + 1;
            update(tree, lazy, 0, intervals[i][0], intervals[i][1], 0, n-1, val);
        }
        vector<int> ans(queries.size());
        for(int i=0;i<queries.size();i++){
            int temp = query(tree, lazy, 0, 0, n-1, queries[i]);
            if(temp == INT_MAX){
                ans[i] = -1;
            } else {
                ans[i] = temp;
            }
        }
        
        delete[] tree;
        delete[] lazy;
        return ans;
    }
};
