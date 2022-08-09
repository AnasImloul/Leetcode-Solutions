class Solution:
    def findCenter(self, edges: List[List[int]]) -> int:
        
        """ From the Constraints: A valid STAR GRAPH is confirmed. 
		That means the center will be common to every edges. 
		Therefore we can get the center by comparing only first 2 elements"""
        
        for i in range (1):
            
            # Check if first element of first edge mathches with any element of second edges
            
            if edges[i][0] == edges [i+1][0] or edges[i][0] == edges[i+1][1]:
                return edges[i][0]
            
            #Otherwise second element of first edge will be the answer
            else:
                return edges[i][1]
