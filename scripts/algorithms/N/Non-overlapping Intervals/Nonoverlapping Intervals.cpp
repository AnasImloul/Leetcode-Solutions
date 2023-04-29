class Solution {
        void solve(priority_queue <pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> &pq,int e,int &cnt){

       while(!pq.empty() && pq.top().first<e){
           e = min(e,pq.top().second);
             pq.pop();
             cnt++;
        }
       
    }

public:
    int eraseOverlapIntervals(vector<vector<int>>& grid) {
           priority_queue <pair<int,int>, 
           vector<pair<int,int>>, greater<pair<int,int>> > pq;

       for(int i =0; i<grid.size(); i++){
           pq.push({grid[i][0],grid[i][1]});
       }
       int cnt =0;
       while(!pq.empty()){
           int e = pq.top().second;
           pq.pop();
           solve(pq,e,cnt);
       }
       return cnt;
    }
};