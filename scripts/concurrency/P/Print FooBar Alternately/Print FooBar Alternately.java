// Runtime: 48 ms (Top 30.18%) | Memory: 44.5 MB (Top 36.45%)
import java.util.concurrent.*;
class FooBar {
    private int n;
    Semaphore runf, runb;

    public FooBar(int n) {
        this.n = n;
        runf = new Semaphore(1);
        runb = new Semaphore(0);
    }

    public void foo(Runnable printFoo) throws InterruptedException {

        for (int i = 0; i < n; i++) {
            runf.acquire();
            printFoo.run();
            runb.release();
        }
    }

    public void bar(Runnable printBar) throws InterruptedException {

        for (int i = 0; i < n; i++) {
            runb.acquire();
            printBar.run();
            runf.release();
        }
    }
}