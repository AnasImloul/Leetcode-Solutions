class FindSumPairs {
public:
    //use map to store the element as key and its frequency as its value
    unordered_map<int,int> freq;
    vector<int> v1;
    vector<int> v2;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        for(auto ele:nums2)
            freq[ele]++;
        v1=nums1;
        v2=nums2;
    }
    
    void add(int index, int val) {
        //decrease the freq of value at the index
        freq[v2[index]]-- ;
        v2[index]+=val;
        //we got a new value, increment the freq of the value
        freq[v2[index]]++;
    }
    
    int count(int tot) {
        //traverese through the v1 and find the elements which sum upto the target tot
        int pairs=0;
        for(auto ele:v1)
            if(tot>ele && freq.count(tot-ele))
                pairs+=freq[tot-ele];
        return pairs;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */
