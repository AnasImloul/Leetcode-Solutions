class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        priority_queue<pair<double, pair<int, int>>, vector<pair<double, pair<int, int>>>, greater<pair<double, pair<int, int>>>> myHeap;
        for (int i=0; i<arr.size(); ++i) {
            for (int j=i + 1; j < arr.size(); ++j) {
                myHeap.push({(double)arr[i] / (double)arr[j], {arr[i], arr[j]}});
				// Add all pair of numbers in the heap
            }
        }
        for (int i=1; i<k; ++i) {
            myHeap.pop();
        }
        return {myHeap.top().second.first, myHeap.top().second.second};
    }
};
// Time : O(n^2 + klogn)
// Space : O(m^2)
