class Solution {
    class Tag {
    public:
        string value;
        bool isStart;
        Tag():value(""), isStart(true){}
        Tag(string value, bool isStart):value(value), isStart(isStart){}
    };
    
    pair<int, bool> parseCData(string& s, int pos) {
        //cout << "Parse cdata " << s.substr(pos) << endl;  
        const string startPattern = "<![CDATA[";
        if (s.find(startPattern, pos) != pos) {
            return {pos, false};
        }
        
        const string endPattern = "]]>";
        int end = s.find(endPattern, pos);
        if (end == -1) {
            return {pos, false};
        }
        return {end+3, true};
    }
    
    pair<Tag, bool> parseTag(string& s, int& pos) {
        //cout << "Parse tag " << s.substr(pos) << endl;
        Tag res;
        if (pos+1 == s.length()) return {res, false};
        if (s[pos+1] == '/') {
            res.isStart = false;
            pos++;
        }
        pos++;
        int end = s.find(">", pos);
        if (end == -1 || end-pos < 1 || end-pos > 9) return {res, false};
        string name = s.substr(pos, end-pos);
        for (char& c : name) {
            if (c < 'A' || c > 'Z') return {res, false};
        }
        res.value = name;
        pos = end+1;
        return {res, true};
    }
    bool isValid(vector<Tag>& tags, int start, int end) {
        //cout << start << " " << end << endl;
        if (start > end) return true;
        if (!tags[start].isStart) return false;
        int k = start+1;
        int c = 1;
        while (k <= end && c > 0) {
            if (tags[k].value == tags[start].value) {
                c += (tags[k].isStart) ? 1 : -1;
            }
            k++;
        }
        if (c != 0) return false;
        k--;
        return isValid(tags, start+1, k-1) && isValid(tags, k+1, end);
    }
public:
    bool isValid(string code) {
        vector<Tag> tags;
        int n = code.length();
        int i = 0;
        while (i < n) {
            int k = i;
            while (k < n && code[k] != '<') {
                k++;
            }
            if (k > i) {
                if (i == 0) return false;
                i = k;
                if (i == n) return false;
            } else {
                if (code[k+1] == '!') {
                    if (i == 0) return false;
                    auto cdata = parseCData(code, k);
                    if (!cdata.second) return false;
                    i = cdata.first;
                    if (i == n) return false;
                } else {
                    auto tag = parseTag(code, i);
                    if (!tag.second) return false;
                    if (i == n && tag.first.isStart) return false;
                    tags.push_back(tag.first);
                }
            }
        }
        if (tags.size() < 2) return false;
        int m = tags.size();
        if (tags[0].value != tags[m-1].value || !tags[0].isStart || tags[m-1].isStart){
            return false;
        }
        return isValid(tags, 1, m-2);
    }
};

