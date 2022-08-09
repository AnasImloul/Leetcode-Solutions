class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        vector<int> table1(arr.size(), 0);
        vector<int> table2(arr.size(), 0);
        table1[0] = 1;
        table2[0] = 1;
        int max_len = 1;
        for (int i=1; i<arr.size(); ++i) {
            table1[i] = 1;
            table2[i] = 1;
            if (arr[i] < arr[i - 1] && (i & 1) == 0) {
                table1[i] = table1[i - 1] + 1;
            } else if (arr[i] > arr[i - 1] && (i & 1) == 1) {
                table1[i] = table1[i - 1] + 1;
            }
            if (arr[i] > arr[i - 1] && (i & 1) == 0) {
                table2[i] = table2[i - 1] + 1;
            } else if (arr[i] < arr[i - 1] && (i & 1) == 1) {
                table2[i] = table2[i - 1] + 1;
            }
            max_len = max(max_len, table1[i]);
            max_len = max(max_len, table2[i]);
        }
        return max_len;
    }
};
