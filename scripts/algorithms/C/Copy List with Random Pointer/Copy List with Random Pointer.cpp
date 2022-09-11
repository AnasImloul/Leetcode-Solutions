// Runtime: 20 ms (Top 20.49%) | Memory: 11.3 MB (Top 60.56%)
class Solution {
public:
    Node* copyRandomList(Node* head) {

        if(head==NULL){
            return NULL;
        }

        Node* temp= head;
        while(temp!=NULL){
            Node* m= new Node(temp->val);
            m->next= temp->next;
            temp->next= m;
            temp = temp->next->next;
        }
        temp= head;
        while(temp!=NULL){
            if(temp->random==NULL){
                temp->next->random=NULL;
            }
            else{
                temp->next->random= temp->random->next;
            }

            temp= temp->next->next;
        }
        temp= head;
        Node* p= new Node(-1);
        Node* r= p;
        Node* q= head;
        while(q!=NULL){
            q= q->next->next;
            p->next=temp->next;
            p=p->next;
            temp->next=q;
            temp= temp->next;
        }
        p->next=NULL;

        return r->next;
    }
};