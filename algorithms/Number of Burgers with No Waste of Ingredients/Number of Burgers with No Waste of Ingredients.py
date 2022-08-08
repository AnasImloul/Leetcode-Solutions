class Solution(object):
    def numOfBurgers(self, t, c):
        
        if t==c==0:
            return [0,0]
        four=(t-2*c)//2  # no of jumbo burgers by solving 4x+2y=t and x+y=c
        two=c-four #number of small burgers
        if c>=t or (t-2*c)%2==1 or four<0 or two<0: #if cheese is less than tomatoes or if number of jumbo burgers is a decimal or number of burgers are negtive we return empty list
            return []
        
        return [four,two]
        
