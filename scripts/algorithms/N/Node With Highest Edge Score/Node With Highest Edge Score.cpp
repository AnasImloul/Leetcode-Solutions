// Runtime: 125 ms (Top 92.8%) | Memory: 120.00 MB (Top 68.01%)

class Solution {
public:
    int edgeScore(vector<int>& edges) {
        
        int n = edges.size();
        
        // This array will store in-degree for each node.
        vector<long long> inDegree(n,0);
        
        // This variable will store max in-degree number. It means max of all the values in 'inDegree' vector.
        long long maxVal = LONG_MIN;
        
        
        // This will store index of max value in 'inDegree' vector. This index will correspond to our required node with maximum in-degree.
        int minIndx = -1;
        
        
        // Traverse and fill the 'inDegree' vector.
        for(int i=0;i<edges.size();i++)
            inDegree[edges[i]] += i;
        
        
        
        // Traversed our 'inDegree' vector to get max value (max in-degree) in array and keep record of the index where we get that max in-degree value.
        for(int i=0;i<n;i++)
        {
            if(maxVal < inDegree[i])
            {
                maxVal = inDegree[i];
                minIndx = i;
            }
                
        }
        
        // Happily return the index of maximum in-degree. That is our node with maximum in-degree.
        return minIndx;
    }
};
