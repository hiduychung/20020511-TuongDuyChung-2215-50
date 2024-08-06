struct Complex {
    // your code goes here
    // Cac bien thanh vien
    int a;
    int b;
    // your code goes here
    // Hai ham khoi tao
    Complex() {
        a = 0;
        b = 0;
    }
    
    Complex(int _a, int _b) {
        a = _a;
        b = _b;
    }

    double abs() {
        // your code goes here
        return sqrt(a * a + b * b);
    }
    
    void print() {
        // your code goes here
        if (b == 0) {
            cout << a;
        } else if (b < 0) {
            if (a != 0) {
                if (b != -1)
                    cout << a << b << 'i';
                else
                    cout << a << "-i";
            } else {
                if (b != -1)
                    cout << b << 'i';
                else
                    cout << "-i";
            }
        } else {
            if (a != 0) {
                if (b != 1)
                    cout << a << '+' << b << 'i';
                else 
                    cout << a << "+i";
            } else {
                if (b != 1)
                    cout << '+' << b << 'i';
                else 
                    cout << "i";
            }
        }
        cout << '\n';
    }
};

Complex add(Complex a, Complex b) {
    // your code goes here
    Complex ans;
    ans.a = a.a + b.a;
    ans.b = a.b + b.b;
    
    return ans;
}