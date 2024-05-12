#include <iostream>
#include <string>

using namespace std;

struct nodo {
    string placa;
    int movimientos;
    string tipo;
    nodo *sig;
};

nodo *cab = NULL;

void Registrarvehiculo() {
    nodo *aux = new nodo;
    cout << "Registrar placa: ";
    cin >> aux->placa;
    cout << "Registrar tipo (Carro o Moto): ";
    cin >> aux->tipo;
    aux->movimientos = 0;

    if (cab == NULL) {
        cab = aux;
        cab->sig = NULL;
    } else {
        aux->sig = cab;
        cab = aux;
    }
}

void Mostrar() {
    if (cab == NULL) {
        cout << "El parqueadero esta vacio." << endl;
        return;
    }

    nodo *temp = cab;
    while (temp != NULL) {
        cout << "Placa: " << temp->placa << ", Tipo: " << temp->tipo << ", Movimientos: " << temp->movimientos << endl;
        temp = temp->sig;
    }
}

void Eliminarregistro() {
    if (cab == NULL) {
        cout << "El parqueadero esta vacio, no hay vehiculos que eliminar." << endl;
        return;
    }

    nodo *temp = cab;
    cab = cab->sig;
    delete temp;
    cout << "Se ha eliminado el ultimo vehiculo registrado." << endl;
}

void CalcularCostoMovimientos(string placa) {
    int costosencillo, costopormovimiento;
    nodo *temp = cab;
    while (temp != NULL) {
    if (temp->placa == placa) {
    if (temp->tipo == "Carro") {
        costosencillo = 1000;
        costopormovimiento = 100;
        } else if (temp->tipo == "Moto") {
        costosencillo = 500;
        costopormovimiento = 50;
        } else {
            cout << "Tipo de vehiculo no valido." << endl;
            return;
            }

        int valor = costosencillo + (temp->movimientos * costopormovimiento);
        cout << "El valor a pagar para el vehiculo con placa " << placa << " es: " << valor << endl;
        return;
        }
        temp = temp->sig;
    }
    cout << "No se encontro ningun vehiculo con la placa " << placa << endl;
}

void Ingreseelnumerodeplaca() {
    string placa;
    cout << "Ingrese su numero de placa: ";
    cin >> placa;

    nodo *temp = cab;
    while (temp != NULL) {
        if (temp->placa == placa) {
        cout << "El vehículo con placa " << placa << " esta registrado en el parqueadero." << endl;
        return;
        }
        temp = temp->sig;
    }
    cout << "El vehiculo con placa " << placa << " no esta registrado en el parqueadero." << endl;
}

void IngreseMovimientos() {
    string placa;
    int movimientos;
    cout << "Ingrese el numero de placa del vehiculo: ";
    cin >> placa;
    cout << "Ingrese los movimientos para sacar el automovil: ";
    cin >> movimientos;

    nodo *temp = cab;
    while (temp != NULL) {
        if (temp->placa == placa) {
            temp->movimientos = movimientos;
            cout << "Se han registrado " << movimientos << " movimientos para el vehiculo con placa " << placa << endl;
            CalcularCostoMovimientos(placa);
            return;
        }
        temp = temp->sig;
    }

    cout << "No se encontro ningun vehiculo con la placa " << placa << endl;
}

int main() {
    int opcs = 0;
    do {
        cout << "\n     Menu      " << endl;
        cout << "1. Registrar vehiculo" << endl;
        cout << "2. Mostrar registro del parqueadero" << endl;
        cout << "3. Eliminar registro del parqueadero" << endl;
        cout << "4. Ingrese el numero de placa" << endl;
        cout << "5. Ingrese los movimientos para sacar el automovil" << endl;
        cout << "6. Salir" << endl;
        cout << "Elija una opcion: ";
        cin >> opcs;

        switch (opcs) {
            case 1:
            Registrarvehiculo();
            break;
            case 2:
            Mostrar();
            break;
            case 3:
            Eliminarregistro();
            break;
            case 4:
            Ingreseelnumerodeplaca();
            break;
            case 5:
            IngreseMovimientos();
            break;
            case 6:
            cout << "Finalizacion del programa." << endl;
            break;
            default:
            cout << "Opcion invalida." << endl;
            break;
        }
    } while (opcs != 6);

    return 0;
}