// Runtime: 20 ms (Top 8.9%) | Memory: 12.04 MB (Top 5.3%)

class Solution {
public:
    vector<int> circularGameLosers(int n, int k) {
        map<int,int> mp;
        int i=1; int turn=1;
        while (mp[i]!=1){
            mp[i]++;
            int addy= (i+(turn*k));
            if (addy%n==0)i=n;
            else i= addy%n;
            turn++;
        }
        vector<int> ans;
        for (int i=1; i<=n; i++){
            if (mp[i]==0)ans.push_back(i);
        }
        return ans;
    }
};