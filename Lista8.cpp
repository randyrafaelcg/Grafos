#include "Lista8.h"
#define Numeros "numeros.csv"
template<class T>
Lista8<T>::Lista8()
{
	//primero = new Tripla<T>;
	//ultimo = new Tripla<T>;
	//primero->sig = ultimo;
	//ultimo->ant = primero;
	primero = NULL;
	ultimo = NULL;
}

template<class T>
Lista8<T>::~Lista8()
{
	while (primero != ultimo)
	{
		eliminar_principio();
	}
}

template<class T>
T Lista8<T>::getprimero()
{
	return primero->dato;
}

template<class T>
T Lista8<T>::getultimo()
{
	return ultimo->dato;
}

template<class T>
void Lista8<T>::insertar_principio(T dato)
{
	if (primero == NULL)
	{
		Tripla<T>* segundo1;
		primero = new Tripla<T>(dato);
		//primero = segundo1;
		ultimo = primero;
	}
	else
	{
		Tripla<T>* segundo;
		segundo = primero;
		primero = new Tripla<T>(dato);
		primero->sig = segundo;
		segundo->ant = primero;
	}
}

template<class T>
void Lista8<T>::insertar_final(T dato)
{
	if (ultimo == NULL)
	{
		Tripla<T>* segundo1;
		ultimo = new Tripla<T>(dato);
		primero = ultimo;
		//ultimo->sig = NULL;
	}
	else
	{
		Tripla<T>* segundo;
		segundo = ultimo;
		ultimo = new Tripla<T>(dato);
		ultimo->ant = segundo;
		segundo->sig = ultimo;
	}
}

template<class T>
void Lista8<T>::insertar_final_con_peso(T dato, int peso)
{
	if (ultimo == NULL)
	{
		Tripla<T>* segundo1;
		ultimo = new Tripla<T>(dato,peso);
		primero = ultimo;
		//ultimo->sig = NULL;
	}
	else
	{
		Tripla<T>* segundo;
		segundo = ultimo;
		ultimo = new Tripla<T>(dato,peso);
		ultimo->ant = segundo;
		segundo->sig = ultimo;
	}
}

template<class T>
void Lista8<T>::eliminar_principio()
{
	if (primero != NULL)
	{
		if (primero == ultimo)
		{
			delete primero;
			ultimo = NULL;
			primero = NULL;
		}
		else
		{
			Tripla<T>* nodo = primero->sig;

			delete primero;

			primero = nodo;
			primero->ant = NULL;
		}
	}
	else
		cout << "Lista vacia" << endl;
}

template<class T>
void Lista8<T>::eliminar_final()
{
	if (primero != NULL)
	{
		if (primero == ultimo)
		{
			delete primero;
			ultimo = NULL;
			primero = NULL;
		}
		else
		{
			Tripla<T>* nodo = ultimo->ant;

			delete ultimo;

			ultimo = nodo;
			ultimo->sig = NULL;
		}
	}
	else
		cout << "Lista vacia" << endl;
}


template<class T>
void Lista8<T>::mostrar()
{
	if (primero == NULL)
		cout << "Lista Vacia" << endl;
	else
	{
		Tripla<T>* nodo = primero;
		while (nodo != NULL)
		{
			cout << nodo->dato << " ";
			nodo = nodo->sig;
		}
		cout << endl;
	}
}

template<class T>
void Lista8<T>::menor()
{
	if (primero == NULL)
		cout << "Lista Vacia" << endl;
	else
	{
		T small;
		Tripla<T>* nodo = primero;
		small = nodo->dato;
		while (nodo != ultimo)
		{
			if (small > nodo->dato)
				small = nodo->dato;
			nodo = nodo->sig;
		}
		cout << "Menor: " << small << endl;
	}
}

template<class T>
void Lista8<T>::busqueda(int pos)
{
	if (primero == NULL)
		cout << "Lista Vacia" << endl;
	else
	{
		Tripla<T>* nodo = primero;
		bool noexiste = true;
		int c = 1;
		while (nodo != NULL && c != pos + 1)
		{
			if (c == pos)
			{
				cout << "Elemento de la pos " << pos << ": " << nodo->dato << endl;
				noexiste = false;
			}
			c++;
			nodo = nodo->sig;
		}
		if (noexiste)
			cout << "Posicion fuera de rango";
		cout << endl;
	}
}

template<class T>
T Lista8<T>::getElemPos(int pos)
{
	if (primero == NULL)
	{
		//cout << "Lista Vacia" << endl;
		return -1;
	}
	else
	{
		Tripla<T>* nodo = primero;
		bool noexiste = false;
		int c = 1;
		while (nodo != NULL && c != pos + 1)
		{
			if (c == pos)
				return nodo->dato;
			c++;
			nodo = nodo->sig;
		}
		return -1;
	}
}

template<class T>
void Lista8<T>::busquedaSec(T dato)
{
	if (primero == NULL)
		cout << "Lista Vacia" << endl;
	else
	{
		int c = 0;
		bool existe = false;
		Tripla<T>* nodo = primero;
		while (nodo != ultimo && !existe)
		{
			c++;
			nodo = nodo->sig;
			if (nodo->dato == dato)
				existe = true;

		}
		if (existe)
		{
			cout << "Elemento hallado en la pos " << c << " : " << nodo->dato;
		}
		else
			cout << "Elemento inexistente";
		cout << endl;
	}
}

template<class T>
int recserch(Tripla<T>* nodo, Tripla<T>* ultimo, T dato, int pos)
{
	if (nodo == ultimo)
		return -1;
	else if (nodo->dato == dato)
		return pos;
	recserch(nodo->sig, ultimo, dato, pos + 1);
}

template<class T>
void Lista8<T>::busquedaSecRec(T dato)
{
	if (primero == NULL)
		cout << "Lista Vacia" << endl;
	else
	{
		Tripla<T>* nodo = primero;
		int pos = 1;
		int bus = recserch(nodo, ultimo, dato, pos);
		if (bus != -1)
			cout << "Elemento hallado recursivamente en la pos " << bus << endl;
		else
			cout << "El elemento no existe" << endl;
	}
}

template<class T>
void Lista8<T>::ordenar()
{
	if (primero == NULL)
		cout << "Lista Vacia" << endl;
	else
	{
		Tripla<T>* nodo = primero;
		Tripla<T>* nodo2 = nodo->sig;
		T aux;
		while (nodo != ultimo)
		{
			while (nodo2 != NULL)
			{
				if (nodo->dato > nodo2->dato)
				{
					aux = nodo2->dato;
					nodo2->dato = nodo->dato;
					nodo->dato = aux;
				}
				nodo2 = nodo2->sig;
			}
			cout << nodo->dato << " ";
			nodo = nodo->sig;
			nodo2 = nodo->sig;
		}
		cout << endl;
	}
}

template<class T>
void Lista8<T>::leerdearchivo()
{
	ifstream archivo(Numeros);
	string linea, num;
	char delimitador = ',';
	while (getline(archivo, linea))
	{
		stringstream stream(linea);
		getline(stream, num, delimitador);
		insertar_principio(stoi(num));
	}
	cout << "ARCHIVO LEIDO CORRECTAMENTE" << endl;
}