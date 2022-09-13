// Runtime: 3 ms (Top 65.19%) | Memory: 7.9 MB (Top 10.48%)
class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string>ans;
        int l=target.size(), count=0,ind=0; // ind is index of the target array

        for(int i=1;i<=n;i++){
            if(count==l) break;
            if(target[ind]!=i){
                ans.push_back("Push");
                ans.push_back("Pop");
            }
            else{
                ans.push_back("Push");
                count++;
                ind++;
            }
        }
        return ans;
    }
};