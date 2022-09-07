// Runtime: 122 ms (Top 39.97%) | Memory: 81.7 MB (Top 80.48%)
class BrowserHistory {
    int current;
    ArrayList<String> history;
    public BrowserHistory(String homepage) {
        this.history = new ArrayList<>();
        history.add(homepage);
        this.current = 0;
    }

    public void visit(String url) {
        while (history.size()-1 > current) {//delete forward history
            history.remove(history.size()-1);//which means delete everything beyond our current website
        }
        history.add(url);
        ++current;
    }

    public String back(int steps) {
        if (steps>current) current = 0;//if we can't get enough back, we return first thing in our history
        else current -= steps;//if there will be no arrayindexoutofrange error, go back
        return history.get(current);//return current webpage
    }

    public String forward(int steps) {
        //if we are going to move more than our arraylist, then we will return the last element
        if (steps+current>=history.size()) current = history.size() - 1;
        else current += steps;//if there will be no arrayindexoutofrange error, go forward!
        return history.get(current);//return the current webpage
    }
}

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory obj = new BrowserHistory(homepage);
 * obj.visit(url);
 * String param_2 = obj.back(steps);
 * String param_3 = obj.forward(steps);
 */