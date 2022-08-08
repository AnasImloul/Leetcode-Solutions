class TimeMap {
public:
    map<string,vector<pair<int,string>>> mp;
    string Max;
    TimeMap() {
        Max = "";
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back(make_pair(timestamp,value));
        Max = max(Max,value);
    }
    
    string get(string key, int timestamp) {
        pair<int,string> p = make_pair(timestamp,Max);
        int l = upper_bound(mp[key].begin(),mp[key].end(),p)-mp[key].begin();
        if(l==0){
            return "";
        }
        return mp[key][l-1].second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
