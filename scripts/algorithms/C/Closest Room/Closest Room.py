# Runtime: 3555 ms (Top 46.27%) | Memory: 66.7 MB (Top 10.45%)

from sortedcontainers import SortedList

class Solution:
    def closestRoom(self, rooms: List[List[int]], queries: List[List[int]]) -> List[int]:
        rooms.sort(key=lambda x: x[1], reverse=True) # Sort by decreasing order of room size
        qArr = [[i, q] for i, q in enumerate(queries)] # Zip queries with their index
        qArr.sort(key=lambda x: x[1][1], reverse=True) # Sort by decreasing order of query minSize

        def searchClosestRoomId(preferredId):
            if len(roomIdsSoFar) == 0:
                return -1
            cands = []
            i = roomIdsSoFar.bisect_right(preferredId)
            if i > 0:
                cands.append(roomIdsSoFar[i - 1])
            if i < len(roomIdsSoFar):
                cands.append(roomIdsSoFar[i])
            return min(cands, key=lambda x: abs(x - preferredId))

        roomIdsSoFar = SortedList()
        n, k = len(rooms), len(queries)
        i = 0
        ans = [-1] * k
        for index, (prefferedId, minSize) in qArr:
            while i < n and rooms[i][1] >= minSize:
                roomIdsSoFar.add(rooms[i][0]) # Add id of the room which its size >= query minSize
                i += 1
            ans[index] = searchClosestRoomId(prefferedId)
        return ans