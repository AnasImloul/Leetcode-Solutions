// Runtime: 87 ms (Top 26.83%) | Memory: 9.5 MB (Top 93.67%)
class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        for(int i=0;i<arr.size();i++)
        {
          if(arr[i]==0)
          {
              arr.pop_back();
              arr.insert(arr.begin()+i,0);
              i++;
          }
            }

    }
};