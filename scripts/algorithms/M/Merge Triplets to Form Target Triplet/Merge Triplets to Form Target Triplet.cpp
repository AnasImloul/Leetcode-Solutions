class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        int first = 0, second = 0, third = 0;
        for (auto tr : triplets) {
            if (tr[0] == target[0] && tr[1] <= target[1] && tr[2] <= target[2]) first = 1;
            if (tr[0] <= target[0] && tr[1] == target[1] && tr[2] <= target[2]) second = 1;
            if (tr[0] <= target[0] && tr[1] <= target[1] && tr[2] == target[2]) third = 1;
        }
        return first && second && third;
    }
};
