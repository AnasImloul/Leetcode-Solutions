class Solution {
public:
    
     
    // Steps : 
    // 1 - For each node, you need to find the sizes of the subtrees rooted in each of its children.
    
    // 2 - How to determine the number of nodes in the rest of the tree? 
	// Can you subtract the size of the subtree rooted at the node from the total number of nodes of the tree?
    
    // 3 - Use these values to compute the score of the node. Track the maximum score, and how many nodes achieve such score. 
    
	// calculating size of each subtree by standing at every node  '0' to 'n-1'
    int dfs(int src,vector<vector<int>>& g,vector<int>& size)
    {
         int ans = 1;// for curent node
         for(auto child : g[src]){
             ans += dfs(child,g,size);
         }
         return size[src] = ans; 
     }
    
    // This code can also be work for generalized tree not only for Binary tree
    int countHighestScoreNodes(vector<int>& parents) 
    {    
        int n=parents.size();
        vector<int>size(n,0);  // size[i] indicates size of subtree(rooted at i node) + 1
        vector<vector<int>>g(n);  // storing left and right child of a node
        for(int i=1;i<n;i++){
            g[parents[i]].push_back(i); // 'There is no parent for 0th node'
        }
        
        dfs(0,g,size); //calculating size of each subtree(rooted at ith node)

        long long int maxCount = 0; // To avoid overflow  because perform product below you should take "long long int"
        long long int maxScore = 0;
        for(int i=0;i<n;i++) // Nodes from '0' to 'n-1'
        {
            // calculate score of each node after removal their 'edge' or 'node itself'.
            long long int product = 1;
            product = max(product, (long long int)(n - size[i])); // calculating leftover nodes excluding child nodes 
            for(auto x : g[i])
            {
                product = product*size[x];
            }
            
            if(product > maxScore){
                maxScore = product;
                maxCount = 1;
            }
            else if(product == maxScore){
                maxCount++; // store count of nodes which have maximum score equal to "maxScore"
            }
        }
            
        return maxCount;
    }
};
