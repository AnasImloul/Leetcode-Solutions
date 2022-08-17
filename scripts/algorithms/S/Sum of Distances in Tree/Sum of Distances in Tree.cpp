/*
    
    Finding sum of distance from ith node to all other nodes takes O(n), so it will take O(n^2)
    if done naively to find distance for all.
    
            x---------------------y
          /  \                    \
         o    o                    o
        /                         / \  
       o                         o   o
       
      Above is a graph where x and y are subtrees with them as the root. They both are neighbors
      and are connected by an edge.
      
      From x's POV
             x
          /  |   \                    
         o    o   y                  
        /          \                    
       o            o                
                  /  \
                 o    o
                 
    From y's POV
                 y                  
               /    \                    
              x      o                
            /  |    /  \
           o   o   o    o
          /
         o 
         
    As evident froma above, the tree structure looks different when we change the root of tree.
    So even if we find the sum of distance for node 0 as root, the subanswers are actually not correct
    for other nodes when they are the root of tree. The subanswers are only correct when node 0 is root,
    since that is how it was computed.
    
    We use something called re-rooting, this allows us to find a relation so that we can change the root of the tree
    and use the answer from its neighbor to compute answer for it.
    So if we compute the answer for node 0 as root, we can find the answers for its children, then those children can 
    be used to compute for their neighbors and so on.
    
    For the 1st diagram:
    distance[x] = sum(x) + sum(y) + count(y)
    
    distance[x] is the overall sum of distance with root as x
    sum(i) is the sum of distance of all the descendents for a subtree rooted at i
    count(i) is the no. of descendent nodes in the subtree rooted at i
    
    Now why count(y) ?
    Consider a node z in subtree y, dist(x, z) = dist(y, z) + 1
    So sum(y) already accounts for dist(y, z) and we just need to add 1
    So if there are n_y nodes in the subtree, we need to add +1 that many times.
    
    distance[x] = sum(x) + sum(y) + count(y) -----------------1
    distance[y] = sum(y) + sum(x) + count(x) -----------------2
    
    From (1) - (2)
    distance[x] - distance[y] = count(y) - count(x) ----------3
    distance[x] = distance[y] - count(x) + count(y)
    
    Above relation can be used to find the answer for a neighbor, when the answer for
    the other neighbor is known.
    
    In our case, we can compute the answer for node 0 as root in one traversal of post order.
    Then in another traversal with again root as 0, compute the answer for its children and from
    them to their children nodes and so on.
    
    distance[child] = distance[parent] - count(child) + (N - count(child))
    Since we also know the no. of nodes in subtree with child as root, the remaining nodes = (N - count(child))
    
    
    Re-rooting Ref: https://leetcode.com/problems/sum-of-distances-in-tree/solution/
    
    TC: O(N)
    SC: O(N)
*/
class Solution {
private:
    int n = 0;
    // subtree_distance[i] = Sum of distance to other nodes when the ith-node is root
    vector<int> subtree_distance;
    // subtree_count[i] = no. of nodes in the subtree with ith-node as root
    vector<int> subtree_count;
public:
    void postorder(int root, int parent, vector<vector<int>>& graph) {
        // Perform DFS for the child nodes
        for(auto child: graph[root]) {
            // Avoid iterating to the parent, it will create a loop otherwise
            if(child != parent) {
                postorder(child, root, graph);
                // Update the subtree count and sum of distance
                subtree_count[root] += subtree_count[child];
                // distance[X] = distance[X] + distance[Y] + n_Y
                subtree_distance[root] += subtree_distance[child] + subtree_count[child];
            }
        }
    }
    
    void preorder(int root, int parent, vector<vector<int>>& graph) {
        for(auto child: graph[root]) {
            if(child != parent) {
                // distance[child] = distance[parent] - count[child] + count(parent)
                subtree_distance[child] = subtree_distance[root] - subtree_count[child] + (n - subtree_count[child]);
                preorder(child, root, graph);
            }
        }
    }
    
    vector<int> reRootingSol(int n, vector<vector<int>>& edges) {
        // create an undirected graph
        vector<vector<int> > graph(n);
        for(auto edge: edges) {
            int src = edge[0], dst = edge[1];
            graph[src].emplace_back(dst);
            graph[dst].emplace_back(src);
        }
        
        this->n = n;
        this->subtree_count.resize(n, 1);
        this->subtree_distance.resize(n, 0);
        
        // This computes the subtree sum and subtree node count when 0 is the root of graph
        // Imagine looking at the graph from node 0's POV
        postorder(0, -1, graph);
        // Since we have computed the sum distance from node's POV, we can use that information
        // to find the sum of distance from each node's POV i.e imagine looking at the graph from
        // POV of each node
        preorder(0, -1, graph);
        return this->subtree_distance;
    }
    
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        return reRootingSol(n, edges);
    }
};
