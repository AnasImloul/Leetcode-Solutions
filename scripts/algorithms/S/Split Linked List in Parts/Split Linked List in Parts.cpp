// Runtime: 15 ms (Top 36.14%) | Memory: 8.9 MB (Top 57.65%)
class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k)
    {
       vector<ListNode*>ans;
       int len=0;
        ListNode*temp=head;
       while(temp!=NULL)
           len++,temp=temp->next;

       int y=len/k , z=len%k;

       while(head !=NULL)
       {
           ans.push_back(head);
           int count=1;
           while(head!=NULL && count<y)
                 head=head->next,count++;

           if(z && y)
           {
               head=head->next;z--;
           }
           if(head==NULL) continue;
           ListNode*temp=head->next;
           head->next=NULL;
           head=temp;
       }
       while(ans.size()<k)
       {
           ans.push_back(NULL);
       }

       return ans;
    }
};