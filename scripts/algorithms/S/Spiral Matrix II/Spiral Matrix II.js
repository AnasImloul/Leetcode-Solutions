// Runtime: 51 ms (Top 99.51%) | Memory: 42.1 MB (Top 65.95%)
var generateMatrix = function(n) {
    const arr = new Array(n).fill(0).map(() => new Array(n).fill(0));
    let count = 1, index = 1, i = 0, j =0, changed = false, toIncrease = true;
    arr[i][j] = index;
    while(index < n*n) {
        index++;
        if(i == n-count && j > count-1) {
            j--;
            toIncrease = false;
            changed = true;
        }
        else if(i !== n-count && j == n-count) {
            i++;
            toIncrease = false;
            changed = true;
        }
        if(i == count-1 && !changed) {
            if(toIncrease) j++;
            else j--;
        }
        else if(j == count-1 && !changed) {
            if(i == count) {
                toIncrease = true;
                j++;
                count++;
            }
            else if(toIncrease) i++;
            else i--;
        }
        arr[i][j] = index;
        if(index == 4*(n-1)) {
            toIncrease = true;
            count++;
        }
        changed = false;
    }
    return arr;
};