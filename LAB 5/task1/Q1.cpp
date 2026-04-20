#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std;

int GCD(int a ,int b){
	if(b==0){
		return a;
	}
	
	return GCD(b,a%b);
}
int main(int argc, char** argv) {
	int gcd= GCD(12,54);
	cout<<gcd;
}
