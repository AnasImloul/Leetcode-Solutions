class MyLinkedList {
    struct Node{
        int val;
        Node *next,*prev;
        Node(int x){val=x,next=prev=NULL;}
    };
    Node *head;int size;
public:
    MyLinkedList() {
        head=NULL;size=0;
    }
    
    int get(int index) {
        if(index>=size or index<0) return -1;
        Node *ptr=head;
        for(int i=0;i<index;i++) ptr=ptr->next;
        return ptr->val;
    }
    
    void addAtHead(int val) {
        Node *newNode=new Node(val);
        newNode->next=head;
        if(head) head->prev=newNode;
        head=newNode;
        size++;
    }
    
    void addAtTail(int val) {
        addAtIndex(size,val);
    }
    
    void addAtIndex(int index, int val) {
        if(index<0 or index>size) return;
        if(index==0){
            addAtHead(val);return;
        }
        Node *newNode=new Node(val);
        Node *prev=head;
        for(int i=0;i<index-1;i++){
            prev=prev->next;
        }
        newNode->next=prev->next;
        prev->next=newNode;
        newNode->prev=prev;
        if(newNode->next) newNode->next->prev=newNode;
        size++;
    }
    
    void deleteAtIndex(int index) {
        if(index>=size or index<0) return;
        if(index==0){
            Node *temp=head;
            head=head->next;
            delete temp;size--;
            return;
        }
        Node *del=head;
        for(int i=0;i<index;i++){
            del=del->next;
        }
        if(del->prev) del->prev->next=del->next;
        if(del->next) del->next->prev=del->prev;
        delete del;
        size--;
    }
};
