// Runtime: 43 ms (Top 90.65%) | Memory: 81.4 MB (Top 44.17%)
class SnapshotArray {

    TreeMap<Integer,Integer>[] snapshotArray;
    int currSnapId;

    public SnapshotArray(int length) {
        snapshotArray = new TreeMap[length];
        for(int i=0;i<length;i++)
        {
            snapshotArray[i] = new TreeMap();
        }
        currSnapId =0;
    }

    public void set(int index, int val) {
        snapshotArray[index].put(currSnapId,val);
    }

    public int snap() {
        return currSnapId++;
    }

    public int get(int index, int snap_id) {
        Integer lowerKey = snapshotArray[index].floorKey(snap_id);

        if(lowerKey !=null)
        {
            return snapshotArray[index].get(lowerKey);
        }
        return 0;
    }
}

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray obj = new SnapshotArray(length);
 * obj.set(index,val);
 * int param_2 = obj.snap();
 * int param_3 = obj.get(index,snap_id);
 */