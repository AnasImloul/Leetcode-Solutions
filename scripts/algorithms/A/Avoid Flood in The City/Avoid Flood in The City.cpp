class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        vector<int> ans(rains.size() , -1) ;
        unordered_map<int,int> indices ; //store the lake and its index 
        set<int> st ; //stores the indices of zeros 
        
        for(int i = 0 ; i < rains.size() ; ++i ){
            if(!rains[i]) st.insert(i) ;
            else{
                if(indices.find(rains[i]) == end(indices)) indices[rains[i]] = i ;
                else{
                    int prevDay = indices[rains[i]] ;
                    auto it = st.upper_bound(prevDay) ;
                    if(it == end(st)) return {} ;
                    ans[*it] = rains[i] ;
                    indices[rains[i]] = i ;
                    st.erase(it);
                }
            }
        }
        
        for(int i = 0 ; i < ans.size(); ++i ){
            if(!rains[i] and ans[i] == -1) ans[i] = 1 ;
        }
        return ans ;
    }
};
