#include"aleatorio.h"
ZZ Semilla(long long t){
	t=t/10+1;
	ZZ x=ZZ(0),y=ZZ(0);
	long long n;
	long long f1;
	long long p1=(long long)(&f1)+(long long)(clock());
	while(NumBits(x)<t){
		n+=(long long)(&p1);
		if(n<0)n=n*-1;
		x=(x<<4)+n;
	}
	x=x>>(NumBits(x)-t);
	n=0;
	long long f2;
	long long p2=(long long)(&f2);
	while(NumBits(y)<t){
		n+=(long long)(&p2);
		if(n<0)n=n*-1;
		y=(y<<3)+n;
	}
	y=y>>(NumBits(y)-t);
	y>>=1;
	ZZ rsp(0);
	for(int i=0;i<t;i++){
		rsp<<=1;
		rsp+=(x&ZZ(1))^(y&ZZ(1));
		x>>=1;
		y>>=1;
	}
	return rsp;
}

ZZ Aleatorio(ZZ n,long long particion,long long vueltas, long long nbits,long long posicion){
	bool arr[nbits];
	ZZ tmo=n;
	int bet=NumBits(n);
	for(int i=0;i<bet;i++){
		arr[i]=((tmo & ZZ(1))==ZZ(1));
		tmo>>=1;
	}
	for(int i=bet;i<nbits;i++){
		arr[i]=arr[i-bet]^arr[i-bet+1];
	}
	long long t=nbits/particion;
	for(int k=0;k<vueltas;k++){
		for(int i=0;i<nbits;i+=2*t){
			bool u;
			if(i+posicion-1<nbits)u=arr[i+posicion-1]^arr[i];
			for(int j=i;j<nbits &&j<i+t-1;j++){
				arr[j]=arr[j+1];
			}
			if(i+t<nbits)arr[i+t-1]=u;
			if(i+posicion-1<nbits)u=arr[i+posicion-1]^arr[i+2*t-1];
			for(int j=i+2*t-1;j<nbits && j>i+t;j--){
				arr[j]=arr[j-1];
			}
			if(i+t<nbits)arr[i+t]=u;
		}
		for(int i=0;i<nbits;i+=2*t){
			for(int j=i;j<nbits && j+t<nbits && j<i+t;j++){
				bool tmp=arr[j+t];
				arr[j+t]=arr[j];
				arr[j]=tmp;
			}
		}
	}
	arr[0]=1;
	arr[nbits-1]=1;
	ZZ rsp=ZZ(0);
	for(int i=0;i<nbits;i++){
		rsp=(rsp<<1)+arr[i];
	}
	return rsp;
}
long long rf=0;
long long vueltas=0;
ZZ RandomNumber(long long t){
	ZZ s=Semilla(t);
	long long particion=t/10+1;
	long long yum=t/particion+1;
	ZZ n=Aleatorio(s,particion,vueltas,t,rf);
	vueltas=(vueltas+1)%70;
	rf=(rf+1)%particion;
	return n;
}
ZZ coprimo(ZZ n){
	ZZ a;
	do{
		a=RandomBnd(n-3)+2;
	}
	while(Mcd(a,n)!=1);
	return a;
}
bool MillerRabin(ZZ n,long long t){
	int r=conv<int>(n-(n/6)*6);
	if(r!=1 && r!=5)return 0;
	ZZ a,b,m=n-1;
	int k=0;
	while((m&ZZ(1))==0){
		m>>=1;
		++k;
	}
	bool rsp;
	for(int j=0;j<t;++j){
		a=RandomBnd(n-3)+2;
		rsp=0;
		b=PotenciaMod(a,m,n);
		if(b==1 || b==n-1){
			rsp=1;
		}
		if(!rsp){
			for(int i=0;i<k-1 && !rsp;i++){
				b=(b*b)-((b*b)/n)*n;
				if(b==1){
					return 0;
				}
				else if(b==n-1){
					rsp=1;
				}
			}
		}
		if(rsp==0){
			return 0;
		}
	}
	return 1;
}
ZZ RandomPrime(long long t){
	int arr[10]={3,5,7,11,13,17,19,23,29,31};
	bool b;
	ZZ a;
	long long x=0;
	do{
		x++;
		if(x>400) return RandomPrime(t);
		b=1;
		a=RandomNumber(t);
		for(int i=0;b && i<10;i++){
			b=b && (a%arr[i]!=0);
		}
		b=b && MillerRabin(a,10);
	}
	while(!b);
	return a;
}
