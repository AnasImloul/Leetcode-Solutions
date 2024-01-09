// Runtime: 44 ms (Top 98.71%) | Memory: 35.90 MB (Top 48.93%)

class Solution {
public:
    int hardestWorker(int n, vector<vector<int>>& logs) {
        int last = 0, emp = 0, larg = 0, period;
        for(vector<int>& log: logs) {
            period = log[1] - last;
            if(larg == period)
                emp = min(emp, log[0]);
            else if(larg < period) {
                larg = period;
                emp = log[0];
            }
            last = log[1];
        }
        return emp;
    }
};
