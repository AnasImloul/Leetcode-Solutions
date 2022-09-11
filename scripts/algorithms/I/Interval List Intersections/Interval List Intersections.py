# Runtime: 325 ms (Top 13.56%) | Memory: 15.2 MB (Top 15.52%)
from collections import deque

class Solution:
    def intervalIntersection(self, firstList: List[List[int]], secondList: List[List[int]]) -> List[List[int]]:

        answer = []

        if len(firstList) == 0 or len(secondList) == 0:
            return answer

        first_queue= deque(firstList)
        second_queue = deque(secondList )

        first = first_queue.popleft()
        second = second_queue.popleft()

        while first_queue or second_queue:

            if first[1] < second[0]:
                if len(first_queue):
                    first = first_queue.popleft()
                    continue
                break
            if second[1] < first[0]:
                if len(second_queue) > 0:
                    second = second_queue.popleft()
                    continue
                break

            if first[0] <= second[0] and second[0] <= first[1]:
                if first[1] <= second[1]:
                    answer.append([second[0], first[1]])
                    if len(first_queue) > 0:
                        first = first_queue.popleft()
                        continue
                    break

                else:
                    answer.append(second)
                    if len(second_queue) > 0:
                        second = second_queue.popleft()
                        continue
                    break
            if second[0] <= first[0] and first[0] <= second[1]:
                if second[1] <= first[1]:
                    answer.append([first[0], second[1]])
                    if len(second_queue) > 0:
                        second = second_queue.popleft()
                        continue
                    break

                else:
                    answer.append(first)
                    if len(first_queue) > 0:
                        first = first_queue.popleft()
                        continue
                    break

        if first[0] <= second[0] and second[0] <= first[1]:
            if first[1] <= second[1]:

                if len(answer) > 0:

                    if answer[-1] != [second[0], first[1]]:
                        answer.append([second[0], first[1]])
                elif not answer:
                    answer.append([second[0], first[1]])
            else:
                if len(answer) > 0:
                    if answer[-1] != second:
                        answer.append(second)
                elif not answer:
                    answer.append(second)
        elif second[0] <= first[0] and first[0] <= second[1]:
            if second[1] <= first[1]:
                if len(answer) > 0:
                    if answer[-1] != [first[0], second[1]]:
                        answer.append([first[0], second[1]])
                elif not answer:
                    answer.append([first[0], second[1]])
            else:
                if len(answer) > 0:
                    if answer[-1] != first:
                        answer.append(first)
                elif not answer:

                    answer.append(first)

        return answer