var flatten = function(head) {
    var arr = [];
    var temp = head;
    var prev= null;
    while(temp)
        {
            if(temp.child!= null)
                {
                    arr.push(temp.next);
                    temp.next = temp.child;
                    temp.child.prev = temp;
                    temp.child = null;
                }
            prev = temp;
            temp = temp.next
        }
    for(var j=arr.length-1; j>=0; j--)
        {
            if(arr[j] != null)
                mergeOtherLists(arr[j]);
        }
    return head;
	
	function mergeOtherLists(root)
		{
			prev.next=root;
			root.prev=prev;
		   while(root)
			   {
				  prev = root;
				   root = root.next;
			   }
		}
};
