// Runtime: 4 ms (Top 37.02%) | Memory: 8.80 MB (Top 13.84%)

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        priority_queue <int, vector<int>, greater<int> > pq;
        
        for(int i=0;i<nums.size();i++)
            pq.push(nums[i]);
        
        int curr_min=0;
        int count=0;
        
        while(!pq.empty()){
            if(pq.top()==0)pq.pop();
            else{
                int top=pq.top()-curr_min;
                if(top!=0){
                    curr_min+=top;
                    count++;
                }
                pq.pop();
            }
        }
        return count;
    }
};
