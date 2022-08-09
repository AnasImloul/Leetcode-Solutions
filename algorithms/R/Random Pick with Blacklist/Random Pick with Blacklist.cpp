class Solution {
public:
    int idx;
    unordered_map<int, int>mp;
    set<int> s;
    Solution(int n, vector<int>& blacklist) {
       idx = n - blacklist.size();
       n--;
       for(int i = 0; i<blacklist.size(); i++) s.insert(blacklist[i]);
       for(int i = 0; i<blacklist.size(); i++){
           if(blacklist[i] < idx){
           while(s.find(n) != s.end())n--;
           mp[blacklist[i]] = n;
           n--; 
           }
       } 
    }
    
    int pick() {
      int ans = rand()%(idx);
      if(mp.count(ans)) return mp[ans];
      return ans;
    }
};
