class Solution {
public:
    
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        
        int count=0;
        unordered_map<int,int> mp;
        
        /* Philosophy
        
        1. I know that Addtion have two parts in it  EG (a +b , Part 1 - a, Part 2- b.
        2.So, Lets make and find this dependency factors. How can I do it?
        
        3. If there are 4 Sum. it means 2 sums is going to Part 1 and another 2 gonna be Part 2 which are dependent on Part 1 for 0 resultant.
        
        4. I gonna store summation 2 nums1 in a FREQUENCY Hashmap.
        
        5. Then I traverse 2nd part of the summation (rest to nums) and keep checking that do (0-it1-it2) is exist in map . 
       
        6. If yes, the add the frequency of Part1 int COUNT var.
        
        7. return count;
        */
        
        //Traversing Part 1
        for (auto &it1: nums1)
            for (auto &it2:nums2)
                mp[it1+it2]++; 
        
        // Traversing Part 2
        for(auto &it3: nums3)
            for(auto &it4:nums4)
               if(mp.count(0-it3-it4)) count+=mp[0-it3-it4];
        
        return count;
    }
};

