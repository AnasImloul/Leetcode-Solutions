class Solution:
    def canPlaceFlowers(self, flowerbed: List[int], n: int) -> bool:
        f = [0] + flowerbed + [0]

        i, could_plant = 1, 0
        while could_plant < n and i < len(f) - 1:
            if f[i + 1]:
                # 0 0 1 -> skip 3
                i += 3
            elif f[i]:
                # 0 1 0 -> skip 2
                i += 2
            elif f[i - 1]:
                # 1 0 0 -> skip 1
                i += 1
            else:
                # 0 0 0 -> plant, becomes 0 1 0 -> skip 2
                could_plant += 1
                i += 2

        return n <= could_plant
