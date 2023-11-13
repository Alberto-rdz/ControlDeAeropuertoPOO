#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stdio.h>
#include <conio.h>
#include <malloc.h>
#include <math.h>
#include <stdlib.h>
#include <fstream>
#include <string.h>
using namespace std;
#ifdef _WIN32
#define CLEAR "cls"
#elif defined(unix)||defined(__unix__)||defined(__unix)||defined(__APPLE__)||defined(__MACH__)
#define CLEAR "clear"
#else
#error "SO no soportado para limpiar pantalla"
#endif
int menus();
void proceso(int opcion);
void asignacionAlta();
int seleccionAvion();
void Boletaje();
void listaOrdenada();
void pausa();
void error();

int pss,cont,horasal,minsal,horalleg,minlleg,nuevsal,nuevlleg,horaDeSalida_,horaDeLlegada_,cupoEnClaseTurista_,cupoEnElite_,capacidadEquipaje_,selec;
int folioAvion_;
string origen_,destino_;
float precioDeBoleto_;
bool encontrado=false;


class Vuelos{ //Clase padre 
	//Atributos encapsulados 
private:
	string ciudadDeOrigen;
	string ciudadDeDestino;
	
	string TerminalDeLLegada;
	string DirectoOEscala;
	int cupoEnClaseTurista;
	int vendidosEnTurista;
	int folioAvion;
	int cupoEnElite;
	int vendidoEnElite;
	int capacidadEquipaje;
	int horaDeSalida;
	int horaDeLLegada;
	float duracion;
	float precioDeBoleto;
	float descuento;
	
	
	
	
	//M?todos publicos 
	//M?todo = Una funcion 
public:
	
	Vuelos(int,string,string,int,int,float,int,int,int); //Constructor de la clase Uasurio
	//Falta poner parametros- ******PENDIENTE AVERIGUAR***
	
	//Metodos del menu
	void alta();
	void ventaDeBoletos();
	void cancelacionDeBoletos();
	
	void listadoDePasajeros();
};

Vuelos::Vuelos(int _folioAvion, string _origen, string _destino, int _horaDeSalida, int _horaDeLLegada, float _precioDeBoleto,int _cupoEnClaseTurista, int _cupoEnElite, int _capacidadEquipaje){// mi constructor
	folioAvion=_folioAvion;
	ciudadDeOrigen = _origen;
	ciudadDeDestino = _destino;
	horaDeSalida = _horaDeSalida;
	horaDeLLegada = _horaDeLLegada;
	precioDeBoleto = _precioDeBoleto;
	cupoEnClaseTurista = _cupoEnClaseTurista;
	cupoEnElite = _cupoEnElite;
	capacidadEquipaje=_capacidadEquipaje;

}

void Vuelos::alta(){//tengoq ue decir de donde sale esta area. Se le declara Regtangulo::area
	
	int nuevsal,contsal=0,nuevlleg,contlleg=0,dur,nuevdur,contdur=0;
	system("cls");
	if(horaDeSalida>60){
		nuevsal=horaDeSalida;
		while(nuevsal>60){
			nuevsal=nuevsal-60;
			contsal++;
		};
	}
	else{
		nuevsal=horaDeSalida;
	}
	if(horaDeLLegada>60){
		nuevlleg=horaDeLLegada;
		while(nuevlleg>60){
			nuevlleg=nuevlleg-60;
			contlleg++;
		};
	}
	else{
		nuevlleg=horaDeLLegada;
	}
	dur=horaDeLLegada-horaDeSalida;
	
	if(dur>60){
		nuevdur=dur;
		while(nuevdur>60){
			nuevdur=nuevdur-60;
			contdur++;
		};
	}
	else{
		nuevdur=dur;
	}
	
	cout<<"AQUI TIENE LA INFO DEL VUELO"<<endl;
	
	cout<<"FOLIO: "<<folioAvion<<endl;
	cout<<"La ciudad de origen es: " <<ciudadDeOrigen<< endl;
	cout<<"La ciudad de destino es: " <<ciudadDeDestino<< endl;
	if(contsal>10){
		if(nuevsal>10){
			cout<<"Hora de salida: " <<contsal<<":"<<nuevsal<<endl;
		}
		else{
			cout<<"Hora de salida: " <<contsal<<":0"<<nuevsal<<endl;
		}
	}
	else{
		if(nuevsal>10){
			cout<<"Hora de salida: 0" <<contsal<<":"<<nuevsal<<endl;
		}
		else{
			cout<<"Hora de salida: " <<contsal<<":0"<<nuevsal<<endl;
		}
	}
	if(contlleg>10){
		if(nuevlleg>10){
			cout<<"Hora de llegada: " <<contlleg<<":"<<nuevlleg<<endl;
		}
		else{
			cout<<"Hora de llegada: " <<contlleg<<":0"<<nuevlleg<<endl;
		}
	}
	else{
		if(nuevlleg>10){
			cout<<"Hora de llegada: 0" <<contlleg<<":"<<nuevlleg<<endl;
		}
		else{
			cout<<"Hora de llegada: " <<contlleg<<":0"<<nuevlleg<<endl;
		}
	}
	
	if(contdur>10){
		if(nuevdur>10){
			cout<<"Duracion total del vuelo: " <<contdur<<":"<<nuevdur<<endl;
		}
		else{
			cout<<"Duracion total del vuelo: " <<contdur<<":0"<<nuevdur<<endl;
		}
	}
	else{
		if(contdur>0){
			if(nuevdur>10){
				cout<<"Duracion total del vuelo: 0" <<contdur<<":"<<nuevdur<<endl;
			}
			else{
				cout<<"Duracion total del vuelo: 0" <<contdur<<":0"<<nuevdur<<endl;
			}
		}
		else{
			if(nuevdur>10){
				cout<<"Duracion total del vuelo: 00:"<<nuevdur<<endl;
			}
			else{
				cout<<"Duracion total del vuelo: 00:0"<<nuevdur<<endl;
			}
		}
	}
	cout<<"COSTO TOTAL DE BOLETO: " <<precioDeBoleto<< " Pesos "<<endl;
	cout<<"CAPACIDAD DE PASAJEROS EN CLASE TURISTA: "<<cupoEnClaseTurista<<endl;
	cout<<"CAPACIDAD DE PASAJEROS EN CLASE ELITE: "<<cupoEnElite<<endl;
	cout<<"CAPACIDAD DE EQUIPAJE: "<<capacidadEquipaje<<" Kg"<<endl;
	
	
	system("pause");
	
}

void bajaDeUnVuelo(){
	ofstream aux;
	ifstream lectura;
	int AuxFolio=0;
	encontrado=false;
	aux.open("auxiliar.txt",ios::out);
	lectura.open("vuelos.txt",ios::in);
	if(aux.is_open() && lectura.is_open()){
		cout<<"INGRESA EL FOLIO CORRESPONDIENTE AL VUELO QUE DESEA DAR DE BAJA: ";
		cin>>AuxFolio;
		lectura>>folioAvion_;
		while(!lectura.eof()){
			lectura>>origen_>>destino_>>horaDeSalida_>>horaDeLlegada_>>precioDeBoleto_>>cupoEnClaseTurista_>>cupoEnElite_>>capacidadEquipaje_;
			if(AuxFolio!=folioAvion_){
				aux<<folioAvion_<<" "<<origen_<<" "<<destino_<<" "<<horaDeSalida_<<" "<<horaDeLlegada_<<" "<<precioDeBoleto_<<" "<<cupoEnClaseTurista_<<" "<<cupoEnElite_<<" "<<capacidadEquipaje_<<endl;
			}else{
				encontrado=true;
				cout<<"REGISTRO ELIMINADO"<<endl;
				
			}
			lectura>>folioAvion_;
		}
	}
	else{
		cout<<"NO SE PUEDO ABRIR EL ARCHIVO"<<endl;
	}
	if(encontrado==false){
		cout<<"NO SE ENCONTRO NINGUN VUELO CON EL FOLIO: "<<AuxFolio<<endl;
	}
	aux.close();
	lectura.close();
	remove("vuelos.txt");
	rename("auxiliar.txt","vuelos.txt");
	
}
class menu
{
private:
	string tipoDeBoleto;
	string nombre;
	string domicilio;
	string celular;
	string FechaPago;
	string codigoCliente;
	string codigoVuelo;
	string descuento;
		
public:
	void altaCliente();
	void bajaCliente();
	void modificarCliente();
	void listarClientes();
	void menuPrincipal();
	void detallesCliente();
	void mostarRegistro(string codigo);
};

void menu::menuPrincipal()
{
	int opcion;
	do
	{
		cout<<"\t\t\t\t***VENTA DE BOLETOS***\t\t\t\t\n\n";
		cout<<"1. VENDER UN BOLETO\n\n";
		cout<<"2. MOSTRAR DETALLES DE BOLETO\n\n";
		cout<<"3. LISTA DE BOLETOSS\n\n";
		cout<<"4. CANCELAR BOLETOS\n\n";
		cout<<"5. MODIFICAR BOLETO\n\n";
		cout<<"6. SALIR\n\n";
		cout<<"Opci\242n: ";
		cin>>opcion;
		system(CLEAR);
		switch(opcion)
		{
		default:
			cout<<"Ha ingresado una opci\242n no valida!\n\n";
			break;
			
		case 1:
			altaCliente();
			break;
			
		case 2:
			detallesCliente();
			break;
			
		case 3:
			listarClientes();
			break;
			
		case 4:
			bajaCliente();
			break;
			
		case 5:
			modificarCliente();
			break;
			
		case 6:
			break;
		}
	}
	while(opcion!=6);
}

void menu::altaCliente()
{
	ofstream escritura;
	ifstream verificador;
	ifstream lectura;
	ifstream verificador2;
	string auxCodigo;
	string auxCodigoVuelo;
	int auxCodigoVuelo2,verf=0;
	bool coincidencia=false;
	verificador.open("clientes.txt",ios::in);
	escritura.open("clientes.txt",ios::app);
	lectura.open("vuelos.txt",ios::in);
	verificador2.open("vuelos.txt",ios::in);
	if(escritura.is_open()&&verificador.is_open()&&lectura.is_open()&&verificador2.is_open())
	{
		cout<<"LOS VUELOS DISPONIBLES PARA VENTA SON: "<<endl;
		lectura>>folioAvion_;
		while(!lectura.eof()){
			lectura>>origen_>>destino_>>horaDeSalida_>>horaDeLlegada_>>precioDeBoleto_>>cupoEnClaseTurista_>>cupoEnElite_>>capacidadEquipaje_;
			cout<<"VUELO:"<<folioAvion_<<" ORIGEN:"<<origen_<<" DESTINO:"<<destino_<<endl;
			lectura>>folioAvion_;
		}
		while(verf==0){
			cout<<"INGRESA EL FOLIO CORRESPONDIENTE DEL VUELO QUE DESEA COMPRAR: ";
			cin>>auxCodigoVuelo2;
			verificador2>>folioAvion_;
			while(!verificador2.eof()){
				verificador2>>origen_>>destino_>>horaDeSalida_>>horaDeLlegada_>>precioDeBoleto_>>cupoEnClaseTurista_>>cupoEnElite_>>capacidadEquipaje_;
				if(auxCodigoVuelo2==folioAvion_){
					verf=1;
					cout<<"VUELO CORRECTO"<<endl;
					fflush(stdin);
					cout<<"INGRESE DE NUEVO EL CODIGO PARA ASIGNARLO AL BOLETO: ";
					getline(cin,auxCodigoVuelo);
				}
				verificador2>>folioAvion_;
			}
		};
		cout<<"\t\t\t\t***VENTA DE BOLETOS***\t\t\t\t\n\n";
		fflush(stdin);
		cout<<"Ingresa el c\242digo del cliente: ";
		getline(cin,auxCodigo);
		if(auxCodigo=="")
			do
		{
			cout<<"c\242digo de cliente no v\240lido!, intentalo nuevamente: ";
			getline(cin,auxCodigo);
		}
		while(auxCodigo=="");
		do
		{
			verificador.seekg(0);
			getline(verificador,codigoCliente);
			while(!verificador.eof())
			{
				getline(verificador,codigoVuelo);
				getline(verificador,tipoDeBoleto);
				getline(verificador,nombre);
				getline(verificador,domicilio);
				getline(verificador,celular);
				getline(verificador,FechaPago);
				
				if(codigoCliente==auxCodigo)
				{
					coincidencia=true;
					cout<<"\n\nYa existe un cliente con ese c\242digo!\n\n";
					cout<<"El cliente con ese c\242digo es: "<<nombre<<"\n\n";
					cout<<"Ingresa un c\242digo v\240lido!: ";
					getline(cin,auxCodigo);
					if(auxCodigo=="")
						do
					{
						cout<<"\nc\242digo de cliente no v\240lido!, intentalo nuevamente: ";
						getline(cin,auxCodigo);
					}
					while(auxCodigo=="");
					
					break;
				}
				
				getline(verificador,codigoCliente);
			}
			
			if(verificador.eof()&&auxCodigo!=codigoCliente)
								   coincidencia=false;
			
		}
		while(coincidencia==true);
		system(CLEAR);
		codigoVuelo=auxCodigoVuelo;
		codigoCliente=auxCodigo;
		cout<<"\t\t\t\t***VENTA DE BOLETO***\t\t\t\t\n\n";
		cout<<"VUELO: "<<codigoVuelo<<endl;
		cout<<"Ingresa el c\242digo del cliente: ";
		cout<<codigoCliente;
		cout<<"\n\n";
		fflush(stdin);
		cout<<"Ingresa el tipo de boleto (TURISTA-ELITE): ";
		getline(cin,tipoDeBoleto);
		fflush(stdin);
		cout<<"Ingresa el nombre del cliente: ";
		getline(cin,nombre);
		cout<<"\n\n";
		fflush(stdin);
		cout<<"Ingresa el domicilio del cliente: ";
		getline(cin,domicilio);
		cout<<"\n\n";
		fflush(stdin);
		cout<<"Ingresa el n\243mero de telefono del cliente: ";
		getline(cin,celular);
		cout<<"\n\n";
		fflush(stdin);
		cout<<"Ingresa el tipo de descuento del cliente"<<endl;
		cout<<"ESTUDIANTE(15%)-INAPAM(10%)-MAESTROS(20%)-SIN DESCUENTO: ";
		getline(cin,descuento);
		cout<<"\n\n";
		fflush(stdin);
		cout<<"Ingresa la fecha de inscripci\242n del cliente: ";
		getline(cin,FechaPago);
		cout<<"\n\n";
		
		escritura<<codigoVuelo<<"\n"<<codigoCliente<<"\n"<<tipoDeBoleto<<"\n"<<nombre<<"\n"<<domicilio<<"\n"<<celular<<"\n"<<descuento<<"\n"<<FechaPago<<"\n";
		
		cout<<"El registro se ha completado correctamente.\n\n";
	}
	
	else
	{
		error();
	}
	
	escritura.close();
	verificador.close();
	pausa();
}

void menu::bajaCliente()
{
	ifstream lectura;
	ofstream auxiliar;
	bool encontrado=false;
	string auxCodigo;
	char respuesta[5];
	lectura.open("clientes.txt",ios::in);
	auxiliar.open("auxiliar.txt",ios::out);
	cout<<"\t\t\t\t**CANCELACION DE BOLETOS***\t\t\t\t\n\n"<<endl;
	if(lectura.is_open()&&auxiliar.is_open())
	{
		fflush(stdin);
		cout<<"Ingresa el c\242digo del cliente que deseas dar de baja: ";
		getline(cin,auxCodigo);
		getline(lectura,codigoVuelo);
		while(!lectura.eof())
		{
			getline(lectura,codigoCliente);
			getline(lectura,tipoDeBoleto);
			getline(lectura,nombre);
			getline(lectura,domicilio);
			getline(lectura,celular);
			getline(lectura,descuento);
			getline(lectura,FechaPago);
			
			if(auxCodigo==codigoCliente)
			{
				encontrado=true;
				cout<<"\n\nRegistro Encontrado\n\n";
				cout<<"Vuelo: "<<codigoVuelo<<endl;
				cout<<"C\242digo: "<<codigoCliente<<endl;
				cout<<"Tipo del Boleto: "<<tipoDeBoleto<<endl;
				cout<<"Nombre: "<<nombre<<endl;
				cout<<"Domicilio: "<<domicilio<<endl;
				cout<<"Celular: "<<celular<<endl;
				cout<<"Descuento: "<<descuento<<endl;
				cout<<"Fecha de inscripci\242n: "<<FechaPago<<endl;
				cout<<"\n\n";
				cout<<"Realmente deseas dar de baja a: "<<nombre<<" (s/n)?: ";
				cin.getline(respuesta,5);
				if(strcmp(respuesta,"s")==0||strcmp(respuesta,"S")==0||
				   strcmp(respuesta,"si")==0||strcmp(respuesta,"SI")==0||
				   strcmp(respuesta,"Si")==0||strcmp(respuesta,"sI")==0)
				{
					cout<<"\n\nEl VUELO se ha dado de baja correctamente\n\n";
				}
				
				else
				{
					
					cout<<"\n\nVUELO conservado\n\n";
					auxiliar<<codigoVuelo<<"\n"<<codigoCliente<<"\n"<<tipoDeBoleto<<"\n"<<nombre<<"\n"<<domicilio<<"\n"<<celular<<"\n"<<descuento
						<<"\n"<<FechaPago<<"\n";
					
				}
				
			}
			else
			{
				auxiliar<<codigoVuelo<<"\n"<<codigoCliente<<"\n"<<tipoDeBoleto<<"\n"<<nombre<<"\n"<<domicilio<<"\n"<<celular<<"\n"<<descuento<<"\n"<<FechaPago<<"\n";
			}
			getline(lectura,codigoVuelo);
		}
		if(encontrado==false)
		{
			cout<<"\n\nNo se encontr\242 el c\242digo: "<<auxCodigo<<"\n\n";
		}
		
	}
	else
	{
		error();
	}
	lectura.close();
	auxiliar.close();
	remove("clientes.txt");
	rename("auxiliar.txt","clientes.txt");
	pausa();
}

void menu::detallesCliente()
{
	string auxCodigoVuelo;
	ifstream mostrar;
	bool encontrado=false;
	mostrar.open("clientes.txt",ios::in);
	if(mostrar.is_open())
	{
		fflush(stdin);
		cout<<"\t\t\t\t***Consultar detalles de un VUELO***\t\t\t\t\n\n";
		cout<<"Ingresa el c\242digo del VUELO que deseas consultar detalles: ";
		getline(cin,auxCodigoVuelo);
		getline(mostrar,codigoVuelo);
		while(!mostrar.eof())
		{
			getline(mostrar,codigoCliente);
			getline(mostrar,tipoDeBoleto);
			getline(mostrar,nombre);
			getline(mostrar,domicilio);
			getline(mostrar,celular);
			getline(mostrar,descuento);
			getline(mostrar,FechaPago);
			
			if(auxCodigoVuelo==codigoVuelo)
			{
				encontrado=true;
				cout<<"\n\nRegistro Encontrado\n\n";
				cout<<"C\242digo: "<<codigoCliente<<endl;
				cout<<"Tipo de Boleto: "<<tipoDeBoleto<<endl;
				cout<<"Nombre: "<<nombre<<endl;
				cout<<"Domicilio: "<<domicilio<<endl;
				cout<<"Celular: "<<celular<<endl;
				cout<<"Tipo de descuento: "<<descuento<<endl;
				cout<<"Fecha de inscripci\242n: "<<FechaPago<<endl;
				cout<<"\n\n";
			}
			
			getline(mostrar,codigoVuelo);
		}
		
		if(encontrado==false)
		{
			cout<<"\n\nNo se encontro el registro: "<<auxCodigoVuelo<<"\n\n";
		}
	}
	
	else
	{
		error();
	}
	
	mostrar.close();
	pausa();
}

void menu::modificarCliente()
{
	ifstream lectura;
	ifstream verificador;
	ofstream auxiliar;
	string auxCodigo;
	string codigoModif;
	string auxTipoBol;
	string auxNombre;
	string auxDomicilio;
	string auxCelular;
	string auxDescuento;
	string auxFecha;
	bool encontrado=false;
	bool coincidencia=false;
	bool mismoCodigo=false;
	lectura.open("clientes.txt",ios::in);
	verificador.open("clientes.txt",ios::in);
	auxiliar.open("auxiliar.txt",ios::out);
	cout<<"\t\t\t\t***Modificar los datos del BOLETO***\t\t\t\t\n\n";
	if(lectura.is_open()&&verificador.is_open()&&auxiliar.is_open())
	{
		fflush(stdin);
		cout<<"Ingresa el c\242digo del BOLETO que deseas modificar: ";
		getline(cin,auxCodigo);
		
		if(auxCodigo=="")
		{
			do
			{
				cout<<"c\242digo de cliente no v\240lido!, intentalo nuevamente: ";
				getline(cin,auxCodigo);
			}
			while(auxCodigo=="");
		}
		
		codigoModif=auxCodigo;
		
		getline(lectura,codigoVuelo);
		while(!lectura.eof())
		{
			getline(lectura,codigoCliente);
			getline(lectura,tipoDeBoleto);
			getline(lectura,nombre);
			getline(lectura,domicilio);
			getline(lectura,celular);
			getline(lectura,descuento);
			getline(lectura,FechaPago);
			
			if(auxCodigo==codigoCliente)
			{
				encontrado=true;
				mostarRegistro(codigoModif);
				
				cout<<"**********************************************";
				cout<<"\n\n";
				cout<<"Ingresa la nueva informaci\242n para el BOLETO\n\n";
				fflush(stdin);
				cout<<"Ingresa el c\242digo del BOLETO: ";
				getline(cin,auxCodigo);
				if(auxCodigo==codigoModif)
				{
					mismoCodigo=true;
				}
				if(mismoCodigo==false)
				{
					do
					{
						if(auxCodigo==codigoModif)
						{
							coincidencia=false;
							break;
						}
						verificador.seekg(0);
						getline(verificador,codigoVuelo);
						while(!verificador.eof())
						{
							getline(verificador,codigoCliente);
							getline(verificador,tipoDeBoleto);
							getline(verificador,nombre);
							getline(verificador,domicilio);
							getline(verificador,celular);
							getline(verificador,descuento);
							getline(verificador,FechaPago);
							
							if(auxCodigo==codigoCliente)
							{
								coincidencia=true;
								cout<<"\n\nYa existe un BOLETO con ese c\242digo!\n\n";
								cout<<"El cliente con ese c\242digo es: "<<nombre<<"\n\n";
								cout<<"Ingresa un c\242digo v\240lido!: ";
								getline(cin,auxCodigo);
								
								if(auxCodigo=="")
								{
									do
									{
										cout<<"\nc\242digo de cliente no v\240lido!, ";
										cout<<"intentalo nuevamente: ";
										getline(cin,auxCodigo);
									}
									while(auxCodigo=="");
								}
								break;
							}
							
							getline(verificador,codigoVuelo);
						}
						
						if(verificador.eof()&&auxCodigo!=codigoCliente)
						{
							coincidencia=false;
						}
						
					}
					while(coincidencia==true);
				}
				system(CLEAR);
				cout<<"***Modificar los datos de un BOLETO***\n\n";
				cout<<"VUELO: "<<codigoVuelo<<endl;
				cout<<"Ingresa el c\242digo del BOLETO que deseas modificar: ";
				cout<<codigoModif;
				mostarRegistro(codigoModif);
				cout<<"\n**********************************************";
				cout<<"\n\n";
				cout<<"Ingresa la nueva informaci\242n para el BOLETO\n\n";
				cout<<"Ingresa el c\242digo del cliente: ";
				cout<<auxCodigo;
				cout<<"\n\n";
				fflush(stdin);
				cout<<"Ingresa el tipo de boleto (TURISTA-ELITE): ";
				getline(cin,auxTipoBol);
				cout<<"\n\n";
				fflush(stdin);
				cout<<"Ingresa el nombre del cliente: ";
				getline(cin,auxNombre);;
				fflush(stdin);
				cout<<"\n\n";
				cout<<"Ingresa el domicilio del cliente: ";
				getline(cin,auxDomicilio);
				cout<<"\n\n";
				fflush(stdin);
				cout<<"Ingresa el n\243mero de telefono del cliente: ";
				getline(cin,auxCelular);
				cout<<"\n\n";
				fflush(stdin);
				cout<<"Ingresa el tipo de descuento";
				cout<<"\nALUMNOS(15%)-INAPAM(10%)-MAESTROS(20%)-SIN DESCUENTO: ";
				getline(cin,auxDescuento);
				fflush(stdin);
				cout<<"Ingresa la fecha de inscripci\242n del cliente: ";
				getline(cin,auxFecha);
				cout<<"\n\n";
				auxiliar<<codigoVuelo<<"\n"<<auxCodigo<<"\n"<<auxTipoBol<<"\n"<<auxNombre<<"\n"<<auxDomicilio<<"\n"<<auxCelular<<"\n"<<auxDescuento<<"\n"<<auxFecha<<"\n";
				cout<<"El Registro se ha modificado correctamente.\n\n";
			}
			
			
			else
			{
				
				auxiliar<<codigoVuelo<<"\n"<<codigoCliente<<"\n"<<tipoDeBoleto<<"\n"<<nombre<<"\n"<<domicilio<<"\n"<<celular<<"\n"<<descuento<<"\n"<<FechaPago<<"\n";
			}
			
			
			getline(lectura,codigoVuelo);
		}
		
	}
	else
	{
		error();
	}
	
	if(encontrado==false)
	{
		cout<<"\n\nNo se encontr\242 ning\243n registro con ese c\242digo!\n\n";
	}
	lectura.close();
	verificador.close();
	auxiliar.close();
	remove("clientes.txt");
	rename("auxiliar.txt","clientes.txt");
	pausa();
}

void menu::listarClientes()
{
	int i=0;
	ifstream lectura;
	lectura.open("clientes.txt",ios::in);
	if(lectura.is_open())
	{
		cout<<"\t\t\t\t***Listado de todos los clientes***\t\t\t\t\n\n";
		getline(lectura,codigoVuelo);
		while(!lectura.eof())
		{
			i++;
			getline(lectura,codigoCliente);
			getline(lectura,tipoDeBoleto);
			getline(lectura,nombre);
			getline(lectura,domicilio);
			getline(lectura,celular);
			getline(lectura,descuento);
			getline(lectura,FechaPago);
			cout<<"Vuelo: "<<codigoVuelo<<endl;
			cout<<"C\242digo: "<<codigoCliente<<endl;
			cout<<"Tipo de Boleto: "<<tipoDeBoleto<<endl;
			cout<<"Nombre: "<<nombre<<endl;
			cout<<"Domicilio: "<<domicilio<<endl;
			cout<<"Celular: "<<celular<<endl;
			cout<<"Descuento: "<<descuento<<endl;
			cout<<"Fecha de inscripci\242n: "<<FechaPago<<endl;
			cout<<"\n\n";
			getline(lectura,codigoVuelo);
		}
		
		if(i==1)
						   cout<<"Hay un solo cliente registrado en BETOX\n\n";
		
		else
			
			cout<<"Hay un total de "<<i<<" clientes registrados en BETOX\n\n";
	}
	else
	{
		error();
	}
	lectura.close();
	pausa();
}

void menu::mostarRegistro(string codigo)
{
	
	ifstream mostrar;
	mostrar.open("clientes.txt",ios::in);
	getline(mostrar,codigoVuelo);
	while(!mostrar.eof())
	{
		getline(mostrar,codigoCliente);
		getline(mostrar,tipoDeBoleto);
		getline(mostrar,nombre);
		getline(mostrar,domicilio);
		getline(mostrar,celular);
		getline(mostrar,descuento);
		getline(mostrar,FechaPago);
		
		if(codigo==codigoCliente)
		{
			cout<<"\n\nRegistro Encontrado\n\n";
			cout<<"VUELO: "<<codigoVuelo<<endl;
			cout<<"C\242digo: "<<codigoCliente<<endl;
			cout<<"Tipo de Boleto: "<<tipoDeBoleto<<endl;
			cout<<"Nombre: "<<nombre<<endl;
			cout<<"Domicilio: "<<domicilio<<endl;
			cout<<"Celular: "<<celular<<endl;
			cout<<"Descuento: "<<descuento<<endl;
			cout<<"Fecha de inscripci\242n: "<<FechaPago<<endl;
			cout<<"\n\n";
		}
		
		getline(mostrar,codigoCliente);
	}
	
	mostrar.close();
}
void listaDeVuelos(){
	int contador=0,contfolios[50],i=0,n,j,x,aux;
	ofstream auxDoc;
	ifstream lectura;
	auxDoc.open("auxiliar.txt",ios::out);
	lectura.open("vuelos.txt",ios::in);
	if(auxDoc.is_open() && lectura.is_open()){
		lectura>>folioAvion_;
		
		while(!lectura.eof()){
			lectura>>origen_>>destino_>>horaDeSalida_>>horaDeLlegada_>>precioDeBoleto_>>cupoEnClaseTurista_>>cupoEnElite_>>capacidadEquipaje_;
			contador++;
			contfolios[i]=folioAvion_;
			i++;
			lectura>>folioAvion_;
		}
		lectura.close();
		for(n=0;n<contador;n++){
			for(j=0;j<contador;j++){
				if(contfolios[j] > contfolios[j+1]){
					aux = contfolios[j];
					contfolios[j] = contfolios[j+1];
					contfolios[j+1]= aux;
				}
			}
		}
		for(x=0;x<contador;x++){
			lectura.open("vuelos.txt",ios::in);
			lectura>>folioAvion_;
			while(!lectura.eof()){
				lectura>>origen_>>destino_>>horaDeSalida_>>horaDeLlegada_>>precioDeBoleto_>>cupoEnClaseTurista_>>cupoEnElite_>>capacidadEquipaje_;
				if(contfolios[x]==folioAvion_){
					auxDoc<<folioAvion_<<" "<<origen_<<" "<<destino_<<" "<<horaDeSalida_<<" "<<horaDeLlegada_<<" "<<precioDeBoleto_<<" "<<cupoEnClaseTurista_<<" "<<cupoEnElite_<<" "<<capacidadEquipaje_<<endl;
				}
				lectura>>folioAvion_;
			}
			lectura.close();
		}
	}
	auxDoc.close();
	remove("vuelos.txt");
	rename("auxiliar.txt","vuelos.txt");
	listaOrdenada();
}	
	
int main(int argc, char *argv[]) {
		
		int opcion, a;
		char c;
		do
		{
			cout<<endl<<endl;
			opcion=menus();
			proceso(opcion);
			do
			{
				cout<<endl;
				cout<<"Desea realizar alguna otra transaccion (S)(N): ";
				cin>>c;
				a=0;
				switch(c)
				{
				case 's':
				case 'S':a=2;break;
				case 'n':
				case 'N':break;
				default: cout<<endl<<"Ingrese un valor correcto"<<endl;a=1;
				} 
			} while (a==1);
			system ("cls");
		} while (a==2);
		system ("pause");
		return 0;
}

int menus(){
	int opcion;
	cout<<"---------------MENU DEL BETOX---------------"<<endl;
	cout<<"---------------------------------------------"<<endl<<endl;
	cout<<"ALTA DE UN VUELO..............................(1)"<<endl;
	cout<<"BAJA DE UN VUELO..............................(2)"<<endl;
	cout<<"BOLETAJE......................................(3)"<<endl;
	cout<<"LISTA DE VUELO ORDENADOS POR NUMERO DE VUELO..(4)"<<endl;
	cout<<"Salir / Exit..................................(5)"<<endl;
	cout<<endl<<"Elija la opcion que desea realizar: ";
	cin>>opcion;
	return opcion;
}

	
void proceso(int opcion) {
		
	switch (opcion){
	case 1:
			asignacionAlta();
			break;
	case 2:
			bajaDeUnVuelo();
			break;
	case 3:
			Boletaje();
			break;
	case 4:
			listaDeVuelos();
			break;
	case 5:cout<<endl<<"Ud. ha salido del sistema"<<endl<<endl;exit (0); 
	default: {
			cout<<"Ingrese un valor correcto"<<endl;
			menu();
		}
		}
		
}

void asignacionAlta(){
	system("cls");
	folioAvion_=0;
	
	ofstream escritura;
	
	escritura.open("vuelos.txt",ios::out|ios::app);
	/*ofstream fol;
	fol.open("foliosAviones.txt",ios::app);
	if(fol.fail()){
		cout<<"ERROR"<<endl;
	}
	fol<<"Folio: " <<folioAvion_<< endl;*/
	if(escritura.is_open()){
		cout<<"CUANTOS VUELOS VAS A AGREGAR: "; cin>>cont;
		for(int i=0; i<cont; i++){
			srand(time(0));
			folioAvion_ = 1 + rand();
			cout<<"VUELO "<<i+1<<endl;
			cout<<"****INGRESA LAS CIUDADES SIN ESPACIOS***"<<endl;
			cout<<"CIUDAD DE ORIGEN: "; cin>>origen_;
			cout<<"CIUDAD DE DESTINO: "; cin>>destino_;
			cout<<"HORA DE SALIDA: "<<endl; 
			cout<<"HORAS: "; cin>>horasal;
			cout<<"MINUTOS: "; cin>>minsal;
			cout<<"HORA DE LLEGADA: "<<endl; 
			cout<<"HORAS: "; cin>>horalleg;
			cout<<"MINUTOS: "; cin>>minlleg;
			cout<<"PRECIO DEL BOLETO: "; cin>>precioDeBoleto_;
			selec=seleccionAvion();
			do{
				if(selec>=1 && selec<=3){
					switch(selec){
					case 1:
						cupoEnClaseTurista_=150;
						cupoEnElite_=75;
						capacidadEquipaje_=5175;
						break;
					case 2:
						cupoEnClaseTurista_=160;
						cupoEnElite_=80;
						capacidadEquipaje_=5450;
						break;
					default:
						cupoEnClaseTurista_=130;
						cupoEnElite_=50;
						capacidadEquipaje_=4895;
					}
				}
				else{
					cout<<"NUMERO SELECCIONADO NO CORRESPODEN A UN MODELO DE AVION"<<endl;
					cout<<"VUELVA A SELECCIONAR..."<<endl;
					selec=seleccionAvion();
				}
			} while(selec>=4 || selec<=0);
			
			nuevsal=(horasal*60)+(minsal);
			nuevlleg=(horalleg*60)+(minlleg);
			
			horaDeSalida_=nuevsal;
			horaDeLlegada_=nuevlleg;
			escritura<<folioAvion_<<" "<<origen_<<" "<<destino_<<" "<<horaDeSalida_<<" "<<horaDeLlegada_<<" "<<precioDeBoleto_<< " "<<cupoEnClaseTurista_<<" "<<cupoEnElite_<<" "<<capacidadEquipaje_<<endl;
			pss=i;
			Vuelos pss(folioAvion_,origen_,destino_,horaDeSalida_,horaDeLlegada_,precioDeBoleto_,cupoEnClaseTurista_,cupoEnElite_,capacidadEquipaje_);
			
			pss.alta();
	}
		
		escritura.close();
		system("cls");
	}
}

int seleccionAvion(){
	int seleccion;
	cout<<"----SELECCIONA UNA AVION PARA ESTE VUELO----"<<endl;
	cout<<"(1)Boeing 787 Dreamliner: TURISTA-150 personas max ELITE-75 personas max EQUIPAJE- 5,175 kg max"<<endl;
	cout<<"(2)Boeing 747 Intercontinetal: TURISTA-160 personas max ELITE-80 personas max EQUIPAJE- 5,450 kg max"<<endl;
	cout<<"(3)Boeing 757: TURISTA-130 personas max ELITE-50 personas max EQUIPAJE- 4,895 kg max"<<endl;
	cout<<"NUMERO DE AVION SELECIONADO: "; cin>>seleccion;
	
	return seleccion;
}

void Boletaje(){
	menu inicio;
	inicio.menuPrincipal();	
}

void listaOrdenada(){
	ifstream lectura;
	int nuevsalLec,contsalLec=0,nuevllegLec,contllegLec=0,durLec,nuevdurLec,contdurLec=0;
	lectura.open("vuelos.txt",ios::in);
	system("cls");
	if(lectura.is_open()){
		lectura>>folioAvion_;
		while(!lectura.eof()){
			lectura>>origen_>>destino_>>horaDeSalida_>>horaDeLlegada_>>precioDeBoleto_>>cupoEnClaseTurista_>>cupoEnElite_>>capacidadEquipaje_;
			if(horaDeSalida_>60){
				nuevsalLec=horaDeSalida_;
				while(nuevsalLec>60){
					nuevsalLec=nuevsalLec-60;
					contsalLec++;
				};
			}
			else{
				nuevsalLec=horaDeSalida_;
			}
			if(horaDeLlegada_>60){
				nuevllegLec=horaDeLlegada_;
				while(nuevllegLec>60){
					nuevllegLec=nuevllegLec-60;
					contllegLec++;
				};
			}
			else{
				nuevllegLec=horaDeLlegada_;
			}
			durLec=horaDeLlegada_-horaDeSalida_;
			
			if(durLec>60){
				nuevdurLec=durLec;
				while(nuevdurLec>60){
					nuevdurLec=nuevdurLec-60;
					contdurLec++;
				};
			}
			else{
				nuevdurLec=durLec;
			}
			cout<<"FOLIO: "<<folioAvion_<<endl;
			cout<<"La ciudad de origen es: " <<origen_<< endl;
			cout<<"La ciudad de destino es: " <<destino_<< endl;
			if(contsalLec>10){
				if(nuevsalLec>10){
					cout<<"Hora de salida: " <<contsalLec<<":"<<nuevsalLec<<endl;
				}
				else{
					cout<<"Hora de salida: " <<contsalLec<<":0"<<nuevsalLec<<endl;
				}
			}
			else{
				if(nuevsalLec>10){
					cout<<"Hora de salida: 0" <<contsalLec<<":"<<nuevsalLec<<endl;
				}
				else{
					cout<<"Hora de salida: " <<contsalLec<<":0"<<nuevsalLec<<endl;
				}
			}
			if(contllegLec>10){
				if(nuevllegLec>10){
					cout<<"Hora de llegada: " <<contllegLec<<":"<<nuevllegLec<<endl;
				}
				else{
					cout<<"Hora de llegada: " <<contllegLec<<":0"<<nuevllegLec<<endl;
				}
			}
			else{
				if(nuevllegLec>10){
					cout<<"Hora de llegada: 0" <<contllegLec<<":"<<nuevllegLec<<endl;
				}
				else{
					cout<<"Hora de llegada: " <<contllegLec<<":0"<<nuevllegLec<<endl;
				}
			}
			
			if(contdurLec>10){
				if(nuevdurLec>10){
					cout<<"Duracion total del vuelo: " <<contdurLec<<":"<<nuevdurLec<<endl;
				}
				else{
					cout<<"Duracion total del vuelo: " <<contdurLec<<":0"<<nuevdurLec<<endl;
				}
			}
			else{
				if(contdurLec>0){
					if(nuevdurLec>10){
						cout<<"Duracion total del vuelo: 0" <<contdurLec<<":"<<nuevdurLec<<endl;
					}
					else{
						cout<<"Duracion total del vuelo: 0" <<contdurLec<<":0"<<nuevdurLec<<endl;
					}
				}
				else{
					if(nuevdurLec>10){
						cout<<"Duracion total del vuelo: 00:"<<nuevdurLec<<endl;
					}
					else{
						cout<<"Duracion total del vuelo: 00:0"<<nuevdurLec<<endl;
					}
				}
			}
			cout<<"COSTO TOTAL DE BOLETO: " <<precioDeBoleto_<< " Pesos "<<endl;
			cout<<"CAPACIDAD DE PASAJEROS EN CLASE TURISTA: "<<cupoEnClaseTurista_<<endl;
			cout<<"CAPACIDAD DE PASAJEROS EN CLASE ELITE: "<<cupoEnElite_<<endl;
			cout<<"CAPACIDAD DE EQUIPAJE: "<<capacidadEquipaje_<<" Kg"<<endl;
			cout<<"********************************************************************"<<endl;
			lectura>>folioAvion_;
		}
		}
	lectura.close();
}
	
void pausa()
{
	cout<<"Presiona Enter para continuar...";
	getch();
	system(CLEAR);
}
	
void error()
{
	cout<<"No se pudo abrir el archivo de registros, asegurese que el archivo se encuentre en\n";
	cout<<"la misma ubicaci\242n que el programa o que el archivo de texto se llame: \n";
	cout<<"clientes.txt, si el archivo tiene otro nombre ren\242mbrelo al ya mencionado\n\n";
}
	
