 public int findKthNumber(int n, int k) {
    lexicalorder(n);         
    int a= ans.get(k-1);
    return a;
}

public void lexicalorder(int n)
{
    for(int i=1; i<=9; i++){
        helper(i,n);
    }
}

public void helper(int x, int n){
    if(x<=n){
        ans.add(x);
    }
    else{
        return;
    }
    for(int i=0; i<=9; i++){
        helper(x*10+i, n);
    }
}
