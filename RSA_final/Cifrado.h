#include "Bloques.h"
#include "aleatorio.h"
#include "Lib_math.h"
class RSA{
	string diccionario="abcdefghijklmnopqrstuvwxyz.,-_()ABCDEFGHIJKLMNOPQRSTUVWXYZ 0123456789";
	ZZ d,p1,p2;
	long long t;
	public:
	ZZ e,n;
	RSA(long long);
	string Cifrar(string);
	string Descifrar(string);
};
