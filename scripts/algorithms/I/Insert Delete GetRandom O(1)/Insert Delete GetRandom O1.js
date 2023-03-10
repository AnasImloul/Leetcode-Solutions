var RandomizedSet = function() {
    this._data = [];
    this._flatData = [];
};

RandomizedSet.prototype.hash = function(val) {
    return val % 1e5;
}

RandomizedSet.prototype.insert = function(val) {
    const hash = this.hash(val);
    let basket = this._data[hash];
    
    for (let i = 0; i < basket?.length; i++) {
        if (basket[i][0] === val) { return false; }
    }
    
    if (!basket) {
        this._data[hash] = [[val, this._flatData.length]];
    } else {
        this._data[hash].push([val, this._flatData.length]);
    }
    this._flatData.push(val);    
    return true;
};

RandomizedSet.prototype.remove = function(val) {
    const hash = this.hash(val);
    let basket = this._data[hash];
    if (!basket) { return false; }
    for (let i = 0; i < basket.length; i++) {
        const currBasket = basket[i];
        if (currBasket[0] === val) {
            const idxInFlat = currBasket[1];
            const reassignedValueInFlat = del(this._flatData, idxInFlat);
            // Write new address in _data if needed
            if (reassignedValueInFlat) {
                this._data[this.hash(reassignedValueInFlat)].forEach(item => {
                    if (item[0] === reassignedValueInFlat) {
                        item[1] = idxInFlat;
                        return; // from forEach
                    }
                });
            }
            // Delete from _data
            del(basket, i);
            return true;
        }
    }
    return false;
};

RandomizedSet.prototype.getRandom = function() {
    return this._flatData[getRandomInt(0, this._flatData.length - 1)];
};

function getRandomInt(min, max) {
    min = Math.ceil(min);
    max = Math.floor(max);
    return Math.floor(Math.random() * (max - min + 1)) + min;
}

function del(arr, idx) {
    if (!arr.length) { return null; }
    if (idx === arr.length - 1) { arr.pop(); return null; }
    arr[idx] = arr.pop();
    return arr[idx];
}