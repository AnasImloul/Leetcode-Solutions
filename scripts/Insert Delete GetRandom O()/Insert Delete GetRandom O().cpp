class RandomizedSet {
public:
    unordered_map<int, int> mp;
    vector<int> v;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(mp.find(val) != mp.end()) return false;
        mp[val] = v.size();
        v.push_back(val);
        return true;
    }
    
    bool remove(int val) {
        if(mp.find(val) != mp.end()){
            v[mp[val]] = v.back();
            mp[v.back()] = mp[val];
            v.pop_back();
            mp.erase(val);
            return true;
        } 
        return false;
    }
    
    int getRandom() {
        return v[rand()%v.size()];
    }
};
