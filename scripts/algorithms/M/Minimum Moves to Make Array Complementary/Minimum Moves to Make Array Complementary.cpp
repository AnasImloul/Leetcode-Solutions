// Runtime: 367 ms (Top 23.53%) | Memory: 89 MB (Top 32.94%)
class Solution {
public:
  int minMoves(vector<int>& nums, int limit) {
    vector<int>table(limit + limit + 2, 0);

    for(int i = 0, j = nums.size()-1; i < j; i++, j--){
      if(nums[i] > nums[j]) swap(nums[i], nums[j]);
      table[nums[i]+1]--, table[nums[j]+1+limit]++;
    }

    int sum = nums.size();
    for(int i = 0; i != table.size(); i++)
      table[i] = sum += table[i];

    for(int i = 0, j = nums.size()-1; i < j; i++, j--)
      table[nums[i] + nums[j]]--;

    return *min_element(table.begin(), table.end());
  }
};