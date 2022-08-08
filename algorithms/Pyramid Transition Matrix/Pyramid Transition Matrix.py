class Solution(object):
    def pyramidTransition(self, bottom, allowed):
        """
        :type bottom: str
        :type allowed: List[str]
        :rtype: bool    
        """
        dic = defaultdict(list)
        for i in allowed:
            dic[(i[0], i[1])].append(i[2])
        
        res = []
        
        def dfs(arr, nxt):
            #base case second floor and check top exists
            if len(arr) == 2 and dic[(arr[0], arr[1])]:
                return True
            
            #go to the next row now
            if len(arr) == len(nxt) + 1:
                return dfs(nxt, [])

            #keep iterating the same row
            if dic[(arr[len(nxt)], arr[len(nxt) + 1])]:
                for val in dic[(arr[len(nxt)], arr[len(nxt) + 1])]:
                    if dfs(arr, nxt + [val]):
                        return True
            return False
        
        return dfs(bottom, [])
