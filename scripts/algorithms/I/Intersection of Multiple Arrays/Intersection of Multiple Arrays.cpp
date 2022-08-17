class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        int n = nums.size(); // gives the no. of rows
        map<int,int> mp; // we don't need unordered_map because we need the elements to be in sorted format.
        vector<int> vec;
        
        // traverse through the 2D array and store the frequency of each element
        for(int row=0;row<n;row++)
        {
            for(int col=0;col<nums[row].size();col++)
            {
                mp[nums[row][col]]++;
            }
        }
        
        // In the 2D array, intersection occurs when the elements are present in every row.
        // So the frequency of the element should match with the no. or rows in the 2D array.
        for(auto element : mp)
            if(element.second == n)
                vec.push_back(element.first);
        
        // return the intersecting elements
        return vec;
    }
};
