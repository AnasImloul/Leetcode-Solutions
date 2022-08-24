// Runtime: 134 ms (Top 54.42%) | Memory: 52.1 MB (Top 6.15%)

var getIntersectionNode = function(headA, headB) {
   let node1 = headA;
   let node2 = headB;

    const set = new Set()

    while(node1 !== undefined || node2!== undefined){
        if(node1 && set.has(node1)){
            return node1
        }
        if(node2 && set.has(node2)){
            return node2
        }
        if(node1){
            set.add(node1)
            node1 = node1.next;
        }
        else if(node2){
            set.add(node2)
            node2 = node2.next;
        }
        else {return}
    }
 };