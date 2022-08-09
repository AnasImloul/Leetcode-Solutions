 class Solution:
    def validateBinaryTreeNodes(self, n: int, leftChild: List[int], rightChild: List[int]) -> bool:
        
        left_set=set(leftChild)
        right_set=set(rightChild) 

        que=[]

        for i in range(n):
            if i not in left_set and i not in right_set:
                que.append(i)
        
        if len(que)>1 or len(que)==0:
            return False
        
        
        graph=defaultdict(list)

        for i in range(n):
            graph[i]=[]

            if leftChild[i]!=-1:
                graph[i].append(leftChild[i])

            if rightChild[i]!=-1:
                graph[i].append(rightChild[i])
        
        visited=set()
        visited.add(que[0])
        
        
        while len(que)>0:
            item=que.pop(0)
            

            children=graph[item]

            for child in children:
                if child not in visited:
                    que.append(child)
                    visited.add(child)
                else:
                    return False


        for i in range(n):
            if i not in visited:
                return False

        return True
