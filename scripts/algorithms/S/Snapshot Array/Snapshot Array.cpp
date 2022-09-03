// Runtime: 366 ms (Top 61.08%) | Memory: 85.5 MB (Top 97.26%)
class SnapshotArray {
    int timestamp;
    unordered_map<int, vector<int>> toSnaps, toValues;
public:
    SnapshotArray(int length) {
        timestamp = 0;
    }

    void set(int index, int val) {
        if (toSnaps.count(index) == 0) {
            // After lower_bound, prevent returning negative lo
            toSnaps[index].push_back(-1);
            // 0 means not found
            toValues[index].push_back(0);
        }
        // same timestamp -> just update value
        if (toSnaps[index].back() == timestamp) {
            toValues[index].back() = val;
        }
        // not -> add timestamp and value
        else {
            toSnaps[index].push_back(timestamp);
            toValues[index].push_back(val);
        }
    }

    int snap() {
        return timestamp++;
    }

    int get(int index, int snap_id) {
        // check whether index exists or not
        if (toSnaps.count(index) == 0) return 0;
        auto& snaps = toSnaps[index];
        int lo = 0, hi = snaps.size()-1;
        while (lo < hi) {
            int m = lo + (hi - lo)/2;
            if (snaps[m] >= snap_id) hi = m;
            else lo = m + 1;
        }
        // lower bound can be larger than target
        if (snaps[lo] > snap_id) lo--;
        // if lo is negative, then ther is no value of index at lo time
        //if (lo < 0) return 0;
        return toValues[index][lo];
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */