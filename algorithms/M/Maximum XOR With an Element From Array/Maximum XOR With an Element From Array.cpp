struct Trie {
    Trie *z;
    Trie *o;
    Trie() {
        z = NULL;
        o = NULL;
    }
};

class Solution {
public:
    
    Trie* insert(Trie* node, int k, int num) {
        if(node == NULL) {
            node = new Trie();
        }
        if(k < 0) return node;
        if(((num >> k) & 1) == 1) {
            node -> o = insert(node->o, k - 1, num);
        }
        else {
            node -> z = insert(node->z, k - 1, num);
        }
        return node;
    }
    
    int getmax(Trie* node, int k, int num) {
        if(k < 0) return 0;
        int res = 0;
        bool bit = ((num >> k) & 1);
        if(bit == 1) {
            if(node->z) {
                res = pow(2, k) + getmax(node->z, k - 1, num);
            }
            else {
                res = getmax(node->o, k - 1, num);
            }
        }
        else {
            if(node->o) {
                res = pow(2, k) + getmax(node->o, k - 1, num);
            }
            else {
                res = getmax(node->z, k - 1, num);
            }
        }
        return res;
    }
    
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int m = queries.size();
        vector<int> ans(m, -1);
        vector<pair<pair<int, int>, int> > q;
        for(int i = 0; i < m; i++) {
            q.push_back({{queries[i][0], queries[i][1]}, i});
        }
        sort(q.begin(), q.end(), [](pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
            return a.first.second < b.first.second;
        });
        
        sort(nums.begin(), nums.end());
        
        int j = 0;
        
        Trie *root = new Trie();
        
        for(int i = 0; i < m; i++) {
            pair<pair<int, int>, int> p = q[i];
            int num = p.first.first;
            int lim = p.first.second;
            int idx = p.second;
            
            while(j < n && nums[j] <= lim) {
                root = insert(root, 31, nums[j]);
                j++;
            }
            
            if(j > 0) {
                ans[idx] = getmax(root, 31, num);
            }
        }
        
        return ans;
    }
};
