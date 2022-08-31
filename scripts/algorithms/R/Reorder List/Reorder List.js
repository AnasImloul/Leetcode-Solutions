// Runtime: 170 ms (Top 23.07%) | Memory: 50.4 MB (Top 34.29%)
var reorderList = function(head) {
    const dummyL = new ListNode(-1);
    const dummyR = new ListNode(-1);

    let currL = dummyL;
    let currR = dummyR;
    let past = false;

    let fast = head;
    let slow = head;
    while (slow) {
        if (!fast?.next) {
            past = true
        }

        if (past) {
            currR.next = slow;
            currR = slow;
        } else {
            currL.next = slow
            currL = slow;
        }

        if (fast) {
            fast = fast.next?.next || null;
        }
        slow = slow.next
    }
    currL.next = null;
    currR.next = null;

    dummyR.next = reverse(dummyR.next);
    return merge(dummyL.next, dummyR.next);
};

const merge = (l, r) => {
    const dummy = new ListNode(-1);

    let currL = l;
    let currR = r;
    let last = dummy;

    let count = 0;
    while (currL && currR) {
        if (count % 2 === 0) {
            last.next = currL;
            last = currL;
            currL = currL.next
        } else {
            last.next = currR;
            last = currR;
            currR = currR.next
        }

        count++
    }

    last.next = (currL || currR);
    return dummy.next;
}

const reverse = (head) => {
    let prev = null;
    let curr = head;
    while (curr) {
        const tempPrev = curr.next;
        curr.next = prev;
        prev = curr;
        curr = tempPrev;
    }

    return prev;
}