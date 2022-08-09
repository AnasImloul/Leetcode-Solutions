class Solution:
def f_fcn(self,restaurants, veganFriendly, maxPrice, maxDistance):
	f_lst = filter(lambda x: (veganFriendly == 1 and x[2] == 1 and x[3] <= maxPrice and x[4] <= maxDistance) or
				   (veganFriendly == 0 and x[3] <= maxPrice and x[4] <= maxDistance), restaurants)
	return f_lst

def h_fcn(self,lst):
	return([lst[0], lst[1]])

def filterRestaurants(self, restaurants: List[List[int]], veganFriendly: int, maxPrice: int, maxDistance: int) -> List[int]:

	res = map(self.h_fcn, self.f_fcn(restaurants, veganFriendly, maxPrice, maxDistance))


	return map(lambda x: x[0], sorted(res, key=lambda x: (-x[1], -x[0])))
