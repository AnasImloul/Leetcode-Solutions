class Solution {
public: 
    pair<int,int> seprateRealAndImg(string &s){
        int i = 0;
        string real,img;
        while(s[i] != '+') real += s[i++];
        while(s[++i] != 'i') img += s[i];
        
        return {stoi(real),stoi(img)};
    }
    string complexNumberMultiply(string num1, string num2) {
        pair<int,int> x = seprateRealAndImg(num1);
        pair<int,int> y = seprateRealAndImg(num2);
        
        int a1 = x.first,b1 = x.second;
        int a2 = y.first,b2 = y.second;
        
        int real = (a1 * a2) - (b1*b2);
        int img = (b1*a2) + (a1 * b2);
        
        return to_string(real) + "+" + to_string(img) + "i";
    }
};
