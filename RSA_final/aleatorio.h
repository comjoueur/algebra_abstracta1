#include "Lib_math.h"
#include <time.h>
ZZ Semilla(long long);
//genera una semilla
ZZ Aleatorio(ZZ,long long,long long,long long,long long);
//genera un numero a partir de la semilla,particion,vueltas,num de bits,posicion aleatoria
ZZ RandomNumber(long long);
ZZ coprimo(ZZ);
bool MillerRabin(ZZ,long long);
ZZ RandomPrime(long long t);
