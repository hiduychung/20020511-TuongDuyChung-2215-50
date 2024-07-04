#include <iostream>
#include <cmath>

using namespace std;

void kiem_tra(int a1, int a2, int b1, int b2) {


    if (a1 > a2 && b1 < b2&& abs(a1-a2)%abs(b2-b1)==0  ) {
        cout<<"YES"<<endl;
    }
    else if(a1 < a2 && b1 >b2&& abs(a1-a2)%abs(b2-b1)==0 ){
        cout<<"YES"<<endl;
    }
//    else if()
    else {cout<<"NO"<<endl;}

}

int main() {
    int a1, a2, b1, b2;
    cin >> a1 >>b1 >>a2>>b2;

    kiem_tra(a1, a2, b1,b2);

    return 0;
}
