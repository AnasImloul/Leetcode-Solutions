/*
1. Create a integer vector, where each integer's bits represent, if a particular char is present or not
2. Loop each word in the array and set each bit, create bit map of each word
3. Use recursion to add each word with take once and not to take once type dp recursion 
4. A word can only be taken if its bits are not overlaping with the current string's bit status
   - to do this, we need to check if there sum is equal to bit wise andding of them, 
     if eaual then there is no overlaping, if not equal then there is overlaping
5. Also we don't have to take the word which has repeted char ( if we have set it to INT_MAX )
6. Finally if i is less then 0, check the size of the s with the ans and take maximum
*/

class Solution {
public:
    int ans = 0;
    void solve(vector<int>& v, vector<string>& arr, int i, string s, int status){
        if(i < 0) { 
            ans = max(ans, (int)s.size());
        }else{
            solve(v, arr, i-1, s, status);
            if( (v[i] != INT_MAX ) && ( (v[i] + status) == (v[i] | status)) ){ 
                solve(v, arr, i-1, s+arr[i], status  | v[i]);
            }
        }
    }
    
    int maxLength(vector<string>& arr) {
        vector<int> v(arr.size());
        for(int i= 0; i < arr.size(); ++i){
            for(auto c: arr[i]) {
                if((v[i] >> (c - 'a'))& 1){ //if already bit is set, then set value to INT_MAX
                    v[i] = INT_MAX;
                }else{                      // if not set, then set it to 1
                    v[i] = v[i] | (1 << (c - 'a'));
                }
            }
        }
        string s = "";
        solve(v, arr, arr.size()-1, s, 0);
        return ans;
    }
};
