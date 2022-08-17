class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int,int>sk;
        vector<int>res;
        for(auto i:arr1){
            sk[i]++;
        }
        for(auto j:arr2){
            for(auto z:sk){
                if(z.first==j){
                    int x=z.second;
                    for(int l=0;l<x;l++){
                        res.push_back(z.first);
                    }
                }
               
            }
        }
        for(auto z:sk){
            if(z.second==4 && find(res.begin(), res.end(),z.first)==res.end()){
                   int p=z.second;
                  for(int aqq=0;aqq<p;aqq++){
                      res.push_back(z.first);
                  }
                }
            
            if(z.second==3 && find(res.begin(), res.end(),z.first)==res.end()){
                   int p=z.second;
                  for(int aq=0;aq<p;aq++){
                      res.push_back(z.first);
                  }
                }
            
              if(z.second==2 && find(res.begin(), res.end(),z.first)==res.end()){
                   int p=z.second;
                  for(int a=0;a<p;a++){
                      res.push_back(z.first);
                  }
                }
            
         if(z.second==1 && find(res.begin(), res.end(),z.first)==res.end()){
                    res.push_back(z.first);
                }
        }
        
        return res;
            
    }
};
