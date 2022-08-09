class Solution {
public:

void add1(vector<int>& arr) {
    
    if(arr.back() < 9) {
        arr.back()++;
        return ;
    }
    
    reverse(begin(arr),end(arr));
    int carry = 1;
    
    for(int i=0;i<arr.size();i++) {
        
        if(arr[i] < 9) {arr[i]++;carry=0;break;}
        
        arr[i] = 0;
        carry = 1;
    }
    
    if(carry == 1) arr.push_back(1);
    reverse(begin(arr),end(arr));
}

int compress(vector<char>& chars) {
    
    int i=0;
    for(int j=0;j<chars.size();j++) {
        
        if(j == chars.size()-1 or chars[j] != chars[j+1]) {
            chars[i++] = chars[j];
        }
        
        else {
            
            vector<int> cnt{0};
            char ch = chars[j];
            while(j < chars.size()and chars[j] == ch) {
                j++;
                add1(cnt);
            }
            
            j--; // bcoz j will be incremented in for loop updation condition.
            chars[i++] = ch;
            
            for(auto& it:cnt)
                chars[i++] = '0'+it;
            
        }
    }
    chars.erase(chars.begin()+i,chars.end());
    return i;
}
