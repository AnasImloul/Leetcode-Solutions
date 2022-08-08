class Solution:
    def maximum69Number(self, num):
        lst= list(str(num)) #! convert the number to a list
        for i in range(len(lst)): #! iterate through the list
            if lst[i]=='6': #! if the element is 6
                lst[i]='9' #! replace the element with 9
                break #! break the loop
        return int(''.join(lst))  #! convert the list to a number

