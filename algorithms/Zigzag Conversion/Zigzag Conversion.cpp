class Solution {
public:
    string convert(string s, int numRows) {
        
        /*The logic that we apply here is that, we arre going to use vector to create the required pattern. 
        A vector whose number of rows shall be defined and we shall follow the required pattern. 
        The logic that I applied sometimes ges indexOutOfBounds for numRows = 2 and 1.
        So, I have dealt with them seperately.*/
        
        if (numRows == 1)
        /*When numRows == 1, the same string is needed.*/
            return s;
        
        if (numRows == 2)
        /*When numRows == 2, the alternate charatcers go in each row.*/
        {
            string ret = "";
            int i = 0;
            
            for (i = 0;i < s.length(); i+=2)
            {
                ret+= s[i];
            }
            
            for (i = 1; i < s.length(); i+=2)
            {
                ret+= s[i];
            }
            
            return ret;
        }
        
        vector <vector <char>> ans;
        ans.resize (numRows);
        
        string ret = "";
        
        int x = 0;
        bool cond = true;
        /*When cond == true, that means we are going downwards for every next row.
        When it is false, we have to start moving upwards.*/
        
        for (int i = 0; i < s.length(); i++)
        {
            char ch = s[i];
            
            ans [x].push_back (ch);
            
            if (cond)
            {
                x++;
            }
            
            if (x == numRows)
            {
                cond = false;
                x--;
            }
            
            if (!cond)
            {
                x--;
            }
            
            if (x < 0)
            {
                cond = true;
                x++;
                x++;
            }
        }
        
        for (int i = 0; i < numRows; i++)
        {
            for (int j = 0; j < ans [i].size(); j++)
            {
                ret += ans [i][j];
            }                               
        }
        
        
        
        return ret;
        
    }
};
