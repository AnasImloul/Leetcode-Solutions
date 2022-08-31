// Runtime: 887 ms (Top 68.93%) | Memory: 235.7 MB (Top 56.17%)
class RangeFreqQuery {
private:
    int size;
    unordered_map< int, vector<int> > mp;
public:
    RangeFreqQuery(vector<int>& arr) {
        size=arr.size();
        for (int i=0; i<size;i++){
            mp[arr[i]].push_back(i);
        }
    }
    int query(int left, int right, int value) {
        int first = lower_bound(mp[value].begin(),mp[value].end(),left)- mp[value].begin();
        int second = upper_bound(mp[value].begin(),mp[value].end(),right)- mp[value].begin();
        return second-first;
    }
};