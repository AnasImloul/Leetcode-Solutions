class SeatManager:
    def __init__(self, n: int):
        self.lis = list(range(1,n+1))
    def reserve(self) -> int:
        mini = min(self.lis)
        self.lis.remove(mini)
        return mini

    def unreserve(self, seatNumber: int) -> None:
        self.lis.append(seatNumber)
