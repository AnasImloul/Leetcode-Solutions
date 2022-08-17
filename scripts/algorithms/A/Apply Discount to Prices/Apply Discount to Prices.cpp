class Solution {
public:
    string discountPrices(string sentence, int discount) {
        
		// doit is a function
        auto doit = [&](string word) {
		
            int n(size(word));
            if (word[0] != '$' or n == 1)   return word;
            
            long long price = 0;
            for (int i=1; i<n; i++) {
                if (!isdigit(word[i]))  return word;
                price = price*10 + (word[i]-'0');
            }
            
			stringstream ss2;
            double discountPercentage = (100 - discount) / 100.0;
            ss2 << fixed << setprecision(2) << (discountPercentage * price);
            return "$" + ss2.str();
        };
        
        string word, res;
        stringstream ss(sentence);
        
        while (ss >> word) {
            res += doit(word)+" ";
        }
        
        res.pop_back();
        return res;
    }
};
