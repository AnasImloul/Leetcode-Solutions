// Runtime: 4716 ms (Top 20.00%) | Memory: 181.4 MB (Top 20.00%)

class ArraySegTree{
    // Array to perfrom operations on, range query operation, PointUpdate operation
    constructor(A,op=(a,b)=>a+b,upOp=(a,b)=>a+b,opSentinel=0){
        this.n=A.length,this.t=[...Array(4*this.n+1)],this.op=op,this.upOp=upOp,this.opSentinel=opSentinel
        //root's idx =1
        this.build(A,1,0,this.n-1)
    }
    left=x=>this.t[2*x];right=x=>this.t[2*x+1]
    build(A,idx,left,right){
        if(left==right)
            return this.t[idx]=A[left]
        let mid=(left+right)>>1
        this.build(A,2*idx,left,mid) //go left
        this.build(A,2*idx+1,mid+1,right) //go right
        this.t[idx]=this.op(this.left(idx),this.right(idx)) //merge
    }
    //just specify l,r on actual queries
    //Here queries use the actul indices of the starting array A, so rangeQuery(0,n-1) returns the whole array
    rangeQuery=(l,r,tl=0,tr=this.n-1,idx=1)=>{
        if(l>r)
            return this.opSentinel
        if(l===tl&&r===tr)
            return this.t[idx]
        let mid=(tl+tr)>>1
        return this.op(
                this.rangeQuery(l,Math.min(r,mid),tl,mid,idx*2),
                this.rangeQuery(Math.max(l,mid+1),r,mid+1,tr,idx*2+1)
        )
    }
    //just specify arrIdx,newVal on actual pointUpdates
    pointUpdate=(arrIdx,newVal,tl=0,tr=this.n-1,idx=1)=>{
        if(tl==tr)
            return this.t[idx]=this.upOp(this.t[idx],newVal)
        let mid=(tl+tr)>>1
        if(arrIdx<=mid)
            this.pointUpdate(arrIdx,newVal,tl,mid,2*idx)
        else
            this.pointUpdate(arrIdx,newVal,mid+1,tr,2*idx+1)
        this.t[idx]=this.op(this.left(idx),this.right(idx))
    }
    seachPrefixIndex=(x,start=0,end=this.n-1)=>{
        let s=this.rangeQuery(start,end)
        if(s<x)
            return -1
        if(start===end)
            return start
        let mid=start+end>>1,left=this.rangeQuery(start,mid)
        if( left>=x)
            return this.seachPrefixIndex(x,start,mid)
        else
            return this.seachPrefixIndex(x-left,mid+1,end)
    }
}

var MKAverage = function(m, k) {
    this.A=[],this.m=m,this.k=k,this.div=m-2*k
    this.S1=new ArraySegTree([...Array(1e5+2)].map(d=>0))//indices
    this.S2=new ArraySegTree([...Array(1e5+2)].map(d=>0))//sums
};

/**
 * @param {number} num
 * @return {void}
 */
MKAverage.prototype.addElement = function(num) {
    this.A.push(num)
    this.S1.pointUpdate(num,1)
    this.S2.pointUpdate(num,num)
    if(this.A.length>this.m){
        let z=this.A.shift()
        this.S1.pointUpdate(z,-1)
        this.S2.pointUpdate(z,-z)
    }
};

/**
 * @return {number}
 */
MKAverage.prototype.calculateMKAverage = function() {
    if(this.A.length<this.m)
        return -1

    let S=this.S1.seachPrefixIndex(this.k+1),
        count1=this.S1.rangeQuery(0,S),
        take=(count1-this.k)*S

    let E=this.S1.seachPrefixIndex(this.m-this.k),
        count2=this.S1.rangeQuery(0,E),
        remove=(count2-this.m+this.k)*E

    let midSum=this.S2.rangeQuery(S+1,E)
    return (take+midSum-remove)/this.div>>0
};