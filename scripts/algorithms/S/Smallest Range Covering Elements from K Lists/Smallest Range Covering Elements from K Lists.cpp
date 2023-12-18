// Runtime: 53 ms (Top 49.31%) | Memory: 15.90 MB (Top 91.78%)

#include <vector>
#include <queue>
#include <limits>

using namespace std;

struct Item {
    int val;
    int r;
    int c;
    
    Item(int val, int r, int c): val(val), r(r), c(c) {
    }
};

struct Comp {
    bool operator() (const Item& it1, const Item& it2) {
        return it2.val < it1.val;
    }
};

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<Item, vector<Item>, Comp> pq;
        
        int high = numeric_limits<int>::min();
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            pq.push(Item(nums[i][0], i, 0));
            high = max(high , nums[i][0]);
        }
        int low = pq.top().val;
        
        vector<int> res{low, high};
        
        while (pq.size() == (size_t)n) {
            auto it = pq.top();
            pq.pop();
            
            if ((size_t)it.c + 1 < nums[it.r].size()) {
                pq.push(Item(nums[it.r][it.c + 1], it.r, it.c + 1));
                high = max(high, nums[it.r][it.c + 1]);
                low = pq.top().val;
                if (high - low < res[1] - res[0]) {
                    res[0] = low;
                    res[1] = high;
                }
            }
        }
        
        return res;
    }
};

