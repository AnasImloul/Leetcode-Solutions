class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int>sk;
        unordered_map<int,int>skk;
        for(int i=0;i<arr.size();i++){
            sk[arr[i]]++;
        }
		 for(auto j : sk)
        {
            if(skk[j.second]==1){
                return false;
            }
            skk[j.second]++;   
        }
        
        return true;
    }
};
