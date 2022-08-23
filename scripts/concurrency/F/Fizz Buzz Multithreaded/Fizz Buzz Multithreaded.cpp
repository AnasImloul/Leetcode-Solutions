// Runtime: 627 ms (Top 5.10%) | Memory: 6.7 MB (Top 85.34%)
class FizzBuzz {
private:
    int n;
    int current_number;
    mutex number_mutex;
    const int number_of_threads = 4;
    bool done = true;

public:
    FizzBuzz(int n) {
        this->n = n;
        if (n > 0){
            done = false;
        }
        current_number = 1;
    }

private:
    void nextNumber(){
        if (current_number < n){
            scoped_lock lock(number_mutex);
            current_number++;
        } else{
            done = true;
        }
    }

public:
    // printFizz() outputs "fizz".
    void fizz(function<void()> printFizz) {
        while (!done){
            if (!(current_number % 3 ) && (current_number % 5)){
                printFizz();
                nextNumber();
            }
        }
    }

    // printBuzz() outputs "buzz".
    void buzz(function<void()> printBuzz) {
        while (!done){
            if ((current_number % 3 ) && !(current_number % 5)){
                printBuzz();
                nextNumber();
            }
        }
    }

    // printFizzBuzz() outputs "fizzbuzz".
    void fizzbuzz(function<void()> printFizzBuzz) {
        while (!done){
            if (!(current_number % 3 ) && !(current_number % 5)){
                printFizzBuzz();
                nextNumber();
            }
        }
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber) {

        while (!done){
            if ((current_number % 3 ) && (current_number % 5)){
                printNumber(current_number);
                nextNumber();
            }
        }
    }
};