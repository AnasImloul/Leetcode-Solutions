// Brute Force => T.C: O(n^2) | S.C: O(n);
var MyCalendar = function() {
  this.val = [];
};

MyCalendar.prototype.book = function(start, end) {
  for (let book of this.val) {
    if (end > book[0] && start < book[1]) return false;
  }
  this.val.push([start, end]);
  return true;
};
