from heapq import heapify, heappop, heappush

class RatedFood:
    def __init__(self, rating, food):
        self.rating = rating
        self.food = food
        
    def __lt__(self, other):
        if other.rating == self.rating:
            return self.food < other.food
        return self.rating < other.rating

class FoodRatings:
    def __init__(self, foods: List[str], cuisines: List[str], ratings: List[int]):
        self.cuis_to_score_heap = defaultdict(list)
        self.food_to_latest_ratings = defaultdict(int)
        self.food_to_cuis = defaultdict(str)
        
        for food, cuis, rating in zip(foods, cuisines, ratings):
            self.food_to_cuis[food] = cuis
            self.food_to_latest_ratings[food] = rating
            heappush(self.cuis_to_score_heap[cuis], RatedFood(-rating, food))
        
        

    def changeRating(self, food: str, newRating: int) -> None:
        self.food_to_latest_ratings[food] = newRating
        cuis = self.food_to_cuis[food]
        heappush(self.cuis_to_score_heap[cuis], RatedFood(-newRating, food))
        

    def highestRated(self, cuisine: str) -> str:
        while True:
            ratedFood = heappop(self.cuis_to_score_heap[cuisine])
            if self.food_to_latest_ratings[ratedFood.food] == (-ratedFood.rating):
			
				# because the food item is still valid, we put it back into the heap
                heappush(self.cuis_to_score_heap[cuisine], ratedFood)
				
                return ratedFood.food
