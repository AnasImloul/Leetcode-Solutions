class Solution {
public:
    int romanToInt(string s) {
    int s_len = s.length();
    int * s_arr = new int[s_len];
    for(int i = 0; i < s_len; i++)
    {
        switch(s[i])
        {
            case'I':
                s_arr[i] = 1; break;
                
            case'V':
                s_arr[i] = 5; break;
                
            case'X':
                s_arr[i] = 10; break;
            
            case'L':
                s_arr[i] = 50; break;
                
            case'C':
                s_arr[i] = 100; break;
                
            case'D':
                s_arr[i] = 500; break;
                
            case'M':
                s_arr[i] = 1000; break;
        }
    }
    
    int val = 0;
    val += s_arr[0];
    for(int i = 1; i < s_len; i++)
    {
        if(s_arr[i-1] < s_arr[i]) // e.g. IV
        {
            val += s_arr[i]; // we add V(5) and;
            val -= s_arr[i-1] * 2; // substract two I(1) because we had added it before
        }
        else
        {
            val += s_arr[i];
        }
    }
	return val;   
    }
};    
