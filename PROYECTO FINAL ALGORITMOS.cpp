#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

const string archivoProductosNuevo = "productos_nuevo.txt";
const string archivoInventarioNuevo = "inventario_nuevo.txt";
const string archivoClientes = "clientes.txt";
const string archivoVentas = "ventas.txt";
const string archivoProveedores = "proveedores.txt"; 

struct Articulo {
    int idArticulo;
    string nombreArticulo;
    string precioArticulo;
    string fechaVencimiento;
};

struct Cliente {
    int idCliente;
    string nombre;
    string direccion;
    string telefono;
};

struct Proveedor {
    int idProveedor;
    string nombreProveedor;
    string direccionProveedor;
    string telefonoProveedor;
};

struct Ventas {
    int idVentas;
    string Producto;
    string cantidad;
    string Precio;
};

void mostrarArticulos(const vector<Articulo>& articulos) {
    for (const Articulo& articulo : articulos) {
        cout << "ID: " << articulo.idArticulo << endl;
        cout << "Nombre: " << articulo.nombreArticulo << endl;
        cout << "Precio: " << articulo.precioArticulo << endl;
        if (!articulo.fechaVencimiento.empty()) {
            cout << "Fecha de Vencimiento: " << articulo.fechaVencimiento << endl;
        }
        cout << "----------------------------" << endl;
    }
}

void agregarNuevosArticulos(vector<Articulo>& articulos) {
    cout << "Cuantos Articulos Quiere Ingresar: ";
    int cantidad;
    cin >> cantidad;

    for (int i = 0; i < cantidad; i++) {
        Articulo nuevoArticulo;
        cout << "Ingrese ID del Articulo: ";
        cin >> nuevoArticulo.idArticulo;
        cout << "Ingrese Nombre del Articulo: ";
        cin.ignore();
        getline(cin, nuevoArticulo.nombreArticulo);
        cout << "Ingrese Precio del Articulo: ";
        cin >> nuevoArticulo.precioArticulo;
        cout << "Ingrese Fecha de Vencimiento (si aplica): ";
        cin.ignore();
        getline(cin, nuevoArticulo.fechaVencimiento);

        articulos.push_back(nuevoArticulo);
    }
}

void mostrarInventario(const vector<Articulo>& inventario) {
    if (inventario.empty()) {
        cout << "El inventario está vacío." << endl;
    } else {
        cout << "Inventario de Articulos:" << endl;
        for (const Articulo& articulo : inventario) {
            cout << "ID: " << articulo.idArticulo << endl;
            cout << "Nombre: " << articulo.nombreArticulo << endl;
            cout << "Precio: " << articulo.precioArticulo << endl;
            if (!articulo.fechaVencimiento.empty()) {
                cout << "Fecha de Vencimiento: " << articulo.fechaVencimiento << endl;
            } else {
                cout << "Fecha de Vencimiento: No aplica" << endl;
            }
            cout << "-----------------------------" << endl;
        }
    }
}

void guardarArticulosEnArchivo(const vector<Articulo>& articulos, const string& nombreArchivo) {
    ofstream archivoSalida(nombreArchivo);
    if (!archivoSalida.is_open()) {
        cerr << "Error al abrir el archivo " << nombreArchivo << " para escritura." << endl;
        return;
    }

    for (const Articulo& articulo : articulos) {
        archivoSalida << articulo.idArticulo << " " << articulo.nombreArticulo << " " << articulo.precioArticulo << " " << articulo.fechaVencimiento << endl;
    }

    archivoSalida.close();
}

vector<Articulo> cargarArticulosDesdeArchivo(const string& nombreArchivo) {
    vector<Articulo> articulos;
    ifstream archivoEntrada(nombreArchivo);
    if (!archivoEntrada.is_open()) {
        cerr << "Error al abrir el archivo " << nombreArchivo << " para lectura." << endl;
        return articulos;
    }

    Articulo articulo;
    while (archivoEntrada >> articulo.idArticulo >> articulo.nombreArticulo >> articulo.precioArticulo >> articulo.fechaVencimiento) {
        articulos.push_back(articulo);
    }

    archivoEntrada.close();
    return articulos;
}

void mostrarClientes(const vector<Cliente>& clientes) {
    if (clientes.empty()) {
        cout << "No hay clientes registrados." << endl;
    } else {
        cout << "Lista de Clientes:" << endl;
        for (const Cliente& cliente : clientes) {
            cout << "ID: " << cliente.idCliente << endl;
            cout << "Nombre: " << cliente.nombre << endl;
            cout << "Dirección: " << cliente.direccion << endl;
            cout << "Teléfono: " << cliente.telefono << endl;
            cout << "--------------------------" << endl;
        }
    }
}

void agregarNuevoCliente(vector<Cliente>& clientes) {
    Cliente nuevoCliente;
    cout << "Ingrese ID del Cliente: ";
    cin >> nuevoCliente.idCliente;
    cout << "Ingrese Nombre del Cliente: ";
    cin.ignore();
    getline(cin, nuevoCliente.nombre);
    cout << "Ingrese Dirección del Cliente: ";
    getline(cin, nuevoCliente.direccion);
    cout << "Ingrese Teléfono del Cliente: ";
    cin >> nuevoCliente.telefono;

    clientes.push_back(nuevoCliente);
}

void guardarClientesEnArchivo(const vector<Cliente>& clientes, const string& nombreArchivo) {
    ofstream archivoSalida(nombreArchivo);
    if (!archivoSalida.is_open()) {
        cerr << "Error al abrir el archivo " << nombreArchivo << " para escritura." << endl;
        return;
    }

    for (const Cliente& cliente : clientes) {
        archivoSalida << cliente.idCliente << " " << cliente.nombre << " " << cliente.direccion << " " << cliente.telefono << endl;
    }

    archivoSalida.close();
}

vector<Cliente> cargarClientesDesdeArchivo(const string& nombreArchivo) {
    vector<Cliente> clientes;
    ifstream archivoEntrada(nombreArchivo);
    if (!archivoEntrada.is_open()) {
        cerr << "Error al abrir el archivo " << nombreArchivo << " para lectura." << endl;
        return clientes;
    }

    Cliente cliente;
    while (archivoEntrada >> cliente.idCliente >> cliente.nombre >> cliente.direccion >> cliente.telefono) {
        clientes.push_back(cliente);
    }

    archivoEntrada.close();
    return clientes;
}

void mostrarProveedores(const vector<Proveedor>& proveedores) {
    if (proveedores.empty()) {
        cout << "No hay proveedores registrados." << endl;
    } else {
        cout << "Lista de Proveedores:" << endl;
        for (const Proveedor& proveedor : proveedores) {
            cout << "ID: " << proveedor.idProveedor << endl;
            cout << "Nombre: " << proveedor.nombreProveedor << endl;
            cout << "Dirección: " << proveedor.direccionProveedor << endl;
            cout << "Teléfono: " << proveedor.telefonoProveedor << endl;
            cout << "-----------------------" << endl;
        }
    }
}

void agregarNuevoProveedor(vector<Proveedor>& proveedores) {
    Proveedor nuevoProveedor;
    cout << "Ingrese ID del Proveedor: ";
    cin >> nuevoProveedor.idProveedor;
    cout << "Ingrese Nombre del Proveedor: ";
    cin.ignore();
    getline(cin, nuevoProveedor.nombreProveedor);
    cout << "Ingrese Dirección del Proveedor: ";
    getline(cin, nuevoProveedor.direccionProveedor);
    cout << "Ingrese Teléfono del Proveedor: ";
    cin >> nuevoProveedor.telefonoProveedor;

    proveedores.push_back(nuevoProveedor);
}

void guardarProveedoresEnArchivo(const vector<Proveedor>& proveedores, const string& nombreArchivo) {
    ofstream archivoSalida(nombreArchivo);
    if (!archivoSalida.is_open()) {
        cerr << "Error al abrir el archivo " << nombreArchivo << " para escritura." << endl;
        return;
    }

    for (const Proveedor& proveedor : proveedores) {
        archivoSalida << proveedor.idProveedor << " " << proveedor.nombreProveedor << " " << proveedor.direccionProveedor << " " << proveedor.telefonoProveedor << endl;
    }

    archivoSalida.close();
}

vector<Proveedor> cargarProveedoresDesdeArchivo(const string& nombreArchivo) {
    vector<Proveedor> proveedores;
    ifstream archivoEntrada(nombreArchivo);
    if (!archivoEntrada.is_open()) {
        cerr << "Error al abrir el archivo " << nombreArchivo << " para lectura." << endl;
        return proveedores;
    }

    Proveedor proveedor;
    while (archivoEntrada >> proveedor.idProveedor >> proveedor.nombreProveedor >> proveedor.direccionProveedor >> proveedor.telefonoProveedor) {
        proveedores.push_back(proveedor);
    }

    archivoEntrada.close();
    return proveedores;
}

void mostrarVentas(const vector<Ventas>& ventas) {
    if (ventas.empty()) {
        cout << "No hay ventas registradas." << endl;
    } else {
        cout << "Lista de Ventas:" << endl;
        for (const Ventas& venta : ventas) {
            cout << "ID Venta: " << venta.idVentas << endl;
            cout << "Producto: " << venta.Producto << endl;
            cout << "Cantidad: " << venta.cantidad << endl;
            cout << "Precio: " << venta.Precio << endl;
            cout << "------------------------" << endl;
        }
    }
}

void agregarNuevaVenta(vector<Ventas>& ventas) {
    Ventas nuevaVenta;
    cout << "Ingrese ID de la Venta: ";
    cin >> nuevaVenta.idVentas;
    cout << "Ingrese Producto Vendido: ";
    cin.ignore();
    getline(cin, nuevaVenta.Producto);
    cout << "Ingrese Cantidad Vendida: ";
    cin >> nuevaVenta.cantidad;
    cout << "Ingrese Precio de la Venta: ";
    cin >> nuevaVenta.Precio;

    ventas.push_back(nuevaVenta);
}

void guardarVentasEnArchivo(const vector<Ventas>& ventas, const string& nombreArchivo) {
    ofstream archivoSalida(nombreArchivo);
    if (!archivoSalida.is_open()) {
        cerr << "Error al abrir el archivo " << nombreArchivo << " para escritura." << endl;
        return;
    }

    for (const Ventas& venta : ventas) {
        archivoSalida << venta.idVentas << " " << venta.Producto << " " << venta.cantidad << " " << venta.Precio << endl;
    }

    archivoSalida.close();
}
vector<Ventas> cargarVentasDesdeArchivo(const string& nombreArchivo) {
    vector<Ventas> ventas;
    ifstream archivoEntrada(nombreArchivo);
    if (!archivoEntrada.is_open()) {
        cerr << "Error al abrir el archivo " << nombreArchivo << " para lectura." << endl;
        return ventas;
    }

    Ventas venta;
    while (archivoEntrada >> venta.idVentas >> venta.Producto >> venta.cantidad >> venta.Precio) {
        ventas.push_back(venta);
    }

    archivoEntrada.close();
    return ventas;
}
int main() {
    vector<Articulo> articulos = cargarArticulosDesdeArchivo(archivoProductosNuevo);
    vector<Articulo> inventario = cargarArticulosDesdeArchivo(archivoInventarioNuevo);
    vector<Cliente> clientes = cargarClientesDesdeArchivo(archivoClientes);
    vector<Proveedor> proveedores = cargarProveedoresDesdeArchivo(archivoProveedores);
    vector <Ventas> ventas = cargarVentasDesdeArchivo(archivoVentas);

    cout << "-------------------------------------------------------------------------" << endl;
    cout << "Bienvenido al sistema de facturacion" << endl;
    cout << "-------------------------------------------------------------------------" << endl;
    cout << "Seleccione la opcion que desea realizar" << endl;
    cout << "1. Gestionar Clientes" << endl;
    cout << "2. Gestionar Articulos" << endl;
    cout << "3. Gestionar Ventas" << endl;
    cout << "4. Gestionar Inventario" << endl;
    cout << "5. Gestionar Proveedores" << endl;

    int opcion;
    cin >> opcion;
    cout << "-------------------------------------------------------------------------" << endl;

    switch (opcion) {
        case 1:
            int subopcionClientes;
            cout << "-------------------------------------------------------------------------" << endl;
            cout << "Bienvenido al menu de clientes" << endl;
            cout << "-------------------------------------------------------------------------" << endl;
            cout << "Elija la operacion a realizar" << endl;
            cout << "1. Mostrar clientes" << endl;
            cout << "2. Agregar nuevo cliente" << endl;
            cin >> subopcionClientes;

            switch (subopcionClientes) {
                case 1:
                    mostrarClientes(clientes);
                    break;

                case 2:
                    agregarNuevoCliente(clientes);
                    guardarClientesEnArchivo(clientes, archivoClientes);
                    cout << "Cliente agregado exitosamente." << endl;
                    break;

                default:
                    cout << "Opción no Válida" << endl;
            }
            break;

        case 2:
            int subopcionArticulos;
            cout << "------------------------------------------------------------------------- " << endl;
            cout << "Bienvenido al menu de articulos" << endl;
            cout << "-------------------------------------------------------------------------" << endl;
            cout << "Elija tu operacion a realizar" << endl;
            cout << "1. Ver articulos en existencia" << endl;
            cout << "2. Ingresar nuevos articulos" << endl;
            cin >> subopcionArticulos;

            switch (subopcionArticulos) {
                case 1:
                    cout << "-------------------------------------------------------------------------" << endl;
                    cout << "Bienvenido al menu de articulos, ahora veras nuestros articulos en existencia:" << endl;
                    cout << "-------------------------------------------------------------------------" << endl;
                    mostrarArticulos(articulos);
                    break;

                case 2:
                    agregarNuevosArticulos(articulos);
                    guardarArticulosEnArchivo(articulos, archivoProductosNuevo);
                    cout << "Articulos ingresados exitosamente." << endl;
                    break;

                default:
                    cout << "Opción no Válida" << endl;
            }
            break;

        case 3:
            int subopcionVentas;
            cout << "-------------------------------------------------------------------------" << endl;
            cout << "Bienvenido al menu de ventas" << endl;
                        cout << "-------------------------------------------------------------------------" << endl;
            cout << "Elija tu operación a realizar" << endl;
            cout << "1. Mostrar ventas" << endl;
            cout << "2. Realizar nueva venta" << endl;
            cin >> subopcionVentas;

            switch (subopcionVentas) {
                case 1:
                    cout << "-------------------------------------------------------------------------" << endl;
                    cout << "Bienvenido al menu de ventas, aqui estan las ventas realizadas:" << endl;
                    cout << "-------------------------------------------------------------------------" << endl;
                    mostrarVentas(ventas);
                    break;

                case 2:
                    agregarNuevaVenta(ventas);
                    guardarVentasEnArchivo(ventas, archivoVentas);
                    cout << "Venta realizada exitosamente." << endl;
                    break;

                default:
                    cout << "Opción no Válida" << endl;
            }
            break;

        case 4:
            int subopcionInventario;
            cout << "-------------------------------------------------------------------------" << endl;
            cout << "Bienvenido al menu de inventario" << endl;
            cout << "-------------------------------------------------------------------------" << endl;
            cout << "Elija tu operacion a realizar" << endl;
            cout << "1. Mostrar inventario" << endl;
            cin >> subopcionInventario;

            switch (subopcionInventario) {
                case 1:
                    cout << "-------------------------------------------------------------------------" << endl;
                    cout << "Bienvenido al menu de inventario, aqui esta el inventario actual:" << endl;
                    cout << "-------------------------------------------------------------------------" << endl;
                    mostrarInventario(inventario);
                    break;

                default:
                    cout << "Opción no Válida" << endl;
            }
            break;

        case 5:
            int subopcionProveedores;
            cout << "-------------------------------------------------------------------------" << endl;
            cout << "¡Bienvenido al menu de proveedores" << endl;
            cout << "-------------------------------------------------------------------------" << endl;
            cout << "Elija la operacion a realizar" << endl;
            cout << "1. Mostrar proveedores" << endl;
            cout << "2. Agregar nuevo proveedor" << endl;
            cin >> subopcionProveedores;

            switch (subopcionProveedores) {
                case 1:
                    cout << "-------------------------------------------------------------------------" << endl;
                    cout << "Bienvenido al menu de proveedores, aqui estan los proveedores registrados:" << endl;
                    cout << "-------------------------------------------------------------------------" << endl;
                    mostrarProveedores(proveedores);
                    break;

                case 2:
                    agregarNuevoProveedor(proveedores);
                    guardarProveedoresEnArchivo(proveedores, archivoProveedores);
                    cout << "Proveedor agregado exitosamente." << endl;
                    break;

          
        default:
            cout << "Opción no Válida" << endl;
    }

    return 0;
}}

