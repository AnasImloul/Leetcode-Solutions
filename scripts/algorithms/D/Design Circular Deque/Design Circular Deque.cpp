// Runtime: 45 ms (Top 45.02%) | Memory: 16.9 MB (Top 51.36%)
class MyCircularDeque {
public:

    deque<int> dq;

    int max_size;

    MyCircularDeque(int k) {

        max_size = k;
    }

    bool insertFront(int value) {

        if(dq.size() < max_size)
        {
            dq.push_front(value);

            return true;
        }

        return false;
    }

    bool insertLast(int value) {

        if(dq.size() < max_size)
        {
            dq.push_back(value);

            return true;
        }

        return false;
    }

    bool deleteFront() {

        if(dq.size() > 0)
        {
            dq.pop_front();

            return true;
        }

        return false;
    }

    bool deleteLast() {

        if(dq.size() > 0)
        {
            dq.pop_back();

            return true;
        }

        return false;
    }

    int getFront() {

        if(dq.size() > 0)
            return dq.front();

        return -1;
    }

    int getRear() {

        if(dq.size() > 0)
            return dq.back();

        return -1;
    }

    bool isEmpty() {

        return dq.empty();
    }

    bool isFull() {

        return dq.size() == max_size;
    }
};