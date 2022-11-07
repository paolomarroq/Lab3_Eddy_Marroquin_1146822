#include "pch.h"
#include "string"
#include "iostream"
#include "fstream"
#include "windows.h"
#include "string.h"
#include "conio.h"

using namespace System;
using namespace std;

int MultRecursivo(int n, int m, int Total)
{
	if (m != 0)
	{
		Total = Total + n;
		m = m - 1;
		return MultRecursivo(n, m, Total);
	}
	else
	{
		return Total;
	}
}

string EvalPalindromas(string palabra, string copia)
{
	char* cadena;
	cadena = (char*)palabra.c_str();
	cadena = _strrev(cadena);

	if (palabra == copia)
	{
		return " Es Polindroma";
	}
	else
	{
		return " No es polindroma";
	}
}
int CantidadPol(string palabra, string copia)
{
	char* cadena;
	cadena = (char*)palabra.c_str();
	cadena = _strrev(cadena);

	if (palabra == copia)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void LeerArchivo(string nombre) {
	int Cantidad = 0;
	fstream archivo;
	archivo.open(nombre, ios::in);
	string linea;
	string Palindromas;
	char delimitador = ',';

	while (archivo.good())
	{
		getline(archivo, linea, delimitador);

		Palindromas = linea.c_str();
		cout << "Resultado: " << Palindromas << "\t" << EvalPalindromas(Palindromas, Palindromas) << endl;
		Cantidad = Cantidad + CantidadPol(Palindromas, Palindromas);
	}
	cout << "Cantidad Palindromas: " << Cantidad << endl;
	archivo.close();
}

int ConverDecimal(int n, int base, int total)
{
	int cifras[100];
	int i = 0, exponente = 0;

	while (n > 0)
	{
		cifras[i] = n % 10;
		n = n / 10;
		i++;
		exponente = i;
	}
	for (int j = i - 1; j >= 0; j--)
	{
		total = total + (cifras[j] * (pow(base, j)));
		exponente--;
	}
	return total;
}

string ConverDestino(int num, int base)
{
	if (num == 1) {
		return "1";
	}
	if (num % base == 0) {
		return ConverDestino(num / base, base) + "0";
	}
	if (num % base == 1) {
		return ConverDestino(num / base, base) + "1";
	}
	if (num % base == 2) {
		return ConverDestino(num / base, base) + "2";
	}
	if (num % base == 3) {
		return ConverDestino(num / base, base) + "3";
	}
	if (num % base == 4) {
		return ConverDestino(num / base, base) + "4";
	}
	if (num % base == 5) {
		return ConverDestino(num / base, base) + "5";
	}
	if (num % base == 6) {
		return ConverDestino(num / base, base) + "6";
	}
	if (num % base == 7) {
		return ConverDestino(num / base, base) + "7";
	}
	if (num % base == 8) {
		return ConverDestino(num / base, base) + "8";
	}
	else {
		return ConverDestino(num / base, base) + "9";
	}
}

int main()
{
	
	int Menu = 0;
	int Mult1 = 0, Mult2 = 0;
	int BaseOrigen = 0, BaseDestino = 0, Valor = 0;
	int OtraAccion = 0;
	bool Error = true;

	Console::WriteLine("Laboratorio No.03");
	while (Error == true) 
	{
		try
		{
			Console::WriteLine("Ingrese el numero segun la accion que desea ejecutar: \n1. Multiplicacion \n2. Palíndromas \n3. Conversion de base N a base M \n4. Salir ");
			Menu = Convert::ToInt32(Console::ReadLine());


			switch (Menu)
			{
			case 1:

				Console::WriteLine("Usted eligio la opcion de multiplicacion");
				Console::WriteLine("Ingrese un valor para el multiplicando");
				Mult1 = Convert::ToInt32(Console::ReadLine());
				Console::WriteLine("Ingrese un valor para el multiplicador");
				Mult2 = Convert::ToInt32(Console::ReadLine());

				cout << "Resultado: " << MultRecursivo(Mult1, Mult2, 0) << endl;

				Console::WriteLine("Desea realizar otra accion \n1. SI \n2. NO ");
				OtraAccion = Convert::ToInt32(Console::ReadLine());
				if (OtraAccion == 1)
				{
					Error = true;
				}
				else if (OtraAccion == 2)
				{
					Error = false;
					Console::WriteLine("Usted eligio no realizar otra accion");
				}
				else
				{
					Console::WriteLine("Dato ingresado no valido, sera Redirigido al Inicio ");
				}

				break;

			case 2:

				Console::WriteLine("Usted eligio la opcion de identificar palabras palingromas");
				Console::WriteLine("Por Favor, Espere...");
				Sleep(2000);
				LeerArchivo("Ejercicio2.txt");   //NOMBRE DEL ARCHIVO
				Console::ReadKey();

				Console::WriteLine("Desea realizar otra accion \n1. SI \n2. NO ");
				OtraAccion = Convert::ToInt32(Console::ReadLine());
				if (OtraAccion == 1)
				{
					Error = true;
				}
				else if (OtraAccion == 2)
				{
					Error = false;
					Console::WriteLine("Usted eligio no realizar otra accion");
				}
				else
				{
					Console::WriteLine("Dato ingresado no valido, sera Redirigido al Inicio ");
				}
				break;

			case 3:

				Console::WriteLine("Usted eligio la opcion de conversion de bases");
				Console::WriteLine("Ingrese el valor de la base de origen entre 2 y 10");
				BaseOrigen = Convert::ToInt32(Console::ReadLine());
				Console::WriteLine("Ingrese el numero que desea convertir");
				Valor = Convert::ToInt32(Console::ReadLine());
				Console::WriteLine("Ingrese el valor de la base destino entre 2 y 10");
				BaseDestino = Convert::ToInt32(Console::ReadLine());

				if (BaseDestino <= 9 && BaseDestino > 1)
				{
					cout << "Resultado: " << ConverDestino(ConverDecimal(Valor, BaseOrigen, 0), BaseDestino) << endl;
				}
				else if (BaseDestino == 10)
				{
					cout << "Resultado: " << ConverDecimal(Valor, BaseOrigen, 0) << endl;
				}
				else
				{
					Console::WriteLine("Dato de base no permitido, Intente otra base entre 2 y 10 ");
				}

				Console::WriteLine("Desea realizar otra accion \n1. SI \n2. NO ");
				OtraAccion = Convert::ToInt32(Console::ReadLine());
				if (OtraAccion == 1)
				{
					Error = true;
				}
				else if (OtraAccion == 2)
				{
					Error = false;
					Console::WriteLine("Usted eligio no realizar otra accion");
				}
				else
				{
					Console::WriteLine("Dato ingresado no valido, sera Redirigido al Inicio ");
				}

				break;

			case 4:
				Console::WriteLine("Usted eligio la opcion de Salir \nEsperamos verlo de nuevo pronto");
				Error = false;
				break;

			default:
				Console::WriteLine(" \nValor ingresado NO VALIDO intente nuevamente");
				break;
			}
		}
		catch (...)
		{
			Console::WriteLine(" \nValor ingresado NO VALIDO intente nuevamente Sera Redirigido al Inicio");
		}
	}
	Console::ReadKey();
}
