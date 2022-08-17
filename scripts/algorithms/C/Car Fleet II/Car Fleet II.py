class Car:
    def __init__(self, pos, speed, idx, prev=None, next=None):
        self.pos = pos
        self.speed = speed
        self.idx = idx
        self.prev = prev
        self.next = next

class Solution:
    def getCollisionTimes(self, cars: List[List[int]]) -> List[float]:
        colis_times = [-1] * len(cars)
        cars = [Car(pos, sp, i) for i, (pos, sp) in enumerate(cars)]
        for i in range(len(cars)-1): cars[i].next = cars[i+1]
        for i in range(1, len(cars)): cars[i].prev = cars[i-1]
        
        catchup_order = [((b.pos-a.pos)/(a.speed-b.speed), a.idx, a)
                        for i, (a, b) 
                        in enumerate(zip(cars, cars[1:])) if a.speed > b.speed]
        heapify(catchup_order)
        
        while catchup_order:
            catchup_time, idx, car = heappop(catchup_order)
            if colis_times[idx] > -1: continue # ith car has already caught up
            colis_times[idx] = catchup_time
            if not car.prev: continue # no car is following us
            car.prev.next, car.next.prev = car.next, car.prev
            if car.next.speed >= car.prev.speed: continue # the follower is too slow to catch up
            new_catchup_time = (car.next.pos-car.prev.pos)/(car.prev.speed-car.next.speed)
            heappush(catchup_order, (new_catchup_time, car.prev.idx, car.prev))
        
        return colis_times
