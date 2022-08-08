class Solution {
public:
    int minimumSwap(string s1, string s2) {
        int n = s1.size();
        int cnt1=0,cnt2=0,i=0;
        
        while(i<n){
            int x = s1[i];
            int y = s2[i++];
            if(x=='x' and y=='y') cnt1++;
            if(x=='y' and y=='x') cnt2++;
        }
        
        if((cnt1+cnt2)%2==1) return -1;
        
        return (cnt1/2) + (cnt2/2) + (cnt1%2 + cnt2%2);
    }
};
