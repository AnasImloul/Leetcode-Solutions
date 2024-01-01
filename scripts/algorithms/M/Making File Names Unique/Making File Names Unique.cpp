// Runtime: 126 ms (Top 73.02%) | Memory: 66.40 MB (Top 12.7%)

class Solution {
public:
    vector<string> getFolderNames(vector<string>& names) {
        
        // You can understand the code by seeing explanation below
        
        unordered_map<string, int> mp;
        vector<string> res;
        
        for(auto i : names){
            string val = i;
            int cnt = mp[val];
            
            while(mp[val] != 0){
                val = i + '(' + to_string(cnt) + ')';
				cnt++;
                mp[i] = cnt;
				   
            }
            mp[val]++;
            res.emplace_back(val);
        }
        return res;
        
        
        
        // For better Understanding Code explained Line by line
        
        // names = ["d", "d(1)", "d(2)", "d"]
        
        
        // running for loop
        // val = "d";
        // cnt = mp[val] = mp["d"] = 0;
        // mp[val] = 0, so while loop not executed
        // mp[val]++ -> mp["d"] = 0+1 = 1;
        // res = ["d"]
        
        // Same for "d(1)"
        // mp["d(1)"] = 0+1 = 1;
        // res = ["d", "d(1)"]
        
        // Same for "d(2)"
        // mp["d(2)"] = 0+1 = 1;
        // res = ["d", "d(1)", "d(2)"]
        
        // now, i = "d", val = "d";
        // cnt = mp[val] = mp["d"] = 1, (appeared before)
        // while loop executed bcoz mp[val] = 1 which is greater than 0
        // In while loop,
        // cnt = 1+1 = 2;
        // val = i + '(' + to_string(cnt) + ')' = "d(2)"
        // mp[i] = mp["d"] = cnt = 2;
        
        // now mp[val] = mp["d(2)"] = 1, (appeared before)
        // while loop executed bcoz mp[val] = 1 which is greater than 0
        // In while loop,
        // cnt = 2+1 = 3;
        // val = i + '(' + to_string(cnt) + ')' = "d(3)"
        // mp[i] = mp["d"] = cnt = 3;
        
        // now mp[val] = mp["d(3)"] = 0
        // while loop closed
        // mp[val]++ = mp["d(3)"] = 0+1 = 1;
        // res = ["d", "d(1)", "d(2)", "d(3)"]
        
        // now, return res;
    }
};
