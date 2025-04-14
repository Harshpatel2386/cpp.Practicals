#include <iostream>
using namespace std;

int countDigit(int n) {
    int count=0;
    if(n==0) return 1;
    while(n!=0){
        count++;
        n/=10;
    }
    return count;
}

long long concatenateDigits(int n, int k) {
    long long result=n;
    int digits=countDigit(n);

    for(int i=1;i<k;i++) {
        long long temp=n;
        for(int j=0;j<digits;j++) {
            result*=10;
        }
        result+=temp;
    }
    return result;
}

int superDigit(long long n) {

    if(n<10) 
        return n;

    long long sum=0;
    while(n>0) {
        sum+=n%10;
        n/=10;
    }
    return superDigit(sum);
}

int main() {
    int n,k;
    cout<<"Enter n: ";
    cin>>n;
    cout<<"Enter k: ";
    cin>>k;

    long long fullNumber=concatenateDigits(n,k);
    cout<<superDigit(fullNumber)<<endl;

    cout<<"Harsh Hirpara- 24CE040"<<endl;
    return 0;
}
