class Solution {
public:
  int helper(unsigned long s, unsigned long n0, unsigned long n1, unsigned long n2, int turn){
    if(n0 == 0 && n1 == 0 && n2 == 0) return 1;
    
    int next_turn = 1^turn;
    int tmp = next_turn;
    
    if(s == 0){
      if(n1 || n2){
        if(n1)                tmp = helper(1, n0, n1-1, n2, next_turn);
        if(tmp != turn && n2) tmp = helper(2, n0, n1, n2-1, next_turn);
      }
    }
    else if(s == 1){
      if(n0 || n1){
        if(n0)                tmp = helper(1, n0-1, n1, n2, next_turn);
        if(tmp != turn && n1) tmp = helper(2, n0, n1-1, n2, next_turn);
      }
    }
    else{
      if(n0 || n2){
        if(n0)                tmp = helper(2, n0-1, n1, n2, next_turn);
        if(tmp != turn && n2) tmp = helper(1, n0, n1, n2-1, next_turn);
      }
    }
    
    return tmp;
  }
  
  
  bool stoneGameIX(vector<int>& stones) {
    int n0 = 0, n1 = 0, n2 = 0;
    
    for(auto &x: stones){
      int tmp = x % 3;
      if(tmp == 0) n0++;
      else if(tmp == 1) n1++;
    }
   
    n2 = stones.size() - n0 - n1;
    n0 = n0%2;                                      //without this small line we will have TLE and whan I wrote contest I don't consider it =(
    return helper(0, n0, n1, n2, 0) == 0;
  }
};
