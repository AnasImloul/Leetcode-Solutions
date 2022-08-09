typedef pair<int,int> p;
class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        // Heap 'q' will store the k largest elements of the array 
        // The following heap is of pair where first element of pair is the element and the second element is the corresponding index
        // That's how in queue sorting will be done according to the array element
        priority_queue<p,vector<p>,greater<p>>q;
        for(int i=0;i<nums.size();i++)
        {
            q.push({nums[i],i});
            if(q.size()>k)
            {
                q.pop();
            }
        }
        
        // heap 'aux' will sort the elements based on their index
        // sorting according to the index is necessary in order get the original order of the elements 
		// in the following heap the first element of the pair is the index and the second element is the array element itself
        priority_queue<p,vector<p>,greater<p>>aux;
        while(!q.empty())
        {
            aux.push({q.top().second,q.top().first});
            q.pop();
        }
        
        // once the elements are sorted according to their indices , push them in a vector
        vector<int>ans;
        while(!aux.empty())
        {
            ans.push_back(aux.top().second);
            aux.pop();
        }
        
        // finally return the answer
        return ans;
    }
};
