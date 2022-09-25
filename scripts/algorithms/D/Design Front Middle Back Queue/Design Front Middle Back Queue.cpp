// Runtime: 112 ms (Top 10.29%) | Memory: 20 MB (Top 68.57%)
struct Node {
    int val;
    Node *prev, *next;
    Node() {
        val = 0, prev = next = NULL;
    }

    Node(int x) {
        val = x, prev = next = NULL;
    }

    Node(int x, Node *p, Node *n) {
        val = x, prev = p, next = n;
    }
};

class FrontMiddleBackQueue {
    Node *head;
    int size;
public:
    FrontMiddleBackQueue() {
        head = NULL;
        size = 0;
    }

    void pushFront(int val) {
        head = new Node(val, NULL, head);
        if(head->next) {
            head->next->prev = head;
        }
        size++;
    }

    void pushMiddle(int val) {
        if(size == 0) {
            head = new Node(val);
            size++;
            return;
        }

        if(size == 1) {
            pushFront(val);
            return;
        }

        Node *ptr = NULL;
        int n = size/2;
        while(n--) {
            if(ptr == NULL)
                ptr = head;
            else
                ptr = ptr->next;
        }

        // Even or Odd push to next of ptr
        Node *next = ptr->next;
        ptr->next = new Node(val, ptr, next);
        if(next)
            next->prev = ptr->next;
        size++;
    }

    void pushBack(int val) {
        Node *ptr = head;
        if(ptr == NULL)
            head = new Node(val);
        else {
            while(ptr->next) {
                ptr = ptr->next;
            }
            ptr->next = new Node(val, ptr, NULL);
        }
        size++;
    }

    int popFront() {
        if(size == 0)
            return -1;
        int val = head->val;
        head = head->next;
        if(head)
            head->prev = NULL;
        size--;
        return val;
    }

    int popMiddle() {
        if(size == 0)
            return -1;

        if(size == 1) {
            int val = head->val;
            head = NULL;
            size--;
            return val;
        }

        int n = size/2;
        Node *ptr = NULL;
        while(n--) {
            if(ptr == NULL)
                ptr = head;
            else
                ptr = ptr->next;
        }

        int val = -1;
        Node *temp = NULL;

        if(size & 1) { // Odd size delete ptr->next
            val = ptr->next->val;
            temp = ptr->next->next;
            ptr->next = temp;
            if(temp)
                temp->prev = ptr;
        } else { // Even size delete ptr
            if(ptr == head) {
                val = popFront();
                size++; // since decreased by popFront
            }
            else {
                val = ptr->val;
                ptr->prev->next = ptr->next;
                ptr->next->prev = ptr->prev;
            }
        }
        size--;
        return val;
    }

    int popBack() {
        if(size == 0)
            return -1;
        if(size == 1) {
            int val = head->val;
            head = NULL;
            size = 0;
            return val;
        }

        Node *ptr = head;
        while(ptr->next) {
            ptr = ptr->next;
        }

        if(ptr->prev)
            ptr->prev->next = NULL;
        size--;
        return ptr->val;
    }
};