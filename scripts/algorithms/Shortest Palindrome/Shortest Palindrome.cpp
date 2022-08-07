class Solution {
public:
    string shortestPalindrome(string s) {
        
        int BASE = 26, MOD = 1e9+7;
        int start = s.size()-1;
        
        // Calculate hash values from front and back
        long front = 0, back = 0;
        long power = 1;
        
        for(int i=0; i<s.size(); i++){
            front = (front*BASE + (s[i]-'a'+1))%MOD;
            back = (back*BASE + (s[start--]-'a'+1))%MOD;
            power = (power*BASE)%MOD;
        }
        
        // If hash values of both front and back are same, then it is a palindrome
        if(front == back){
            return s;
        }
        
        // As it is not palindrome, add last characters in the beginning, and then check.
        // Store the hash value of the newly added characters from front and back
        
		// new_front will be added to front to get new hash value
        // new_back will be added to back to get new hash value 
        long new_front = 0, new_back = 0;
        long new_power = 1;
		
		int end=s.size()-1;
        string ans = "";
        
        while(end >= 0){
			// Taking character from ending 
            int ch = (s[end]-'a'+1);
            
            new_front = (new_front*BASE + ch*power) % MOD;
            new_back = (ch*new_power + new_back) % MOD;
            new_power = (new_power*BASE) % MOD;
            
            int final_front = (new_front + front) % MOD;
			back = (back*BASE) % MOD;
            int final_back = (new_back + back) % MOD;
                
			// Storing it in separate string
            ans += s[end];
            end--;
            
			// Both hashes are same
            if(final_front == final_back){
                break;
            }
        }
        return ans+s;
    }
};
