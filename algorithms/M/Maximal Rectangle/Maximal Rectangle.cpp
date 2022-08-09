class Solution {
private:
    vector<int> nextSmallerElement(int *arr , int n){
        stack<int> st;
        st.push(-1);
        vector<int> ans(n);
        
        for(int i = n - 1 ; i >= 0 ; i--){
            int curr = arr[i];
            
            while(st.top() != -1 && arr[st.top()] >= curr){
                st.pop();
            }
            
            ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }
    
    vector<int> prevSmallerElement(int *arr , int n){
        stack<int> st;
        st.push(-1);
        vector<int> ans(n);
        
        for(int i = 0; i < n ; i++){
            int curr = arr[i];
            
            while(st.top() != -1 && arr[st.top()] >= curr){
                st.pop();
            }
            
            ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }
    
    int largestRectangleArea(int * heights , int n){
        int area = INT_MIN;
        
        vector<int> next(n);
        next = nextSmallerElement(heights , n);
        
        vector<int> prev(n);
        prev = prevSmallerElement(heights , n);
        
        for(int i = 0 ; i < n ; i++){
            int length = heights[i];
            
            if(next[i] == -1)
                next[i] = n;
            
            int breadth = next[i] - prev[i] - 1;
            int newArea = length * breadth;
            area = max(area , newArea);
        }
        return area;
    }
    
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        
        int n = matrix.size();
        int m = matrix[0].size();
        int M[n][m];
        
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                M[i][j] = matrix[i][j] - '0';
            }
        }
                
        //step 1 : compute area of 1st row
        int area = largestRectangleArea(M[0] , m);
        
        for(int i = 1 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                
        //step 2 : add upar wala element if it is 1
                if(M[i][j] != 0)
                    M[i][j] = M[i][j] + M[i-1][j];
                    
                else
                    M[i][j] = 0;
            }
            
            area = max(area , largestRectangleArea(M[i] , m));
        }
        return area;
    }
};
