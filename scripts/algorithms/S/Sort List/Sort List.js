// Runtime: 308 ms (Top 36.34%) | Memory: 71.4 MB (Top 24.44%)
function getListSize(head) {
    let curr = head;
    let size = 0;

    while(curr !== null) {
        size += 1;

        curr = curr.next;
    }

    return size;
}

function splitInHalf(head, n) {
    let node1 = head;
    let curr = head;

    for (let i = 0; i < Math.floor(n / 2) - 1; i++) {
        curr = curr.next;
    }

    const node2 = curr.next;
    curr.next = null;

    return [
        node1,
        Math.floor(n / 2),
        node2,
        n - Math.floor(n / 2),
    ]
}

function merge(head1, head2) {
    if (head1.val > head2.val) {
        return merge(head2, head1)
    }

    const head = head1;
    let curr = head1;

    let runner1 = curr.next;
    let runner2 = head2;

    while (runner1 !== null || runner2 !== null) {
        const runner1Value = runner1 ? runner1.val : Infinity;
        const runner2Value = runner2 ? runner2.val : Infinity;

        if (runner1Value < runner2Value) {
            curr.next = runner1;
            runner1 = runner1.next;
        } else {
            curr.next = runner2;
            runner2 = runner2.next;
        }

        curr = curr.next;
    }

    curr.next = null;
    return head;
}

var sortList = function(head) {
    const size = getListSize(head);

    function mergeSort(node, n) {
        if (n <= 1) {
            return node;
        }

        const [node1, n1, node2, n2] = splitInHalf(node, n);
        const [merged1, merged2] = [mergeSort(node1, n1), mergeSort(node2, n2)];

        return merge(merged1, merged2);
    }

    return mergeSort(head, size);
};