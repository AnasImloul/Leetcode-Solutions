// Runtime: 365 ms (Top 20.28%) | Memory: 39.4 MB (Top 95.17%)
class MyHashSet {
    vector<int> v;
public:
    MyHashSet() {

    }

    void add(int key) {
        auto it = find(v.begin(), v.end(), key);
        if(it == v.end()){
            v.push_back(key);
        }

    }

    void remove(int key) {
        auto it = find(v.begin(), v.end(), key);
        if(it != v.end()){
            v.erase(it);
        }
    }

    bool contains(int key) {
        return find(v.begin(), v.end(), key) != v.end();
    }
};