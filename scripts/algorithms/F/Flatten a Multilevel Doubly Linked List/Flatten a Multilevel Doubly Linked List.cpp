class Solution {
public:
    Node* flatten(Node* head)
    {
        if(head==NULL) return head;
       Node *temp=head;
       stack<Node*> stk;
       while(temp->next!=NULL || temp->child!=NULL  || stk.size()!=0)
       {
           if(temp->next==NULL && temp->child==NULL && stk.size())
           {
               Node *a=stk.top();
               stk.pop();
               temp->next=a;
               a->prev=temp;
           }
           if(temp->child!=NULL)
           {
               if(temp->next!=NULL)
               {
               Node* a=temp->next;
               a->prev=NULL;
               stk.push(a);
               }
               temp->next=temp->child;
               temp->next->prev=temp;
               temp->child=NULL;
               
           }
           temp=temp->next;
       }
        return head;
    }
};
Feel free to ask in doubt in comment section