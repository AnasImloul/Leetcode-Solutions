// Runtime: 294 ms (Top 93.33%) | Memory: 126.60 MB (Top 92.59%)

/* 
    Time: addElement: O(logm) | calculateMKAverage: O(1)
    Space: O(m)
    Tag: TreeMap, Sorting, Queue
    Difficulty: H
*/

class MKAverage {
    map<int, int> left, middle, right;
    queue<int> q;
    int sizeofLeft, sizeofMiddle, sizeofRight;
    int k;
    long long mkSum;
    int m;

    void addToSet1(int num) {
        left[num]++;
        sizeofLeft++;
    }

    void deleteFromSet1(int num) {
        left[num]--;
        if (left[num] == 0) left.erase(num);
        sizeofLeft--;
    }

    void addToSet2(int num) {
        middle[num]++;
        sizeofMiddle++;
        mkSum += num;
    }

    void deleteFromSet2(int num) {
        middle[num]--;
        if (middle[num] == 0) middle.erase(num);
        sizeofMiddle--;
        mkSum -= num;
    }

    void addToSet3(int num) {
        right[num]++;
        sizeofRight++;
    }

    void deleteFromSet3(int num) {
        right[num]--;
        if (right[num] == 0) right.erase(num);
        sizeofRight--;
    }

public:
    MKAverage(int m, int k) {
        sizeofLeft = 0, sizeofMiddle = 0, sizeofRight = 0;
        mkSum = 0;
        this->k = k;
        this->m = m;
    }

    void addElement(int num) {
        if (sizeofLeft < k) {
            addToSet1(num);
            q.push(num);
        } else if (sizeofMiddle < (m - (2 * k))) {
            int lastEle = prev(left.end())->first;
            if (num >= lastEle) {
                addToSet2(num);
            } else {
                deleteFromSet1(lastEle);
                addToSet1(num);
                addToSet2(lastEle);
            }
            q.push(num);
        } else if (sizeofRight < k) {
            int last1 = prev(left.end())->first;
            int last2 = prev(middle.end())->first;
            if (num >= last1 && num >= last2) {
                addToSet3(num);
            } else if (num >= last1 && num < last2) {
                deleteFromSet2(last2);
                addToSet2(num);
                addToSet3(last2);
            } else {
                deleteFromSet2(last2);
                addToSet3(last2);
                deleteFromSet1(last1);
                addToSet2(last1);
                addToSet1(num);
            }
            q.push(num);
        } else {
            int toErase = q.front();
            q.pop();
            int first3 = right.begin()->first;
            int first2 = middle.begin()->first;
            int first1 = left.begin()->first;

            if (toErase >= first3) {
                deleteFromSet3(toErase);
            } else if (toErase >= first2) {
                deleteFromSet3(first3);
                deleteFromSet2(toErase);
                addToSet2(first3);
            } else {
                deleteFromSet3(first3);
                deleteFromSet2(first2);
                deleteFromSet1(toErase);
                addToSet1(first2);
                addToSet2(first3);
            }
            addElement(num);
        }
    }

    int calculateMKAverage() {
        if (q.size() < m) return -1;
        return mkSum / (m - (2 * k));
    }
};
