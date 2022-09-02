// Runtime: 888 ms (Top 54.12%) | Memory: 105 MB (Top 66.11%)
class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> pq;
        int sum = 0, curr;

        for (auto pile : piles) {
            pq.push(pile);
            sum += pile;
        }

        while (k--) {
            curr = pq.top();
            pq.pop();
            sum -= curr/2;
            pq.push(curr - curr/2);
        }

        return sum;
    }
};