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