class Foo {
public:
    int count = 0;
    mutex mtx;
    condition_variable cv;
    Foo() {
        count = 1;
        //cv.notify_all();
    }

    void first(function<void()> printFirst) {
        
        unique_lock<mutex> lck(mtx);
		// No point of this wait as on start count will be 1, we need to make the other threads wait.
        // while(count != 1){
        //     cv.wait(lck);
        // }
        // printFirst() outputs "first". Do not change or remove this line.

        printFirst();
        count = 2;
        cv.notify_all();
    }

    void second(function<void()> printSecond) {
        unique_lock<mutex> lck(mtx);
        while(count != 2){
            cv.wait(lck);
        }
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        count = 3;
        cv.notify_all();
    }

    void third(function<void()> printThird) {
        unique_lock<mutex> lck(mtx);
        while(count != 3){
            cv.wait(lck);
        }
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
    }
};
