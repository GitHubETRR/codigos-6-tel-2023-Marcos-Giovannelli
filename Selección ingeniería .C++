#include <iostream>
using namespace std;
#define CANT 3

//Clases
class persona 
{
  private:
    string nombre_apellido;
    int edad;
  public:
    void colocar_nom_ap(string);
    void colocar_edad(int);
    int retorno_edad(void);
    string retorno_nombre(void);
};

class cliente : public persona
{
  private:
    string resultado;
  public:
    void colocar_carrera(string);
    string retorno_resultado(void);
    void mostrar_data(string);
};

class ingenieria_industrial 
{
  private:
    string habilidades[CANT] = {"ORGANIZACION", "LIDERAZGO"};
    string intereses[CANT] = {"CONSTRUCCION", "DESARROLLO"};
    string aspiraciones[CANT] = {"FLEXIBILIDAD LABORAL", "CONOCIMIENTOS VARIOS"};
  public:
    bool verificar_habilidades(string);
    bool verificar_intereses(string);
    bool verificar_aspiraciones(string);
};

class ingenieria_electronica
{
  private:
    string habilidades[CANT] = {"PROGRAMACION", "ANALISIS DE CIRCUITOS"};
    string intereses[CANT] = {"NUEVAS TECNOLOGIAS", "COMPUTACION"};
    string aspiraciones[CANT] = {"DESARROLLO DE SOFTWARE","CREACION DE CIRCUITOS COMPLEJOS"};
  public:
    bool verificar_habilidades(string);
    bool verificar_intereses(string);
    bool verificar_aspiraciones(string);
};

class ingenieria_mecanica 
{
  private:
    string habilidades[CANT] = {"DESARROLLO DE PIEZAS MECANICAS", "FABRICACION DE EQUIPOS"};
    string intereses[CANT] = {"SISTEMAS MECANICOS", "FISICA Y MATERIALES"};
    string aspiraciones[CANT] = {"TRABAJOS ELECTRICOS", "FABRICAR MOTORES"};
  public:
    bool verificar_habilidades(string);
    bool verificar_intereses(string);
    bool verificar_aspiraciones(string);
};

//Métodos
void persona::colocar_nom_ap(string nom_ap)
{
  nombre_apellido = nom_ap;
}
void persona::colocar_edad(int ed)
{
  edad = ed;
}

int persona::retorno_edad(void) 
{
  return (edad);
}

string persona::retorno_nombre(void)
{
  return (nombre_apellido);
}


bool ingenieria_industrial::verificar_habilidades(string x)
{
  bool flag = false;
  for (int i = 0; i < CANT; i++)
  {
     if (habilidades[i] == x) flag = true;
  }
  return flag;
}
bool ingenieria_industrial::verificar_intereses(string x)
{
  bool flag = false;
  for (int i = 0; i < CANT; i++)
  {
     if (intereses[i] == x) flag = true;
  }
  return flag;
}
bool ingenieria_industrial::verificar_aspiraciones(string x)
{
  bool flag = false;
  for (int i = 0; i < CANT; i++)
  {
     if (aspiraciones[i] == x) flag = true;
  }
  return flag;
}

bool ingenieria_electronica::verificar_habilidades(string x)
{
  bool flag = false;
  for (int i = 0; i < CANT; i++)
  {
     if (habilidades[i] == x) flag = true;
  }
  return flag;
}
bool ingenieria_electronica::verificar_intereses(string x)
{
  bool flag = false;
  for (int i = 0; i < CANT; i++)
  {
     if (intereses[i] == x) flag = true;
  }
  return flag;
}
bool ingenieria_electronica::verificar_aspiraciones(string x)
{
  bool flag = false;
  for (int i = 0; i < CANT; i++)
  {
     if (aspiraciones[i] == x) flag = true;
  }
  return flag;
}

bool ingenieria_mecanica::verificar_habilidades(string x)
{
  bool flag = false;
  for (int i = 0; i < CANT; i++)
  {
     if (habilidades[i] == x) flag = true;
  }
  return flag;
}
bool ingenieria_mecanica::verificar_intereses(string x)
{
  bool flag = false;
  for (int i = 0; i < CANT; i++)
  {
     if (intereses[i] == x) flag = true;
  }
  return flag;
}
bool ingenieria_mecanica::verificar_aspiraciones(string x)
{
  bool flag = false;
  for (int i = 0; i < CANT; i++)
  {
     if (aspiraciones[i] == x) flag = true;
  }
  return flag;
}

//Prototipos de funciones
string mayus(string);
string pregunta1(void);
string pregunta2(void);
string pregunta3(void);

void corroborar_palabra(string, ingenieria_industrial, ingenieria_electronica, ingenieria_mecanica);
void conteo (void);
void resultado (cliente);

//Variables de tipo int
int cuenta_ing_ind, cuenta_ing_elec, cuenta_ing_mec, conteo_ing_ind_hab, conteo_ing_ind_int, conteo_ing_ind_asp, conteo_ing_elec_hab, conteo_ing_elec_int, conteo_ing_elec_asp, conteo_ing_mec_hab, conteo_ing_mec_int, conteo_ing_mec_asp;

//Programa principal
int main() 
{
  string respuestas, ingenieria, palabra, nombre_apellido;
  cliente entrevistado;
  bool flag = false;
  int edad;
  cout << "Bienvenido al seleccionador de carreras de ingenieria\n";
  cout << "Por favor ingrese su nombre y apellido\n";
  getline(cin, nombre_apellido);
  cout << "Por favor ingrese su edad\n";
  cin >> edad;
  cin.ignore();
  entrevistado.colocar_nom_ap(nombre_apellido);
  entrevistado.colocar_edad(edad);
  cout << "¿Sabés que queres estudiar? Si/No\n";
  cin >> respuestas;
  respuestas = mayus(respuestas);
  if (respuestas == "SI") 
  {
    cout << "¿Es una carrera de ingenieria? Si/No\n";
    cin >> respuestas;
    respuestas = mayus(respuestas);
    if (respuestas == "SI") cout << "Felicidades vas a ser millonario";
    else cout << "Vas a ser pobre el resto de tu vida";
  }
  else 
  {
    cout << "¿Te interesaria alguna ingenieria? Si/No\n";
    cin >> respuestas;
    respuestas = mayus(respuestas);
    if (respuestas == "SI") 
    {
      cout << "Respondé las siguientes preguntas con lo que mas te represente\n";
      flag = true;
    } else cout << "Vas a ser pobre el resto de tu vida";
  }
  if (flag) 
  {
    ingenieria_industrial ing_ind;
    ingenieria_electronica ing_elec;
    ingenieria_mecanica ing_mec;
    cout << "Vamos a empezar con el formulario\n";
    palabra = pregunta1();
    corroborar_palabra(palabra, ing_ind, ing_elec, ing_mec);
    palabra = pregunta2();
    corroborar_palabra(palabra, ing_ind, ing_elec, ing_mec);
    palabra = pregunta3();
    corroborar_palabra(palabra, ing_ind, ing_elec, ing_mec);
    conteo();
    resultado(entrevistado);
  }
  return 0;
}

//Ciclo for para pasar los "si" a mayúscula
string mayus(string x) 
{
  for (auto &c : x)
  {
    c = toupper(c);
  }
  return x;
}

//Funcion de verificacion de a que carrera corresponde la respuesta
void corroborar_palabra(string palabra, ingenieria_industrial ing_ind, ingenieria_electronica ing_elec, ingenieria_mecanica ing_mec)
{
  bool flag = false;
  flag = ing_ind.verificar_habilidades(palabra);
  if (flag) conteo_ing_ind_hab++;
  flag = ing_ind.verificar_intereses(palabra);
  if (flag) conteo_ing_ind_int++;
  flag = ing_ind.verificar_aspiraciones(palabra);
  if (flag) conteo_ing_ind_asp++;
  flag = ing_elec.verificar_habilidades(palabra);
  if (flag) conteo_ing_elec_hab++;
  flag = ing_elec.verificar_intereses(palabra);
  if (flag) conteo_ing_elec_int++;
  flag = ing_elec.verificar_aspiraciones(palabra);
  if (flag) conteo_ing_elec_asp++;
  flag = ing_mec.verificar_habilidades(palabra);
  if (flag) conteo_ing_mec_hab++;
  flag = ing_mec.verificar_intereses(palabra);
  if (flag) conteo_ing_mec_int++;
  flag = ing_mec.verificar_aspiraciones(palabra);
  if (flag) conteo_ing_mec_asp++;
}

void conteo(void)
{
  cuenta_ing_ind = conteo_ing_ind_hab + conteo_ing_ind_int + conteo_ing_ind_asp;
  cuenta_ing_elec = conteo_ing_elec_hab + conteo_ing_elec_int + conteo_ing_elec_asp;
  cuenta_ing_mec = conteo_ing_mec_hab + conteo_ing_mec_int + conteo_ing_mec_asp;
}

void resultado(cliente client)
{
  cout << "Felicidades " << client.retorno_nombre() << " de " << client.retorno_edad() << " años de edad, has terminado el programa.\n";
  cout << "Tu puntaje en Ingenieria Industrial es: " << cuenta_ing_ind << "\n";
  cout << "\t- Puntaje en habilidades: " << conteo_ing_ind_hab << "\n";
  cout << "\t- Puntaje en intereses: " << conteo_ing_ind_int << "\n";
  cout << "\t- Puntaje en aspiraciones: " << conteo_ing_ind_asp << "\n";
  cout << "Tu puntaje en Ingenieria Electronica es: " << cuenta_ing_elec << "\n";
  cout << "\t- Puntaje en habilidades: " << conteo_ing_elec_hab << "\n";
  cout << "\t- Puntaje en intereses: " << conteo_ing_elec_int << "\n";
  cout << "\t- Puntaje en aspiraciones: " << conteo_ing_elec_asp << "\n";
  cout << "Tu puntaje en Ingenieria Mecanica es: " << cuenta_ing_mec << "\n";
  cout << "\t- Puntaje en habilidades: " << conteo_ing_mec_hab << "\n";
  cout << "\t- Puntaje en intereses: " << conteo_ing_mec_int << "\n";
  cout << "\t- Puntaje en aspiraciones: " << conteo_ing_mec_asp << "\n";
  if ((cuenta_ing_ind > cuenta_ing_elec) && (cuenta_ing_ind > cuenta_ing_mec))cout << "Te recomendamos Ingenieria Industrial.\n";
  else if (cuenta_ing_elec > cuenta_ing_mec) cout << "Te recomendamos Ingenieria Electronica.\n";
  else cout << "Te recomendamos Ingenieria Mecanica.\n";
  cout << "Programa finalizado, gracias por elegirnos =)";
}

//Funciones preguntas
string pregunta1(void)
{
  string palabra1;
  int input1;
  cout << "Pregunta Numero 1:\n";
  cout << "¿Cuál de las siguientes habilidades sentis que te definen mejor?\n";
  cout << "1- organización\n";
  cout << "2- programación\n";
  cout << "3- desarrollo de piezas mecánicas\n";
  cin >> input1;
  while (input1 != 1 && input1 != 2 && input1 != 3)
    {
      cout << "Ingrese un valor entre 1 y 3\n";
      cin >> input1;
    }
  if (input1 == 1) palabra1 = "ORGANIZACION";
  if (input1 == 2) palabra1 = "PROGRAMACION";
  if (input1 == 3) palabra1= "DESARROLLO DE PIEZAS MECANICAS";
  return palabra1;
}

string pregunta2(void)
{
  string palabra2;
  int input2;
  cout << "Pregunta Numero 2:\n";
  cout << "¿Cuál de las siguientes atrae más tu interés?\n";
  cout << "1- construcción\n";
  cout << "2- computación\n";
  cout << "3- sistemas mecánicos\n";
  cin >> input2;
  while (input2 != 1 && input2 != 2 && input2 != 3)
    {
      cout << "Ingrese un valor entre 1 y 3\n";
      cin >> input2;
    }
  if (input2 == 1) palabra2 = "CONSTRUCCION";
  if (input2 == 2) palabra2 = "NUEVAS TECNOLOGIAS";
  if (input2 == 3) palabra2 = "SISTEMAS MECANICOS";
  return palabra2;
}

string pregunta3(void)
{ 
  string palabra3;
  int input3;
  cout << "Pregunta Numero 3:\n";
  cout << "¿Qué te gustaria adquirir/tener en un futuro trabajo?\n";
  cout << "1- flexibilidad laboral\n";
  cout << "2- desarrollo de sofware\n";
  cout << "3- trabajos electricos\n";
  cin >> input3;
  while (input3 != 1 && input3 != 2 && input3 != 3)
    {
      cout << "Ingrese un valor entre 1 y 3\n";
      cin >> input3;
    }
  if (input3 == 1) palabra3 = "FLEXIBILIDAD LABORAL";
  if (input3 == 2) palabra3 = "DESARROLLO DE SOFTWARE";
  if (input3 == 3) palabra3 = "TRABAJOS ELECTRICOS";
  return palabra3;
}
