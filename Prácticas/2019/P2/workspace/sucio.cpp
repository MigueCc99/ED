#include <iostream>
#include <fstream>
#include <string>
using namespace std;

template <class T>
class Vector_Dinamico
{
private:
    /**
 *  @page repVector_Dinamico Rep del TDA Vector_Dinamico
 *  @section invVector_Dinamico Invariante de la representación
 *  El invariante es \e rep.nelementos >= 0
 *                   \e rep.datos apunta a una zona de memoria con capacidad para albergar nelementos de tipo T
 * *  @section faVector_Dinamico Función de abstracción
 *  Un objeto válido @e rep del TDA Vector_Dinamico representa al valor
 *  {rep.datos[0], rep.datos[1], ... , rep.datos[nelementos-1}
 **/
    T *datos;
    int nelementos;
    int reservados;

public:
    Vector_Dinamico(int n)
    {
        assert(n >= 0);
        if (n > 0)
            datos = new T[n];
        reservados = n;
        nelementos = 0;
    }

    Vector_Dinamico(const Vector_Dinamico &original)
    {
        nelementos = original.nelementos;
        reservados = original.reservados;
        if (reservados > 0)
        {
            datos = new T[reservados];
            for (int i = 0; i < nelementos; i++)
                datos[i] = original.datos[i];
        }
        else
            reservados = 0;
    }

    ~Vector_Dinamico()
    {
        if (reservados > 0)
            delete[] datos;
    }

    int size() const
    {
        return reservados;
    }

    int getNumElementos() const
    {
        return nelementos;
    }

    void resize(int n)
    {
        assert(n >= 0);
        if (n != reservados)
        {
            if (n != 0)
            {
                T *nuevos_datos = new T[n];
                if (reservados > 0)
                {
                    int minimo = n < nelementos ? n : nelementos;
                    nelementos = minimo;
                    for (int i = 0; i < minimo; i++)
                        nuevos_datos[i] = datos[i];
                    delete[] datos;
                }
                reservados = n;
                datos = nuevos_datos;
            }
            else
            { //Si n==0
                if (reservados > 0)
                    delete[] datos;
                datos = 0;
                reservados = 0;
                nelementos = 0;
            }
        }
    }

    T &operator[](const int i)
    {
        assert(i >= 0 && i < reservados);
        return datos[i];
    }

    const T &operator[](const int i) const
    {
        assert(i >= 0 && i < reservados);
        return datos[i];
    }

    bool operator==(const T &elemento)
    {
        if (elemento == *this)
            return true;
        else
            return false;
    }

    Vector_Dinamico &operator=(const Vector_Dinamico &original)
    {
        if (this != &original)
            if (reservados > 0)
                delete[] datos;
        reservados = original.reservados;
        nelementos = original.nelementos;
        if (reservados > 0)
        {
            datos = new T[reservados];
            for (int i = 0; i < nelementos; i++)
                datos[i] = original.datos[i];
        }
        return *this;
    }

    void aniadeElemento(const T &elemento)
    {
        if (nelementos < reservados)
        {
            datos[nelementos] = elemento;
            nelementos++;
        }
        else
        {
            resize(reservados + 1);
            datos[nelementos] = elemento;
            nelementos++;
        }
    }

    void borrarElemento(const int posicion)
    {
        if (posicion > 0 && posicion < reservados)
        {
            for (int i = posicion; i < nelementos - 1; i++)
                modificaElemento(i, datos[i + 1]);
            resize(nelementos - 1);
        }
    }

    void modificaElemento(const int posicion, const T &elemento)
    {
        datos[posicion] = elemento;
    }
};

class Ingrediente
{
private:
    /**
 *  @page repIngrediente Rep del TDA Ingrediente
 *  @section invIngrediente Invariante de la representación
 *  El invariante es \e 0 <= rep.hidratos <= 100
 *                      0 <= rep.proteinas <= 100
 *                      0 <= rep.grasas <= 100
 *                      0 <= rep.fibras <= 100
 *                      Tipo = {Verdura, Carne, Pescado}
 * *  @section faIngrediente Función de abstracción
 *  Un objeto válido @e rep del TDA Ingrediente representa al valor
 *  {Nombre, Calorias, Hidratos, Proteinas, Grasas, Fibras, Tipo}
 **/

    string nombre; /**< nombre */
    int calorias;  /**< calorias */
    int hidratos;  /**< hidratos */
    int proteinas; /**< proteinas */
    int grasas;    /**< grasas */
    int fibras;    /**< fibras */
    string tipo;   /**< tipo */

    void copiar(const Ingrediente &ingrediente)
    {
        this->nombre = ingrediente.nombre;
        this->calorias = ingrediente.calorias;
        this->hidratos = ingrediente.hidratos;
        this->proteinas = ingrediente.proteinas;
        this->grasas = ingrediente.grasas;
        this->fibras = ingrediente.grasas;
        this->tipo = ingrediente.tipo;
    }

public:
    Ingrediente()
    {
        nombre = "nulo";
        calorias = 0;
        hidratos = 0;
        proteinas = 0;
        grasas = 0;
        fibras = 0;
        tipo = "nulo";
    }

    Ingrediente(string nombre, int calorias, int hidratos, int proteinas, int grasas, int fibras, string tipo)
    {
        this->nombre = nombre;
        this->calorias = calorias;
        this->hidratos = hidratos;
        this->proteinas = proteinas;
        this->grasas = grasas;
        this->fibras = fibras;
        this->tipo = tipo;
    }

    Ingrediente(const Ingrediente &ingrediente)
    {
        copiar(ingrediente);
    }

    Ingrediente &operator=(const Ingrediente &ingrediente)
    {
        if (this != &ingrediente)
        {
            copiar(ingrediente);
        }
        return *this;
    }

    const string getNombre() const { return nombre; }
    const int getCalorias() const { return calorias; }
    const int getHidratos() const { return hidratos; }
    const int getProteinas() const { return proteinas; }
    const int getGrasas() const { return grasas; }
    const int getFibras() const { return fibras; }
    const string getTipo() const { return tipo; }

    void setNombre(string nombre) { this->nombre = nombre; }
    void setCalorias(int calorias) { this->calorias = calorias; };
    void setHidratos(int hidratos) { this->hidratos = hidratos; }
    void setProteinas(int proteinas) { this->proteinas = proteinas; }
    void setGrasas(int grasas) { this->grasas = grasas; }
    void setFibras(int fibras) { this->fibras = fibras; }
    void setTipo(string tipo) { this->tipo = tipo; }

    friend ostream &operator<<(ostream &os, const Ingrediente &ingrediente);
    friend istream &operator>>(istream &is, Ingrediente &ingrediente);
};

ostream &operator<<(ostream &os, const Ingrediente &ingrediente)
{
    os << "Nombre " << ingrediente.getNombre() << endl;
    os << "Calorias " << ingrediente.getCalorias() << endl;
    os << "Hc " << ingrediente.getHidratos() << endl;
    os << "Proteinas " << ingrediente.getProteinas() << endl;
    os << "Grasas " << ingrediente.getGrasas() << endl;
    os << "Fibra " << ingrediente.getFibras() << endl;
    os << "Tipo " << ingrediente.getTipo() << endl;

    return os;
}

istream &operator>>(istream &is, Ingrediente &ingrediente)
{
    string nom, tip, cal, hc, pro, gra, fib;
    char delim = ';';
    std::getline(is, nom, delim);
    std::getline(is, cal, delim);
    std::getline(is, hc, delim);
    std::getline(is, pro, delim);
    std::getline(is, gra, delim);
    std::getline(is, fib, delim);
    std::getline(is, tip);

    Ingrediente iflujo(nom, stoi(cal), stoi(hc), stoi(pro), stoi(gra), stoi(fib), tip);
    ingrediente = iflujo;

    return is;
}

class Ingredientes
{
private:
    /**
 *  @page repIngrediente Rep del TDA Ingredientes
 *  @section invIngredientes Invariante de la representación
 *  El invariante es \e numIngredientes >0
 * *  @section faIngrediente Función de abstracción
 *  Un objeto válido @e rep del TDA Ingrediente representa al valor
 *  {Nombre, Calorias, Hidratos, Proteinas, Grasas, Fibras, Tipo}
 **/

    Vector_Dinamico<Ingrediente> datos;

public:
    Ingredientes() : datos(0) {}

    void insertarIngrediente(const Ingrediente &ingrediente)
    {
        datos.aniadeElemento(ingrediente);
        //ordenaPorNombre();
    }

    void borrarIngrediente(const int nroIngrediente)
    {
        datos.borrarElemento(nroIngrediente);
    }

    void borrarIngredienteXNombre(const string &nombre)
    {
        bool encontrado = false;
        for (int i = 0; i < getNumIngredientes() && !encontrado; i++)
        {
            if (getIngrediente(i).getNombre() == nombre)
            {
                borrarIngrediente(i);
                encontrado = true;
            }
        }
    }

    void modificaIngrediente(const int i, const Ingrediente &ingrediente)
    {
        datos.modificaElemento(i, ingrediente);
        ordenaPorNombre();
    }

    Ingrediente getIngrediente(const int i)
    {
        return datos[i];
    }

    Ingrediente get(const string &nombre)
    {
        Ingrediente aux;
        for (int i = 0; i < getNumIngredientes(); i++)
            if (getIngrediente(i).getNombre() == nombre)
                aux = getIngrediente(i);
        return aux;
    }

    const int getNumIngredientes() const
    {
        return this->datos.getNumElementos();
    }

    string getInformacion(const string &nombre)
    {
    }

    Ingredientes getIngredientesTipo(const string tipo)
    {
        Ingredientes ingredientesTipo;
        for (int i = 0; i < getNumIngredientes(); i++)
            if (getIngrediente(i).getTipo() == tipo)
                ingredientesTipo.insertarIngrediente(getIngrediente(i));
        return ingredientesTipo;
    }

    Ingrediente &operator[](const int i)
    {
        return datos[i];
    }

    const Ingrediente &operator[](const int i) const
    {
        return datos[i];
    }

    void ordenaPorNombre()
    {
        Ingrediente aux;
        for (int i = 1; i < getNumIngredientes(); i++)
            for (int j = 0; j < getNumIngredientes() - 1; j++)
                if (getIngrediente(j).getNombre() > getIngrediente(j + 1).getNombre())
                {
                    aux = getIngrediente(j);
                    modificaIngrediente(j, getIngrediente(j + 1));
                    modificaIngrediente(j + 1, aux);
                }
    }

    void ordenaPorTipo()
    {
        Ingrediente aux;
        for (int i = 1; i < getNumIngredientes(); i++)
            for (int j = 0; j < getNumIngredientes() - 1; j++)
                if (getIngrediente(j).getTipo() > getIngrediente(j + 1).getTipo())
                {
                    aux = getIngrediente(j);
                    modificaIngrediente(j, getIngrediente(j + 1));
                    modificaIngrediente(j + 1, aux);
                }
    }

    void imprimirPorTipo(ostream &os)
    {
        ordenaPorTipo();
        os << *this;
    }

    friend ostream &operator<<(ostream &os, const Ingredientes &ingredientes);
    friend istream &operator>>(istream &is, Ingredientes &ingredientes);
};

ostream &operator<<(ostream &os, const Ingredientes &ingredientes)
{
    for (int i = 0; i < ingredientes.getNumIngredientes(); i++)
    {
        os << ingredientes[i];
        os << endl;
    }
    return os;
}

istream &operator>>(istream &is, Ingredientes &ingredientes)
{
    Ingrediente aux;
    string linea;
    getline(is, linea);
    int cont = 0;
    while (cont != 371)
    {
        is >> aux;
        ingredientes.insertarIngrediente(aux);
        cont++;
    }
    //ingredientes.ordenaPorNombre();
    return is;
}

void MuestraParametros()
{

    cout << "1.- Dime el nombre del fichero con los ingredientes" << endl;
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        MuestraParametros();
        return 0;
    }
    /******************************************************************************************/
    //SECTION 1: Test sobre la lectura de un ingrediente
    //Ingrediente debe tener operadores de consulta y de modificacion por cada parametros
    //ademas de sobrecarga de lectura y escritura
    string nf = argv[1];
    ifstream f(nf);
    if (!f)
    {
        cout << "No puedo abrir " << nf << endl;
        return 0;
    }
    //Quitamos la primera linea
    string linea;
    getline(f, linea);

    Ingrediente i;
    f >> i;
    cout << "Leido ingrediente:" << endl;
    cout << "Nombre " << i.getNombre() << endl;
    cout << "Calorias " << i.getCalorias() << endl;
    cout << "Hc " << i.getHidratos() << endl;
    cout << "Proteinas " << i.getProteinas() << endl;
    cout << "Grasas " << i.getGrasas() << endl;
    cout << "Fibra " << i.getFibras() << endl;
    cout << "Tipo " << i.getTipo() << endl;
    cout << endl
         << "Ahora probamos la sobrecarga de salida:\t" << i << endl;

    cout << "\n Pulsa una tecla para continuar...." << endl;
    cin.get();
    /******************************************************************************************/
    //SECTION 2: Test sobre el objeto Ingredientes. En primer lugar comprobamos que la sobrecarga de entrada/salida
    //esta bien. Y por lo tanto la operación de insertar
    //Ponemos el puntero del fichero al principio

    f.seekg(0);
    Ingredientes all_ingre;
    cout << "Lectura de todos los ingredientes" << endl;
    f >> all_ingre;

    //Comprobamos que hemos hecho bien la lectura
    cout << "Los ingredientes ordenados por nombre..." << endl
         << endl;
    cout << all_ingre << endl;
    ;
    cout << "Pulse una tecla para continuar..." << endl
         << endl;
    cin.get();

    /******************************************************************************************/
    //Section 3: Sobre ingredientes comprobamos  que la indexacion por tipo funciona

    cout << "Imprimos por tipo " << endl;
    all_ingre.imprimirPorTipo(cout);

    cout << endl
         << "Pulse una tecla para continuar..." << endl
         << endl;
    cin.get();

    /******************************************************************************************/
    //SECTION 4: Sobre ingredientes comprobamos consultar por nombre, size y borrar
    /*
  cout<<endl<<endl;
  cout << "El numero de ingredientes son " << all_ingre.getNumIngredientes() << endl;
  //all_ingre.getNumIngredientes();
  
  cout<<"Dime un nombre de ingrediente:";
  string n;
  getline(cin,n);
  Ingrediente ing=all_ingre.get(n);
  if (ing.getNombre()!="Undefined"){
    cout<<"Información del ingrediente "<<ing<<endl;
    cout<<"Pulse una tecla para continuar...."<<endl;
    cin.get();
    
    //borra por nombre del ingrediente
    all_ingre.borrarIngredienteXNombre(n);
    cout<<"Tras el borrado de "<<ing.getNombre()<<" los ingredientes son:"<<endl<<all_ingre;
    cout << "Numero de ingredientes tras el borrado son " << all_ingre.getNumIngredientes() << endl;
    cout<<"Pulse una tecla para continuar ...."<<endl;
    cin.get();
    cout<<"Ahora los vemos ordenados por tipo"<<endl;
    all_ingre.imprimirPorTipo(cout);
   }
   else{
	   cout<<"El ingrediente "<<n<<" no aparece "<<endl;
    
   }
  cout<<endl<<"Pulse una tecla para continuar..."<<endl<<endl;
  cin.get();
  */
    /******************************************************************************************/
    //SECTION 5: Obtiene los tipos diferentes y los  ingredientes de un tipo concreto
    /*
   VD<string> tipos=all_ingre.getTipos();
   cout<<"Los tipos de alimentos son:"<<endl;
   for (int i=0;i<tipos.size(); ++i){
      cout<<tipos[i]<<endl;
   }
   cout<<"Pulse una tecla para continuar "<<endl;
   cin.get();
  
   string tipo="Molusco";
   ingredientes ingre_tipo=all_ingre.getIngredienteTipo(tipo);
   cout<<"Los ingredientes de tipo "<<tipo<<" son: "<<endl<<ingre_tipo<<endl;
*/
}