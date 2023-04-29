class Solution:
    def findCrossingTime(self, n: int, k: int, time: List[List[int]]) -> int:
        ans = 0
        left = [[-t[0]-t[2], -i] for i, t in enumerate(time)]
        right = []
        save = []
        heapify(left)
        cnt = note = tmstamp = 0
        while cnt < n:
            if len(left) == len(right) == 0 and save[0][0] > tmstamp:
                tmstamp = save[0][0]
            while save and save[0][0] <= tmstamp:
                t, eff, idx, direction = heappop(save)
                if direction == 1:
                    heappush(left, [eff, idx])
                else:
                    heappush(right, [eff, idx])
            flag = True
            if note == n:
                while len(right) == 0:
                    t, eff, idx, direction = heappop(save)
                    tmstamp = t
                    if direction == 0: heappush(right, [eff, idx])
            elif len(right) == 0: flag = False
            cnt += flag
            if flag:
                eff, idx = heappop(right)
                tmstamp += time[-idx][2]
                heappush(save, [tmstamp + time[-idx][3], eff, idx, 1])
            else:
                eff, idx = heappop(left)
                tmstamp += time[-idx][0]
                heappush(save, [tmstamp + time[-idx][1], eff, idx, 0])
                note += 1
        return tmstamp