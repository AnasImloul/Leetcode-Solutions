class Solution {
public:
  unordered_map<int,int>table;
  int y, x;
  
  Solution(int m, int n) {
    y = m, x = n;      
  }
    
  vector<int> flip() {
    int Y = rand() % y, X = rand() % x, id;
    
    while(table. count(id = (Y << 14) + X )){
      if(++X == x) X = 0, Y++;
      if(Y == y) Y = 0;
    } 
    
    table[id] = 1;
    return {Y, X};    
  }
    
  void reset() {
    table.clear();   
  }
};
