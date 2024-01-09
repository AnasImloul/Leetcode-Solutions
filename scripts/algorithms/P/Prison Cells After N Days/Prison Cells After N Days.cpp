// Runtime: 0 ms (Top 100.0%) | Memory: 12.40 MB (Top 75.91%)

class Solution {

public:
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        if(N == 0) return cells;
        prison(cells, 1);              //Prison cells for one day, The pattern repeats from day 1 - 14
        prison(cells, (N - 1) % 14);         //Simply day 14 = day 1, Day 0 never repeats because of corners  
        return cells;                               
    }
    void prison(vector<int>& cells, const int& N){
        for(int i = 0; i < N; i++){
            vector<int> v(8,0);
        for(int i = 1; i < 7; i++)
            if(cells[i - 1] == cells[i + 1])
                v[i] = 1;
            else v[i] = 0;
        cells = v;
        }
    }
};
