// Runtime: 1989 ms (Top 31.75%) | Memory: 238.4 MB (Top 54.28%)
class Solution {
public:

    // function for finding maximum subarray having sum less than k

    int find_max(vector<int>& arr, int k)
    {
        int n = arr.size();

        int maxi = INT_MIN;

        // curr_sum will store cumulative sum

        int curr_sum = 0;

        // set will store the prefix sum of array

        set<int> s;

        // put 0 into set, if curr_sum == k, (curr_sum - k) will be zero

        s.insert(0);

        for(int i = 0; i < n; i++)
        {
            // calculate cumulative sum

            curr_sum += arr[i];

            // find the prefix sum in set having sum == curr_sum - k

            auto it = s.lower_bound(curr_sum - k);

            // if prefix sum is present, update the maxi

            if(it != s.end())
            {
                maxi = max(maxi, curr_sum - *it);
            }

            // insert prefix sum into set

            s.insert(curr_sum);
        }

        return maxi;
    }

    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {

        int n = matrix.size();

        int m = matrix[0].size();

        int maxi = INT_MIN;

        // fix the position two two rows and take cumulative sum of columns between two fixed rows

        for(int start_row = 0; start_row < n; start_row++)
        {
            vector<int> col_array(m, 0);

            for(int end_row = start_row; end_row < n; end_row++)
            {
                // take cumulative sum of columns between two fixed rows

                for(int col = 0; col < m; col++)
                {
                    col_array[col] += matrix[end_row][col];
                }

                // find maximum subarray having sum less than equal to k

                int curr_max = find_max(col_array, k);

                // update the maximum sum

                maxi = max(maxi, curr_max);
            }
        }

        return maxi;
    }
};