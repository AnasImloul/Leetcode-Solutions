// Runtime: 4 ms (Top 66.87%) | Memory: 7.9 MB (Top 80.77%)
class MapSum {
public:
    map<string,int>mp;
    MapSum() {

    }

    void insert(string key, int val) {
        mp[key]=val;
    }

    int sum(string prefix) {
        int count=0;
        for(auto i:mp){
            int j;
            for(j=0;j<i.first.size() && j<prefix.size();j++){
                if(i.first[j]!=prefix[j])break;
            }
            if(j==prefix.size())count+=i.second;
        }
        return count;
    }
};