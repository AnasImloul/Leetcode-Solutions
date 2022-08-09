class Solution:
    def subdomainVisits(self, cpdomains: List[str]) -> List[str]:
        output, ans = {}, []
        for domain in cpdomains : 
            number, domain = domain.split(' ')
            sub_domain = domain.split('.')
            pair = ''
            print(sub_domain)
            for i in reversed(range(len(sub_domain))) :
                if i == len(sub_domain)-1 : 
                    pair += sub_domain[i]
                else : 
                    pair = sub_domain[i] +'.'+ pair 
                print(pair)
                
                # output.append(str(number) + ' '+pair)
                if pair not in output.keys() : 
                    output[pair] = int(number)
                else : 
                    output[pair] += int(number)
                    
        for key in output.keys() : 
            ans.append(str(output[key]) + ' '+key)
                
        return ans
