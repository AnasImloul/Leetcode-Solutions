#define pp pair< int , char > 

class Solution {
public:
    string removeDuplicates(string s, int k) {
        
        int n=s.size();
        
        stack< pp > stk;
        
        int i=0;
        
        while(i<n)
        {
            int count=1;
            
            char ch=s[i];
            
            while((i+1)<n && s[i]==s[i+1])
            {
                i++;
                count++;
            }
         
            int c=0;
            
            if(!stk.empty() && stk.top().second==ch)
            {
                c+=stk.top().first;
                stk.pop();
            }
            
            count+=c;
            
            count=count%k;
            
            if(count!=0)
            {
                stk.push({count , ch});
            }
            
            i++;
            
            
        }
        
        string str="";
        
        while(!stk.empty())
        {
            int count=stk.top().first;
            
            while(count--)
            {
                str.push_back(stk.top().second);
            }
            
            stk.pop();
        }
        
        reverse(str.begin() , str.end());
        
        return str;
        
    }
};