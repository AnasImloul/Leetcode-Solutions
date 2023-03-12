class Solution {
public:
    int countLatticePoints(vector<vector<int>>& C) {
      set<pair<int,int>> S;
        for(int i=0;i<C.size();i++){
            int a=C[i][0],b=C[i][1],x=C[i][2],l=a-x,d=b-x;
            for(int j=l;j<=x+a;j++)
            for(int k=d;k<=x+b;k++)
                if(pow(a-j,2)+pow(b-k,2)<=x*x) 
                S.insert({j,k}); 
        }
        return S.size();  
    }
};