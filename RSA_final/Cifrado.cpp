#include "Cifrado.h"
RSA::RSA(long long nbits){
	p1=RandomPrime(nbits);
	p2=RandomPrime(nbits);
	n=p1*p2;
	ZZ f=(p1-1)*(p2-1);
	e=coprimo(f);
	d=Inversa_mod(e,f);
	t=ZZ_str(n).size();
}
string RSA::Cifrar(string p){
	t=ZZ_str(n).size();
	vector<ZZ>vec=precifrado(p,diccionario,t);
	for(int i=0;i<vec.size();i++){
		vec[i]=PotenciaMod(vec[i],e,n);
	}
	return postcifrado(vec,t);
}
string RSA::Descifrar(string p){
	t=ZZ_str(n).size();
	ZZ exp1=d%(p1-1);
	ZZ exp2=d%(p2-1);
	vector<ZZ>vec=predescifrado(p,t);
	for(int i=0;i<vec.size();i++){
		ZZ elementos[2];
		elementos[0]=PotenciaMod(vec[i],exp1,p1);
		elementos[1]=PotenciaMod(vec[i],exp2,p2);
		ZZ modulos[2]={p1,p2};
		vec[i]=RestoChino(2,elementos,modulos);
	}
	p= postdescifrado(vec,diccionario,t);
	return p;
}
