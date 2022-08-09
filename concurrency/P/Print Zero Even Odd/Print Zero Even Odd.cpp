class ZeroEvenOdd {
private:
    int n;
    mutex mx;
    condition_variable cv;
    atomic<int> num_to_print;
    atomic<int> current;

public:
    ZeroEvenOdd(int n) {
        this->n = n;
        num_to_print = 0;
        current = 0;
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        do_work(printNumber, [&]{return num_to_print == 0;});
    }

    void even(function<void(int)> printNumber) {
        do_work(printNumber, [&]{return num_to_print != 0 && num_to_print % 2 == 0;});
    }

    void odd(function<void(int)> printNumber) {
         do_work(printNumber, [&]{return num_to_print % 2 != 0;});
    }
    
protected:
   void do_work(function<void(int)> print, function<bool()> eval)
    {
        while(current <= n)
        {
            unique_lock<mutex> ul(mx);
            cv.wait(ul, [&]{return eval() || current > n;});
            if(current > n) break;
            print(num_to_print);
            num_to_print = num_to_print == 0 || num_to_print == n ? ++current : 0;
            cv.notify_all();
        }
    }
};
