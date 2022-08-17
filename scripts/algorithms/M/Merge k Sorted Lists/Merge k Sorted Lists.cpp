// To compare the elements of node
class Comparator{
    
public:
    bool operator()(ListNode* n1, ListNode* n2){
        return n2->val < n1->val;
    }
};

class Solution {
public: 
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        int k=lists.size();
        
        if(k==0) return NULL;
        
        list<ListNode*> ll;
                
        priority_queue<ListNode*, vector<ListNode*>, Comparator> minheap;
        
//         push first element of every subarray in the minheap
        for(int i=0; i<k; i++){
            if(lists[i]) minheap.push(lists[i]);
        }        
        
//          push remaining elements 
        while(!minheap.empty()){
//             take out top element
            ListNode* n =minheap.top(); 
            minheap.pop();
//             push the next element of its same array if exists
            if(n && n->next) minheap.push(n->next);
            
//             minimum elements of the remaining will always be at top
            if(!ll.empty()){
                ll.back()->next=n;
                ll.push_back(n);
            }
            else{
                ll.push_back(n);
            }
        }
        
        return ll.front();
        
    }
};
