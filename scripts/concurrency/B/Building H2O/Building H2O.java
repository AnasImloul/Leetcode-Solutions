// Runtime: 37 ms (Top 34.57%) | Memory: 47.5 MB (Top 6.17%)
import java.util.concurrent.*;

class H2O {

    private final CyclicBarrier barrier = new CyclicBarrier(3);
    private final Semaphore hSem = new Semaphore(2);
    private final Semaphore oSem = new Semaphore(1);

    public H2O() {

    }

    public void hydrogen(Runnable releaseHydrogen) throws InterruptedException {
        try {
            hSem.acquire();
            barrier.await();
             // releaseHydrogen.run() outputs "H". Do not change or remove this line.
            releaseHydrogen.run();
        } catch(Exception ignore) {

        } finally {
            hSem.release();
        }

    }

    public void oxygen(Runnable releaseOxygen) throws InterruptedException {
        try {
            oSem.acquire();
            barrier.await();
            // releaseOxygen.run() outputs "O". Do not change or remove this line.
            releaseOxygen.run();
        } catch(Exception ignore) {

        } finally {
            oSem.release();
        }
    }
}