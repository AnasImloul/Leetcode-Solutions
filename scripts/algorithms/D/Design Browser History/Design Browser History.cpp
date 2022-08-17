class Node{
public: 
    string url;
    Node* next;
    Node* back;
    Node(string s){
        url = s;
        next = NULL;
        back = NULL;
    }
};

class BrowserHistory {
    Node* head;
public:    
    BrowserHistory(string homepage) {
        head = new Node(homepage);
    }
    
    void visit(string url) {
        Node* ptr = new Node(url);
        head->next = ptr;
        ptr->back = head;
        head = ptr;
    }
    
    string back(int steps) {
        while(head->back && steps--){ head = head->back; }
        return head->url;
    }
    
    string forward(int steps) {
        while(head->next && steps--){ head = head->next; }
        return head->url;
    }
};
