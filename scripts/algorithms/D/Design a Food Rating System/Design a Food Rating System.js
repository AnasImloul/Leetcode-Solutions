// Runtime: 576 ms (Top 96.50%) | Memory: 85.2 MB (Top 90.21%)
var FoodRatings = function(foods, cuisines, ratings) {
  this.heaps = {}, this.foods = {};
  let n = foods.length;
  for (let i = 0; i < n; i++) {
    let food = foods[i], cuisine = cuisines[i], rating = ratings[i];
    if (!this.heaps[cuisine]) this.heaps[cuisine] = new PriorityQueue((a, b) => { // [food, rating]
      return a[1] === b[1] ? a[0].localeCompare(b[0]) : b[1] - a[1];
    })
    this.heaps[cuisine].add([food, rating]);
    this.foods[food] = { cuisine, rating };
  }
};

FoodRatings.prototype.changeRating = function(food, newRating) {
  this.foods[food].rating = newRating;
  let { cuisine } = this.foods[food];
  this.heaps[cuisine].add([food, newRating]);
};

FoodRatings.prototype.highestRated = function(cuisine) {
  let heap = this.heaps[cuisine];
  while (this.foods[heap.top()[0]].rating !== heap.top()[1]) {
    heap.remove();
  }
  return heap.top()[0];
};

class PriorityQueue {
  constructor(comparator = ((a, b) => a - b)) {
    this.values = [];
    this.comparator = comparator;
    this.size = 0;
  }
  add(val) {
    this.size++;
    this.values.push(val);
    let idx = this.size - 1, parentIdx = Math.floor((idx - 1) / 2);
    while (parentIdx >= 0 && this.comparator(this.values[parentIdx], this.values[idx]) > 0) {
      [this.values[parentIdx], this.values[idx]] = [this.values[idx], this.values[parentIdx]];
      idx = parentIdx;
      parentIdx = Math.floor((idx - 1) / 2);
    }
  }
  remove() {
    if (this.size === 0) return -1;
    this.size--;
    if (this.size === 0) return this.values.pop();
    let removedVal = this.values[0];
    this.values[0] = this.values.pop();
    let idx = 0;
    while (idx < this.size && idx < Math.floor(this.size / 2)) {
      let leftIdx = idx * 2 + 1, rightIdx = idx * 2 + 2;
      if (rightIdx === this.size) {
        if (this.comparator(this.values[leftIdx], this.values[idx]) > 0) break;
        [this.values[leftIdx], this.values[idx]] = [this.values[idx], this.values[leftIdx]];
        idx = leftIdx;
      } else if (this.comparator(this.values[leftIdx], this.values[idx]) < 0 || this.comparator(this.values[rightIdx], this.values[idx]) < 0) {
        if (this.comparator(this.values[leftIdx], this.values[rightIdx]) <= 0) {
          [this.values[leftIdx], this.values[idx]] = [this.values[idx], this.values[leftIdx]];
          idx = leftIdx;
        } else {
          [this.values[rightIdx], this.values[idx]] = [this.values[idx], this.values[rightIdx]];
          idx = rightIdx;
        }
      } else {
        break;
      }
    }
    return removedVal;
  }
  top() {
    return this.values[0];
  }
  isEmpty() {
    return this.size === 0;
  }
}