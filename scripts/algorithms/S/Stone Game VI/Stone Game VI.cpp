// Runtime: 1085 ms (Top 9.58%) | Memory: 129.1 MB (Top 30.29%)
vector<int> alice, bob;

struct myComp {
  bool operator()(pair<int, int>& a, pair<int, int>& b){
      return alice[a.second] + bob[a.second] < alice[b.second] + bob[b.second];
  }
};

class Solution {
public:
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
        alice = aliceValues;
        bob = bobValues;
        priority_queue<pair<int, int>, vector<pair<int, int>>, myComp> a,b;

        for(int i=0;i<aliceValues.size();i++){
            a.push({aliceValues[i], i});
            b.push({bobValues[i], i});
        }

        int ans1, ans2;
        ans1 = ans2 = 0;
        int vis[100001] = {};

        while(a.size()){
            while(a.size() && vis[a.top().second] == 1) a.pop();
            if(a.size()){
                ans1 += a.top().first;
                vis[a.top().second] = 1;
                a.pop();
            }

            while(b.size() && vis[b.top().second] == 1) b.pop();
            if(b.size()){
                ans2 += b.top().first;
                vis[b.top().second] = 1;
                b.pop();
            }
        }

        if(ans1 == ans2) return 0;
        if(ans1 > ans2) return 1;
        return -1;
    }
};