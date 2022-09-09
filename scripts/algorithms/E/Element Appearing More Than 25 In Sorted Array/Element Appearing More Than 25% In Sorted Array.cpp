// Runtime: 45 ms (Top 0%) | Memory: 14.4 MB (Top 0%)
class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {

        int freq = 0.25 * arr.size();
        map<int,int>m;
        for(int i: arr)
            m[i]++;

        int k;
        for(auto i: m)
        {
            if(i.second > freq)
            {
              k = i.first;
                break;
            }
        }
        return k;
    }
};