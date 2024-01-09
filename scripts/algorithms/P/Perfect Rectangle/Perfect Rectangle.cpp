// Runtime: 69 ms (Top 97.04%) | Memory: 32.80 MB (Top 50.74%)

class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        unordered_map<long long, int> mark;
        const long long N=1000000;
        for(vector<int>& x:rectangles){
            int x1=x[0];
            int y1=x[1];
            int x2=x[2];
            int y2=x[3];
            mark[x1*N+y1]++;
            mark[x1*N+y2]--;
            mark[x2*N+y1]--;
            mark[x2*N+y2]++;
        }
        int n_mark=0;
        for(auto ptr=mark.begin();ptr!=mark.end();ptr++)
            if(ptr->second!=0){
                if(abs(ptr->second)!=1) return false;
                n_mark++;
            }
        return n_mark==4;
    }
};
