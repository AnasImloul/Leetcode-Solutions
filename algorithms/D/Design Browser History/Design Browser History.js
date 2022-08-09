var BrowserHistory = function(homepage) {
    this.page = {
        url: homepage,
        back: null,
        next: null,
    };
};

BrowserHistory.prototype.visit = function(url) {
    this.page.next = {
        url,
        back: this.page,
        next: null
    };
    this.page = this.page.next;
};

BrowserHistory.prototype.back = function(steps) {
    while (this.page.back && steps) {
        this.page = this.page.back;
        steps--;
    }
    
    return this.page.url;
};

BrowserHistory.prototype.forward = function(steps) {
    while (this.page.next && steps) {
        this.page = this.page.next;
        steps--;
    }
    
    return this.page.url;
};
