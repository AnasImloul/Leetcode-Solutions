// Runtime: 2 ms (Top 56.5%) | Memory: 8.00 MB (Top 77.08%)

class SummaryRanges {
public:
 
  SummaryRanges() {
        
  }
    
  void addNum(int val) {
    data_given.insert(val);
  }
    
  vector<vector<int>> getIntervals() {
      vector<vector<int>> res;
      int start = -1;
      int end = -1;
      for ( auto  &item: data_given) {
          if (start == -1) {
              start = item;
              end = item;
          } else if (item == end + 1) {
              end = item;
          } else {
              res.push_back({start, end});
              start = end = item;
          }
      }
      
      if (start != -1) res.push_back({start, end});
      
      return res;
  }
private:
  set<int> data_given;
};

