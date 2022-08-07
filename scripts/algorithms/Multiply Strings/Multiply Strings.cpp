class Solution {
    void compute(string &num, int dig, int ind, string &ans){
        int c = 0;  // carry digit..
        int i = num.size()-1;
        //  again travarsing the string in reverse
        while(i >= 0){
            int mul = dig*(num[i]-'0') + c;  // the curr digit's multiplication
            c = mul/10; // carry update..
            mul %= 10;  // mul update in  a single digit..
            if(ind >= ans.length()){    // here if the index where we'll put the value is out of bounds...
                ans.push_back('0' + mul);
            }
            else{
                //  here adding the val with the previous digit and further computing the carry...
                mul += (ans[ind] - '0');
                c += mul/10;
                mul %= 10;
                ans[ind] = ('0' + mul);
            }
            i--;
            ind++;  // increment the index where we'll put the val;
        }
        
        if(c > 0){ //   if carry is non-zero...
            ans.push_back('0' + c);
        }
        
    } 
public:
    string multiply(string num1, string num2) {
        string ans = "";    //  the string which we have to return as answer..
        if(num1 == "0" || num2 == "0") return "0";  // base case..
        int ind = 0;    // the index from which we'll add the multiplied value to the ans string
        for(int i  = num1.size()-1; i >= 0; ind++,i--){     
        // travarsing in reverse dir. on num1 and increasing ind bcz for every digit
        //  of num1 we'll add the multiplication in a index greater than the previous iteration
            int dig = num1[i]-'0';  // the digit with which we'll multiply by num2..
            compute(num2, dig, ind, ans);   // function call for every digit and num2
        }
//   we have calculated the ans in a reverse way such that we can easily add a leading digit & now reversing it...
        reverse(ans.begin(), ans.end());    
        return ans;
    }
};