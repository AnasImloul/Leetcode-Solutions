'''
class Solution {
public:
    string subStrHash(string s, int power, int modulo, int k, int hashValue) {
        int n=s.size();                         
        long long int sum=0;
        long long int p=1;
		// Intializing a window from end of size k 
        for(int i=0;i<k;i++){
                sum=(sum+((s[n-k+i]-'a'+1)*p));         
                if(i!=k-1)
                    p=(p*power)%modulo;
        }
		// storing the res when ever we get required answer
        int res=n-k;   // storing the res when ever we get required answer
		// slide window to right and removing ith index element and adding (i-k)th index element 
        for(int i=n-1;i>=k;i--)
		{                                          
		//removing last element from window
                sum-=(s[i]-'a'+1)*(p%modulo);               
				 // dividing by modulo to avoid integer overflow conditions
                sum=sum%modulo;                  
				 // muliplying the given string by power
                sum=sum*(power%modulo);            
				 // adding (i-k)th element in the window  
                sum+=s[i-k]-'a'+1;                 
				 // if sum < 0 then it created problem in modulus thats why making it positive
            while(sum%modulo<0){                              
                sum=sum+modulo;
            }
            if(sum%modulo==hashValue){
                res=i-k;                                           // storing the starting window index because we have to return the first string from starting 
            }
        }
        return s.substr(res,k);
    }
};
'''
