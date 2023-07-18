#include <bits/stdc++.h>
using namespace std;

unsigned long int gcd(unsigned long int a, unsigned long int b){
    while(b > 0){
        unsigned long int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

unsigned long int pow(unsigned long int a, unsigned long int x, unsigned long int n){
    unsigned long int result = 1;
    while(x > 0){
        if(x % 2 == 1){
            result = (result * a) % n;
        }
        x = x / 2;
        a = (a * a) % n;
    }
    return result;
}

string Primality_Test(unsigned long int n){
    int k = 100;
    if(n <= 1){
        return "neither prime nor composite.";
    }
    if(n == 2 || n == 3){
        return "Prime";
    }
    while(k > 0){
        unsigned long int a = 2 + rand() % (n - 3);
        if(gcd(n, a) != 1){
            return "composite";
        }
        if(pow(a, n - 1, n) != 1){
            return "composite";
        }
        k--;
    }

    return "Prime";
}

int main(){
    srand(time(NULL));
    unsigned long int n;
    cout << "Enter a number: ";
    cin >> n;

    cout << Primality_Test(n);
    return 0;
}
