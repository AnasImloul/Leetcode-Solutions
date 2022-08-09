class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n=score.size();
        vector<string> vs(n);
        unordered_map<int,int> mp;
        for(int i=0; i<score.size(); i++){
            mp[score[i]]=i;
        }
        sort(score.begin(),score.end(),greater<int>());
        for(int i=0; i<score.size(); i++){
            int temp=mp[score[i]];
            if(i==0){
                vs[temp]="Gold Medal";
                continue;
            }
            if(i==1){
                vs[temp]="Silver Medal";
                continue;
            }
            if(i==2){
                 vs[temp]="Bronze Medal";
                 continue;
            }
            int t=i+1;
            string st= to_string(t);
            vs[temp]=st;
        }
        return vs;
    }
};
