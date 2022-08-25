// Runtime: 1233 ms (Top 81.70%) | Memory: 153.5 MB (Top 96.08%)
class Solution {
    const long p1 = 1299827; /// 1299827; 299807; 199807;
    const long p2 = 1e9 + 7;

    struct Hit { int count, row, col; Hit() {count=row=col=0;}};

    int minsize(vector<vector<int>>& paths) {
        int msize=INT_MAX;
        for (auto v : paths) { msize = min(msize,int(v.size())); }
        return msize;
    }

    bool collision(vector<vector<int>>& paths,int len,Hit& hit,int row,int col) {
        if (hit.count == 0) return false;
        if (hit.row == row) return true; // what should we do for internal collisions?
        auto& v1 = paths[hit.row];
        auto& v2 = paths[row];
        for (int i=0, c1=hit.col, c2=col; i<len; i++, c1++, c2++)
            if (v1[c1] != v2[c2])
                return true;
        return false;
    }

    bool rabinkarp(vector<vector<int>>& paths,int len) {
        unordered_map<long,Hit> hits;
        long power=1;

        for (int i=0; i<len-1; i++)
            power = (power * p1) % p2;

        for (int i=0, j=0, found=0; i<paths.size(); i++, j=0, found=0) {
            long hash=0;

           while (j < paths[i].size()) {
                if (j >= len) hash = (hash + p2 - (paths[i][j-len] * power) % p2) % p2; // remove item
                hash = (hash * p1 + paths[i][j++]) % p2; // add item
                if (j >= len && (i == 0 || hits.count(hash))) {
                    auto& hit = hits[hash];
                    if (! collision(paths,len,hit,i,j-len)) {
                        hit.count += 1, hit.row = i, hit.col = j-len;
                        if (hit.count == paths.size()) return true;
                        found = 1;
                    }
                }
            }
            if (found == 0) break; // no match/s so give up...
        }
        return false;
    }
public:
    int longestCommonSubpath(int n, vector<vector<int>>& paths) {
        int lo=1, hi=minsize(paths), found=0;

        while (lo<=hi) {
            int len = lo + (hi-lo)/2;

            if (rabinkarp(paths,len)) {
                found = len;
                lo = len+1;
            }
            else
                hi = len-1;
        }
        return found;
    }
};