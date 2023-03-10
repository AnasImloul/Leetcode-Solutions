class Solution:
    def kidsWithCandies(self, candy, extra):
        #create an array(res) with all values as True and it's lenght is same as candies
        res = [True]*len(candy)
        #iterate over the elements in the array candy
        for i in range(len(candy)):
            #if the no. of canides at curr position + extra is greater than or equal to the maximum of candies then continue 
            if (candy[i] + extra) >= max(candy):
                continue
            #if not 
            else:
                #change the value of that position in res as false
                res[i] = False
        #return the res list
        return res   