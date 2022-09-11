// Runtime: 495 ms (Top 92.04%) | Memory: 167 MB (Top 50.64%)
class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        vector<int> arr;
        for (int i=0; i<2*k+1; ++i) {
            arr.push_back(0);
        }

        for (int i=0; i<fruits.size(); ++i) {
            if ((fruits[i][0] < startPos-k) || (fruits[i][0] > startPos+k)) continue;
            arr[fruits[i][0]-(startPos-k)] += fruits[i][1];
        }

        int left = 0, right = 0;
        for (int i = 0; i <= k; ++i) {
            left += arr[i];
            right += arr[k+i];
        }
        int maxSeen = max(left, right);
        int L = arr.size();
        int turn = 1;
        for (int i = 2; i < k+1; i += 2) {
            left = left+arr[k+turn]-arr[i-1]-arr[i-2];
            right = right+arr[k-turn]-arr[L-1-(i-1)]-arr[L-1-(i-2)];
            if (left > maxSeen) maxSeen = left;
            if (right > maxSeen) maxSeen = right;
            turn++;
        }
        return maxSeen;

    }
};
