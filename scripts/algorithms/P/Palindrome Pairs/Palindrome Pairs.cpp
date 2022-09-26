// Runtime: 2661 ms (Top 8.68%) | Memory: 415.7 MB (Top 73.21%)
class Solution {
public:
   // Maybe I should learn trie! :'( this code just beats the time limit !
    pair<bool,bool> dp[5001][301];
    long long mod = 1011001110001111 , base = 31;
    pair<long long,long long> Hashes[5001];
    vector<vector<int>> ans;
    vector<pair<long long,int>> pos[301];
    vector<pair<long long,int>> posR[301];
    vector<vector<int>> palindromePairs(vector<string>& words) {
         for(int i=0; i<words.size(); i++) {
             long long hashL = 0 , hashR = 0;
             long long pw = 1;
             for(int j=0; j<words[i].size(); j++) {
                   hashR = ((hashR * base)%mod + (words[i][j] - 'a' + 1))%mod;
                   hashL = (hashL + ((words[i][j] - 'a' + 1)*pw)%mod)%mod;
                   dp[i][j].first = (hashL==hashR);
                   posR[j+1].push_back({hashL,i});
                   pw = (pw * base)%mod;
             }
             Hashes[i] = {hashL,hashR};
             hashL = 0 , hashR = 0 , pw = 1;
             int l = 1;
             for(int j=words[i].size()-1; j>=0; j--) {
                   hashR = ((hashR * base)%mod + (words[i][j] - 'a' + 1))%mod;
                   hashL = (hashL + ((words[i][j] - 'a' + 1)*pw)%mod)%mod;
                   dp[i][j].second = (hashL==hashR);
                   pos[l++].push_back({hashL,i});
                   pw = (pw * base)%mod;
             }
         }
         set<pair<int,int>> ss;
         for(int i=0; i<words.size(); i++) {
              int len = words[i].size();
              long long cur1 = Hashes[i].first;
              long long cur2 = Hashes[i].second;
              for(int k=0; k<pos[len].size(); k++) {
                    pair<long long,int> nxt = pos[len][k];
                    if(nxt.first == cur1 && i!=nxt.second) {
                          int tot = words[nxt.second].size();
                          int pref = (tot - len) - 1;
                          if(pref>=0 && dp[nxt.second][pref].first) {
                               ss.insert({i,pos[len][k].second});
                          }else if(pref<0) {
                               ss.insert({i,pos[len][k].second});
                          }
                    }
              }
              for(int k=0; k<posR[len].size(); k++) {
                    pair<long long,int> nxt = posR[len][k];
                    if(nxt.first == cur2 && i!=nxt.second) {
                         if(len<words[nxt.second].size() && dp[nxt.second][len].second) {
                              ss.insert({nxt.second,i});
                         }else if(len>=words[nxt.second].size()) {
                              ss.insert({nxt.second,i});
                         }
                    }
              }
         }

        // palindrome + "" empty is a valid pair
        for(int i=0; i<words.size(); i++) {
             if(words[i].size()==0) {
                 for(int j=0; j<words.size(); j++) {
                      int len = words[j].size();
                      if((words[j].size()==0 || dp[j][len-1].first) && j!=i) {
                           ss.insert({i,j});
                           ss.insert({j,i});
                      }
                 }
             }
        }
        for(pair<int,int> p : ss) ans.push_back({p.first,p.second});
        return ans;
    }
};
