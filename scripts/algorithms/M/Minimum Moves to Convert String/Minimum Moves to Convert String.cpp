class Solution {
public:
    int minimumMoves(string s) {
        int moves = 0;
        s += "OO";
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == 'X') {
                s[i] = s[i + 1] = s[i + 2] = 'O';
                moves++;
            }
        }
        return moves;
    }
};
