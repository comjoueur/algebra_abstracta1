#include"Bloques.h"

string ZZ_str(ZZ a){
	stringstream buffer;
	buffer<<a;
	return buffer.str();
}
ZZ str_ZZ(string p){
	char oracion[10000];
	strcpy(oracion,p.c_str());
	return conv<ZZ>(oracion);
}
vector<ZZ> precifrado(string p,string diccio,long long x){
	string total;
	int y,j=0,i;
	for(i=0;i<p.size();i++){
		y=diccio.find(p[i]);
		total+=('0'+(y/10));
		total+=('0'+(y%10));
	}
	y=diccio.find('w');
	string basura;
	basura+=('0'+(y/10));
	basura+=('0'+(y%10));
	while(total.size()%(x-1)!=0){
		total+=basura;
	}
	vector<ZZ>vec;
	j=0;
	while(j<total.size()){
		string tmp;
		i=j+x-1;
		while(j<i){
			tmp+=total[j];
			j++;
		}
		vec.push_back(str_ZZ(tmp));
	}
	return vec;
}
string postcifrado(vector<ZZ>vec,long long x){
	string rsp,tmp;
	for(int i=0;i<vec.size();i++){
		tmp=ZZ_str(vec[i]);
		while(tmp.size()<x){
			tmp='0'+tmp;
		}
		rsp+=tmp;
	}
	return rsp;
}
vector<ZZ> predescifrado(string p,long long x){
	vector<ZZ>vec;
	for(int i=0;i<p.size();i+=x){
		string tmp;
		for(int j=i;j<i+x;j++){
			tmp+=p[j];
		}
		vec.push_back(str_ZZ(tmp));
	}
	return vec;
}
string postdescifrado(vector<ZZ>vec,string diccio,long long x){
	string total,rsp;
	for(int i=0;i<vec.size();i++){
		string tmp=ZZ_str(vec[i]);
		while(tmp.size()!=x-1){
			tmp='0'+tmp;
		}
		total+=tmp;
	}
	for(int i=0;i<total.size();i+=2){
		rsp+=diccio[(total[i]-'0')*10+(total[i+1]-'0')];
	}
	return rsp;
}
