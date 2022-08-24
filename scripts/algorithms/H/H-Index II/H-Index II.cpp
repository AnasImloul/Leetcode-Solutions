// Runtime: 23 ms (Top 74.27%) | Memory: 18.7 MB (Top 49.37%)
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int start = 0 , end = citations.size()-1;
        int n = citations.size();
        while(start <= end){
            int mid = start + (end - start) / 2;
            int val = citations[mid];
            if(val == (n - mid)) return citations[mid];
            else if(val < n - mid){
                start = mid + 1;
            }
            else{
                end = mid - 1;
            }
        }
        return n - start;
    }
};