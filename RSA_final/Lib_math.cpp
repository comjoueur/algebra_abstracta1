#include "Lib_math.h"
ZZ Mcd(ZZ a,ZZ b){
  ZZ tmp,t;
  if(a<b){
  	tmp=a;
	a=b;
	b=tmp;
  }
  while(b>0){
  	tmp=b<<(NumBits(a)-NumBits(b));
	if(tmp>a)
		t=min(a-(tmp>>1),tmp-a);
	else
		t=min(a-tmp,(tmp<<1)-a);
	if(b>t){
		a=b;
		b=t;
	}
	else{
		a=t;
	}
  }
  return a;
}
pair<ZZ,ZZ> Euclides_ext(ZZ a,ZZ b){
        ZZ gcd=Mcd(a,b);
        ZZ x=a/gcd,y=b/gcd,s1(1),s2(0),t1(0),t2(1);
        ZZ q,tmp;
        pair<ZZ,ZZ>par;
        while(y>0){
                q=x/y;
                tmp=x-q*y;
                x=y;y=tmp;
                tmp=s1-q*s2;
                s1=s2;s2=tmp;
                tmp=t1-q*t2;
                t1=t2;t2=tmp;
        }
        par.first=s1;par.second=t1;
        return par;
}
ZZ Inversa_mod(ZZ a,ZZ b){
        ZZ x=a,y=b,r;
        pair<ZZ,ZZ>par=Euclides_ext(x,y);
	r=par.first%b;
        return r;
}
ZZ InversaMod(ZZ a,ZZ p){
	if(a>p){
		a=a%p;
	}
	ZZ u=p,v=a,r(0),s(1),x;
	long long k=0;
	while(v>0){
		if(u%2==0){
			if(r%2==0){
				u/=2;r/=2;++k;
			}
			else{
				u/=2;r=(r+p)/2;++k;
			}
		}
		else if(v%2==0){
			if(s%2==0){
				v/=2;s/=2;++k;
			}
			else{
				v/=2;s=(s+p)/2;++k;
			}
		}
		else{
			x=u-v;
			if(x>0){
				u=x;r-=s;
				if(r<0)r=r+p;
			}
			else{
				v=(x)*(-1);s-=r;
				if(s<0)s=s+p;
			}
		}
	}
	if(r>p)r-=p;
	if(r<0)r+=p;
	r%=p;
	return r;
}
ZZ PotenciaMod(ZZ r,ZZ p,ZZ m){
	ZZ s(1);
	r=r-(r/m)*m;
	r=(r<0)?r+m:r;
	while(p!=0){
		if((p&ZZ(1))==1){
			s=s*r-((s*r)/m)*m;
			s=(s<0)?s+m:s;
		}
		p>>=1;
		r=r*r-((r*r)/m)*m;
		r=(r<0)?r+m:r;
	}
	return s;
}
ZZ RestoChino(long long tam,ZZ *elementos,ZZ *modulos){
	ZZ mult(1);
	for(int i=0;i<tam;i++){
		mult*=modulos[i];
	}
	ZZ M[tam];
	for(int i=0;i<tam;i++){
		M[i]=mult/modulos[i];
	}
	ZZ inversos[tam];
	for(int i=0;i<tam;i++){
		inversos[i]=Inversa_mod(M[i],modulos[i]);
	}
	ZZ x(0);
	for(int i=0;i<tam;i++){
		x+=elementos[i]*M[i]*inversos[i];
	}
	x=x%mult;
	return x;
}
