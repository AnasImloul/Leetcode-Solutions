class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        int ans;
        unordered_map<int,int> mp;
        for(int i=0; i<arr.size(); i++){
            mp[arr[i]]++;
        }

        priority_queue< int, vector<int>, greater<int>> pq;
        for(auto it : mp){
            pq.push(it.second);
        }

        while(k>0){
           k-= pq.top();   
           if(k>=0){
              pq.pop(); 
           }
        }
        return pq.size();
    }
};