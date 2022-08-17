class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        map<int,int> hm;
        for(int i=0;i<tasks.size();i++){
            hm[tasks[i]]++;
        }
        int num,freq,ans=0;
        for (auto i : hm){
            freq = i.second;
            if(freq==1)
                return -1;
            if(freq%3==0){
                ans += freq/3;
            }
            else{
                ans += freq/3 + 1;
            }
        }
        return ans;
    }
};
