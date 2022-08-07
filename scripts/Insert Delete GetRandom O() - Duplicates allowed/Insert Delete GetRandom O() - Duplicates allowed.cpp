class RandomizedCollection {
public:
    
    unordered_map<int, unordered_set<int>> mp;
    
    vector<int> arr;
    
    RandomizedCollection() {
        
    }
    
    bool insert(int val) {
        
        arr.push_back(val);
        
        mp[val].insert(arr.size() - 1);
        
        return mp[val].size() == 1;
    }
    
    bool remove(int val) {
        
        if(mp.count(val))
        {
            // pick one occurance of val and delete it
            
            // find the index
            
            int idx = *(mp[val].begin());
            
            // erase from set
            
            mp[val].erase(mp[val].begin());
            
            // replace this index with last element
            
            int last_val = arr.back();
           
            arr[idx] = last_val;
            
            mp[last_val].insert(idx);
            
            mp[last_val].erase(arr.size() - 1);
            
            arr.pop_back();
            
            // if there is no occurance of val is present then erase it from map
            
            if(mp[val].size() == 0)
            {
                mp.erase(val);
            }
            
            return true;
        }
        
        return false;
    }
    
    int getRandom() {
        
        // generate the random index
        
        int rand_idx = rand() % arr.size();
        
        return arr[rand_idx];
    }
};

