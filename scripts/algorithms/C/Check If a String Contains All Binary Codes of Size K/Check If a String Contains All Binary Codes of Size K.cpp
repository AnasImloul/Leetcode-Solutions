// Runtime: 183 ms (Top 88.92%) | Memory: 20.50 MB (Top 92.45%)

class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n=pow(2,k),m=s.size();
        vector<bool>check(n,0); //Check Array ,initially all value false;
        
        int val=0; //Variable that will help in formation of binary to decimal value of every substring.
        int i=0,j=0; //Sliding window ponter.
        
        while(j<m)
        {
            val=val*2+(s[j]-'0'); //Form Binary ,Make it decimal.
            
            if(j-i+1<k) //If window size is Less than k ,just j++;
                j++;
            else if(j-i+1==k) //If we hit k size.
            {
                check[val]=true; //Mark check cval true.
                val=val-(s[i]-'0')*(pow(2,k-1)); //Remove ith value's Calucaltion .
                i++; //Increment i 
                j++; //and Increment j to maintain size of window as k
            }
        }
        
        for(int l=0;l<n;l++)
        {
            if(check[l]==false) //If we didn't find any value ,means that susbtring is missing
                return false; //Return false;
        }
        
        return true; //Return true;
    }
};
