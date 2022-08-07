class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        dict1={}
        m=""
		#creating a dictionary by mapping each element from string S to string T
        for i,j in zip(s,t):
		# this for the cases like "badc" and "baba" so we dont want two keys mapping to same value hence we can reject directly
            if j in dict1.values() and i not in dict1.keys():
                return False
            dict1[i]=j          
        
		#now take each letter from string s and using dictionary values replace it with that specific character
        for k in s:
            m=m+dict1[k]
			
		#now if newly formed string m == T is same then the strings are Isomorphic
        if(m==t):
            return True
        else:
            return False
