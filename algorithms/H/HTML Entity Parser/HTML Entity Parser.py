class Solution:
    def entityParser(self, text: str) -> str:
        d = {"&quot;" : '"' , "&apos;":"'" , "&amp;" : "&" , "&gt;" : ">" , "&lt;":"<" , "&frasl;" : "/"}
        
        
        
        ans = ""
        i = 0
        while i < len(text):
            bag = ""
            
            #condition if find & and next char is not & also and handdling index out of range for i + 1
            if i+1 < len(text) and text[i] == "&" and text[i+1] != "&":
                
                #create subtring for speacial char till ";"
                for j in range(i , len(text)):
                    if text[j] == ";":
                        bag += text[j]
                        break
                    else:
                        bag += text[j]
                        
                #if that not present in dict we added same as it is
                if bag not in d:
                    ans += bag
                else:
                    ans += d[bag]
                    
                #increment by length of bag 
                i += len(bag)
             
            #otherwise increment by 1
            else:
                ans += text[i]
                i += 1
        return ans
        
