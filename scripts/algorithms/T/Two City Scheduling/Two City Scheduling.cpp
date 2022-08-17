class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        sort(costs.begin(), costs.end(), [](const vector<int> &curr, const vector<int> &next){ // CUSTOM COMPARATOR
            return (curr[0]-curr[1]) < (next[0]-next[1]);   // (comparing cost of sending to A - cost to B)
        });
        // original:   [[10,20],[30,200],[400,50],[30,20]] 
        // after sort: [[30,200],[10,20],[30,20],[400,50]]
        // to do:         a       a          b         b
        
        int sum = 0;
        for(int i=0; i<costs.size()/2; i++){
            sum+=costs[i][0];
            // cout<<costs[i][0]<<" "; // 30 10
        }
        for(int i=costs.size()/2; i<costs.size(); i++){
            sum+=costs[i][1];
            // cout<<costs[i][1]<<" "; // 20 50
        }
        
        return sum;
    }
};