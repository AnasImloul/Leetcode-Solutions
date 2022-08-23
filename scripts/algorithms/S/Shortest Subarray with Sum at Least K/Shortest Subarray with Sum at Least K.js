// Runtime: 127 ms (Top 95.65%) | Memory: 69.9 MB (Top 9.78%)
/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var DoublyLinkedList = function(sum = "DUMMY", index = "DUMMY") {
    this.property = {sum, index}
    this.prev = null
    this.next = null
}

DoublyLinkedList.prototype.deque = function() {
    const dequeNode = this.next

    this.next = dequeNode.next
    dequeNode.next.prev = this

    dequeNode.next = null
    dequeNode.prev = null
    return dequeNode
}

DoublyLinkedList.prototype.pop = function() {
    const dequeNode = this.prev

    this.prev = dequeNode.prev
    dequeNode.prev.next = this

    dequeNode.next = null
    dequeNode.prev = null
    return dequeNode
}

DoublyLinkedList.prototype.push = function(node) {
    const prev = this.prev
    const next = this

    node.prev = prev
    node.next = next

    prev.next = node
    next.prev = node
}

var shortestSubarray = function(nums, k) {
    // Steps :-
    // Initalize 3 vaiables :- sum = 0, subArrayLength = Infinity, queue -> []

    const dummyHead = new DoublyLinkedList()
    const dummyTail = new DoublyLinkedList()
    dummyHead.next = dummyTail
    dummyTail.prev = dummyHead

    let queueSize = 0

    let subArraySize = Number.MAX_SAFE_INTEGER
    let sum = 0
    for (let i = 0; i < nums.length; i++) {
        sum += nums[i]

        // Gives one possible answer, if sum is greater than or
        // equal to k
        if (sum >= k)
            subArraySize = Math.min(subArraySize, i+1)

        let lastDequeued

        // Reduce the queue from left till the sum of elements from
        // first index of queue till last index of queue is less than k
        // Each time we constantly update the lastdequeued element
        // As the last lastdequeued will satisfy sum - lastDequeued.sum >= k
        // Thus the range would be i-lastDequeued.property.index
        // (without lastDequeued.property.index)
        while (queueSize > 0 && sum - dummyHead.next.property.sum >= k) {
            queueSize--
            lastDequeued = dummyHead.deque()
        }

        // Using the lastDequeued value to check
        if (lastDequeued !== undefined) {
            subArraySize = Math.min(subArraySize, i-lastDequeued.property.index)
        }

        // Maintaining the monotonic queue
        while (queueSize > 0 && sum <= dummyTail.prev.property.sum) {
            queueSize--
            dummyTail.pop()
        }

        const newNode = new DoublyLinkedList(sum, i)

        dummyTail.push(newNode)
        queueSize++
    }
    return subArraySize === Number.MAX_SAFE_INTEGER ? -1 : subArraySize
};