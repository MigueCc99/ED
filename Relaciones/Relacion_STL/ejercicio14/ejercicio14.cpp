/*
 * Ejercicio 14
 * Un vector disperso es un vector en el que la inmensa mayoría de sus
 * elementos son nulos. Para representar este tipo de vectores se suele
 * utilizar como representación una lista:
 *
 * template <typename T>
 * class vdisperso{
 *    public:
 *      vdisperso(const vector<T> &v);
 *      void asignar_coeficiente(int i, const T &x);
 *      vector<T> convertir() const;
 *    ...
 *    private:
 *      list< pair<int, T> > coefs;
 *      int n;
 * }
 *
 * De esa forma se ahorra una gran cantidad de espacio. Implementa los dos
 * métodos indicados en la parte pública.
*/

#include <iostream>
#include <list>
#include <vector>

using namespace std;

template <class T>
class vdisperso{
private:

  list<pair<int,T> > coefs;
  int n;

public:

  vdisperso(const vector<T> &v){
    n = 0;
    for(vector<T>::iterator it = v.begin(); it != v.end(); ++it)
      if(*it != 0)
        coefs.push_back(pair<int,T>(n,*it));
  }

  void asignar_coeficiente(int i, const T &x){
    list<pair<int,T> >::iterator it = coefs.begin();
    bool encontrado = false;

    while(!encontrado && it != coefs.end()){
      if(it->first == i){
        it->second = x;
        encontrado = true;
        ++it;
      }
      else
        ++it;
    }

    if(!encontrado)
      coef.push_back(pair<int,T>(i,x));
  }

  vector<T> convertir()const{
    vector<T> v_convertido;
    v_convertido.reserve(n);
    vector<T>::iterator itv = v_convertido.begin();
    int pos = 0;

    list<pair<int,T> >::iterator itl = coefs.begin();

    for(int i = 0; i < n; i++){
      if(itl->first == i){
        v_convertido.push_back(itl->second);
        ++itpar;
      }
      else{
        v_convertido.push_back(0);
        ++itv;
      }
    }
    return v_convertido;
  }

  void imprime_v_disperso(){
		cout << "Vector disperso: " << endl;

		for(list<pair<int,T> >::iterator itl = coefs.begin();; itl != coefs.end(); ++itl)
			cout <<" (" << itl->first << "," << itl->second <<") ";
	}

};

int main(){
	vector<int> vector1, vector2;
	int n;

	cout << "Introduzca valores para rellenar el vector: (<0 para acabar)"
		 << endl;
	cin >> n;
	while( n >= 0){
		vector1.push_back(n);
		cin >> n;
	}

	cout << "Vector con los valores introducidos: " << endl;

	for(vector<int>::iterator it = vector1.begin(); it != vector1.end(); ++it){
		cout << *it<< "  ";
	}

	cout << endl << endl ;
	vdisperso <int>v(vector1);
	v.imprime_v_disperso();

	cout << endl << endl;

	vector2 = v.convertir();

	cout << "Convertido: " << endl;
	for(int i = 0 ; i<vector2.size() ; ++i)
		cout << vector2[i] << " " ;

	cout << endl;
}
