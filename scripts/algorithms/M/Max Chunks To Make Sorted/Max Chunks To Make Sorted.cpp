// Runtime: 6 ms (Top 11.71%) | Memory: 7.3 MB (Top 29.81%)
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        // using chaining technique
        int maxi=INT_MIN;
        int ans =0;

        for(int i=0;i<size(arr);i++)

        {
            maxi = max(maxi,arr[i]);

            if(maxi==i)
            {
                //.. found partition
                ans++;

            }
        }
        return ans;
    }
};
