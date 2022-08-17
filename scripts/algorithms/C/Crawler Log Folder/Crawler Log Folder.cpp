//1.using stack
class Solution {
public:
    int minOperations(vector<string>& logs) {
	
        if(logs.size()==0) return 0;
		
        stack<string> st;
        for(auto x: logs){
            if (x[0] != '.')  //Move to the child folder so add children
                st.push(x);
            else if(x=="../"){ // Move to the parent folder of the current folder so pop
                 if(!st.empty())  st.pop(); 
                 else continue; //don’t move the pointer beyond the main folder.
            }
        }
        return st.size();
    }
};
//2.
class Solution {
public:
    int minOperations(vector<string>& logs) {
         int ans = 0;
        for (string log : logs) {
            if (log == "../") { // go deeper
                ans--; 
                ans = max(ans, 0);
            } else if (log != "./") // one level up
			   ans++; 
        }
        return ans;
    }
};
//3.
class Solution {
public:
    int minOperations(vector<string>& logs) {
        int res = 0;
        for (string s : logs) {
            if (s=="../") res = max(0, --res);
            else if (s=="./") continue;
            else res++;
        }
        return res;
    }
};
