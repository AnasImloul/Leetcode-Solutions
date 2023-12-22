// Runtime: 252 ms (Top 67.16%) | Memory: 107.00 MB (Top 74.59%)

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countDistinctIntegers(vector<int>& nums) {
		// unordered_set constructor to insert all elements in a vector
		// Note :- unordered_set only maintains unique values in it 
        unordered_set<int> s(nums.begin() , nums.end());
		// for every num find its reverse
        for(auto i : nums){
            int num = 0;
            while(i){
                int rem = i % 10;
                num = num * 10 + rem;
                i /= 10;
            }
			// insert the reverse
                s.insert(num);
        }
		// since every element in unordered_set is unique the size of it itself is answer
        return s.size();
    }
};
