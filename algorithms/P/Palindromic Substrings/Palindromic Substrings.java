int n = s.length();
        int count = 0;
        for(int i = 0;i<n;i++){
            int l = i;
            int r = l;
            while(l>=0 && r<n && s[l]==s[r]){
                count++;
                l--;
                r++;
            }
        }
        for(int i = 0;i<n-1;i++){
            int l =  i;
            int r = l+1;
            while(l>=0 && r<n && s[l]==s[r]){
                count++;
                l--;
                r++;
            }
        }
        return count;