class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if(!head or !head->next or !head->next->next) return {-1,-1};
        int mini = 1e9;
        int prevInd = -1e9;
        int currInd = 0;
        int start = -1e9;
        int prev = head->val;
        head = head->next;

        while(head->next){
            if(prev<head->val and head->next->val<head->val){
                mini = min(mini,currInd-prevInd);
                prevInd = currInd;
                if(start==-1e9) start = currInd;
            }
            if(prev>head->val and head->next->val>head->val){
                mini = min(mini,currInd-prevInd);
                prevInd = currInd;
                if(start==-1e9) start = currInd;
            }
            prev = head->val;
            head = head->next;
            currInd++;
        }

        if(start!=prevInd) return {mini,prevInd-start};
        return {-1,-1};
    }
};