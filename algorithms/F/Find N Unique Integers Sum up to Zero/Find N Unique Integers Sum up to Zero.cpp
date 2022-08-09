class Solution {
public:
    vector<int> sumZero(int n) {
        if(n == 1){
            return {0};
        }else{
            vector<int> res;
            for(int i=n/2*-1;i<=n/2;i++){
                if(i == 0){
                    if(n%2 == 0){
                        continue;
                    }else{
                        res.push_back(i);
                        continue;
                    } 
                }
                res.push_back(i);
            }
         return res;   
        }
    }
};
