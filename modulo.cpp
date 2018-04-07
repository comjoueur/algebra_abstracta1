#include<iostream>
using namespace std;
int modular(int a,int b){
	int r=a-(a/b)*b;
	return (r<0)*b+r;
}
int main(){
	int a,b;
	cin>>a>>b;
	cout<<modular(a,b)<<endl;
	return 0;
}
