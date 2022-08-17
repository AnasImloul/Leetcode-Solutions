var MyCalendarTwo = function() {
  this.calendar = [];
  this.overlaps = [];
};

/** 
 * @param {number} start 
 * @param {number} end
 * @return {boolean}
 */
MyCalendarTwo.prototype.book = function(start, end) {
  for (let date of this.overlaps) {
    if (start < date[1] && end > date[0]) return false;
  }

  for (let date of this.calendar) {
    if (start < date[1] && end > date[0]) {
      this.overlaps.push([Math.max(date[0], start), Math.min(date[1], end)]);
    }
  }
  this.calendar.push([start, end]); 
  return true;
};
