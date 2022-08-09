var getNumberOfBacklogOrders = function(orders) {
    const buyHeap = new Heap((child, parent) => child.price > parent.price)
    const sellHeap = new Heap((child, parent) => child.price < parent.price)
    
    for (let [price, amount, orderType] of orders) {
        
        // sell
        if (orderType) {
            
            // while there are amount to be decremented from the sell,
            // orders to in the buy backlog, and the price of the largest
            // price is greater than the sell price decrement the
            // amount of the order with the largest price by the amount
            while (amount > 0 && buyHeap.peak() && buyHeap.peak().price >= price) {
                if (buyHeap.peak().amount > amount) {
                    buyHeap.peak().amount -= amount
                    amount = 0
                } else {
                    amount -= buyHeap.pop().amount
                }
            }
            
            // if there is any amount left, add it to the sale backlog
            if (amount) {
                sellHeap.push({ price, amount })
            }

        // buy
        } else {
            
            // while there are amount to be decremented from the buy,
            // orders to in the sell backlog, and the price of the smallest
            // price is less than the buy price decrement the
            // amount of the order with the smallest price by the amount
            while (amount > 0 && sellHeap.peak() && sellHeap.peak().price <= price) {
                if (sellHeap.peak().amount > amount) {
                    sellHeap.peak().amount -= amount
                    amount = 0
                } else {
                    amount -= sellHeap.pop().amount;
                }
            }
            
            // if there is any amount left, add it to the buy backlog
            if (amount) {
                buyHeap.push({ price, amount })
            }
        }
    }
    
    // total all of the amounts in both backlogs and return the result
    let accumultiveAmount = 0;
    for (const { amount } of buyHeap.store) {
        accumultiveAmount += amount;
    }
    for (const { amount } of sellHeap.store) {
        accumultiveAmount += amount;
    }
    return accumultiveAmount % 1000000007
};

class Heap {
    constructor(fn) {
        this.store = [];
        this.fn = fn;
    }
    
    peak() {
        return this.store[0];
    }
    
    size() {
        return this.store.length;
    }
    
    pop() {
        if (this.store.length < 2) {
            return this.store.pop();
        }
        const result = this.store[0];
        this.store[0] = this.store.pop();
        this.heapifyDown(0);
        return result;
    }
    
    push(val) {
        this.store.push(val);
        this.heapifyUp(this.store.length - 1);
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
                child = child2
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
        return child && this.fn(this.store[child], this.store[parent]);
    }
}
