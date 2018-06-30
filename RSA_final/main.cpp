#include"Cifrado.h"
int main(){
	string g;
       	RSA r(1024);
        cout<<"¿Que operacion desea hacer?"<<endl;
        cout<<"1.Cifrar\n2.Descifrar\n3.Mostrar Clave Publica"<<endl;
        cin>>g;
        if(g=="1"){
                ofstream fout("Cifrado.txt");
                ZZ a;
                cout<<"Introduzca la clave publica"<<endl;
                cout<<"e: ";
                cin>>a;
		r.e=a;
                cout<<"n: ";
                cin>>a;
                r.n=a;
                cout<<"Introduzca el mensaje"<<endl;
                char oracion[1000];
                cin.getline(oracion,1000);
                cin.getline(oracion,1000);
                string p(oracion);
                fout<<r.Cifrar(p)<<endl;
        }
        else if(g=="2"){
		cout<<r.e<<endl;
		cout<<r.n<<endl;
		string w;
		while(w!="ahora")cin>>w;
                ifstream fin("Cifrado.txt");
                string p;
                fin>>p;
                cout<<r.Descifrar(p)<<endl;
        }
}
