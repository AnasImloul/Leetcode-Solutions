class Solution:
	def findTheDistanceValue(self, array1: List[int], array2: List[int], d: int) -> int:

		result = 0

		array2 = sorted(array2)

		for num in array1:

			flag = True

			low = 0
			high = len(array2)-1

			while low <= high:

				mid = (low + high) // 2

				if abs(array2[mid] - num) <= d:
					flag = False
					break

				elif array2[mid] > num:
					high = mid - 1

				else:
					low = mid + 1;

			if flag == True:

				result = result + 1

		return result
