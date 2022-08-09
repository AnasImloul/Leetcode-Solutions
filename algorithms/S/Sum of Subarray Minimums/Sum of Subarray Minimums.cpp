class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        
        int n = arr.size();
        
        long long mod = 1e9 + 7;
        
        vector<int> left_smaller(n, -1);
        
        vector<int> right_smaller(n, n);
        
        stack<int> st;
        
        // fill left_smaller array
        
        // find next smaller element on left side
        
        for(int i = 0; i < n; i++)
        {
            // remove the index with greater element than arr[i]
            
            while(!st.empty() && arr[st.top()] >= arr[i])
            {
                st.pop();
            }
          
            // if stack is empty
           
            if(st.empty())
            {
                left_smaller[i] = -1;
            }
            else
            {
                left_smaller[i] = st.top();
            }
            
            // push the current index into stack
            
            st.push(i);
        }
        
        while(!st.empty())
        {
            st.pop();
        }
        
        // fill the right_smaller array
        
        // find the next smaller element on right side
        
        for(int i = n - 1; i >= 0; i--)
        {
            // remove the index with greater element than arr[i]
            
            while(!st.empty() && arr[st.top()] > arr[i])
            {
                st.pop();
            }
            
            // if stack is empty
            
            if(st.empty())
            {
                right_smaller[i] = n;
            }
            else
            {
                right_smaller[i] = st.top();
            }
            
            // push the current index into stack
            
            st.push(i);
        }
        
        // calculate the sum
        
        long long sum = 0;
        
        for(int i = 0; i < n; i++)
        {
            // sum of total subarrays which has arr[i] as smallest element
            
            long long curr = ((right_smaller[i] - i) % mod * (i - left_smaller[i]) % mod * arr[i] % mod) % mod;
            
            // update the sum
            
            sum = (sum % mod + curr % mod) % mod;
        }
        
        return sum;
    }
};
