// Runtime: 116 ms (Top 31.18%) | Memory: 43.8 MB (Top 89.57%)
var rotateRight = function(head, k) {
    if(k === 0 || !head) return head;

    let n = 0;
    let end = null;

    let iterator = head;
    while(iterator) {
        n += 1;
        end = iterator;
        iterator = iterator.next;
    }

    const nodesToRotate = k % n;
    if(nodesToRotate === 0) return head;

    let breakAt = n - nodesToRotate;
    iterator = head;
    while(breakAt - 1 > 0) {
        iterator = iterator.next;
        breakAt -= 1;
    }

    const newHead = iterator.next;
    iterator.next = null;
    end.next = head;

    return newHead;
};