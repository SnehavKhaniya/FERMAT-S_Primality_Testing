#include <bits/stdc++.h>
using namespace std;

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

unsigned long int no_of_Fliars(unsigned long int n){
    unsigned long int count = 0;
    cout << "\nFliars : ";
    for(unsigned long int a = 2; a < n - 1; ++a){
        if(pow(a, n - 1, n) == 1){
            count++;
            cout << a << " ";
        }
    }
    return count;
}

int main(){
    
    unsigned long int n;
    cout << "Enter a composite number: ";
    cin >> n;

    unsigned long int Fliars = no_of_Fliars(n);
    cout << "\nNo. of Fliars : " << Fliars << endl;
    cout << "Probability of error : " << (double)Fliars / (n - 3);

    return 0;
}