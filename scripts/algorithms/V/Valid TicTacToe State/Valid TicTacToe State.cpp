// Runtime: 0 ms (Top 100.0%) | Memory: 9.70 MB (Top 16.84%)

class Solution {
public:
// 1. Number of 'O' > Number of X -> return false
//     2. Number of X - Number of Os > 1 -> Return false
//     3. If O wins -
//         a) Number of Os  == Number of Xs
//         b) And X should not be winning
//     4. If X wins -
//         a) O should not win
//         b) no. of x should be 1 more than no. of O
    bool validTicTacToe(vector<string>& board) {
        int o=0,x=0;
        for(int i=0;i<3;i++)
        {
            for(auto j:board[i])
            {
                if(j == 'X')
                x++;
                else if(j == 'O')
                o++;
            }
        }
        if(o>x || (x-o > 1))return false;
        bool winx = false,wino = false;
        if(board[0] == "XXX" || board[1] == "XXX" || board[2] == "XXX")
        winx=true;
        if(board[0] == "OOO" || board[1] == "OOO" || board[2] == "OOO")
        wino=true;

        if(!winx || !wino)
        {
            string s1,s2,s3,s4,s5;
            s1.push_back(board[0][0]);
            s1.push_back(board[1][0]);
            s1.push_back(board[2][0]);
            s2.push_back(board[0][1]);
            s2.push_back(board[1][1]);
            s2.push_back(board[2][1]);
            s3.push_back(board[0][2]);
            s3.push_back(board[1][2]);
            s3.push_back(board[2][2]);
            s4.push_back(board[0][0]);
            s4.push_back(board[1][1]);
            s4.push_back(board[2][2]);
            s5.push_back(board[0][2]);
            s5.push_back(board[1][1]);
            s5.push_back(board[2][0]);
            if(s1 == "XXX" || s2 == "XXX" || s3== "XXX" || s4 == "XXX" || s5=="XXX")
            winx=true;
            
            if(s1 == "OOO" || s2 == "OOO" || s3== "OOO" || s4 == "OOO" || s5=="OOO")
            wino=true;

        }
        if(wino && winx)
        return false;
        if(wino)
        {
            if(o==x)
            return true;
            return false;
        }
        if(winx)
        {
            if(o+1 == x)
            return true;
            return false;
        }
        return true;
    }
};
