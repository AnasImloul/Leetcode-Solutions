// Runtime: 250 ms (Top 87.22%) | Memory: 93.50 MB (Top 94.36%)

class Solution {
public:
    
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n=s.length();
        vector<int> dir(n+1,0);
        for(int k=0;k<shifts.size();k++){
            int i = shifts[k][0], j=shifts[k][1], move = (shifts[k][2] == 0 ? -1:1);
            dir[i] += move, dir[j+1] -= move;
        }
        
        for(int i=1;i<n+1;i++) dir[i] += dir[i-1]; // cummulative effect of all shifts on each index 
        
        for(int i=0;i<n;i++){
            int idx = (s[i]-'a' + dir[i])%26;
            if(idx<0) idx += 26;
            char new_ch = (char)(idx + 'a');
            s[i] = new_ch;
        }
        return s;
    }
}; 
