// Runtime: 166 ms (Top 87.34%) | Memory: 113.60 MB (Top 78.69%)

class Solution {
   public:
    vector<int> nodesBetweenCriticalPoints(ListNode *head) {
        ListNode *curr = head, *prev = NULL;
        int minDistance = INT_MAX, maxDistance = -1, size = 0, preCP = 0,
            first = 0;
        while (curr) {
            if (curr->next && prev) {
                if ((curr->val < prev->val && curr->val < curr->next->val) ||
                    (curr->val > prev->val && curr->val > curr->next->val)) {
                    if (first == 0) {
                        first = size;
                    } else {
                        minDistance = min(minDistance, size - preCP);
                        maxDistance = max(maxDistance, size - first);
                    }
                    preCP = size;
                }
            }
            size++;
            prev = curr;
            curr = curr->next;
        }
        return {minDistance == INT_MAX ? -1 : minDistance, maxDistance};
    }
};
