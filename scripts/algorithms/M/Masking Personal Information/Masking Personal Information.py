class Solution:
    def maskPII(self, s: str) -> str:
        res=''
        if '@' in s:
            
            l=s.split('@')
            
            a=l[0]
            b=l[1]
            
            c=b.split('.')
            
            
            res=a[0].lower()+'*'*5+a[-1].lower()+'@'+c[0].lower()+'.'+c[1].lower()
            return res
        else:
            l=0
            res=''
            flag=False
            f=False
            c=0
            for i in range(len(s)-1,-1,-1):
                if s[i]=="(" or s[i]==')' or s[i]=='-' or s[i]=='+' or s[i]==' ':
                    continue
                  
                if f==True:
                    c+=1
                    continue
                
                if flag==False:
                    res=s[i]+res
                else:
                    res='*'+res
                    
                
                
                if l==3 or l==6:
                    if l==3:
                        flag=True
                    res='-'+res
                l+=1
                
                if len(res)==12:
                    f=True
            if c==1:
                res='+*-'+res
            elif c==2:
                res="+**-"+res
            elif c==3:
                res="+***-"+res
                    
           
            return res
            
                    
                    
                    
                    
        
