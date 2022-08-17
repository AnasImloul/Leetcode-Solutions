class Solution {
public:
  
  int helper(string& num, int idx, string last){
    // If we have made it to the end of num we have found a valid sequence
    if(num.size() == idx){ return 1; }
    // The number of valid sequences starting from idx
    int count = 0;
    // If num[idx] == '0' then skip
    if(num[idx] != '0'){
      // Check all the possible numbers starting from idx
      for(int i=idx; i<num.size(); ++i){
        // Construct the number
        string s = num.substr(idx, i-idx+1);
        // If the number has less digits then the last number in the sequence it can't be bigger
        if(s.size() < last.size()){ continue; }
        // If the number is bigger or equal than the last (needs the size check as "3" > "20")
        if(last.size() < s.size() || s >= last){
		  // Do the recursice call  with idx = i+1 and last=s 
          count += helper(num, i+1, s);
        }
      }
    }
    return count;
  }
  
  int numberOfCombinations(string num) {
    return helper(num, 0, "0");
  }
};
