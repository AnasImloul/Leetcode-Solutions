class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int col = strs[0].size();
        int row = strs.size();
        int count = 0;
        for(int c = 0 ; c < col ; c++){
            for(int r = 1 ; r < row ; r++){
                if(strs[r][c] - strs[r - 1][c] < 0){
                    count++;
                    break;
                }
            }
        }
        return count;
    }
};
