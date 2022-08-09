/*
1.mark the starting and ending pt of each building
    -> let height of starting pt be negative and ending pt be positive   [2,4,10] -> [[2,-10],[4,10]]
2.mark all consecutive building
    ->store every pair of x and y in pair sort it acc to x
3.get max y for all x values
    ->use heap-->(multiset) to store all buildings, insert new height of building else erase buiding height
4.remove pts of same height and store ans in results
*/
class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
		//step1
        vector<pair<int,int>> coordinate;
        for(auto building: buildings){
            coordinate.push_back({building[0],-building[2]});
            coordinate.push_back({building[1],building[2]});
        }
		//step2
        sort(coordinate.begin(), coordinate.end());
        
		//step3
        multiset<int,greater<int>> pq = {0};
        vector<vector<int>> result;
        int prev = 0;
        for(auto p: coordinate){
            if (p.second<0) pq.insert(-p.second);
            else pq.erase(pq.find(p.second));
            int cur=*pq.begin();
            if (prev!=cur) {
                result.push_back({p.first,cur});
                prev=cur;
            }
        }
        return result;
    }
};
