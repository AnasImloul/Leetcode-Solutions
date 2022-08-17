class Solution {
public:
    #define pii pair<int,int>
    
    vector<int> arrayRankTransform(vector<int>& arr) {
        if(arr.size()==0) return {};
        
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        
        for(int i=0; i<arr.size(); i++)
            pq.push({arr[i],i});

        int temp = pq.top().first;
        int rank = 1;
        while(!pq.empty()) {
            pii p = pq.top();
            pq.pop();
            if(temp == p.first)
                arr[p.second] = rank;
            else {
                arr[p.second] = ++rank;
                temp = p.first;
            }
        }
        return arr;
    }
};
