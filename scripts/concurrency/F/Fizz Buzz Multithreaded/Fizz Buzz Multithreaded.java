// Runtime: 9 ms (Top 72.94%) | Memory: 41.9 MB (Top 91.34%)
class FizzBuzz {
    private int n;
    private int count;
    private final Lock mutex = new ReentrantLock(true);
    public FizzBuzz(int n) {
        this.n = n;
        count = 1;
    }

    // printFizz.run() outputs "fizz".
    public void fizz(Runnable printFizz) throws InterruptedException {
        while(1>0){
        mutex.lock();
            if(count>n){
                mutex.unlock();
                return;
            }
            if(count%3==0 && count%5!=0){
                printFizz.run();
                count++;
            }
        mutex.unlock();
        }
    }

    // printBuzz.run() outputs "buzz".
    public void buzz(Runnable printBuzz) throws InterruptedException {
        while(1>0){
        mutex.lock();
            if(count>n){
                mutex.unlock();
                return;
            }
            if(count%3!=0 && count%5==0){
                printBuzz.run();
                count++;
            }
        mutex.unlock();
        }
    }

    // printFizzBuzz.run() outputs "fizzbuzz".
    public void fizzbuzz(Runnable printFizzBuzz) throws InterruptedException {
        while(1>0){
        mutex.lock();
            if(count>n){
                mutex.unlock();
                return;
            }
            if(count%3==0 && count%5==0){
                printFizzBuzz.run();
                count++;
            }
        mutex.unlock();
        }
    }

    // printNumber.accept(x) outputs "x", where x is an integer.
    public void number(IntConsumer printNumber) throws InterruptedException {
       while(1>0){
        mutex.lock();
            if(count>n){
                mutex.unlock();
                return;
            }
            if(count%3!=0 && count%5!=0){
                printNumber.accept(count);
                count++;
            }
        mutex.unlock();
       }
    }
}