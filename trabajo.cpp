#include <bits/stdc++.h>
using namespace std;
string abecedario="abcdefghijklmnopqrstuvwxyz ";
string Cifrar1(string p){
	for(int i=0;i<p.size();i++)
		p[i]=abecedario[abecedario.size()-abecedario.find(p[i])-1];
	return p;
}
string Descifrar1(string p){
	for(int i=0;i<p.size();i++)
		p[i]=abecedario[abecedario.size()-abecedario.find(p[i])-1];
	return p;
}
string Cifrar2(string p,int clave){
	string rsp;
	//while(p%(clave-1)!=1)p+='x';
	for(int i=0;i<clave;i++){
		int j=i;
		bool x=1;
		while(j<p.size()){
			rsp+=p[j];
			if(x){
				int movida=2*clave-2*i-2;
				if(movida!=0)j+=movida;
				else j+=2*(clave-1);
			}
			else{
				int movida=2*i;
				if(movida!=0)j+=movida;
				else j+=2*(clave-1);
			}
			x=!x;
		}
	}
	return rsp;
}
string Descifrar2(string p,int clave){
	string rsp(p.size(),'x');
	int i=0;
	int k=0;
	while(i<p.size()){
		int j=k;
		bool x=1;
		while(j<p.size()){
			rsp[j]=p[i++];
			if(x){
				int movida=2*clave-2*k-2;
				if(movida!=0)j+=movida;
				else j+=2*(clave-1);
			}
			else{
				int movida=2*k;
				if(movida!=0)j+=movida;
				else j+=2*(clave-1);
			}
			x=!x;
		}
		k++;
	}
	return rsp;
}
int main() {
  char oracion[1000];
  cin.getline(oracion,1000);
	string p(oracion);
	int clave;
	cout<<"ingrese la clave"<<endl;
	cin>>clave;
	p=Cifrar2(Cifrar1(p),clave);
	cout<<p<<endl;
	p=Descifrar1(Descifrar2(p,clave));
	cout<<p<<endl;
	return 0;
}
