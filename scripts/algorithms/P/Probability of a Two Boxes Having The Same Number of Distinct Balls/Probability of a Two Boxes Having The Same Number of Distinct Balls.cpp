// Runtime: 164 ms (Top 66.20%) | Memory: 6.6 MB (Top 54.93%)
class Solution {
public:
    double c[7][7]={},v=0,tc=0;
    int t=0;
    void solve(int idx,int k1,int k2,int n1,double p,vector<int>& balls){
        if(idx==size(balls)){
            if(n1==t){
                v+=(k1==k2)*p;
                tc+=p;
            }
        }else{
            int k11,k12;
            for(int i=0;i<=balls[idx];++i){
                if(i+n1>t) break;
                k11=k1+(i>0);
                k12=k2+(balls[idx]-i>0);
                solve(idx+1,k11,k12,n1+i,p*c[balls[idx]][i],balls);
            }
        }
    }
    double getProbability(vector<int>& balls) {
        for(int i=0;i<=6;++i){
            c[i][0]=c[i][i]=1;
            for(int j=1;j<i;++j)c[i][j]=c[i-1][j]+c[i-1][j-1];
        }
        for(auto&i:balls)t+=i;
        t/=2;
        solve(0,0,0,0,1,balls);
        return v/tc;
    }
};