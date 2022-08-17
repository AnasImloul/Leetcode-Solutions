var LockingTree = function(parent) {
    this.parents = parent;
    this.children  = [];
    this.locked = new Map();
    
    for (let i = 0; i < this.parents.length; ++i) {
        this.children[i] = [];
    }
    
    for (let i = 1; i < this.parents.length; ++i) {
        const parent = this.parents[i];
        
        this.children[parent].push(i);
    }
};

LockingTree.prototype.lock = function(num, user) {
    if (this.locked.has(num)) return false;

    this.locked.set(num, user);
   
    return true;
};

LockingTree.prototype.unlock = function(num, user) {
    if (!this.locked.has(num) || this.locked.get(num) != user) return false;
    
    this.locked.delete(num);
    
    return true;
};

LockingTree.prototype.upgrade = function(num, user) {
    let isLocked = traverseUp(num, this.parents, this.locked);

    if (isLocked) return false;

    const queue = [];

    isLocked = false;

    queue.push(num);

    while (queue.length > 0) {
        const node = queue.shift();

        if (node != num && this.locked.has(node)) {
            isLocked = true;
            this.locked.delete(node);
        }

        for (let i = 0; i < this.children[node].length; ++i) {
            queue.push(this.children[node][i]);
        }
    } 

    if (!isLocked) return false;

    this.locked.set(num, user);

    return true;


    function traverseUp(num, parents, locked) {
        if (locked.has(num)) return true;
        if (num === 0) return false;

        const parentIdx = parents[num];

        return traverseUp(parentIdx, parents, locked);
    }
};
