class Solution {
public:
    int bestClosingTime(string customers) {
        int c=0 , n=customers.length();
        vector<int> pen;  // No. of N to the left
        for(int i=0;i<n;i++)
        {
            pen.emplace_back(c);
            if(customers[i]=='N') c++;
            
        }
        int ans=n , plty=c;
        for(int i=n-1;i>=0;i--)
        {
            int aage = c - pen[i];
            aage = n-i - aage;   // Number of Y on the remaining part
            if(plty >= aage + pen[i])
            {
               plty= aage + pen[i];
                ans=i;
            }
        }
        return ans;
        
    }
};