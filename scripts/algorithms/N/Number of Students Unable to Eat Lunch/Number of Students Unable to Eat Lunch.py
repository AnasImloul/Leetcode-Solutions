// Runtime: 76 ms (Top 5.69%) | Memory: 17.30 MB (Top 7.83%)

class Solution:
    def countStudents(self, students: List[int], sandwiches: List[int]) -> int:
        count = 0
        while len(students) > count:
            if students[0] == sandwiches[0]:
                sandwiches.pop(0)
                count = 0
            else:
                students.append(students[0])
                count+=1

            students.pop(0)
        return len(students)
		
#Upvote will be encouraging.
