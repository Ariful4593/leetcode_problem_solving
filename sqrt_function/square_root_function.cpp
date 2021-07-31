#include<iostream>
using namespace std;

int mySqrt(int x) {
        double l = 0, r = 1e9;
        for(int t = 1; t <= 100; t++){
            double m = (l + r) * 0.5;
            if(m * m > x){
                r = m;
            }
            else{
                l = m;
            }
        }

        return (int)l;
    }
int main()
{
    int x;
    cin >> x;
    cout << mySqrt(x);
}
