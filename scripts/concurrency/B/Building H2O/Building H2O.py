import threading

class H2O:
    def __init__(self):
        self.cv = threading.Condition()
        self.sum = 0 # releaseHydrogen will +1, releaseOxygen will -2

    def hydrogen(self, releaseHydrogen: 'Callable[[], None]') -> None:
        with self.cv:
            self.cv.wait_for(lambda : -2 <= self.sum <= 1)
            self.sum += 1
            releaseHydrogen()
            self.cv.notifyAll()

    def oxygen(self, releaseOxygen: 'Callable[[], None]') -> None:
        with self.cv:
            self.cv.wait_for(lambda : 0 <= self.sum <= 2)
            self.sum -= 2
            releaseOxygen()
            self.cv.notifyAll()