// Runtime: 2 ms (Top 60.19%) | Memory: 6.1 MB (Top 62.14%)
class Solution {
public:
    string alphabetBoardPath(string target) {
        string ans = "";
        int prevRow = 0;
        int prevCol = 0;
        int curRow = 0;
        int curCol = 0;
        for(int i = 0; i < target.length(); i++){
            prevCol = curCol;
            prevRow = curRow;
            curRow = (target[i] - 'a')/5;
            curCol = (target[i] - 'a')%5;
            if(curRow == 5 and abs(curCol - prevCol) > 0){
                curRow--;
            }
            if(curRow - prevRow > 0){
                ans += string((curRow - prevRow), 'D');
            }else{
                ans += string((prevRow - curRow), 'U');
            }
            if(curCol - prevCol > 0){
                ans += string((curCol - prevCol), 'R');
            }else{
                ans += string((prevCol - curCol), 'L');
            }
            if(((target[i] - 'a')/5) == 5 and abs(curCol - prevCol) > 0){
                ans += 'D';
                curRow++;
            }
            ans += '!';
        }
        return ans;

    }
};