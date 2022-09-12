// Runtime: 125 ms (Top 23.98%) | Memory: 42.5 MB (Top 47.00%)
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {

        int max_s = 0, left =0, right = 0, n = cardPoints.size();

        //getting sum of k right elements
        for(int i = 0; i<k; i++){
            right += cardPoints[n-i-1];
        }

        // Assumming max as sum of k right elements
        max_s = right;
        for(int i = 0; i<k; i++){
            left += cardPoints[i];
            right -= cardPoints[n-k+i];
            max_s = max(max_s, left+right);
        }
        return max_s;
    }
};