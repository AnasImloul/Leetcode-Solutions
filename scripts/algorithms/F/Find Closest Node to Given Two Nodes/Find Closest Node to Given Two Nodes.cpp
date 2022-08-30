// Runtime: 308 ms (Top 59.56%) | Memory: 97.7 MB (Top 72.24%)
class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {

        int n = edges.size();

        // 2 distance vectors to store the distance of all the nodes from node1 and node2
        vector<int> dist1(n, -1);
        vector<int> dist2(n, -1);

        // 2 visited vectors to keep a track of all the nodes visited from node1 and node2
        // this is done to deal with the possible cycles in the graph
        vector<bool> vis1(n, false);
        vector<bool> vis2(n, false);

        int curNode = node1;
        int curDist = 0;

        // iterate over the edges and keep track of the distance between node1 and current node
        // if curNode == -1, end of path reached.
        // if vis[curNode] == true, cycle detected.

        while(curNode!=-1 && vis1[curNode] == false) {
            vis1[curNode] = true;
            dist1[curNode] = curDist;
            curNode = edges[curNode];
            curDist++;
        }

        // repeat above steps for node2
        curNode = node2;
        curDist = 0;
        while(curNode!=-1 && vis2[curNode] == false) {
            vis2[curNode] = true;
            dist2[curNode] = curDist;
            curNode = edges[curNode];
            curDist++;
        }

        // iterate over the distance vectors and check if the current node has path from node1 and node 2
        // the distance from both nodes to the current node will be saved in the distance vectors

        int minDist = INT_MAX;
        int index = -1;
        for(int i=0;i<n;i++) {
            if(dist1[i] != -1 && dist2[i]!=-1) {
                int maxDist = max(dist1[i], dist2[i]);
                if(maxDist < minDist) {
                    minDist = maxDist;
                    index = i;
                }
            }
        }

        return index;

    }
};