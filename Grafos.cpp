
#include"Grafo.h"
#define Archivo "archivo2.txt"

int main()
{
    /*cout << "Hello World!\n";
    Grafo prueba(5);
    prueba.InsertarArista(4, 2);
    prueba.InsertarArista(2, 3);
    prueba.InsertarArista(2, 1);
    prueba.InsertarArista(1, 3);
    prueba.InsertarArista(3, 0);
    prueba.InsertarArista(0, 1);
    if (prueba.BFS_Origen(4))
        cout << "recorrido"<<endl;
    else
        cout << "no hay"<<endl;
    prueba.MostrarCamino(1);*/

    cout << "Hello World !\n";
    Grafo prueba(6);
    prueba.LeerDeArch(Archivo);
    prueba.BFS_Origen(4);
    //cout << "recorrido" << endl;
    cout << "4 al 0" << endl;
    prueba.MostrarCamino(0);
    cout << "4 al 1" << endl;
    prueba.MostrarCamino(1);
    cout << "4 al 2" << endl;
    prueba.MostrarCamino(2);
    cout << "4 al 3" << endl;
    prueba.MostrarCamino(3);
    cout << "4 al 5" << endl;
    prueba.MostrarCamino(5);
    //prueba.MostrarTodo();
}
