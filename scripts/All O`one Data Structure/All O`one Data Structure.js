var AllOne = function() {
  this.map = new Map();
  this.pre = '';
};

/** 
 * @param {set} map
 * @param {function} handler
 * @return {map}
 */
AllOne.prototype.sort = function(map, handler) {
  return new Map([...map].sort(handler));
};

/** 
 * @param {string} key
 * @return {void}
 */
AllOne.prototype.inc = function(key) {
  this.map.set(key, this.map.get(key) + 1 || 1);
  this.pre = 'inc';
};

/** 
 * @param {string} key
 * @return {void}
 */
AllOne.prototype.dec = function(key) {
  this.map.get(key) == 1 ? this.map.delete(key) : this.map.set(key, this.map.get(key) - 1);
  this.pre = 'dec';
};

/**
 * @return {string}
 */
AllOne.prototype.getMaxKey = function() {
  if (this.pre != 'max') {
    this.map = this.sort(this.map, (a, b) => b[1] - a[1]);
  }
  this.pre = 'max';
  return this.map.keys().next().value || '';
};

/**
 * @return {string}
 */
AllOne.prototype.getMinKey = function() {
  if (this.pre != 'min') {
    this.map = this.sort(this.map, (a, b) => a[1] - b[1]);
  }
  this.pre = 'min';
  return this.map.keys().next().value || '';
};
