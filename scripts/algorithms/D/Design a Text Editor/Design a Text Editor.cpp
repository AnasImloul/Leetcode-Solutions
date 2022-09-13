// Runtime: 380 ms (Top 93.02%) | Memory: 106.3 MB (Top 89.43%)
class TextEditor {
    stack<char> left;
    stack<char> right;
public:
    TextEditor() {

    }

    void addText(string text) {
        for(auto &c : text){
            left.push(c);
        }
    }

    int deleteText(int k) {
        int cnt=0;
        while(!left.empty() and k>0){
            left.pop();
            cnt++;
            k--;
        }
        return cnt;
    }

    string cursorLeft(int k) {
        while(!left.empty() and k>0){
            char c = left.top();left.pop();
            right.push(c);
            k--;
        }
        // returning the last min(10, len) characters to the left of the cursor
        return cursorShiftString();
    }

    string cursorRight(int k) {
        while(!right.empty() and k>0){
            char c = right.top();right.pop();
            left.push(c);
            k--;
        }
        // returning the last min(10, len) characters to the left of the cursor
        return cursorShiftString();
    }

    // function to return the last min(10, len) characters to the left of the cursor
    string cursorShiftString(){
        string rtn = "";
        int cnt=10;
        while(!left.empty() and cnt>0){
            char c = left.top();left.pop();
            rtn += c;
            cnt--;
        }
        reverse(rtn.begin(),rtn.end());
        for(int i=0;i<rtn.size();i++){
            left.push(rtn[i]);
        }
        return rtn;
    }
};