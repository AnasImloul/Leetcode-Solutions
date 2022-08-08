class Solution {
public:
    //we can make an O(n**3) algorithm by simply iterating 3 times across the array and 
    //taking the bitwise AND. That would involve a lot of duplicate AND calculation.
    //Instead we can iterate using two counters i and j, and store the count of every 
    //bitwise AND we encounter in a hashmap. Then we will iterate the array and for every
    //value in the hashmap, if it's bitwise AND with the current element is zero, then we
    //add the number of times that AND appears in our array to our answer.
    int countTriplets(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<nums.size();j++){
                mp[nums[i]&nums[j]]++;
            }
        }
        int ans=0;
        for(int k=0;k<nums.size();k++){
            for(unordered_map<int,int>::iterator it=mp.begin();it!=mp.end();it++){
                if(!(nums[k]&it->first)){
                    ans+=it->second;
                }
            }
        }
        return ans;
    }
};