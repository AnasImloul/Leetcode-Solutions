def greedy(k,a):
    
    def do_stuff(x,y,i,j,l):
        if a[j]==x: #check previous obstacle and change lane
            return y
        elif a[j]==y:
            return x
        else:
            while i<n and (a[i+1]==0 or a[i+1]==l):#to avoid 0s and same lane duplicates
                i+=1
            if i==n:
                return -1
            if a[i+1]==x: #check the next coming obstacle
                return y
            elif a[i+1]==y:
                return x
    n=k-1
    ans=0
    
    l=2 #current lane
    
    i=0
    while i<n:
        if l==a[i+1]: #when we encounter next obstacle
            j=i #stored for checking before obstacle
            while i<n and l==a[i+1]: #avoiding same lane duplicates
                i+=1
            ans+=1
            if i==n:
                break

            if l==2: #deciding which lane to shift next
                l = do_stuff(1,3,i,j,l)
            elif l==1:
                l = do_stuff(2,3,i,j,l)
            else:
                l= do_stuff(1,2,i,j,l)
            
            if l==-1: #case when i==n hits
                    break
                
            if i>0: #edge case
                i-=1
        i+=1
    return ans

class Solution:
    def minSideJumps(self, obstacles: List[int]) -> int:
        return greedy(len(obstacles),obstacles)
