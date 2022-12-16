#include <iostream>
#include <string>

using namespace std;

struct elemento
{
    std::string nombre;
    elemento *SiguienteElemento;
    elemento *AnteriorElemento;
};

struct IdentificadorLista
{
    elemento *Primero;
    elemento *Ultimo;
    int tamano;
};

class ListaDoble
{
private:
    IdentificadorLista *MiLista = new IdentificadorLista; // Reservamos dinámicamente un puntero a IdentificadorLista
public:
    ListaDoble();
    void InsertarNodoEnListaVacia(std::string info);
    void InsertarNodoInicioLista(std::string info);
    void InsertarNodoFinLista(std::string info);
    bool InsertarNodoPosicion(std::string info, int posicion);
    bool SuprimirInicioLista(void);
    bool SuprimirNodoPosicion(int posicion);
    void Destruir(void);
    void ImprimirLista(bool sentido);
};

ListaDoble::ListaDoble()
{
    MiLista->Primero = nullptr;
    MiLista->Ultimo = nullptr;
    MiLista->tamano = 0;
}

void ListaDoble::InsertarNodoEnListaVacia(std::string info)
{
    elemento *NodoNuevo;
    // Reserva en memoria dinámica para un nuevo nodo
    NodoNuevo = new elemento;
    // Información que tiene el nuevo nodo en la lista
    NodoNuevo->nombre = info;
    // Actualizamos punteros del nuevo nodo, al ser el primero apuntán a null los 2
    NodoNuevo->SiguienteElemento = nullptr;
    NodoNuevo->AnteriorElemento = nullptr;
    // Actualizamos nuestro identificador de lista
    MiLista->Primero = NodoNuevo;
    MiLista->Ultimo = NodoNuevo;

    MiLista->tamano++;
}

void ListaDoble::InsertarNodoInicioLista(std::string info)
{
    elemento *NodoNuevo;

    NodoNuevo = new elemento;

    NodoNuevo->nombre = info;

    NodoNuevo->SiguienteElemento = MiLista->Primero;
    NodoNuevo->AnteriorElemento = nullptr; // Al ser el primer nodo no apuntara a un nodo anterior

    MiLista->Primero->AnteriorElemento = NodoNuevo;

    // Actualizamos el identificador de lista
    MiLista->Primero = NodoNuevo;
    MiLista->tamano++;
}

void ListaDoble::InsertarNodoFinLista(std::string info)
{
    elemento *NodoNuevo;

    NodoNuevo = new elemento;

    NodoNuevo->nombre = info;

    NodoNuevo->SiguienteElemento = nullptr;
    NodoNuevo->AnteriorElemento = MiLista->Ultimo;

    MiLista->Ultimo->SiguienteElemento = NodoNuevo; // Antes era null, ahora es el penultimo
    // Actualizamos identificador de lista
    MiLista->Ultimo = NodoNuevo;

    MiLista->tamano++;
}

bool ListaDoble::InsertarNodoPosicion(std::string info, int posicion)
{
    // Comprobaciones iniciales
    if (MiLista->tamano < 2)
    { // Tenemos que usar función al Inicio o al fin
        return 0;
    }

    if (posicion < 0 || posicion >= MiLista->tamano)
    { // Fuera de rango de Lista
        return 0;
    }

    elemento *NodoNuevo, *temporal;
    NodoNuevo = new elemento;

    NodoNuevo->nombre = info;

    temporal = MiLista->Primero;
    for (int i = 1; i < posicion; i++)
    { // Recorremos Lista hasta encontrar Nodo de la posición indicada
        temporal = temporal->SiguienteElemento;
    }

    if (temporal->SiguienteElemento == nullptr)
    { // Si es el ultimo elemento de la lista habría que usar Insertar Nodo al final de la lista
        return 0;
    }
    // Mejora, al ser doblemente enlazada podemos elegir por donde comenzar a recorrer la lista (inicio o fin). El más corto
    temporal->SiguienteElemento->AnteriorElemento = NodoNuevo;
    NodoNuevo->SiguienteElemento = temporal->SiguienteElemento;
    NodoNuevo->AnteriorElemento = temporal;
    temporal->SiguienteElemento = NodoNuevo;
    // Actualizamos identificador de lista. Al ir el nuevo nodo en medio, unicamente actualizamos tamaño
    MiLista->tamano++;

    return 1;
}

bool ListaDoble::SuprimirInicioLista()
{
    if (MiLista->tamano == 0)
    { // No hay nodo que suprimir
        return 0;
    }

    elemento *ASuprimir;

    ASuprimir = MiLista->Primero;

    // Actualizamos identificador de lista.
    MiLista->Primero = ASuprimir->SiguienteElemento;
    if (MiLista->tamano == 1)
    { // Si sólo hay un nodo, al eliminarle nos quedamos sin nodos->no hay último ni primero
        MiLista->Ultimo = nullptr;
        MiLista->Primero = nullptr;
    }
    else
    {
        MiLista->Primero->AnteriorElemento = nullptr;
    }
    // Borramos el nodo
    delete ASuprimir; // Liberamos memoria

    MiLista->tamano--;

    return 1;
}

bool ListaDoble::SuprimirNodoPosicion(int posicion)
{
    if (MiLista->tamano <= 1 || posicion < 1 || posicion > MiLista->tamano)
    { // Error
        return 0;
    }
    if (MiLista->tamano == posicion)
    { // Queremos borrar el ultimo elemento
        elemento *ASuprimir;
        ASuprimir = MiLista->Ultimo;

        MiLista->Ultimo->AnteriorElemento->SiguienteElemento = nullptr;
        MiLista->Ultimo = MiLista->Ultimo->AnteriorElemento;
        delete ASuprimir;
        MiLista->tamano--;

        return 1;
    }

    elemento *ASuprimir, *temporal;

    temporal = MiLista->Primero;
    for (int i = 0; i < posicion; i++)
    { // Recorremos Lista hasta encontrar Nodo de la posición indicada
        temporal = temporal->SiguienteElemento;
    }

    ASuprimir = temporal;
    temporal->SiguienteElemento->AnteriorElemento = ASuprimir->AnteriorElemento;
    temporal->AnteriorElemento->SiguienteElemento = ASuprimir->SiguienteElemento;

    delete ASuprimir;
    MiLista->tamano--;

    return 1;
}

void ListaDoble::Destruir()
{
    while (MiLista->tamano > 0)
    {
        std::cout << "Borramos primer nodo..." << std::endl;
        SuprimirInicioLista();
        ImprimirLista(1);
    }
}

void ListaDoble::ImprimirLista(bool sentido)
{
    elemento *temporal;

    if (sentido)
    { // Recorremos de inicio a fin
        temporal = MiLista->Primero;
        std::cout << "--Inicio de la lista--" << std::endl;
        while (temporal != nullptr)
        {
            std::cout << "Dir nodo: " << temporal << "|| Anterior nodo: " << temporal->AnteriorElemento << "\t"
                      << "|| Siguiente nodo: " << temporal->SiguienteElemento << "\t"
                      << "|| Nombre nodo: " << temporal->nombre << std::endl;
            temporal = temporal->SiguienteElemento;
        }
        std::cout << "--Fin de la lista--" << std::endl;
    }
    else
    { // Recorremos de fin a inicio
        temporal = MiLista->Ultimo;
        std::cout << "--Fin de la lista--" << std::endl;
        while (temporal != nullptr)
        {
            std::cout << "Dir nodo: " << temporal << "|| Siguiente nodo: " << temporal->SiguienteElemento << "\t"
                      << " || Anterior nodo: " << temporal->AnteriorElemento << "\t"
                      << " || Nombre nodo: " << temporal->nombre << std::endl;
            temporal = temporal->AnteriorElemento;
        }
        std::cout << "--Inicio de la lista--" << std::endl;
    }
}
