// Runtime: 466 ms (Top 38.09%) | Memory: 51 MB (Top 38.09%)
/**
 * @param {number} n
 */
var ExamRoom = function(n) {
    this.n = n
    this.list = []
};

/**
 * @return {number}
 */
ExamRoom.prototype.seat = function() {
    // if nothing in the list, seat the first student at index 0.
    if(this.list.length === 0){
        this.list.push(0)
        return 0
    }

    // find the largest distance between left wall and first student, and right wall and last student
    let distance = Math.max(this.list[0], this.n - 1 - this.list[this.list.length-1])
    // update the largest distance by considering the distance between students
    for(let i=0; i<this.list.length-1; i++){
        distance = Math.max(distance, Math.floor((this.list[i+1] - this.list[i]) / 2))
    }

    // in case the largest distance is between left wall and first student, we seat next student at the left wall
    if(distance === this.list[0]){
        this.list.unshift(0)
        return 0
    }

    // in case the largest distance is between two student, we seat the next student in between these two students
    for(let i=0; i<this.list.length-1; i++){
        if(distance === Math.floor( (this.list[i+1]-this.list[i])/2 )){
            let insertIndex = Math.floor( (this.list[i+1]+this.list[i]) / 2 )
            this.list.splice(i+1,0, insertIndex)
            return insertIndex
        }
    }

    // in case the largest distance is between the last student and the right wall, we seat the next student at the right wall
    this.list.push(this.n-1)
    return this.n - 1
};

/**
 * @param {number} p
 * @return {void}
 */
ExamRoom.prototype.leave = function(p) {
    // We iterate through the list and find the index where the student p sit at, then remove that index.
    for(let i=0; i<this.list.length; i++){
        if(this.list[i] === p) {
            this.list.splice(i, 1)
            break
        }
    }
};

/**
 * Your ExamRoom object will be instantiated and called as such:
 * var obj = new ExamRoom(n)
 * var param_1 = obj.seat()
 * obj.leave(p)
 */