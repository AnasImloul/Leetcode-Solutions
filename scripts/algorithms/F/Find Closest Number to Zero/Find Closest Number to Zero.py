class Solution:
    
    def findClosestNumber1(self, nums: List[int]) -> int:
        return min(nums, key=lambda x: (abs(x), -x))
    
    def findClosestNumber2(self, nums: List[int]) -> int:
        return min(nums, key=lambda x: abs(x - .1))
    
    def findClosestNumber3(self, nums: List[int]) -> int:
        return max((-abs(x), x) for x in nums)[1]
    
    def findClosestNumber4(self, nums: List[int]) -> int:
        return -min(zip(map(abs, nums), map(neg, nums)))[1]

    def findClosestNumber5(self, nums: List[int]) -> int:
        a = min(map(abs, nums))
        return a if a in nums else -a

    def findClosestNumber6(self, nums: List[int]) -> int:
        a = abs(min(nums, key=abs))
        return a if a in nums else -a

    def findClosestNumber7(self, nums: List[int]) -> int:
        x = min(nums, key=abs)
        return x if x >= 0 or -x not in nums else -x
    
    def findClosestNumber8(self, nums: List[int]) -> int:
        return min(sorted(nums, reverse=True), key=abs)
    
    def findClosestNumber9(self, nums: List[int]) -> int:        
        a = abs(nums[0])
        for x in nums:
            if x < 0:
                x = -x
            if x < a:
                a = x
        return a if a in nums else -a
        
    def findClosestNumberA(self, nums: List[int]) -> int:        
        pos = 999999
        neg = -pos
        for x in nums:
            if x < 0:
                if x > neg:
                    neg = x
            elif x < pos:
                pos = x
        return pos if pos <= -neg else neg
        
    def findClosestNumberB(self, nums: List[int]) -> int:        
        pos = 999999
        neg = -pos
        for x in nums:
            if x < pos and neg < x:
                if x < 0:
                    neg = x
                else:
                    pos = x
        return pos if pos <= -neg else neg
        
    def findClosestNumberC(self, nums: List[int]) -> int:        
        pos = 999999
        neg = -pos
        for x in nums:
            if neg < x and x < pos:
                if x < 0:
                    neg = x
                else:
                    pos = x
        return pos if pos <= -neg else neg
        
    def findClosestNumberD(self, nums: List[int]) -> int:        
        pos = 999999
        neg = -pos
        for x in nums:
            if neg < x < pos:
                if x < 0:
                    neg = x
                else:
                    pos = x
        return pos if pos <= -neg else neg
        
    def findClosestNumber(self, nums: List[int], timess=defaultdict(lambda: [0] * 10), testcase=[0]) -> int:
        name = 'findClosestNumber'
        solutions = [getattr(self, s)
                     for s in dir(self)
                     if s.startswith(name)
                     and s != name]
        expect = dummy = object()
        from time import perf_counter as time
        for i in range(10):
            shuffle(solutions)
            for solution in solutions:
                start = time()
                result = solution(nums)
                end = time()
                if expect is dummy:
                    expect = result
                assert result == expect
                timess[solution.__name__][i] += end - start
        testcase[0] += 1
        if testcase[0] == 224:
            for name, times in sorted(timess.items(), key=lambda nt: sorted(nt[1])):
                print(name, *(f'{t*1e3:6.2f} ms' for t in sorted(times)[:3]))
            return
        return result
		
