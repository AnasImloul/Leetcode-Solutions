class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        
        // special case, if node1 and node2 are same the answer will be itself
        if(node1 == node2)
            return node1;

        int n = edges.size();
        // distance vectors for node1 and node2
        vector<int> m1(n, -1);
        vector<int> m2(n, -1);
        int ans = -1;
        int maxD = n + 1;

        int node = node1;
        int dist = 0;
        // calculate distance from node1       
        while(node != -1 && m1[node] == -1)
        {
            m1[node] = dist;
            dist++;
            node = edges[node];   
        }

        node = node2;
        dist = 0;
        // calculate distance from node2 while checking for the same node in distance vector for node1
        while(node != -1 && m2[node] == -1)
        {
            if(m1[node] != -1)
            {
                if(maxD > max(dist, m1[node]))
                {
                    ans = node;
                    maxD = max(dist, m1[node]);
                }
                else if(maxD == max(dist, m1[node]))
                {
                    if(ans > node)
                        ans = node;
                }
            }

            m2[node] = dist;
            dist++;
            node = edges[node];
        }

        return ans;
    }
};