class Solution {
public:
    
    // we know that (x ^ x)  = 0,
    
    // arr = [1,4,8,3,7,8],  let we have to calculate xor of subarray[2,4]
    
    // (1 ^ 4 ^ 8 ^ 3 ^ 7) ^ (1 ^ 4) = (8 ^ 3 ^ 7), this is nothing but prefix[right] ^ prefix[left - 1]
    
    // (1 ^ 1 = 0) and (4 ^ 4) = 0
    
    
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        
        int n = queries.size();
        
        // find the prefix xor of arr
        
        for(int i = 1; i < arr.size(); i++)
        {
            arr[i] = (arr[i - 1] ^ arr[i]);
        }
        
        // calculate each query
        
        vector<int> res(n);
        
        for(int i = 0; i < n; i++)
        {
            int left = queries[i][0];
            
            int right = queries[i][1];
            
            // find the xorr of the subarray
            
            int xorr = arr[right];
            
            if(left > 0)
            {
                xorr ^= arr[left - 1];
            }
            
            res[i] = xorr;
        }
       
        return res;
    }
};