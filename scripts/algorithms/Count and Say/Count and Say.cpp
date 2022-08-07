class Solution {
public:
    string countAndSay(int n) {
        
        // start with base case

        string prev = "1";
        
        int k = 1;
        
        while(k < n)
        {
            string curr = "";
            
            int i = 0;
            
            while(i < prev.size())
            {
                int count = 1;
                
                char ch = prev[i];
                
                // count the consecutive characters
                
                while(i < prev.size() - 1 && prev[i] == prev[i + 1])
                {
                    count++;
                    
                    i++;
                }
                
                // update the curr
                
                curr += to_string(count);
                
                curr += ch;
                
                i++;
            }
            
            // update the prev as curr and increment k
            
            prev = curr;
            
            k++;
        }
        
        return prev;
    }
};
