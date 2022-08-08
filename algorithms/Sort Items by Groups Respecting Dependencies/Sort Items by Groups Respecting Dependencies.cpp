/*
    https://leetcode.com/problems/sort-items-by-groups-respecting-dependencies/
    
    TC: O(n + m + E), E = No. of edges as seen from 'beforeItems' array
    SC: O(n + m)
    
    Looking at the problem, it is clearly a topological sort problem. But there are two things that
    needs ordering. The nodes within a group can have an ordering, as well the groups.
    
    Idea:
    1. Topological sort for nodes alone.
    2. Topological sort for just the groups
    3. In order to do above, we create two graphs. One graph just for the groups with m nodes, where the nodes are actually the
    group IDs. Another graph with size n, it is for the graph nodes.
    4. Then perform topological sort for both the graphs.
    5. Once we have the ordered nodes after topological sort, we fill the nodes of each group with that order.
    6. Then using the topological order of groups, just fill the nodes for each group.
*/
class Solution {
public:
    // Topological Sort
    vector<int> topologicalSort(vector<unordered_set<int> >& graph, vector<int>& indegree) {
        vector<int> order;
        int processed = 0, n = graph.size();
        
        queue<int> q;
        // Add 0 indegree nodes
        for(int node = 0; node < n; node++) 
            if(indegree[node] == 0)
                q.emplace(node);
        
        while(!q.empty()) {
            auto node = q.front();
            q.pop();
            
            // process the node
            ++processed;
            order.emplace_back(node);
            
            // Remove its dependence
            for(auto neighbor: graph[node]) {
                --indegree[neighbor];
                if(indegree[neighbor] == 0)
                    q.emplace(neighbor);
            }
        }
        
        return processed < n ? vector<int>{} : order;
    }
    
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        // Each node without a group will be self contained in a new group with only itself
        // Set the new group id for each isolated node
        for(int node = 0; node < n; node++)
            if(group[node] == -1)
                group[node] = m++;
        
        // We create two graphs, one for the groups and another for the actual nodes
        vector<unordered_set<int> > group_graph(m), node_graph(n);
        // Stores the indegree for: Amongst Groups and nodes respectively
        vector<int> group_indegree(m, 0), node_indegree(n, 0);
        
        // Create cyclic graph for group and individual nodes
        for(auto node = 0; node < n; node++) {
            // Group to which the current node belongs
            int dst_group = group[node];
            // Source Groups on which the current node has a dependency
            for(auto src_node: beforeItems[node]) {
                int src_group = group[src_node];
                // check if the dependency is inter group or intra group
                // It is inter group dependency, make sure that the same dst_group was not seen
                // before, otherwise indegree will get additional 1, same logic for the node_graph
                if(dst_group != src_group && !group_graph[src_group].count(dst_group)) {
                    group_graph[src_group].emplace(dst_group);
                    ++group_indegree[dst_group];
                }
                
                // Add the dependency amongst the nodes
                if(!node_graph[src_node].count(node)) {
                    node_graph[src_node].emplace(node);
                    ++node_indegree[node];
                }
            }
        }
        
        // Perform topological sort at a node level 
        vector<int> ordered_nodes = topologicalSort(node_graph, node_indegree);
        // Perform topological sort at a group level
        vector<int> ordered_groups = topologicalSort(group_graph, group_indegree);
        // Overall order of nodes
        vector<int> order;
        
        // For each group, put the ordered nodes after topological sort
        vector<vector<int> > group_ordered_nodes(m);
        for(auto node: ordered_nodes)
            group_ordered_nodes[group[node]].emplace_back(node);
        
        // Now that within each group, all the nodes are ordered.
        // Using the topological sort info about the groups, just put the nodes in that order
        for(auto group: ordered_groups) 
            for(auto node: group_ordered_nodes[group])
                order.emplace_back(node);
        
        return order;
    }
};
