// Runtime: 380 ms (Top 41.73%) | Memory: 138.9 MB (Top 59.95%)
class TextEditor {
    StringBuilder res;
    int pos=0;

    public TextEditor() {
        res = new StringBuilder();
    }

    public void addText(String text) {
        res.insert(pos,text);
        pos += text.length();
    }

    public int deleteText(int k) {
        int tmp = pos;
        pos -= k;
        if(pos<0) pos=0;
        res.delete(pos,tmp);
        return tmp-pos;
    }

    public String cursorLeft(int k) {
        pos-=k;
        if(pos<0) pos = 0;
        if(pos<10) return res.substring(0,pos);
        return res.substring(pos-10,pos);
    }

    public String cursorRight(int k) {
        pos+=k;
        if(pos>res.length()) pos = res.length();
        if(pos<10) return res.substring(0,pos);
        return res.substring(pos-10,pos);
    }
}
