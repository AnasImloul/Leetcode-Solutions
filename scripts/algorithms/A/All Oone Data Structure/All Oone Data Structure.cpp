// Runtime: 107 ms (Top 69.2%) | Memory: 56.30 MB (Top 39.92%)

class Entry {
public:
    int cnt;
    unordered_set <string> keys;
    Entry(int _cnt, string &key) {
        cnt = _cnt;
        keys.insert(key);
    }
    void add(string &key) {
        keys.insert(key);
    }
    void remove(string &key) {
        keys.erase(key); 
    }
    bool empty() {
        return keys.empty(); 
    }
    string getAnyKey() {
        return *(keys.begin()); 
    }
};

class AllOne {
public:
    
    list <Entry> data;
    unordered_map <string, list<Entry>::iterator> pos;
    
    AllOne() {
        
    }
    
    void inc(string key) {
        
        if (data.empty()) {
            data.push_back(Entry(1, key));
            pos[key] = data.begin(); 
            return;
        }
        
        if (pos.find(key) == pos.end()) {
            if (data.begin()->cnt == 1) {
                data.begin()->add(key);
                pos[key] = data.begin(); 
            }
            else {
                pos[key] = data.insert(data.begin(), Entry(1, key)); 
            }
        }
        else {
            auto entry = pos[key]; 
            if (entry == prev(data.end())) {
                pos[key] = data.insert(data.end(), Entry(entry->cnt+1, key)); 
            }
            else if (entry->cnt+1 == next(entry)->cnt) {
                next(entry)->add(key);
                pos[key] = next(entry); 
            }
            else {
                pos[key] = data.insert(next(entry), Entry(entry->cnt+1, key)); 
            }
            entry->remove(key);
            if (entry->empty()) data.erase(entry); 
        }
        
    }
    
    void dec(string key) {
        auto entry = pos[key]; 
        if (entry->cnt > 1) {
            if (entry == data.begin()) {
                pos[key] = data.insert(data.begin(), Entry(entry->cnt-1, key)); 
            }
            else if (entry->cnt-1 == prev(entry)->cnt) {
                prev(entry)->add(key);
                pos[key] = prev(entry); 
            }
            else {
                pos[key] = data.insert(entry, Entry(entry->cnt-1, key)); 
            }
        }
        else pos.erase(key); 
        
        entry->remove(key);
        if (entry->empty()) data.erase(entry); 
        
    }
    
    string getMaxKey() {
        if (data.empty()) return ""; 
        return prev(data.end())->getAnyKey(); 
    }
    
    string getMinKey() {
        if (data.empty()) return ""; 
        return data.begin()->getAnyKey(); 
    }
    
     
};
