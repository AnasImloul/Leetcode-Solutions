class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
      long long n = beans.size();
      sort(beans.begin(), beans.end());
      long long sum = 0;
            for(int i=0; i<n; i++)
            {
                    sum += beans[i];
            }
       long long ans = sum;
       for(int i=0; i<n; i++)
       {
            long long curr = sum - (n-i)*beans[i];
            if(ans > curr)
            ans = curr;
       }
      return ans;      
    }    
};
