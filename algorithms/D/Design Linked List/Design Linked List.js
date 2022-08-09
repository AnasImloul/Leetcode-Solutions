var MyLinkedList = function() {
    this.linked = [];
};

MyLinkedList.prototype.get = function(index) {
    if(index < this.linked.length){
        return this.linked[index];
    }
    return -1;
};

MyLinkedList.prototype.addAtHead = function(val) {
    this.linked.unshift(val);
};

MyLinkedList.prototype.addAtTail = function(val) {
    this.linked.push(val);
};

MyLinkedList.prototype.addAtIndex = function(index, val) {
    if(index <= this.linked.length){
        this.linked.splice(index,0,val);
    }
};

MyLinkedList.prototype.deleteAtIndex = function(index) {
    this.linked.splice(index,1);
};
