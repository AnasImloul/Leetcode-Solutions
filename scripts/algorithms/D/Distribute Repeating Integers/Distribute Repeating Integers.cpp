// Runtime: 1691 ms (Top 10.64%) | Memory: 76.9 MB (Top 63.83%)
class Solution {
public:
    bool solve(vector<int>&q, map<int,int>&count, int idx){
        if(idx==q.size()){
            return true;
        }
        for(auto it=count.begin();it!=count.end();it++){
            if(it->second>=q[idx]){
                count[it->first]-=q[idx];
                if(solve(q,count,idx+1))
                    return true;
                count[it->first]+=q[idx];
            }
        }
        return false;
    }
    bool canDistribute(vector<int>& nums, vector<int>& quantity) {
        map<int,int>count;
        int n=nums.size();
        for(int i=0;i<n;i++){
            count[nums[i]]++;
        }
        sort(quantity.begin(),quantity.end(),greater<int>());
        return solve(quantity,count,0);

    }
};