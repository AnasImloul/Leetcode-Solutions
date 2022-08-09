class MyHashMap {
public:
    vector<pair<int,int>> mpp;
    MyHashMap() {
        
    }
    
    void put(int key, int value) {
        for(int i=0;i<mpp.size();i++){
            if(mpp[i].first==key){
                mpp[i].second=value;
                break;
            }
        }
        mpp.push_back({key,value});
    }
    
    int get(int key) {
        for(int i=0;i<mpp.size();i++){
            if(mpp[i].first==key && mpp[i].second!=INT_MIN)return mpp[i].second;
        }
        return -1;
    }
    
    void remove(int key) {
        for(int i=0;i<mpp.size();i++){
            if(mpp[i].first==key)mpp[i].second=INT_MIN;
        }
    }
};
