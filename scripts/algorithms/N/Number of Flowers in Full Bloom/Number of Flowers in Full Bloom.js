// Runtime: 394 ms (Top 78.26%) | Memory: 80.8 MB (Top 73.91%)
/**
 * @param {number[][]} flowers
 * @param {number[]} persons
 * @return {number[]}
 */
var fullBloomFlowers = function(flowers, persons) {
    // *** IDEATION *** //
    // key observation:
    // total number of flowers see on day i =
    // number of flowers has already bloomed so far on day i - number of flowers already ended ("died") prior to day i

    // find number of flowers already bloomed on day i
    // each flower has a start day
    // start array = [1, 3, 9, 4] for example
    // on day 8, there are 3 flowers bloomed:
    // equivalent to find the number of elements in the "start" array which is less than or equal to 8

    // find number of flowers already ended on day i
    // each flower has an end day
    // end array = [6, 7, 12, 13] for example
    // on day 8, there are 2 flowers already ended:
    // equivalent to find the number of elements in the "end" array which is less than 8
    // equivalent to find the number of elements in the "end" array which is less than or equal to 7

    // both process above can be solved efficiently with binary search on a sorted array
    // hence we need to first build 2 array "start" and "end" and sorted it
    // then apply the formula at the beginning to return the required answer

    // *** IMPLEMENTATION *** //
    // step 1: build the "start" and "end" array
    let start = [];
    let end = [];

    for (let i = 0; i < flowers.length; i++) {
        start[i] = flowers[i][0];
        end[i] = flowers[i][1];
    }

    // step 2: sort the "start" and "end" array
    start.sort((a, b) => a - b);
    end.sort((a, b) => a - b);

    // step 3: apply the observation formula using a binarySearch function
    let res = [];
    for (let j = 0; j < persons.length; j++) {
        res[j] = binarySearch(start, persons[j]) - binarySearch(end, persons[j] - 1);
    }
    return res;

    // step 4: implement the binarySearch function (variant from standard binarySearch)
    function binarySearch(array, k) {
        // array is sorted;
        // obj is to find the number of elements in array which is less than or equal to "k"
        let left = 0;
        let right = array.length - 1;
        let index = -1;

        while (left <= right) {
            let mid = left + Math.floor((right - left) / 2);
            if (k < array[mid]) {
                right = mid - 1;
            } else {
                index = Math.max(index, mid); // record the index whenever k >= array[mid]
                left = mid + 1;
            }
        }

        // all elements with in array from position '0' to position 'index' will be less than or equal to k
        return index + 1;
    }
};