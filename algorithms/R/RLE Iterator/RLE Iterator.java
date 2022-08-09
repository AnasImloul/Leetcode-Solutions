class RLEIterator {
    
    long[] prefixEncoded;
    long processed = 0;
    int l = 0;

    public RLEIterator(int[] encoding) {
        int encodeLen = encoding.length;
        this.prefixEncoded = new long[encodeLen];
        for(int i=0;i<encodeLen;i+=2) {
            long prevPrefixSum = 0;
            if(i > 0) {
                prevPrefixSum = this.prefixEncoded[i-2];
            }
            this.prefixEncoded[i] = encoding[i] + prevPrefixSum;
            this.prefixEncoded[i+1] = encoding[i+1];
        }
    }

    public int next(int n) {
        int r = this.prefixEncoded.length-2;
    
        processed += n;
        
        if(l >= this.prefixEncoded.length || processed > this.prefixEncoded[this.prefixEncoded.length - 2]) {
            return -1;
        }
        
        while(l < r) {
            int m = (l + ((r-l)/2));
            if(m % 2 != 0) {
                m = m - 1;
            }
            if(this.prefixEncoded[m] >= processed) {
                r = m;
            } else {
                l = m + 2;
            }
        }
        return l >= this.prefixEncoded.length ? -1: (int) this.prefixEncoded[l + 1];
    }   
}
