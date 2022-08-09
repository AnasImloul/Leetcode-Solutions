class Solution {
public:
    struct comp{
        bool operator()(pair<int,int>&a, pair<int,int>&b){
            return a.first < b.first;
        }
    };
    
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        unordered_map<int,int> hmap;
        int n = barcodes.size();
        if(n==1)return barcodes;
        
        for(auto &bar : barcodes){
            hmap[bar]++;
        }
        
        vector<int> ans;
        priority_queue<pair<int,int>, vector<pair<int,int>>, comp> pq;
        
        for(auto &it : hmap){
            pq.push({it.second, it.first});
        }
        
        while(pq.size()>1){
            
            auto firstBar = pq.top();
            pq.pop();
            
            auto secondBar = pq.top();
            pq.pop();
            
            ans.push_back(firstBar.second);
            ans.push_back(secondBar.second);
            
            --firstBar.first;
            --secondBar.first;
            
            if(firstBar.first > 0){
                pq.push(firstBar);
            }
            
            if(secondBar.first > 0){
                pq.push(secondBar);
            }
        }
        
        if(pq.size()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        
        return ans;
    }
};