class Solution {
public:
    string abbreviateProduct(int left, int right) {
        int highest = 0, trailing = 0; 
        long prefix = 1, suffix = 1; 
        
        for (int x = left; x <= right; ++x) {
            prefix *= x; 
            suffix *= x; 
            for (; prefix >= 1e12; ++highest, prefix /= 10); 
            for (; suffix % 10 == 0; ++trailing, suffix /= 10); 
            if (suffix >= 1e10) suffix %= 10'000'000'000; 
        }
        
        for (; prefix >= 1e5; ++highest, prefix /= 10); 
        highest += log10(prefix); 
        if (highest - trailing < 10) return to_string(suffix) + "e" + to_string(trailing); 
        suffix %= 100'000; 
        return to_string(prefix) + "..." + string(5-to_string(suffix).size(), '0') + to_string(suffix) + "e" + to_string(trailing); 
    }
};
