class Solution {
    public String findLongestWord(String s, List<String> dictionary) {
        
        int[] fre=new int[26];
       
        
        String ans="";
        int flag=0;
        int[] fff=new int[26];
         char[] ch = s.toCharArray();
        for(char c : ch)
            fre[c-'a']+=1;
        
        for(String s1 : dictionary)
        { 
             fff=fre.clone();
             int[] fre1=new int[26];
             char[] ch1 = s1.toCharArray();
            for(char c : ch1)
            {
               
                fre1[c-'a']+=1;
            }
            
            for(char c : ch1)
            {
                if(fre1[c-'a'] <= fff[c-'a'])
                { flag=0;
                  fff[c-'a']-=1; 
                 fre1[c-'a']-=1;
                }
                else
                {flag=1;
                  break;}                
            }
            if(flag==0)
            {
                if(ans != "")
                {
                  if(ans.length() <s1.length())
                  {
                      
                      ans=s1;
                  }else
                  {
                      if(ans.length() ==s1.length())
                      {
                          int f=0;
                         for(int m=0;m<ans.length();m++)
                         {
                             if(ans.charAt(m)>s1.charAt(m))
                             {
                                 f=1;
                                 break;
                             }
                                 
                         }
                          if(f==1)
                              ans=s1;
                      }
                  }
                }
                else
                    ans =s1;
            }
            else
            {
                flag=0;
            }
        }
        
        return ans;
        
    }
}

