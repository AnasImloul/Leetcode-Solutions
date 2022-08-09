class Solution {
public:
    int findLatestStep(vector<int>& arr, int m) {
        int n=size(arr),ans=-1;
        vector<int>cntL(n+2),indL(n+2);
        for(int i=0;i<n;i++){
            int li=indL[arr[i]-1],ri=indL[arr[i]+1],nl=li+ri+1;
            indL[arr[i]]=nl;
            indL[arr[i]-li]=nl;
            indL[arr[i]+ri]=nl;
            cntL[li]--;
            cntL[ri]--;
            cntL[nl]++;
            if(cntL[m]>0)ans=i+1;
        }
        return ans;
    }
};
