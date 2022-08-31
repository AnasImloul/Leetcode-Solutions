// Runtime: 3 ms (Top 82.50%) | Memory: 7.5 MB (Top 36.47%)
/*
 * Below is the interface for Iterator, which is already defined for you.
 * **DO NOT** modify the interface for Iterator.
 *
 * class Iterator {
 * struct Data;
 * Data* data;
 * public:
 * Iterator(const vector<int>& nums);
 * Iterator(const Iterator& iter);
 *
 * // Returns the next element in the iteration.
 * int next();
 *
 * // Returns true if the iteration has more elements.
 * bool hasNext() const;
 * };
 */

class PeekingIterator : public Iterator {
public:
    int _nextVal;
    bool _hasNext;
    PeekingIterator(const vector<int>& nums) : Iterator(nums) {
        // Initialize any member here.
        // **DO NOT** save a copy of nums and manipulate it directly.
        // You should only use the Iterator interface methods.
        _nextVal = 0;
        _hasNext = Iterator::hasNext();
        if (_hasNext)
            _nextVal = Iterator::next();
    }

    // Returns the next element in the iteration without advancing the iterator.
    int peek() {
        return (_nextVal);
    }

    // hasNext() and next() should behave the same as in the Iterator interface.
    // Override them if needed.
    int next() {
        int tmp = _nextVal;

        _hasNext = Iterator::hasNext();
        if (_hasNext)
            _nextVal = Iterator::next();
        return (tmp);
    }

    bool hasNext() const {
        return (_hasNext);
    }
};