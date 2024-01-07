// Runtime: 461 ms (Top 51.72%) | Memory: 129.30 MB (Top 75.86%)

var FrequencyTracker = function() {
    this.counts = new Map();
    this.frequencies = new Map();
};

FrequencyTracker.prototype.removeFrequencyCount = function(number, count) {
    const frequencySet = this.frequencies.get(count);
    frequencySet.delete(number);
    if (frequencySet.size === 0) {
        this.frequencies.delete(count);
    }
}

FrequencyTracker.prototype.addFrequencyCount = function(number, count) {
    const frequencySet = this.frequencies.get(count);
    if (frequencySet) frequencySet.add(number);
    else this.frequencies.set(count, new Set([number]));
}

/** 
 * @param {number} number
 * @return {void}
 */
FrequencyTracker.prototype.add = function(number) {
    let count = this.counts.get(number) || 0;
    if (count > 0) this.removeFrequencyCount(number, count);
    this.counts.set(number, ++count);
    this.addFrequencyCount(number, count);
};

/** 
 * @param {number} number
 * @return {void}
 */
FrequencyTracker.prototype.deleteOne = function(number) {
    let count = this.counts.get(number);
    if (count > 0) {
        this.removeFrequencyCount(number, count);
        this.counts.set(number, --count);
        this.addFrequencyCount(number, count);
    }
};

/** 
 * @param {number} frequency
 * @return {boolean}
 */
FrequencyTracker.prototype.hasFrequency = function(frequency) {
    return this.frequencies.has(frequency);
};
