class Solution:

    def __init__(self, radius: float, x_center: float, y_center: float):
        self.rad = radius
        self.xc = x_center
        self.yc = y_center

    def randPoint(self) -> List[float]:
        while True:
            xg=self.xc+random.uniform(-1, 1)*self.rad*2
            yg=self.yc+random.uniform(-1, 1)*self.rad*2
            if (xg-self.xc)**2 + (yg-self.yc)**2 <= self.rad**2:
                return [xg, yg]


# Your Solution object will be instantiated and called as such:
# obj = Solution(radius, x_center, y_center)
# param_1 = obj.randPoint()
