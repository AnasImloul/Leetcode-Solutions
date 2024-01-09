// Runtime: 267 ms (Top 89.43%) | Memory: 128.90 MB (Top 84.55%)

class TimeMap {
private:
    unordered_map<string, vector<pair<string, int>>> map; // key, {value, timestamp}
    
    string searchVal(vector<pair<string, int>> &vec, const int &timestamp) {
        int low = 0;
        int high = vec.size() - 1;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            if (vec[mid].second > timestamp) {
                high = mid - 1;
            } else if (vec[mid].second < timestamp) {
                low = mid + 1;
            } else {
                return vec[mid].first;
            }
        }
        
        return high >= 0 ? vec[high].first : "";
    }
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        map[key].push_back({value, timestamp});
    }
    
    string get(string key, int timestamp) {
        if (map.find(key) == map.end()) {
            return "";
        }
        return searchVal(map[key], timestamp);
    }
};
