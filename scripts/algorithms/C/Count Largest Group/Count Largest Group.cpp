class Solution {
public:
    int cal(int n){
        int sum = 0;
        while(n > 0){
            sum += n%10;
            n /= 10;
        }
        return sum;
    }

    int countLargestGroup(int n) {
        int a[40];
        for(int i=0; i<40; i++) a[i] = 0;

        for(int i=1; i<=n; i++){
            a[cal(i)]++;
        }

        int max = 0;
        int count = 0;
        for(int i=0; i<40; i++){
            if(a[i] > max){
                count = 1;
                max = a[i];
            }
            else if(a[i] == max) count++;
        }

        return count;
    }
};