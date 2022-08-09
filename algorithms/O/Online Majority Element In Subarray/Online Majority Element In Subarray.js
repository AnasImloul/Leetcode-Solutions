var MajorityChecker = function(arr) {
    this.arr = arr;
};

MajorityChecker.prototype.query = function(left, right, threshold) {
    var candidate = 0
    var count = 0
    for (var i = left; i < right+1; i++) {
        if (count == 0) {
            candidate = this.arr[i];
            count = 1;
        }
        else if (candidate == this.arr[i]) {
            count += 1
        }
        else {
            count -= 1
        }
    }
    
    count = 0
    for (var i = left; i < right+1; i++) {
        if (candidate == this.arr[i]) {
            count += 1
        }
    }

    if (count >= threshold) {
        return candidate
    }   
    return -1
};
