// Runtime: 7 ms (Top 84.73%) | Memory: 8.30 MB (Top 65.52%)

class Solution {
public:
    int findSubstringInWraproundString(string p) {
        int ans=1,prev_ans=1;
        vector<int> arr(26,0);
        arr[p[0]-'a']=1;
        for (int i=1;i<p.size();i++){
            if ((p[i-1]-'a'+1)%26==p[i]-'a') // Checking for continuation
                prev_ans++;
            else
                prev_ans=1;
            if (arr[p[i]-'a']<prev_ans){
                ans+=prev_ans-arr[p[i]-'a'];
                arr[p[i]-'a']=prev_ans;
            }
        }
        return ans;
    }
};
