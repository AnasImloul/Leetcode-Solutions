class Solution {
public:
	//store the frequency of each of the number in the map and
	//then return the answer as sum all the values dividing 2 and 
	//sum all by taking reminder of 2
    vector<int> numberOfPairs(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(auto i: nums) mp[i]++;
        int c1 = 0, c2 = 0;
        for(auto m: mp){
            c1 += m.second/2;
            c2 += m.second%2;
        }
        return {c1, c2};
    }
};
