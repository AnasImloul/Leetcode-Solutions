class NumArray {
    SegmentTree s;
    public NumArray(int[] nums) {
        s = new SegmentTree(nums);
        s.root = s.build(0, s.arr.length, s.arr);//build returns root Node of what it built
    }
    
    public void update(int index, int val) {
        int oldvalue = s.arr[index];//Find old value with traditional array, which is O(1) time complexity
        s.arr[index] = val;//Set our array so that there will be no contradictions if we ever rebuild.
        //If we are going use build function only once, then we don't need to update our traditional array. 
        s.update(s.root, val, index, oldvalue);//Call class' function
    }
    
    public int sumRange(int left, int right) {
        return s.rangeSum(s.root, left, right);
    }
}

class Node {
    int s;//inclusive label
    int e;//inclusive label
    int val;
    Node left;
    Node right;
}

class SegmentTree {
    Node root;
    int[] arr;

    SegmentTree(int [] arr) {
        this.arr = arr;
    }

    public Node build(int start, int end, int[] arr) {
        //Start and End integers have nothing to do with building of our SegmentTree, you may ignore them for now
        //They are needed for querying and updating, so that we can use binary search.
        Node temp = new Node();
        if (arr.length == 1) {//which means we are setting a node equal to an element of arr
            temp.val = arr[0];
            temp.s = start;
            temp.e = end-1;//to make it inclusive
        } else if (arr.length == 0 || start > end || start < 0 || end < 0) {
            return new Node();// may be better
        } else {
            //left = build(start, mid but add 1 if array's length is not divisible by 2, left half of the passed array)
            temp.left = build(start, (start+end)/2 + (arr.length % 2 == 1 ? 1 : 0), Arrays.copyOfRange(arr, 0, arr.length/2 + (arr.length % 2 == 1 ? 1 : 0)));
            //right = build(start, mid but add 1 if array's length is not divisible by 2, right half of the passed array)
            temp.right = build((start+end)/2 + (arr.length % 2 == 1 ? 1 : 0), end, Arrays.copyOfRange(arr, arr.length/2 + (arr.length % 2 == 1 ? 1 : 0), arr.length));
            temp.val = temp.left.val + temp.right.val;
            temp.s = start;
            temp.e = end-1;//to make it inclusive
        }
        return temp;//return this Node to one upper call so that this can be a child of it's parent
    }
    
    public int rangeSum(Node node, int l, int r) {
        if(node == null)
        {
            //Range is completely outside given range
            return 0;
        }
        if(l <= node.s && node.e <= r)
        {
            //Range is completely inside given range
            return node.val;
        }
        //Range is partially inside and partially outside the given range
        int mid = (node.s + node.e) / 2;
        int left = 0;
        int right = 0;
        if (l <= mid) {
            //For example let's say root's borders are 0:3, l,r=1:2
            //Then mid will be 1, then we will go into both directions because 1<=1, and 2>=1
            //Our next calls will be rS(root.left(which is 0:1), 1, 2) and rS(root.right(which is 2:3), 1, 2)
            //Left call's mid will be mid = (0+1)/2 = 0
            //Then 1<=0 ? No it's not, this is why left call's variable named left will be 0
            //Then 2>=0 ? Yes, we will call rS(root.left.right(which is 1:1), 1, 2)
            //Our left call's right call:
            //1:1 is completely inside 1:2, return the value it holds(equals to arr[1] if our arr is up to date)
            //Our original call's left will be arr[1]
            //Let's calculate our first right function
            //With same reasoning, our right function will go to left and be root.right.left(which is 2:2)
            //Our original call's right will be arr[2]
            //Our original/first function will return left + right, which is in fact [1:2] inclusive
            left = rangeSum(node.left, l, r);
        } 
        if (r >= mid) {
            right = rangeSum(node.right, l, r);
        }
        return (left + right);
    }
    //What we are doing is, going downwards in our tree while we update the values we touch upon
    //We need to update root always, since it is sum of every element
    //After that we find mid which is mid value of our current node's start and end(inclusive)
    //At first call this will be (0+arr.length)/2 => mid
    //If given idx is bigger than mid, then we need to keep searching at right branch
    //That is why we call the function with root.right as our new root
    //If given idx is smaller and equals to mid, then we search at left branch
    //Why did we include equality too? Because I built my tree this way.(where equal things go left)
    //If idx is between our root's borders then we will decrease by the old value, increase by the new value.
    //If root equals null, we won't do anything
    //We update our traditional array at above.
    public void update(Node root, int value, int idx, int oldvalue) {
        if (root == null) {
            return;
        }
        int mid = (root.e + root.s) / 2;
        if (idx <= root.e && idx >= root.s) {
            root.val -= oldvalue;
            root.val += value;
        } if (idx > mid) {
            update(root.right, value, idx, oldvalue);
        } else if (idx <= mid) {
            update(root.left, value, idx, oldvalue);
        }
    }
}
