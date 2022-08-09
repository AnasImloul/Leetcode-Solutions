class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int i=0;int j=0;int res=INT_MIN;
        unordered_map<int,int> mp;
        while(j<fruits.size()){
            mp[fruits[j]]++;
            if(mp.size()<=2){ // here instead of using only mp.size==2 , we are using <=2, because ,in case of input [1,1] ,here map size is <2 but we need to update result.
                res=max(res,j-i+1); 
                j++;
            }
            else if(mp.size()>2){
                while(mp.size()>2){
                    mp[fruits[i]]--;
                    if(mp[fruits[i]]==0) mp.erase(fruits[i]);
                    i++;
                }
                j++;
            }
        }
        if(fruits.size()==1 && fruits[0]==0) return 1;
        else return res;
    }
};