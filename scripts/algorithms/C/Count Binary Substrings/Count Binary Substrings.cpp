class Solution {
public:
    int countBinarySubstrings(string s) {
       //Space Complexity -> O(n)
        //Time Complexity -> O(n)
        int n=s.length();
        vector<int> temp(n,0);
        temp[0]=1;
      int idx=0;
        for(int i=1;i<n;i++){
          if(s[i-1]==s[i]){
              temp[idx]++;
          }  
            else{
                idx++;
                temp[idx]=1;
            }
        }
        int ans=0;
        for(int i=1;i<temp.size();i++){
            ans+=min(temp[i-1],temp[i]);
        }
        return ans;
    }
};