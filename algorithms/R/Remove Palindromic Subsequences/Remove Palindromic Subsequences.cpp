  //the major obersavation or we can also verify by giving your own test it always returns 1 or 2 
    //if the whole string is palindrom then return 1 if not then return 2.
class Solution {
   static bool isPal(string s){
        string p = s;
        reverse(p.begin() , p.end());
       return s==p;     
    }
public:
    int removePalindromeSub(string s) {
  
        if(isPal(s)){
            return 1;
        } 
        
        return 2;
    }
};
