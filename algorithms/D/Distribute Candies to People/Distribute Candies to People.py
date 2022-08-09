class Solution:
    def distributeCandies(self, candies: int, num_people: int) -> List[int]:
        candy_dict = {}
        for i in range(num_people) : 
            candy_dict[i] = 0 
        
        candy, i, totalCandy = 1, 0, 0
        while totalCandy < candies : 
            if i >= num_people : 
                i = 0
            if candies - totalCandy >= candy : 
                candy_dict[i] += candy 
                totalCandy += candy
            else : 
                candy_dict[i] += candies - totalCandy
                totalCandy += candies - totalCandy
            i += 1 
            candy += 1  
        return candy_dict.values()
