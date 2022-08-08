var MyCalendarThree = function() {
    this.intersections = [];
    this.kEvents = 0;
    
};

/** 
 * @param {number} start 
 * @param {number} end
 * @return {number}
 */
MyCalendarThree.prototype.book = function(start, end) {
    let added = false;
    for(let i = 0; i < this.intersections.length; i++) {
        const a = this.intersections[i];
        if(end <= a.start) {
            this.intersections.splice(i, 0, {start, end, count: 1});
            this.kEvents = Math.max(this.kEvents, 1);
            this.added = true;
            break;
        }
        if(start < a. start) {
            this.intersections.splice(i, 0, {start, end: a.start, count: 1});
            i++;
            start = a.start;
        }
        if(a.start < start && start < a.end ) {
            this.intersections.splice(i, 0, {start: a.start, end: start, count: a.count});
            i++;
            a.start = start;
        }
        if(end < a.end) {
            this.intersections.splice(i + 1, 0, {start: end, end: a.end, count: a.count});
            a.count++;
            a.end = end;
            this.kEvents = Math.max(this.kEvents, a.count);
            this.added = true;
            break;
        }
        if(end === a.end) {
            a.count++;
            a.end = end;
            this.kEvents = Math.max(this.kEvents, a.count); 
            this.added = true;
            break;
        } 
        if(a.start === start && a.end < end ) {
            a.count++;
            this.kEvents = Math.max(this.kEvents, a.count);
            start = a.end;
        }
    }
    if(!added) {
        this.intersections.push({start, end, count: 1});
        this.kEvents = Math.max(this.kEvents, 1);
    }
    return this.kEvents;
};
