class Solution {
public:
    int countPairs(vector<int>& deliciousness) {
        int cnt=0;
        unordered_map<int,int> mp;
        mp[deliciousness[0]]++;
        int mod=1e9+7;
        for(int i=1;i<deliciousness.size();i++){
            for(int p=1;p<=(1<<21);p*=2){
                if(mp.find(p-deliciousness[i])!=mp.end()){
                    cnt=(cnt+mp[p-deliciousness[i]])%mod;
                    
                }
            }
            mp[deliciousness[i]]++;
            
        }
        return cnt%mod;
    }
};
