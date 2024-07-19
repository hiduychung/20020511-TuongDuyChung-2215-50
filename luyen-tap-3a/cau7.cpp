struct Time {
    // your code goes here
    // Cac bien thanh vien
    int h;
    int m;
    int s;
    // your code goes here
    // Hai ham khoi tao
    Time() {
        this->h = 0;
        this->m = 0;
        this->s = 0;
    }
    
    Time(int h, int m, int s) {
        this->h = h;
        this->m = m;
        this->s = s;
    }

    int second() {
        // your code goes here
        return this->h * 3600 + this->m * 60 + this->s;
    }
    
    void print() {
        // your code goes here
        string hour;
        string minute;
        string second;
        if (this->s < 10) {
            second = "0" + to_string(this->s);
        } else {
            second = to_string(this->s);
        }
        
        if (this->m < 10) {
            minute = "0" + to_string(this->m);
        } else {
            minute = to_string(this->m);
        }
        
        if (this->h < 10) {
            hour = "0" + to_string(this->h);
        } else {
            hour = to_string(this->h);
        }
        
        cout << (hour + ":" + minute + ":" + second + "\n");
    }
};

Time normalize(int h, int m, int s) {
    // your code goes here
    Time t;
    
    if (s > 59) {
        m += (s / 60);
        s = s % 60;
    }
    if (m > 59) {
        h += (m / 60);
        m = m % 60;
    }
    
    t.h = h;
    t.m = m;
    t.s = s;
    
    return t;
}