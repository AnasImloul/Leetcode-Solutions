// T.C: 
// O(1) for init and methods other than pushMiddle(), popMiddle()
// O(N) for pushMiddle(), popMiddle()
// S.C: O(N) for storage 

// Doubly linked list node
function ListNode(val, prev, next) {
    this.val = val || 0;
    this.prev = prev || null;
    this.next = next || null;
}

var FrontMiddleBackQueue = function() {
    this.head = null;
    this.tail = null;
    this.len = 0;
};

/** 
 * @param {number} val
 * @return {void}
 */
FrontMiddleBackQueue.prototype.pushFront = function(val) {
    if (this.len === 0) {
        this.head = new ListNode(val);
        this.tail = this.head;
        this.len += 1;
        return;
    }
    
    let newNode = new ListNode(val);
    newNode.next = this.head;
    this.head.prev = newNode;
    this.head = newNode; // the new node becomes the new head
    this.len += 1;
};

/** 
 * @param {number} val
 * @return {void}
 */
FrontMiddleBackQueue.prototype.pushMiddle = function(val) {
    if (this.len <= 1) {
        this.pushFront(val);
        return;
    }
    let cur = this.head;
    for (let i = 1; i < Math.floor(this.len / 2); i++) { // we go to previous node of median
        cur = cur.next;    
    }
    let newNode = new ListNode(val);
    let next = cur.next;
    cur.next = newNode;
    newNode.prev = cur;
    newNode.next = next;
    if (next) next.prev = newNode;
    this.len += 1;
};

/** 
 * @param {number} val
 * @return {void}
 */
FrontMiddleBackQueue.prototype.pushBack = function(val) {
    if (this.len === 0) {
        this.pushFront(val);
        return;
    }
    
    let newNode = new ListNode(val);
    this.tail.next = newNode;
    newNode.prev = this.tail;
    this.tail = newNode; // end node becomes the new tail
    this.len += 1;
};

/**
 * @return {number}
 */
FrontMiddleBackQueue.prototype.popFront = function() {
    if (this.len === 0) {
        return -1;
    }
    let front = this.head;
    let next = front.next;
    if (next) next.prev = null;
    this.head = next;
    this.len -= 1;
    return front.val;
};

/**
 * @return {number}
 */
FrontMiddleBackQueue.prototype.popMiddle = function() {
    if (this.len <= 2) {
        return this.popFront();
    }
    let cur = this.head;
    for (let i = 1; i < Math.ceil(this.len / 2); i++) { // we go to median node
        cur = cur.next;    
    }

    let prev = cur.prev;
    let next = cur.next;
    cur.prev = null;
    cur.next = null;
    if (prev) prev.next = next;    
    if (next) next.prev = prev;
    this.len -= 1;
    return cur.val;
};

/**
 * @return {number}
 */
FrontMiddleBackQueue.prototype.popBack = function() {
    if (this.len <= 1) {
        return this.popFront();
    }
    let end = this.tail;
    let prev = end.prev;
    end.prev = null;
    prev.next = null;
    this.tail = prev;
    this.len -= 1;
    return end.val;
};

/** 
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * var obj = new FrontMiddleBackQueue()
 * obj.pushFront(val)
 * obj.pushMiddle(val)
 * obj.pushBack(val)
 * var param_4 = obj.popFront()
 * var param_5 = obj.popMiddle()
 * var param_6 = obj.popBack()
 */
