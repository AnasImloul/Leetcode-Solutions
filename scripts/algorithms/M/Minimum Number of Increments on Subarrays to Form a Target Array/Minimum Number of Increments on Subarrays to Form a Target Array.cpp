class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int n=target.size();
        int pre=0, cnt=0;
        for(int i=0;i<n;i++)
        {
            if(target[i]>pre)
            cnt+=target[i]-pre;
            pre=target[i];
        }
        return cnt;
    }
};