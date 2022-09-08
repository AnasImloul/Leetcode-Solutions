// Runtime: 165 ms (Top 69.47%) | Memory: 62.9 MB (Top 100.00%)
class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int winner = arr[0];
        int wins = 0;
        for (int i=1; i<arr.size();i++){
            if(winner > arr[i])
                wins+=1; //increment wins count
            else{
                wins = 1; //new winner
                winner = arr[i];
            }
            if(wins == k)
                break; //if wins count is k, then return winner
        }
        return winner;
    }
};