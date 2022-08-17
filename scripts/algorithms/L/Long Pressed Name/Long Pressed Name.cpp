class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        
        int j = 0, i = 0;
        for( ; i<name.length() && j<typed.length() ; i++)
        {
            if(name[i]!=typed[j++])
                return false;
            
            
            if(i<name.length() && name[i]!= name[i+1])
            {
                while(j<typed.length() && typed[j] == name[i])
                j++;
            }
        }
        
         return (i == name.length() && j == typed.length());
    }
};
