// Runtime: 15 ms (Top 13.93%) | Memory: 42.3 MB (Top 37.50%)
class ZeroEvenOdd {
    private int n;
    Semaphore s0, sEven, sOdd;

    public ZeroEvenOdd(int n) {
        this.n = n;
        s0 = new Semaphore(1);
        sEven = new Semaphore(0);
        sOdd = new Semaphore(0);
    }

    // printNumber.accept(x) outputs "x", where x is an integer.
    public void zero(IntConsumer printNumber) throws InterruptedException {
        for (int i = 1; i <= this.n; i++) {
            s0.acquire();
            printNumber.accept(0);
            if (i % 2 == 0) {
                sEven.release();
            }else {
                sOdd.release();
            }
        }
    }

    public void even(IntConsumer printNumber) throws InterruptedException {
        for (int i = 2; i <= this.n; i += 2) {
            sEven.acquire();
            printNumber.accept(i);
            s0.release();
        }
    }

    public void odd(IntConsumer printNumber) throws InterruptedException {
        for (int i = 1; i <= this.n; i += 2) {
            sOdd.acquire();
            printNumber.accept(i);
            s0.release();
        }
    }
}