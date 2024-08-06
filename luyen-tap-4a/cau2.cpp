struct Rectangle {
    // your code goes here
    // Cac bien thanh vien
    int height;
    int length;
    // your code goes here
    // Hai ham khoi tao
    Rectangle() {
        this->height = 0;
        this->length = 0;
    }
    
    Rectangle(int height, int length) {
        this->height = height;
        this->length = length;
    }

    int getPerimeter() {
        // your code goes here
        return 2 * (this->height + this->length);
    }
    
    void print() {
        // your code goes here
        for (int i = 1; i <= this->height; ++i) {
            for (int j = 1; j <= this->length; ++j) {
                if (j == 1 || i == this->height || i == 1 || j == this->length) {
                    cout << '*';
                } else {
                    cout << ' ';
                }
            }
            cout << '\n';
        }
    }
};

int compare(Rectangle a, Rectangle b) {
    // your code goes here
    int chuViA = a.getPerimeter();
    int chuViB = b.getPerimeter();
    if (chuViA < chuViB) return -1;
    else if (chuViA == chuViB) return 0;
    return 1;
}