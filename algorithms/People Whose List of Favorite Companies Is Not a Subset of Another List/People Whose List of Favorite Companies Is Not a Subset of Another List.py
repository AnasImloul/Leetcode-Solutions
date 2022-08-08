class Solution:
    def peopleIndexes(self, favoriteCompanies: List[List[str]]) -> List[int]:
        
        F = favoriteCompanies
        ans = [] 
        
        seen = set() 
        
        for i in range(len(F)):
            for j in range(i+1,len(F)):
                st1 = set(F[i])
                st2 = set(F[j])
                if st1.intersection(st2) == st1: seen.add(i)
                if st2.intersection(st1) == st2: seen.add(j) 

        ans = []
        for i in range(len(F)):
            if i in seen: continue 
            ans.append(i) 
            
        return ans