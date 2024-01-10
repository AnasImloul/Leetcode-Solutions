// Runtime: 1075 ms (Top 30.77%) | Memory: 97.10 MB (Top 53.85%)

/**
 * @param {number[]} nums
 * @param {number} lower
 * @param {number} upper
 * @return {number}
 */
var countRangeSum = function(nums, lower, upper) {
  if (nums.length === 1) return 1;
  let prefixSums = new Array(nums.length + 1);
  prefixSums[0] = 0; 
  for (let index = 0; index < nums.length; index++) {
    if (index == 0) {
      prefixSums[index + 1] = nums[index];
    } else {
      prefixSums[index + 1] = prefixSums[index] + nums[index];
    }
  }

  let sortedPrefixSums = prefixSums.slice();
  sortedPrefixSums.sort((a, b) => a - b);

  let ranks = new Map();
  for (let index = 0; index < sortedPrefixSums.length; index++) {
      ranks.set(sortedPrefixSums[index], index);
  }

  let count = 0;
  let tree = new SegTree(sortedPrefixSums);
  const reversed = new TreeMap([...ranks.keys()]);

  function getRanks(val) {
    let lowerBound = reversed.floorKey(val + lower - 1);
    let minRank = -1;
    if (lowerBound !== undefined) {
      minRank = ranks.get(lowerBound) + 1;
    }

    let upperBound = reversed.floorKey(val + upper, 0, reversed.length - 1);
    let maxRank = -1;
    if (upperBound !== undefined) {
      maxRank = ranks.get(upperBound);
    }
    return [minRank, maxRank];
  }
  
  for (let index = prefixSums.length - 1; index >= 0; index--) {
    const [minRank, maxRank] = getRanks(prefixSums[index]);
    const c = tree.query(minRank, maxRank);
    count += c;

    const r = ranks.get(prefixSums[index]);
    tree.update(r);
  }

  return count;
};

class SegTree {
    arr = [];
    constructor(arr) {
        const n = arr.length;
        this.size = n;
        this.lastLevelNodeAmount = 2 ** Math.ceil(Math.log2(n));
        this.offset = this.lastLevelNodeAmount - 1;
    }
    update(idx) {
      const newIdx = this.offset + idx;
      this.arr[newIdx] = (this.arr[newIdx] ?? 0) + 1;
      this._update(newIdx, 1);
    }
    _update(idx, diff) {
        const parentIdx = Math.ceil(idx / 2) - 1;
        if (!this.arr[parentIdx]) this.arr[parentIdx] = 0;

        this.arr[parentIdx] += diff;

        if (parentIdx > 0) this._update(parentIdx, diff)
    }
    query = (i, j) => {
        if (i > j) return 0;
        return this._query(i, j, 0, this.lastLevelNodeAmount, 0);
    }
    _query(i, j, l, r, idx) {
        if (i > r || j < l) return 0;
        if (i <= l && j >= Math.min(this.size, r) - 1) {
          return this.arr[idx] ?? 0;
        }

        const mid = l + Math.floor((r - l) / 2);
        const firstChildIdx = 2 * idx + 1;
        const secondChildIdx = 2 * idx + 2;

        if (i >= mid) { // right
            return this._query(i, j, mid, r, secondChildIdx);
        } else if (j < mid) { // left
            return this._query(i, j, l, mid, firstChildIdx);
        }

        const leftQuery = this._query(i, j, l, mid, firstChildIdx);
        const rightQuery = this._query(i, j, mid, r, secondChildIdx);

        return leftQuery + rightQuery;
    }
}

class TreeMap {
    constructor(arr) {
        this.arr = arr;
    }

    floorKey(key) {
        return this.#binarySearch(key, 0, this.arr.length - 1);
    }

    #binarySearch(target, l, r) {
      if (l > r) {
          return r < 0 ? undefined : this.arr[this.arr.length - 1];
      }
      const mid = l + Math.floor((r - l) / 2);
      if (this.arr[mid] === target) return this.arr[mid];
      else if (this.arr[mid - 1] < target && this.arr[mid] > target) return this.arr[mid - 1];
      else if (this.arr[mid] > target) return this.#binarySearch(target, l, mid - 1);
      else return this.#binarySearch(target, mid + 1, r);
  }
}

