// Runtime: 672 ms (Top 16.08%) | Memory: 83 MB (Top 51.75%)
var FreqStack = function() {
    //hashMap to keep track of the values being repeated
    this.frequencyMap = {};

    //List map to keep track of the sequence of the value being entered
    this.listMap = {};

    //Max Frequency variable to keep track of the max frequency
    this.maxValueFrequency = 0;
};

/**
 * @param {number} val
 * @return {void}
 */
FreqStack.prototype.push = function(val) {
    //if the hashMap doesn't have value being pushed then make a entry to it with 1 else increament by 1
    this.frequencyMap[val] = this.frequencyMap[val] ? this.frequencyMap[val]+1 : 1;

    //get the frequency of the value being pushed
    const currentValueFrequency = this.frequencyMap[val];

    //check if the current frequency is max or itself
    this.maxValueFrequency = Math.max(this.maxValueFrequency, currentValueFrequency);

    //if current value frequency is not in the listmap then make a new entry else push it
    if(!this.listMap[currentValueFrequency]) this.listMap[currentValueFrequency] =[val];
    else this.listMap[currentValueFrequency].push(val);

};

/**
 * @return {number}
 */
FreqStack.prototype.pop = function() {
    //make a temporary list of the max value frequency
    const tempList = this.listMap[this.maxValueFrequency];

    //get the last element from the temporary list
    const top = tempList[tempList.length - 1];

    //remove the item from the list
    tempList.pop();

    //update the list
    this.listMap[this.maxValueFrequency] = tempList;

    //if the popped item exist in the frequecy map then decrease it by 1
    if(this.frequencyMap[top]) this.frequencyMap[top]--;

    //if the max value frequency in the listmap is blank then reduce the maxValueFrequency;
    if(this.listMap[this.maxValueFrequency].length === 0) this.maxValueFrequency--;

    //return the max value frequency with proper order if it is same
    return top;

};

//Time O(Log n) // for both Push and Pop
//Space O(n) for storing all the values in the hashMap and listMap