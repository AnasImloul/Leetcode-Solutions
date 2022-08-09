class Solution {
public:
    string fractionAddition(string expression) {
        
        int res_num = 0; //keep track of numerator
        int res_denom = 1; //keep track of denominator
        char sign = '+'; //keep track of sign
		
        for(int i = 0; i < expression.size(); i++){ //parse the expression string
            int next_num = 0;
            int next_denom = 0;
            if(expression[i] == '+' || expression[i] == '-') //updating
                sign = expression[i];
            else{
                int j = i+1;
                while(j < expression.size() && expression[j] != '/') j++; build next numerator
                next_num = stoi(expression.substr(i, j-i));
                int k = j+1;
                while(k < expression.size() && expression[k] >= '0' && expression[k] <= '9') k++; //build next denominator
                next_denom = stoi(expression.substr(j+1, k-(j+1)));
                if(res_denom != next_denom){ //update result numerator and denominator
                    res_num *= next_denom;
                    next_num *= res_denom;
                    res_denom *= next_denom;
                    }
                if(sign == '+') res_num += next_num;
                else res_num -= next_num;
                i = k-1;
            }
        }
        return lowestFraction(res_num, res_denom); //put the fraction into lowest terms and return as string
    }
    
private:
    int findGCD(int a, int b) { //find Greatest Common Denominator
        if(b == 0) return a;
        return findGCD(b, a % b);
   }
    
   string lowestFraction(int num, int denom){ //use GCD to put fraction into lowest terms and return as string
      int gcd;
      gcd = findGCD(num, denom);
      num /= gcd;
      denom /= gcd;
       if(denom < 0){
           denom *= -1;
           num *= -1;
       }
      return to_string(num) + '/' + to_string(denom);
}
    
};
