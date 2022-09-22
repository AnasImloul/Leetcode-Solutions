// Runtime: 390 ms (Top 96.30%) | Memory: 112.1 MB (Top 64.81%)
class Solution {
public:
    vector<bitset<101>> tree;
    vector<int> minDifference(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();

        tree = vector<bitset<101>>(4*(n+1) + 1);
        buildtree(1, 0, n-1, nums);

        vector<int> ans;
        for(auto &e: queries){
            auto finalOnesRepresentations = query(1, 0, n-1, e[0], e[1]);

            // find the first 1
            int i = 0;
            while(i < 101 and finalOnesRepresentations[i] != 1){
                i++;
            }

            int gap = INT_MAX;
            int prev = i;
            i++;
            // find the minimum gap
            for(; i < 101; i++){
                if(finalOnesRepresentations[i] == 1){
                    gap = min(gap, i - prev);
                    prev = i;
                }
            }
            ans.push_back(gap == INT_MAX ? -1 : gap);
        }
        return ans;
    }

    bitset<101> query(int index, int s, int e, int qs, int qe){

        if(s > e) return bitset<101>();
        if(e < qs || s > qe) return bitset<101>();
        if(qs <= s and e <= qe) return tree[index];

        int mid = (s+e)/2;
        auto left = query(index*2, s, mid, qs, qe);
        auto right = query(index*2+1, mid+1, e, qs , qe);
        return left | right;
    }

    void buildtree(int index, int s, int e, vector<int>& a){

        if(s > e)return;

        if(s==e){
            bitset<101> b;
            b[a[s]] = 1;
            tree[index] = b;
            return;
        }

        int mid = (s+e)/2;
        buildtree(index*2, s, mid, a);
        buildtree(index*2+1, mid+1, e, a);
        tree[index] = tree[index*2] | tree[index*2+1];
    }
};