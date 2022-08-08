
var TimeMap = function() {
    this.data = new Map();
};

/** 
 * @param {string} key 
 * @param {string} value 
 * @param {number} timestamp
 * @return {void}
 */
TimeMap.prototype.set = function(key, value, timestamp) {
        if(!this.data.has(key)){
        this.data.set(key, [{timestamp: timestamp, value: value}])
    } else {
        let temp_store = this.data.get(key);
        temp_store.push({timestamp: timestamp, value: value});
        this.data.set(key, temp_store);
    }
};

/** 
 * @param {string} key 
 * @param {number} timestamp
 * @return {string}
 */
TimeMap.prototype.get = function(key, timestamp) {
    if(this.data.has(key)){
        const keyArray = this.data.get(key);
        
        //Optimize with binary search - Ordered by insert time, O(log n) devide and conq method (Like searching a dictionary)
        const index = keyArray.binarySearch(timestamp);           
        if(keyArray[index].timestamp > timestamp){
            return ''
        }
        
        return keyArray[index].value || prev;
    }
    
    return '';
};

Array.prototype.binarySearch = function(key){
        let left = 0;
        let right = this.length - 1;
        
        while (left < right) {
            const i = Math.floor((left + right + 1) / 2);
            if (this[i].timestamp > key) {
                right = i - 1;
            } else {
                left = i;
            }
        }
        
        return left;
}


/** 
 * Your TimeMap object will be instantiated and called as such:
 * var obj = new TimeMap()
 * obj.set(key,value,timestamp)
 * var param_2 = obj.get(key,timestamp)
 */
