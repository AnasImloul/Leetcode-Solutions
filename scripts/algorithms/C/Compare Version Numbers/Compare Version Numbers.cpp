class Solution {
public:
    int compareVersion(string v1, string v2) {
        int ans = 0;
        int n1 = v1.size(), n2 = v2.size();
        
        for(int i=0,j=0; i<n1 || j<n2; ++i, ++j) {
            
            string s1 = "", s2 = "";

            while(i<n1 && v1[i] != '.') {
                if(s1.size() == 0 && v1[i] == '0') {
                    ++i; continue;
                }
                
                s1 += v1[i++];
            }
            
            while(j<n2 && v2[j] != '.') {
                if(s2.size() == 0 && v2[j] == '0') {
                    ++j; continue;
                }
                
                s2 += v2[j++];
            }
            
            if(s1.size() < s2.size()) return -1;
            else if(s2.size() < s1.size()) return 1;
            
            ans = s1.compare(s2);
            if(ans < 0) return -1;
            else if(ans > 0) return 1;
        }
        
        return 0;
        
    }
};