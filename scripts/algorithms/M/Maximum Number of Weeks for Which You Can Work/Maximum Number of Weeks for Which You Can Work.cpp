class Solution {
public:
    long long numberOfWeeks(vector<int>& milestones) {
        long long unsigned int maxel = *max_element(milestones.begin(), milestones.end());
        long long unsigned int sum = 0;
        for (auto& m : milestones) sum += m;
        if (sum - maxel >= maxel) return sum;
        return (sum - maxel) * 2 + 1;
    }
};
