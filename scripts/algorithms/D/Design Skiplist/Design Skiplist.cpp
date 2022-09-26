// Runtime: 84 ms (Top 77.47%) | Memory: 29 MB (Top 86.97%)
class Skiplist {
public:
    map<int,int>s;
    Skiplist() {

    }

    bool search(int target) {
        if(s.find(target)!=s.end())
            return true;
        else
            return false;
    }

    void add(int num) {
        s[num]++;
    }

    bool erase(int num) {
        if(s.find(num)==s.end())
            return false;
        else{
            s[num]--;
            if(s[num]==0)
                s.erase(num);
            return true;
        }
    }
};

/**
 * Your Skiplist object will be instantiated and called as such:
 * Skiplist* obj = new Skiplist();
 * bool param_1 = obj->search(target);
 * obj->add(num);
 * bool param_3 = obj->erase(num);
 */