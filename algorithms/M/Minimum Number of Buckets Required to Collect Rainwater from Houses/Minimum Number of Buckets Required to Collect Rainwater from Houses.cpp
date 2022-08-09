class Solution {
public:
    int minimumBuckets(string street) {
        unordered_map<int,int>mp;
        int res=0;
        for(int i=0;i<street.size();i++){
            if(street[i]=='H'){
                if(mp[i+1]>0 or mp[i-1]>0)continue;
                if(i+1<street.size() and street[i+1]=='.'){
                    res++;
                    mp[i+1]++;
                    continue;
                }
                if(i-1>=0 and street[i-1]=='.'){
                    res++;
                    continue;
                }
                return -1;
            }
        }
        return res;
    }
};
