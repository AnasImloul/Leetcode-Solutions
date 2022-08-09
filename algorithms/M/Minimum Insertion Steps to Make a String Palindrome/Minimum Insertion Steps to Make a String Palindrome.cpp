class Solution {
public:
    int t[501][501];
    int MinInsertion(string x,int m){
    string y=x;
    reverse(y.begin(),y.end());
    for(int i=0;i<m+1;i++){
        for(int j=0;j<m+1;j++){
            if(i==0||j==0)
                t[i][j]=0;
        }
    }
    for(int i=1;i<m+1;i++){
        for(int j=1;j<m+1;j++){
            if(x[i-1]==y[j-1])
                t[i][j]=1+t[i-1][j-1];
            else    
                t[i][j]=max(t[i-1][j],t[i][j-1]);
        }
    }
    return m-t[m][m];
}
    int minInsertions(string s) {
        return MinInsertion(s,s.length());
    }
};
