Time: O(n)  Space: O(1)

class Solution {
public:
    string reverseStr(string s, int k) {
        int n=size(s);
        for(int i=0;i<n;i=i+2*k){
            int j=i+k-1,k=i;
            if(j>=n) 
                j=n-1;
            while(k<(j)){
                swap(s[k],s[j]);
                k++,j--;
            }
        }
        return s;
    }
};
