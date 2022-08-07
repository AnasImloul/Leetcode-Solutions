from collections import defaultdict

class Solution:
    
    def findDuplicate(self, paths: List[str]) -> List[List[str]]:
        
        hashmap = defaultdict(lambda: [])
        
        for i in paths:
            
            path = i.split()
            directory, files = path[0], path[1:]
            
            for file in files:
                
                file = file.split('(')
                filename, content = file[0], file[1][:-1]
                
                hashmap[content].append(directory + "/" + filename)
                
        return [f for f in hashmap.values() if len(f) > 1]
