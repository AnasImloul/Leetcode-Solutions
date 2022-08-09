class Solution:
    def strWithout3a3b(self, a: int, b: int) -> str:
        if a<3 and b<3:
            return 'a'*a+'b'*b
        s=''
        if a>=b:
            k=a//b
            
            if a//b!=a/b:
              
                k+=1
            if k>=3:
                k=2
            while a>0 or b>0:
               
                if a>k:
                    s+='a'*k  
                else:
                    s+='a'*a
                a-=k
                if b>0:
                    s+='b'
                b-=1
                if a==b:
                    k=1
        if a<b:
            k=b//a
            if b//a!=b/a:
               
                k+=1
            if k>=3:
                k=2
            while b>0 or a>0:
                
                if b>k:
                    s+='b'*k  
                else:
                    s+='b'*b
                b-=k
                if a>0:
                    s+='a'
                a-=1
                if a==b:
                    k=1
        return s
