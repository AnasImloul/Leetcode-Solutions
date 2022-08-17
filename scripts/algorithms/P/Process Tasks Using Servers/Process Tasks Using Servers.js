 var assignTasks = function(servers, tasks) {
    // create a heap to manage free servers.
    // free servers will need to be prioritized by weight and index
    const freeServers = new Heap((serverA, serverB) => (
        serverA.weight - serverB.weight || serverA.index - serverB.index
    ));

    // create a heap to manage used servers.
    // used servers will need to be prioritized by availableTime, weight and index
    const usedServers = new Heap((serverA, serverB) => (
        serverA.availableTime - serverB.availableTime || 
        serverA.weight - serverB.weight || 
        serverA.index - serverB.index
    ));
    
    // add all the servers into the free servers heap with the time it is available
    // being 0
    for (let i = 0; i < servers.length; i++) {
        freeServers.push({ weight: servers[i], index: i, availableTime: 0 })
    }
    
    const result = [];
    for (let i = 0; i < tasks.length; i++) {
        // find all the servers that are available and add them to the
        // free servers heap
        while (usedServers.size() && usedServers.peak().availableTime <= i) {
            freeServers.push(usedServers.pop());
        }
        // get the free server with the lowest weight or lower index
        // or the usedServer with the lowest start time.
        const server = freeServers.pop() || usedServers.pop();
        result.push(server.index);
        const availableTime = Math.max(i, server.availableTime);
        server.availableTime = availableTime + tasks[i];
        usedServers.push(server);
    }
    return result;
};

class Heap {

    /**
     * Create a Heap
     * @param {function} compareFunction - compares child and parent element
     * to see if they should swap.  If return value is less than 0 it will
     * swap to prioritize the child.
     */
    constructor(compareFunction) {
        this.store = [];
        this.compareFunction = compareFunction;
    }
    
    peak() {
        return this.store[0];
    }
    
    size() {
        return this.store.length;
    }
    
    pop() {
        if (this.size() < 2) {
            return this.store.pop();
        }
        const result = this.store[0];
        this.store[0] = this.store.pop();
        this.heapifyDown(0);
        return result;
    }
    
    push(val) {
        this.store.push(val);
        this.heapifyUp(this.size() - 1);
    }
        
    heapifyUp(child) {
        while (child) {
            const parent = Math.floor((child - 1) / 2);
            
            if (this.shouldSwap(child, parent)) {
                [this.store[child], this.store[parent]] = [this.store[parent], this.store[child]]
                child = parent;
            } else {
                return child;
            }
        }
    }
    
    heapifyDown(parent) {
        while (true) {
            let [child, child2] = [1,2].map((x) => parent * 2 + x).filter((x) => x < this.size());
            if (this.shouldSwap(child2, child)) {
                child = child2;
            }
            
            if (this.shouldSwap(child, parent)) {
                [this.store[child], this.store[parent]] = [this.store[parent], this.store[child]]
                parent = child;
            } else {
                return parent;
            }
        }
    }
    
    shouldSwap(child, parent) {
        return child && this.compareFunction(this.store[child], this.store[parent]) < 0;
    }
}
