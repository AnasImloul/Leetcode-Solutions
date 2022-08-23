# Runtime: 233 ms (Top 17.20%) | Memory: 15.2 MB (Top 30.57%)
from threading import Lock
from threading import Semaphore

class DiningPhilosophers:

    def __init__(self):
        self.spoons = [Lock() for i in range(5)]
        self.sem = Semaphore(4)

    # call the functions directly to execute, for example, eat()
    def wantsToEat(self,
                   philosopher: int,
                   pickLeftFork: 'Callable[[], None]',
                   pickRightFork: 'Callable[[], None]',
                   eat: 'Callable[[], None]',
                   putLeftFork: 'Callable[[], None]',
                   putRightFork: 'Callable[[], None]') -> None:

        left = philosopher
        right = (philosopher + 1) % 5

        with self.sem:
            with self.spoons[left]:
                with self.spoons[right]:
                    pickLeftFork()
                    pickRightFork()
                    eat()
                    putLeftFork()
                    putRightFork()