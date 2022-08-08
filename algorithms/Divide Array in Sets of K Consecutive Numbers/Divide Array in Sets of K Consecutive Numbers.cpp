class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        if(nums.size() % k) return false;
        
        map<int, int> m;
        for(int i : nums) m[i]++;
        
        int n = m.size();
        while(n) {
            int a = m.begin() -> first;
            m[a]--;
            if(!m[a]) m.erase(a), n--;
            for(int i=1; i<k; i++) {
                if(m.find(a + i) == m.end()) return false;
                m[a + i]--;
                if(!m[a + i]) m.erase(a + i), n--;
            }
        }
        
        return true;
    }
};
