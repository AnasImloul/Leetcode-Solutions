// Runtime: 1493 ms (Top 5.16%) | Memory: 148.6 MB (Top 58.09%)
struct compareMin
{
    bool operator() (pair<int,string> p1, pair<int,string> p2) {
        if(p1.first == p2.first) return p1.second < p2.second;
        return p1.first > p2.first;
    }
};

struct compareMax
{
    bool operator() (pair<int,string> p1, pair<int,string> p2) {
        if(p1.first == p2.first) return p1.second > p2.second;
        return p1.first < p2.first;
    }
};

class SORTracker {
public:
    priority_queue <pair<int,string>, vector<pair<int,string>>, compareMin> min_heap;
    priority_queue <pair<int,string>, vector<pair<int,string>>, compareMax> max_heap;

    SORTracker() {}

    void add(string name, int score) {
        if(!min_heap.empty() && (min_heap.top().first < score || (min_heap.top().first == score && min_heap.top().second > name))) {
                pair<int,string> t = min_heap.top();
                min_heap.pop();
                min_heap.push({score,name});
                max_heap.push(t);
        } else {
            max_heap.push({score,name});
        }
    }

    string get() {
        pair<int,string> s = max_heap.top();
        max_heap.pop();
        min_heap.push(s);
        return s.second;
    }
};