// Runtime: 221 ms (Top 44.66%) | Memory: 64.2 MB (Top 9.81%)
class Solution {
public:
    bool func(vector<int> pos){
        map<int,int> mp;
        for(int i=0;i<pos.size();i++){
            mp[pos[i]]++;
        }

        for(auto it:mp){
            if(mp.find(2*it.first)==mp.end()){
                return false;
            }
            if(mp[it.first]>mp[2*it.first]){
                return false;
            }
            mp[2*it.first]-=mp[it.first];
            if(mp[2*it.first]==0)
                mp.erase(2*it.first);
        }

        return true;
    }

    bool canReorderDoubled(vector<int>& arr) {
        int n=arr.size();
        vector<int> pos,neg;
        int zeroes=0;
        for(int i:arr){
            if(i>0){
                pos.push_back(i);
            }else if(i<0){
                neg.push_back(i);
            }else{
                zeroes++;
            }
        }

        if(zeroes%2!=0){
            return false;
        }

        if(neg.size()%2!=0 or pos.size()%2!=0){
            return false;
        }

        for(int i=0;i<neg.size();i++){
            neg[i]=-1*neg[i];
        }

        sort(pos.begin(),pos.end());
        sort(neg.begin(),neg.end());
        return func(pos) and func(neg);
    }
};