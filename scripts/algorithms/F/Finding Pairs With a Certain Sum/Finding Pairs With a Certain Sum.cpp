// Runtime: 338 ms (Top 40.57%) | Memory: 74.10 MB (Top 78.77%)

class FindSumPairs {
public:
    unordered_map<int, int> mp2;
    
    unordered_map<int, int> mp1;
    
    vector<int> arr;
    
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        
        for(auto x : nums1)
        {
            mp1[x]++;
        }
        
        arr = nums2;
        
        for(auto x : nums2)
        {
            mp2[x]++;
        }
    }
    
    void add(int index, int val) {
        
        mp2[arr[index]]--;
        
        if(mp2[arr[index]] == 0)
        {
            mp2.erase(arr[index]);
        }
        
        arr[index] += val;
        
        mp2[arr[index]]++;
    }
    
    int count(int tot) {
        
        int count = 0;
        
        for(auto x : mp1)
        {
            int val = x.first;
            
            int freq = x.second;
            
            int need = tot - val;
            
            if(mp2.count(need))
            {
                count += mp2[need] * freq;
            }
        }
        
        return count;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */
