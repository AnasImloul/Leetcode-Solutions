class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
		// sort the vector
		//  ["flower","flow","flight"]
		//=>["flight","flow","flower"]
        std::sort(strs.begin(), strs.end());
		// only needs to compare the first and the last element now 
		// since elements between them are sorted alphabetically 
        string first = strs.front();
        string last = strs.back();
        string ans;
        for(int i = 0; i < first.length(); i++) {
            if (first[i] != last[i] ){
                break;
            }else {
                ans += first[i];
            }
        }
        return ans;
    }
};
