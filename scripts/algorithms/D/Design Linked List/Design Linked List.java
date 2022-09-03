// Runtime: 14 ms (Top 41.30%) | Memory: 50.4 MB (Top 74.99%)
class MyLinkedList {

    public class ListNode {
        public int val;
        public ListNode next;

        public ListNode() {

        }

        public ListNode(int val) {
            this.val = val;
        }

        public ListNode(int val, ListNode next) {
            this.val = val;
            this.next = next;
        }
    }

    private ListNode head;
    private ListNode tail;
    private int length;

    public MyLinkedList() {
        length = 0;
    }

    public int get(int index) {
        if (index > length - 1 || index < 0) return -1;
        int thisIndex = 0;
        ListNode temp = head;
        while (thisIndex != index) {
            temp = temp.next;
            thisIndex++;
        }
        return temp.val;
    }

    public void addAtHead(int val) {
        head = new ListNode(val, head);
        length++;
        if (length == 1) tail = head;
    }

    public void addAtTail(int val) {
        length++;
        if (length == 1) {
            ListNode onlyNode = new ListNode(val);
            head = onlyNode;
            tail = head;
            return;
        }
        tail.next = new ListNode(val);
        tail = tail.next;
    }

    public void addAtIndex(int index, int val) {
        if (index <= length) {
            if (index == 0) {
                addAtHead(val);
                return;
            }
            if (index == length) {
                addAtTail(val);
                return;
            }
            length++;
            ListNode temp = head;
            int thisIndex = 0;
            while (thisIndex != index - 1) {
                temp = temp.next;
                thisIndex++;
            }
            temp.next = new ListNode(val, temp.next);
        }
    }

    public void deleteAtIndex(int index) {
        if (index >= length || index < 0) return;
        length--;
        if (index == 0) {
            head = head.next;
            return;
        }
        ListNode temp = head;
        int thisIndex = 0;
        while (thisIndex != index - 1) {
            temp = temp.next;
            thisIndex++;
        }
        if (index == length) {
            tail = temp;
            temp.next = null;
        }
        else temp.next = temp.next.next;
    }
}