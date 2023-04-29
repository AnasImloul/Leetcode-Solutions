class Solution {
public:
    int romanToInt(string s) 
    {

    int count=0,ans=0;
        
    for(int i=0; s[i]!='\0';i++)
    {
        count++;
    }
        
    int s1[count+1];
        
    for(int i=0; i<count; i++)
        {
            if(s[i]=='M')
            s1[i]=1000;
            else if(s[i]=='V')
            s1[i]=5;
            else if(s[i]=='X')
            s1[i]=10;
            else if(s[i]=='L')
            s1[i]=50;
            else if(s[i]=='C')
            s1[i]=100;
            else if(s[i]=='D')
            s1[i]=500;
            else 
            s1[i]=1;
        }  
        
    s1[count]=0;

    for(int j=0; j<=count; j++)
        {
            if (j!=count)
            {          
                 if(s1[j]>=s1[j+1])
                {
                    switch(s1[j])
                    {
                      case 1: ans = ans+1;
                      break;
                      case 5: ans = ans+5;
                      break;
                      case 10: ans = ans+10;
                      break;
                      case 50: ans = ans+50;
                      break;
                      case 100: ans = ans+100;
                      break;
                      case 500: ans = ans+500;
                      break;
                      case 1000: ans = ans+1000;
                      break;
                    }        
                }      

                 else if(s1[j]<s1[j+1])
                {
                    switch(s1[j])
                    {
                    case 1: ans = ans-1;
                    break;
                    case 5: ans = ans-5;
                    break;
                    case 10: ans = ans-10;
                    break;
                    case 50: ans = ans-50;
                    break;
                    case 100: ans = ans-100;
                    break;
                    case 500: ans = ans-500;
                    break;
                    case 1000: ans = ans-1000;
                    break;
                    }           
                }
            }

            else if(j==count)
            {
                switch(s1[j])
                {
                  case 1: ans = ans+1;
                  break;
                  case 5: ans = ans+5;
                  break;
                  case 10: ans = ans+10;
                  break;
                  case 50: ans = ans+50;
                  break;
                  case 100: ans = ans+100;
                  break;
                  case 500: ans = ans+500;
                  break;
                  case 1000: ans = ans+1000;
                  break;
                }
            }
        }

    return ans;
        
    }
};