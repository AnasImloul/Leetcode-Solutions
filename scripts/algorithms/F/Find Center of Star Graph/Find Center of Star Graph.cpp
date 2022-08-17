class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        //the center of a graph will be connected to all the edges
        //so keep a track of number of edges for every node
        //if number of edges is n then it is the center 
        
            //to store the number of edges for every node
        int n=edges.size();
        vector<int> mp(n+2,0);
        for(int i=0;i<edges.size();i++)
        {
            mp[edges[i][0]]++;
            mp[edges[i][1]]++;
            if(mp[edges[i][0]]==n)
                return edges[i][0];
            if(mp[edges[i][1]]==n)
                return edges[i][1];
        }
        return 0;
        
    }
};
