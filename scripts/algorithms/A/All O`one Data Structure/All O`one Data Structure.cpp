class AllOne {
public:
    map<int,unordered_set<string>> minmax;
    unordered_map<string,int> count;
    AllOne() {
        
    }
    
    void inc(string key) {
         int was = count[key]++;
         if(was>0) {
             minmax[was].erase(key);
             if(minmax[was].size()==0) minmax.erase(was);
         }
         minmax[was+1].insert(key);
    }
    
    void dec(string key) {
         int was = count[key]--;
         minmax[was].erase(key);
         if(minmax[was].size()==0) minmax.erase(was);
         if(was-1==0) {
             count.erase(key);
         }else {
             minmax[was-1].insert(key);
         }
    }
    
    string getMaxKey() {
         return minmax.size() == 0 ? "" : *minmax.rbegin()->second.begin();
    }
    
    string getMinKey() { 
        return minmax.size() == 0 ? "" : *minmax.begin()->second.begin();
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */
