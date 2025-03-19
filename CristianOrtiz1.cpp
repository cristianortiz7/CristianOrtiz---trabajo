

#include <iostream>
#include <string>

using namespace std;

// Estructura del nodo para representar un producto
struct Producto {
    int id;
    string nombre;
    Producto *sig;
};

// Puntero global para la lista de productos
Producto *cab = NULL;

// Función para agregar un nuevo producto a la lista
void addProducto() {
    Producto *nuevo = new Producto;
    
    // Solicita datos al usuario
    cout << "Ingrese el ID del producto: ";
    cin >> nuevo->id;
    cin.ignore(); // Limpiar buffer
    
    cout << "Ingrese el nombre del producto: ";
    getline(cin, nuevo->nombre);
    
    nuevo->sig = NULL;

    // Insertar al final de la lista
    if (cab == NULL) {
        cab = nuevo;
    } else {
        Producto *aux = cab;
        while (aux->sig != NULL) {
            aux = aux->sig;
        }
        aux->sig = nuevo;
    }

    cout << "Producto agregado correctamente.\n";
}

// Función para mostrar todos los productos registrados
void viewProductos() {
    if (cab == NULL) {
        cout << "No hay productos registrados.\n";
        return;
    }
    
    Producto *aux = cab;
    cout << "\n>>>>Lista de Productos<<<<\n";
    while (aux != NULL) {
        cout << "ID: " << aux->id << " | Nombre: " << aux->nombre <<endl;
        aux = aux->sig;
    }
}

// Función para buscar un producto por ID
void searchProducto() {
    if (cab == NULL) {
        cout << "No hay productos registrados.\n";
        return;
    }

    int idBuscado;
    cout << "Ingrese el ID del producto a buscar: ";
    cin >> idBuscado;

    Producto *aux = cab;
    while (aux != NULL) {
        if (aux->id == idBuscado) {
            cout << "Producto encontrado -> ID: " << aux->id << ", Nombre: " << aux->nombre << endl;
            return;
        }
        aux = aux->sig;
    }

    cout << "Producto no encontrado.\n";
}

// Función para eliminar un producto por ID
void deleteProducto() {
    if (cab == NULL) {
        cout << "No hay productos registrados.\n";
        return;
    }

    int idEliminar;
    cout << "Ingrese el ID del producto a eliminar: ";
    cin >> idEliminar;

    Producto *aux = cab, *anterior = NULL;

    while (aux != NULL && aux->id != idEliminar) {
        anterior = aux;
        aux = aux->sig;
    }

    if (aux == NULL) {
        cout << "Producto no encontrado.\n";
        return;
    }

    if (anterior == NULL) {
        // Eliminar el primer nodo
        cab = aux->sig;
    } else {
        // Eliminar nodo intermedio o final
        anterior->sig = aux->sig;
    }

    delete aux;
    cout << "Producto eliminado correctamente.\n";
}

// Función para contar los productos registrados
void countProductos() {
    int contador = 0;
    Producto *aux = cab;

    while (aux != NULL) {
        contador++;
        aux = aux->sig;
    }

    cout << "Total de productos registrados: " << contador << endl;
}

// Función para liberar la memoria antes de salir
void liberarMemoria() {
    Producto *aux;
    while (cab != NULL) {
        aux = cab;
        cab = cab->sig;
        delete aux;
    }
    cout << "Memoria liberada correctamente.\n";
}

// Función principal con el menú
int main() {
    int opcion;

    do {
        cout << "\n==== MENÚ ====\n";
        cout << "1. Agregar producto\n";
        cout << "2. Mostrar productos\n";
        cout << "3. Buscar producto por ID\n";
        cout << "4. Eliminar producto por ID\n";
        cout << "5. Contar productos registrados\n";
        cout << "6. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                addProducto();
                break;
            case 2:
                viewProductos();
                break;
            case 3:
                searchProducto();
                break;
            case 4:
                deleteProducto();
                break;
            case 5:
                countProductos();
                break;
            case 6:
                liberarMemoria();
                cout << "Saliendo del sistema...\n";
                break;
            default:
                cout << "Opción inválida. Intente nuevamente.\n";
        }

    } while (opcion != 6);

    return 0;
}
