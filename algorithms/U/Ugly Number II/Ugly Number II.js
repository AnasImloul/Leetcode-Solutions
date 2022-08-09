var nthUglyNumber = function(n) {
let uglyNo = 1;
let uglySet = new Set(); // Set to keep track of all the ugly Numbers to stop repetition
uglySet.add(uglyNo);
let minHeap = new MinPriorityQueue(); // Javascript provides inbuilt min and max heaps, constructor does not require callback function for primitive types but a comparator callback for object data types, to know which key corresponds to the priority
//callback looks like this new MinPriorityQueue((bid) => bid.value)
// if this is confusing, check the documentation here
// https://github.com/datastructures-js/priority-queue/blob/master/README.md#constructor
while(n>1){
    if(!uglySet.has(uglyNo*2)){// add only if the set does not have this ugly no.
        minHeap.enqueue(uglyNo*2,uglyNo*2);// enqueue takes two inputs element and priority respectively, both are same here
        uglySet.add(uglyNo*2);
    }
    if(!uglySet.has(uglyNo*3)){
        minHeap.enqueue(uglyNo*3,uglyNo*3);
        uglySet.add(uglyNo*3);
    }
    if(!uglySet.has(uglyNo*5)){
        minHeap.enqueue(uglyNo*5,uglyNo*5);
        uglySet.add(uglyNo*5);
    }
    uglyNo = minHeap.dequeue().element;//dequeue returns an object with two properties priority and element
    n--;
}

return uglyNo;
};