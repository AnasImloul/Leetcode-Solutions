class Solution {
public:
  bool func(int N, int n, vector<int>& quantities){
    int temp = 0;
    for(int id = 0; temp <= n && id != quantities.size(); id++)
      temp += quantities[id] / N + (quantities[id] % N ? 1 : 0);
    
    return temp <= n;
  }
  
  int minimizedMaximum(int n, vector<int>& quantities) {
    int l = 1, r = *max_element(quantities.begin(), quantities.end());
    
    for(int m = (l + r)>>1; l <= r; m = (l + r)>>1) 
      func(m, n , quantities) ? r = m - 1 : l = m + 1; 
    
    return l;
  }
};
