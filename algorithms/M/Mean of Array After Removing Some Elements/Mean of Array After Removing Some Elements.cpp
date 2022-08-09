class Solution {
public:
    double trimMean(vector<int>& arr) {
        auto first = arr.begin() + arr.size() / 20;
        auto second = arr.end() - arr.size() / 20;
        nth_element(arr.begin(), first, arr.end());
        nth_element(first, second, arr.end());
        return accumulate(first, second, 0.0) / distance(first, second);
    }
};
