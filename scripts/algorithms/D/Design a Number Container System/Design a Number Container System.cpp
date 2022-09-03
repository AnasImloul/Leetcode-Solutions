// Runtime: 652 ms (Top 85.73%) | Memory: 179 MB (Top 14.04%)
class NumberContainers {
public:
    map<int, int> indexToNumber; // stores number corresponding to an index.
    map<int, set<int>>numberToIndex; // stores all the indexes corresponding to a number.
    NumberContainers() {}

    void change(int index, int number) {

        if (!indexToNumber.count(index)) { // if there is no number at the given index.
            numberToIndex[number].insert(index); // store index corresponding to the given number
            indexToNumber[index] = number; // store number corresponding to the index.
        }
        else { // Update both map.

            int num = indexToNumber[index]; // number at given index currently.

            // remove the index
            numberToIndex[num].erase(index);
            if (numberToIndex[num].empty()) numberToIndex.erase(num);

            // insert the new number at the given index and store the index corresponding to that number.
            numberToIndex[number].insert(index);
            indexToNumber[index] = number;
        }
    }

    int find(int number) {
        if (!numberToIndex.count(number)) return -1;
        // returning first element in the set as it will be the smallest index always.
        return *numberToIndex[number].begin();
    }
};