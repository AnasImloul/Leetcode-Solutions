class Solution {
private:
    void tryOddJump(const int idx,
                    const int val,
                    std::map<int, int>& visitedNode,
                    vector<int>& oddJumpsDP,
                    vector<int>& evenJumpsDP) {
        // looking for equal or bigger element and it's going to be smallest posible
        auto jumpPoint = visitedNode.lower_bound(val);
        // If from jumpPoint exists even jump further, then odd jump will have some value
        if(jumpPoint != visitedNode.end()) oddJumpsDP[idx] = evenJumpsDP[jumpPoint->second];
    }
    
    void tryEvenJump(const int idx,
                     const int val,
                     std::map<int, int>& visitedNode,
                     vector<int>& oddJumpsDP,
                     vector<int>& evenJumpsDP) {
        //looking for strictly bigger element because then I can be sure that previous will be equal or less that val for sure
        auto jumpPoint = visitedNode.upper_bound(val);
        // if it's first element, then there is no equal or less option, so no even jump possible
        if(jumpPoint != visitedNode.begin()) 
            evenJumpsDP[idx] = oddJumpsDP[std::prev(jumpPoint)->second]; // (jumpPoint-1) check if further odd jump is possible from largest element that is <= val 
    }
public:
    int oddEvenJumps(vector<int>& arr) {
        const size_t n = arr.size();
        vector<int> oddJumpsDP(n, 0);
        vector<int> evenJumpsDP(n, 0);
        oddJumpsDP[n-1] = 1;
        evenJumpsDP[n-1] = 1;
        std::map<int, int> visitedNode;
        visitedNode[arr[n-1]] = n-1;
        
        /*
        Idea is to move backward and keep track of posibility of odd and even jumps from each cell.
        This way at any jump we could check if further jumps is possible.
        Example 1:
                          v
            arr = [10,13,12,14,15]
            odd = [ -, -, 0, 1, 1]
            even= [ -, -, -, 0, 1]
            
            Let's say we curently have answers for 14 and 15 and trying to work on 12:
                tryOddJump() -> will give us 14 as only possible odd jump(arr[i] <= arr[j] and arr[j] is the smallest possible value), 
				but there is no EVEN jump from 14 further, 
				so we cache odd jump for 12 as 0 as well. 
				That's why I called thouse variables as oddJumpsDP/evenJumpsDP,
				they are caches for subproblems that helps in later computations.
				Without them we would need to check entire further path starting from each cell and it's not efficient.
        */
        int res = 1;
        for(int i=n-2; i>=0; --i) {
            tryOddJump(i, arr[i], visitedNode, oddJumpsDP, evenJumpsDP);
            tryEvenJump(i, arr[i], visitedNode, oddJumpsDP, evenJumpsDP);
            // we alwayse start from 1st jump that is odd jump, so we can add index to the result if odd jump from it is possible
            if(oddJumpsDP[i] == 1) ++res;
            visitedNode[arr[i]] = i;
        }
        
        return res;
    }
};
