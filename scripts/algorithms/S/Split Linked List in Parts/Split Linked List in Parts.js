// Runtime: 72 ms (Top 6.17%) | Memory: 45.00 MB (Top 9.88%)

var splitListToParts = function(head, k) {
    let length = 0, current = head, parts = [];

    while (current) {
        length++;
        current = current.next;
    }

    let base_size = Math.floor(length / k), extra = length % k;
    current = head;

    for (let i = 0; i < k; i++) {
        let part_size = base_size + (extra > 0 ? 1 : 0);
        let part_head = null, part_tail = null;

        for (let j = 0; j < part_size; j++) {
            if (!part_head) {
                part_head = part_tail = current;
            } else {
                part_tail.next = current;
                part_tail = part_tail.next;
            }

            if (current) {
                current = current.next;
            }
        }

        if (part_tail) {
            part_tail.next = null;
        }

        parts.push(part_head);
        extra = Math.max(extra - 1, 0);
    }

    return parts;
};
