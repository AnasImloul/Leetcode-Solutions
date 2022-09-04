// Runtime: 0 ms (Top 100.00%) | Memory: 6.4 MB (Top 13.82%)
class Solution {
public:

    vector<int> numMovesStones(int a, int b, int c) {

        vector<int> arr = {a, b, c};

        sort(arr.begin(), arr.end());

        // find minimum moves

        int mini = 0;

        if(arr[1] - arr[0] == 1 && arr[2] - arr[1] == 1)
        {
            mini = 0;
        }
        else if(arr[1] - arr[0] <= 2 || arr[2] - arr[1] <= 2)
        {
            mini = 1;
        }
        else
        {
            mini = 2;
        }

        // find maximum moves

        int maxi = (arr[1] - arr[0] - 1) + (arr[2] - arr[1] - 1);

        return {mini, maxi};
    }
};