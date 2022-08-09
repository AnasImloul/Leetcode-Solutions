class Solution:
    def distinctNames(self, ideas: List[str]) -> int:
        
        names=defaultdict(set)
        res=0  
        
        #to store first letter as key and followed suffix as val
        for i in ideas:
            names[i[0]].add(i[1:])
            
        #list of distinct first-letters available in ideas (may or may not contain all alphabets,depends upon elements in ideas)
        arr=list(names.keys())
        ans,n=0,len(arr)
        
        for i in range(n):
            for j in range(i+1,n):
                #a,b => 2 distinct first letters
                a,b=arr[i],arr[j]
                # adding the number of distinct posssible suffixes and multiplying by 2 as the new word formed might be "newword1 newword2" or "newword2 newword1"
                res+=len(names[a]-names[b])*len(names[b]-names[a])*2
                
        return res
	
