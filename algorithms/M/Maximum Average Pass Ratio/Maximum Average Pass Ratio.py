class Solution:
	def maxAverageRatio(self, classes: List[List[int]], extraStudents: int) -> float:
		
		n = len(classes)
		
		impacts = [0]*n
		minRatioIndex = 0
		
		# calculate and store impacts for each class in form of tuples -> (-impactValue, passCount, totalCount)
		for i in range(n):
			passCount = classes[i][0]
			totalCount = classes[i][1]
			
			# calculate the impact  for class i
			currentRatio = passCount/totalCount
			expectedRatioAfterUpdate = (passCount+1)/(totalCount+1)
			impact = expectedRatioAfterUpdate - currentRatio
			
			impacts[i] = (-impact, passCount, totalCount)  # note the - sign for impact
			
		heapq.heapify(impacts)
		
		while(extraStudents > 0):
			# pick the next class with greatest impact 
			_, passCount, totalCount = heapq.heappop(impacts)
			
			# assign a student to the class
			passCount+=1
			totalCount+=1
			
			# calculate the updated impact  for current class
			currentRatio = passCount/totalCount
			expectedRatioAfterUpdate = (passCount+1)/(totalCount+1)
			impact = expectedRatioAfterUpdate - currentRatio
			
			# insert updated impact back into the heap
			heapq.heappush(impacts, (-impact, passCount, totalCount))
			extraStudents -= 1
		
		result = 0
			
		# for all the updated classes calculate the total passRatio 
		for _, passCount, totalCount in impacts:
			result += passCount/totalCount
			
		# return the average pass ratio
		return result/n
