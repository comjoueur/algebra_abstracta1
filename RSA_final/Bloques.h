#include<bits/stdc++.h>
#include<NTL/ZZ.h>
#include<sstream>
using namespace NTL;
using namespace std;
string ZZ_str(ZZ);
//conversion ZZ a string
ZZ str_ZZ(string);
//conversion string a ZZ
vector<ZZ> precifrado(string,string,long long);
//conversion una cadena mensaje a un conjunto de numeros segun diccio
string postcifrado(vector<ZZ>,long long);
//conversion de un conjunto de numeros cifrados a un cifrado completo
vector<ZZ> predescifrado(string,long long);
//conversion de un cifrado completo a un conjunto de numeros cifrados
string postdescifrado(vector<ZZ>,string,long long);
//conversion de un conjunto de numeros a un string mensaje segun diccio
