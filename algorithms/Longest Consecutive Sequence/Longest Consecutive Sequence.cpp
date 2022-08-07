class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        set<int> hashSet;
        
        int longestConsecutiveSequence = 0; 
        
        for(auto it : nums){
            hashSet.insert(it);
        }
        
        for(auto it : nums){
            
            if(!hashSet.count(it-1)){
                
                int count = 1;
                
                while(hashSet.count(it+count)) ++count;
                
                longestConsecutiveSequence = max(count,longestConsecutiveSequence);
                
            }
            
        }
        
        return longestConsecutiveSequence;
    }
};
