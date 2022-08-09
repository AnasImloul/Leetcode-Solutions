class Solution {
public:

    vector<int> res;
	
    void backtrack(vector<int>& ans, string s, int curr) {
        // Basic check for end
        if(curr == s.size()) {
            // if more than 3 elements in ans, BOOM, we got it!!
            if(ans.size() > 2) res = ans;
            
            //if not, purpose is not solved :( => return in both scenarios
            return;
        }
        
        // start with current index to check possible string forming next fibbo seq no
        long val = 0;    // stores possible generated numbers
        for(int i = curr; i < s.size(); ++i) {
            if(i > curr && s[curr] == '0') return;  // Handle 0 cases, 01, 02 cannot be considered
            
            val = val*10 + s[i] - '0';
            if(val > INT_MAX) return;
            
            int n = ans.size();            
            if(ans.size() < 2 || val == (long)ans[n-1]+(long)ans[n-2]) {
                // val seems to be next fibbo seq no: insert to ans & go for next seq no
                ans.push_back(val);
                backtrack(ans, s, i+1);
                
                // val seems to be failed to serve purpose: remove it from ans
                ans.pop_back();
            }
        }
    }
    
    vector<int> splitIntoFibonacci(string num) {
        vector<int> ans;        
        
        // Using recursive backtrack strating with 0
        backtrack(ans, num, 0);
        
        return res;
    }
};