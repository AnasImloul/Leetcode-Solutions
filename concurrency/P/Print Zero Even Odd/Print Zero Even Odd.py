from threading import Semaphore
class ZeroEvenOdd:
    def __init__(self, n):
        self.n = n
        self.semOdd  = Semaphore(0) # Permission to write an Odd  Number
        self.semEven = Semaphore(0) # Permission to write an Even Number
        self.semZero = Semaphore(1) # Permission to write a  Zero
	# printNumber(x) outputs "x", where x is an integer.
    def zero(self, printNumber):
        for i in range(1,self.n+1):
            # A) Request Permission to Write a Zero
            self.semZero.acquire()
            printNumber(0)
            # B) Check if "i" if Odd or Even, and give permission to write the number
            if i&1:
                self.semOdd.release()
            else:
                self.semEven.release()
            # C) Permission to write a zero is returned by another Thread ( release triggers a change)
    def even(self, printNumber):
        # A) Iterate only through Even numbers
        for i in range(2,self.n+1,2):
            # B) Request Permission to Write Current Number
            self.semEven.acquire()
            printNumber(i)
            # C) Return Permission to Write a Zero (if applicable)
            self.semZero.release()
    def odd(self, printNumber):
        # A) Iterate only through Odd numbers
        for i in range(1,self.n+1,2):
            # B) Request Permission to Write Current Number
            self.semOdd.acquire()
            printNumber(i)
            # C) Return Permission to Write a Zero (if applicable)
            self.semZero.release()
