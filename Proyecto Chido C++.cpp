#include <iostream>
#include <iomanip>
#include <ctime>

using namespace std;

int buscar(string name);

void Administrador(); //Prototipos
void Altas();
void Bajas();
void Consultas();
void Modificaciones();
void Inventario();
void Usuarios();

void Altas_u();
void Bajas_u();
void Consultas_u();
void Modificaciones_u();
void Mostrar_u();

void Ventas();
string cliente[100] = {};
int total_venta_prod [100] = {};
int total_vendedor[100] = {};
int gran_total;
int check_sell = 0;
int subtotal_2[100] = {};
int cantidad[100] = {};
int egresos_vendedor[100]={};
int egresos_total;

void Verify_admin();
void Verify_seller();

int id [100] = {1, 2, 3, 4, 5};
string producto [100] = {"agua", "leche", "huevos", "pan", "refresco"};
int pc[100] = {10, 10, 10, 10, 10};
int pv[100] = {11, 11, 15, 20, 11};
int existencia [100] = {12, 23, 20, 20, 10};
int nr[100] = {8, 5, 5, 2, 3};
int st[100] = {1, 1, 1, 1, 1};
int total = 5;

int buscar_a(string admin);
string user_admin[100] = {"sofi", "moni"};
int pass_a[100] = {23, 21};
int st_admin[100] = {1, 1};
int check_admin;
int total_admin = 2;

int buscar_v(string seller);
string user_seller[100] = {"hoski", "justin"};
int pass_v[100] = {15, 13};
int st_seller[100] = {1, 1};
int check_seller;
int total_seller = 2;

int i_b;
int i_ba;
int i_bv;

int main() {
    int i;
    int j;
    int opc;
    time_t tSac = time(NULL);
    struct tm* tmP = localtime(&tSac);
    do {
        cout << "Menú\n";
        cout << "1. Administrador\n";
        cout << "2. Ventas\n";
        cout << "3. Salir\n";
        cout << "Opción: ";
        cin>>opc;
        switch (opc) {
            case 1: Verify_admin();
            {
                if (check_admin == 1)
                    Administrador();
                else
                    if (check_admin == 0)
                    cout << "Ha excedido el límite de intentos\n";
                break;
            }
                break;
            case 2: Verify_seller();
            {
                if (check_seller == 1)
                    Ventas();
                else
                    if (check_seller == 0)
                    cout << "Ha excedido el límite de intentos\n";
                break;
            }
                break;
            case 3:
            {
                if (check_sell == 1) {
                    for (j = 0; j < total_seller; j++){
                        gran_total = total_vendedor[j] + gran_total;
                        egresos_total=egresos_vendedor[j]+egresos_total;
                    }
                    cout << setw(30) << "Abarrotes El Tocho\n";
                    cout << setw(30) << "RFC: TOC980615EL1\n";
                    cout << setw(30) << "Ticket de Venta\n";
                    cout << setw(40) << "Hora: " << tmP->tm_hour << ":" << tmP->tm_min << ":" << tmP->tm_sec << endl;
                    cout << setw(40) << "Fecha: " << tmP->tm_mday << "/" << tmP->tm_mon + 1 << "/" << tmP->tm_year + 1900 << endl;
                    cout << endl;
                    cout << "Producto" << setw(10) << "Cantidad" << setw(16) << "Precio Unitario" << setw(10) << "Subtotal\n";
                    for (i = 0; i < total; i++)
                        if (st[i] == 1 && cantidad[i] > 0)
                            cout << setw(8) << producto[i] << setw(10) << cantidad[i] << setw(16) << pv[i] << setw(10) << subtotal_2[i] << endl;
                    cout << setw(41) << "Gran Total: $" << gran_total << endl;
                    cout<<endl;
                    cout<<"Utilidades: $"<<gran_total-egresos_total;
                }
                cout << "Cerrando sistema\n";
            }
                break;
            default: cout << "Opción inválida\n";
        }
    } while (opc != 3);
    return 0;
}

int buscar_a(string admin) {
    i_ba = 0;
    while (i_ba < total_admin && user_admin[i_ba] != admin)
        i_ba++;
    if (i_ba == total_admin)
        return -1;
    else
        if (st_admin[i_ba] == 0) {
        return -2;
    } else
        return i_ba;
}

void Verify_admin() {
    string usuario;
    int pos;
    int pass;
    int i;
    i = 0;
    while (i < 3) {
        cout << "Ingrese nombre de usuario administrador: ";
        cin>>usuario;
        cout << "Ingresa contraseña: ";
        cin>> pass;
        pos = buscar_a(usuario);
        if (pos == -1)
            cout << "Usuario o contraseña incorrectos. Quedan: " << 2 - i << " intentos\n";
        else
            if (pos == -2)
            cout << "Usuario está dado de baja";
        else
            if (pass == pass_a[pos]) {
            check_admin = 1;
            break;
        } else
            cout << "Usuario o contraseña incorrectos. Quedan: " << 2 - i << " intentos\n";
        i++;
    }
    if (i > 2)
        check_admin = 0;
}

int buscar_v(string seller) {
    i_bv = 0;
    while (i_bv < total_seller && user_seller[i_bv] != seller)
        i_bv++;
    if (i_bv == total_seller)
        return -1;
    else
        if (st_seller[i_bv] == 0) {
        return -2;
    } else
        return i_bv;
}

void Verify_seller() {
    string usuario;
    int pos;
    int pass;
    int i;
    i = 0;
    while (i < 3) {
        cout << "Ingrese nombre de usuario vendedor: ";
        cin>>usuario;
        cout << "Ingresa contraseña: ";
        cin>> pass;
        pos = buscar_v(usuario);
        if (pos == -1)
            cout << "Usuario o contraseña incorrectos. Quedan: " << 2 - i << " intentos\n";
        else
            if (pos == -2)
            cout << "Usuario está dado de baja\n";
        else
            if (pass == pass_v[pos]) {
            check_seller = 1;
            break;
        } else
            cout << "Usuario o contraseña incorrectos. Quedan: " << 2 - i << " intentos\n";
        i++;
    }
    if (i > 2)
        check_seller = 0;
}

int buscar(string name) {
    i_b = 0;
    while (i_b < total && producto[i_b] != name)
        i_b++;
    if (i_b == total)
        return -1;
    else
        if (st[i_b] == 0) {
        return -2;
    } else
        return i_b;
}

void Administrador() {
    int opc;
    do {
        cout << "Menú Administrador\n";
        cout << "1. Altas\n";
        cout << "2. Bajas\n";
        cout << "3. Consultas\n";
        cout << "4. Modificaciones\n";
        cout << "5. Mostrar inventario\n";
        cout << "6. Administración de Usuarios\n";
        cout << "7. Regresar\n";
        cout << "Opción: ";
        cin>>opc;
        switch (opc) {
            case 1: Altas();
                break;
            case 2: Bajas();
                break;
            case 3: Consultas();
                break;
            case 4: Modificaciones();
                break;
            case 5: Inventario();
                break;
            case 6: Usuarios();
                break;
            case 7:
                break;
            default: cout << "Opción Inválida\n";
        }
    } while (opc != 7);
}

void Altas() {
    int i;
    int pos;
    int opc;
    string nombre;
    cout << "Altas\n";
    while (true) {
        cout << "Ingrese producto: ";
        cin>>nombre;
        if (nombre == "*")
            break;
        pos = buscar(nombre);
        if (pos == -1) {
            i = total;
            do {
                cout << "Ingrese Precio de Compra: ";
                cin >> pc[i];
                cout << "Ingrese Precio de Venta: ";
                cin >> pv[i];
                if (pv[i] <= pc[i])
                    cout << "El precio de Venta debe ser mayor al precio de Compra\n";
            } while (pv[i] <= pc[i]);
            do {
                cout << "Ingrese cantidad en existencia: ";
                cin >> existencia[i];
                cout << "Ingrese nivel de Reorden: ";
                cin >> nr[i];
                if (existencia[i] <= nr[i])
                    cout << "La existencia debe ser mayor al Nivel de Reorden\n";
            } while (existencia[i] <= nr[i]);
            id[i] = i + 1;
            producto[i] = nombre;
            st[i] = 1;
            i++;
            total = i;
            cout << "El producto ha sido dado de alta exitosamente\n";
        } else
            if (pos == -2) {
            i = i_b;
            while (true) {
                cout << "El producto " << nombre << " está dado de baja, ¿Desea Reactivarlo?\n";
                cout << "1. Sí\n";
                cout << "2. No\n";
                cin >> opc;
                switch (opc) {
                    case 1:
                    {
                        do {
                            cout << "Ingrese Precio de Compra: ";
                            cin >> pc[i];
                            cout << "Ingrese Precio de Venta: ";
                            cin >> pv[i];
                            if (pv[i] <= pc[i])
                                cout << "El precio de Venta debe ser mayor al precio de Compra\n";
                        } while (pv[i] <= pc[i]);
                        do {
                            cout << "Ingrese cantidad en existencia: ";
                            cin >> existencia[i];
                            cout << "Ingrese nivel de Reorden: ";
                            cin >> nr[i];
                            if (existencia[i] <= nr[i])
                                cout << "La existencia debe ser mayor al Nivel de Reorden\n";
                        } while (existencia[i] <= nr[i]);
                        st[i] = 1;
                        cout << "El producto ha sido reactivado exitosamente\n";
                    }
                        break;
                    case 2:
                        break;
                    default: cout << "Opción Inválida\n";
                }
                if (opc < 3)
                    break;
            }
        } else
            cout << "El producto " << producto[pos] << " ya existe\n";
    }
}

void Bajas() {
    int i;
    int pos;
    int opc;
    string nombre;
    cout << "Bajas\n";
    while (true) {
        cout << "Ingrese producto: ";
        cin>>nombre;
        if (nombre == "*")
            break;
        pos = buscar(nombre);
        if (pos == -1)
            cout << "El producto: " << nombre << ", no existe\n";
        else
            if (pos == -2)
            cout << "El producto: " << nombre << ", ya está dado de baja\n";
        else {
            i = pos;
            while (true) {
                cout << "¿Seguro que desea dar de baja el producto: " << producto[i] << "?\n";
                cout << "1. Sí\n";
                cout << "2. No\n";
                cin >> opc;
                switch (opc) {
                    case 1:
                    {
                        st[i] = 0;
                        cout << "El producto ha sido dado de baja exitosamente\n";
                    }
                        break;
                    case 2:
                        break;
                    default: cout << "Opción Inválida\n";
                }
                if (opc < 3)
                    break;
            }
        }
    }
}

void Consultas() {
    int i;
    int pos;
    int opc;
    string nombre;
    cout << "Consultas\n";
    while (true) {
        cout << "Ingrese producto: ";
        cin>>nombre;
        if (nombre == "*")
            break;
        pos = buscar(nombre);
        if (pos == -1) {
            i = total;
            while (true) {
                cout << "El producto " << nombre << " no existe. ¿Desea darlo de Alta?\n";
                cout << "1. Sí\n" << "2. No\n";
                cin >> opc;
                switch (opc) {
                    case 1:
                    {
                        do {
                            cout << "Ingrese Precio de Compra: ";
                            cin >> pc[i];
                            cout << "Ingrese Precio de Venta: ";
                            cin >> pv[i];
                            if (pv[i] <= pc[i])
                                cout << "El precio de Venta debe ser mayor al precio de Compra\n";
                        } while (pv[i] <= pc[i]);
                        do {
                            cout << "Ingrese cantidad en existencia: ";
                            cin >> existencia[i];
                            cout << "Ingrese nivel de Reorden: ";
                            cin >> nr[i];
                            if (existencia[i] <= nr[i])
                                cout << "La existencia debe ser mayor al Nivel de Reorden\n";
                        } while (existencia[i] <= nr[i]);
                        id[i] = i + 1;
                        producto[i] = nombre;
                        st[i] = 1;
                        i++;
                        total = i;
                        cout << "El producto ha sido dado de alta exitosamente\n";
                    }
                        break;
                    case 2:
                        break;
                    default: cout << "Opción Inválida\n";
                }
                if (opc < 3)
                    break;
            }
        } else
            if (pos == -2) {
            i = i_b;
            while (true) {
                cout << "El producto " << nombre << " está dado de baja, ¿Desea Reactivarlo?\n";
                cout << "1. Sí\n";
                cout << "2. No\n";
                cin >> opc;
                switch (opc) {
                    case 1:
                    {
                        do {
                            cout << "Ingrese Precio de Compra: ";
                            cin >> pc[i];
                            cout << "Ingrese Precio de Venta: ";
                            cin >> pv[i];
                            if (pv[i] <= pc[i])
                                cout << "El precio de Venta debe ser mayor al precio de Compra\n";
                        } while (pv[i] <= pc[i]);
                        do {
                            cout << "Ingrese cantidad en existencia: ";
                            cin >> existencia[i];
                            cout << "Ingrese nivel de Reorden: ";
                            cin >> nr[i];
                            if (existencia[i] <= nr[i])
                                cout << "La existencia debe ser mayor al Nivel de Reorden\n";
                        } while (existencia[i] <= nr[i]);
                        st[i] = 1;
                        cout << "El producto ha sido reactivado exitosamente\n";
                    }
                        break;
                    case 2:
                        break;
                    default: cout << "Opción Inválida\n";
                }
                if (opc < 3)
                    break;
            }
        } else {
            i = pos;
            cout << "Resultados del producto: " << producto[i] << endl;
            cout << setw(6) << "ID" << setw(12) << "Producto" << setw(6) << "PC" << setw(6) << "PV" << setw(14) << "Existencia" << setw(6) << "NR" << endl;
            cout << setw(5) << id[i] << setw(12) << producto[i] << setw(7) << pc[i] << setw(6) << pv[i] << setw(9) << existencia[i] << setw(11) << nr[i];
            if (existencia[i] <= nr[i])
                cout << "*\n";
            else
                cout << endl;
        }
    }
}

void Modificaciones() {
    int i;
    int opc;
    int pos;
    string nombre;
    cout << "Modificaciones\n";
    while (true) {
        cout << "Ingrese producto a Modificar: ";
        cin>>nombre;
        if (nombre == "*")
            break;
        pos = buscar(nombre);
        if (pos == -1)
            cout << "El producto: " << nombre << ", no existe\n";
        else
            if (pos == -2)
            cout << "El producto: " << nombre << ", está dado de baja\n";
        else {
            i = pos;
            while (true) {
                cout << "Qué desea Modificar?\n";
                cout << "1. Precio de Compra\n";
                cout << "2. Precio de Venta\n";
                cout << "3. Existencia\n";
                cout << "4. Nivel de Reorden\n";
                cout << "5. TODO\n";
                cout << "6. Regresar\n";
                cin>>opc;
                switch (opc) {
                    case 1:
                    {
                        cout << "El Precio de Compra actual es de: " << pc[i] << endl << "Ingrese el nuevo Precio de Compra: ";
                        cin >> pc[i];
                        cout << "El Precio de Compra ha sido Modificado\n";
                    }
                        break;
                    case 2:
                    {
                        cout << "El Precio de Venta actual es de: " << pv[i] << endl << "Ingrese el nuevo Precio de Venta: ";
                        cin >> pv[i];
                        cout << "El Precio de Venta ha sido Modificado\n";
                    }
                        break;
                    case 3:
                    {
                        cout << "La Existencia actual es de: " << existencia[i] << endl << "Ingrese la nueva Existencia: ";
                        cin >> existencia[i];
                        cout << "La Existencia ha sido Modificada\n";
                    }
                        break;
                    case 4:
                    {
                        cout << "El Nivel de Reorden actual es de: " << nr[i] << endl << "Ingrese el nuevo Nivel de Reorden: ";
                        cin >> nr[i];
                        cout << "El Nivel de Reorden ha sido Modificado\n";
                    }
                        break;
                    case 5:
                    {
                        cout << "Datos actuales:\n";
                        cout << setw(6) << "ID" << setw(12) << "Producto" << setw(6) << "PC" << setw(6) << "PV" << setw(14) << "Existencia" << setw(6) << "NR" << endl;
                        cout << setw(5) << id[i] << setw(12) << producto[i] << setw(7) << pc[i] << setw(6) << pv[i] << setw(9) << existencia[i] << setw(11) << nr[i] << endl;
                        cout << "Ingrese los nuevos datos:\n";
                        cout << "Precio de compra: ";
                        cin >> pc[i];
                        cout << "Precio de Venta: ";
                        cin >> pv[i];
                        cout << "Existencia: ";
                        cin >> existencia[i];
                        cout << "Nivel de Reorden: ";
                        cin >> nr[i];
                        cout << "Los datos han sido Modificados\n";
                    }
                        break;
                    case 6:
                        break;
                    default: cout << "Opción Inválida\n";
                }
                if (opc == 6)
                    break;
            }
        }
    }
}

void Inventario() {
    int i, j, k;
    int opc;
    string salir;
    string temp_prod;
    int temp_id, temp_pc, temp_pv, temp_exist, temp_nr, temp_st;
    cout << "Inventario\n";
    cout << "Mostrar inventario por:\n";
    cout << "1. ID\n" << "2. Producto\n";
    cin>>opc;
    switch (opc) {
        case 1:
        {
            k = total;
            for (i = 0; i < k - 1; i++)
                for (j = 0; j < (k - 1) - i; j++)
                    if (id[j] > id[j + 1]) {
                        temp_id = id[j + 1];
                        id[j + 1] = id[j];
                        id[j] = temp_id;
                        temp_prod = producto[j + 1];
                        producto[j + 1] = producto[j];
                        producto[j] = temp_prod;
                        temp_pc = pc[j + 1];
                        pc[j + 1] = pc[j];
                        pc[j] = temp_pc;
                        temp_pv = pv[j + 1];
                        pv[j + 1] = pv[j];
                        pv[j] = temp_pv;
                        temp_exist = existencia[j + 1];
                        existencia[j + 1] = existencia[j];
                        existencia[j] = temp_exist;
                        temp_nr = nr[j + 1];
                        nr[j + 1] = nr[j];
                        nr[j] = temp_nr;
                        temp_st = st[j + 1];
                        st[j + 1] = st[j];
                        st[j] = temp_st;
                    }
            cout << setw(6) << "ID" << setw(12) << "Producto" << setw(6) << "PC" << setw(6) << "PV" << setw(14) << "Existencia" << setw(6) << "NR" << endl;
            for (j = 0; j < k; j++) {
                if (st[j] == 1) {
                    cout << setw(5) << id[j] << setw(12) << producto[j] << setw(7) << pc[j] << setw(6) << pv[j] << setw(9) << existencia[j] << setw(11) << nr[j];
                    if (existencia[j] <= nr[j])
                        cout << "*\n";
                    else
                        cout << endl;
                }
            }
            while (true) {
                cout << "Presione ''*'' para salir\n";
                cin>>salir;
                if (salir == "*")
                    break;
            }
        }
            break;
        case 2:
        {
            k = total;
            for (i = 0; i < k - 1; i++)
                for (j = 0; j < (k - 1) - i; j++)
                    if (producto[j] > producto[j + 1]) {
                        temp_prod = producto[j + 1];
                        producto[j + 1] = producto[j];
                        producto[j] = temp_prod;
                        temp_id = id[j + 1];
                        id[j + 1] = id[j];
                        id[j] = temp_id;
                        temp_pc = pc[j + 1];
                        pc[j + 1] = pc[j];
                        pc[j] = temp_pc;
                        temp_pv = pv[j + 1];
                        pv[j + 1] = pv[j];
                        pv[j] = temp_pv;
                        temp_exist = existencia[j + 1];
                        existencia[j + 1] = existencia[j];
                        existencia[j] = temp_exist;
                        temp_nr = nr[j + 1];
                        nr[j + 1] = nr[j];
                        nr[j] = temp_nr;
                        temp_st = st[j + 1];
                        st[j + 1] = st[j];
                        st[j] = temp_st;
                    }
            cout << setw(6) << "ID" << setw(12) << "Producto" << setw(6) << "PC" << setw(6) << "PV" << setw(14) << "Existencia" << setw(6) << "NR" << endl;
            for (j = 0; j < k; j++) {
                if (st[j] == 1) {
                    cout << setw(5) << id[j] << setw(12) << producto[j] << setw(7) << pc[j] << setw(6) << pv[j] << setw(9) << existencia[j] << setw(11) << nr[j];
                    if (existencia[j] <= nr[j])
                        cout << "*\n";
                    else
                        cout << endl;
                }
            }
            while (true) {
                cout << "Presione ''*'' para salir\n";
                cin>>salir;
                if (salir == "*")
                    break;
            }
        }
            break;
        default: cout << "Opción inválida\n";
    }

}

void Usuarios() {
    int opc;
    do {
        cout << "Administrador de Usuarios\n";
        cout << "1. Alta de Usuarios\n";
        cout << "2. Baja de Usuarios\n";
        cout << "3. Consulta de Usuarios\n";
        cout << "4. Modificación de Usuarios\n";
        cout << "5. Mostrar Usuarios\n";
        cout << "6. Regresar\n";
        cout << "Opción: ";
        cin>>opc;
        switch (opc) {
            case 1: Altas_u();
                break;
            case 2: Bajas_u();
                break;
            case 3: Consultas_u();
                break;
            case 4: Modificaciones_u();
                break;
            case 5: Mostrar_u();
                break;
            case 6:
                break;
            default: cout << "Opción Inválida\n";
        }
    } while (opc != 6);
}

void Altas_u() {
    int i;
    int pos;
    int opc;
    int pass1;
    int pass2;
    string usuario;
    cout << "Alta de Usuarios\n";
    do {
        cout << "¿El usuario a dar de Atla es Administador o Vendedor?\n";
        cout << "1. Administrador\n";
        cout << "2. Vendedor\n";
        cout << "3. Regresar\n";
        cin>>opc;
        switch (opc) {
            case 1:
            {
                while (true) {
                    cout << "Ingrese Usuario: ";
                    cin>>usuario;
                    if (usuario == "*")
                        break;
                    pos = buscar_a(usuario);
                    if (pos == -1) {
                        i = total_admin;
                        do {
                            cout << "Ingrese contraseña del usuario " << usuario << ": ";
                            cin>>pass1;
                            cout << "Confirme la contraseña: ";
                            cin>>pass2;
                            if (pass1 == pass2) {
                                pass_a[i] = pass2;
                                break;
                            } else
                                cout << "Las contraseñas no coinciden, intente de nuevo\n";
                        } while (pass1 != pass2);
                        user_admin[i] = usuario;
                        st_admin[i] = 1;
                        cout << pass_a[i];
                        i++;
                        total_admin = i;
                        cout << "El usuario ha sido dado de alta exitosamente\n";
                    } else
                        if (pos == -2) {
                        i = i_ba;
                        while (true) {
                            cout << "El usuario " << usuario << " está dado de baja, ¿Desea Reactivarlo?\n";
                            cout << "1. Sí\n";
                            cout << "2. No\n";
                            cin >> opc;
                            switch (opc) {
                                case 1:
                                {
                                    do {
                                        cout << "Ingrese contraseña del usuario " << usuario << ": ";
                                        cin>>pass1;
                                        cout << "Confirme la contraseña: ";
                                        cin>>pass2;
                                        if (pass1 == pass2) {
                                            pass_a[i] = pass2;
                                            break;
                                        } else
                                            cout << "Las contraseñas no coinciden, intente de nuevo\n";
                                    } while (pass1 != pass2);
                                    st_admin[i] = 1;
                                    cout << "El usuario ha sido reactivado exitosamente\n";
                                }
                                    break;
                                case 2:
                                    break;
                                default: cout << "Opción Inválida\n";
                            }
                            if (opc < 3)
                                break;
                        }
                    } else
                        cout << "El usuario " << user_admin[pos] << " ya existe\n";
                }
            }
                break;
            case 2:
            {
                while (true) {
                    cout << "Ingrese Usuario: ";
                    cin>>usuario;
                    if (usuario == "*")
                        break;
                    pos = buscar_v(usuario);
                    if (pos == -1) {
                        i = total_seller;
                        do {
                            cout << "Ingrese contraseña del usuario " << usuario << ": ";
                            cin>>pass1;
                            cout << "Confirme la contraseña: ";
                            cin>>pass2;
                            if (pass1 == pass2) {
                                pass_v[i] = pass2;
                                break;
                            } else
                                cout << "Las contraseñas no coinciden, intente de nuevo\n";
                        } while (pass1 != pass2);
                        user_seller[i] = usuario;
                        st_seller[i] = 1;
                        cout << pass_v[i];
                        i++;
                        total_seller = i;
                        cout << "El usuario ha sido dado de alta exitosamente\n";
                    } else
                        if (pos == -2) {
                        i = i_ba;
                        while (true) {
                            cout << "El usuario " << usuario << " está dado de baja, ¿Desea Reactivarlo?\n";
                            cout << "1. Sí\n";
                            cout << "2. No\n";
                            cin >> opc;
                            switch (opc) {
                                case 1:
                                {
                                    do {
                                        cout << "Ingrese contraseña del usuario " << usuario << ": ";
                                        cin>>pass1;
                                        cout << "Confirme la contraseña: ";
                                        cin>>pass2;
                                        if (pass1 == pass2) {
                                            pass_v[i] = pass2;
                                            break;
                                        } else
                                            cout << "Las contraseñas no coinciden, intente de nuevo\n";
                                    } while (pass1 != pass2);
                                    st_seller[i] = 1;
                                    cout << "El usuario ha sido reactivado exitosamente\n";
                                }
                                    break;
                                case 2:
                                    break;
                                default: cout << "Opción Inválida\n";
                            }
                            if (opc < 3)
                                break;
                        }
                    } else
                        cout << "El usuario " << user_seller[pos] << " ya existe\n";
                }
            }
                break;
            case 3:
                break;
            default: cout << "Opción Inválida\n";
        }
        break;
    } while (opc != 3);

}

void Bajas_u() {
    int i;
    int pos;
    int opc;
    string usuario;
    cout << "Baja de Usuarios\n";
    do {
        cout << "¿El usuario a dar de Baja es Administador o Vendedor?\n";
        cout << "1. Administrador\n";
        cout << "2. Vendedor\n";
        cout << "3. Regresar\n";
        cin>>opc;
        switch (opc) {
            case 1:
            {
                while (true) {
                    cout << "Ingrese usuario: ";
                    cin>>usuario;
                    if (usuario == "*")
                        break;
                    pos = buscar_a(usuario);
                    if (pos == -1)
                        cout << "El usuario: " << usuario << ", no existe\n";
                    else
                        if (pos == -2)
                        cout << "El usuario: " << usuario << ", ya está dado de baja\n";
                    else {
                        i = pos;
                        while (true) {
                            cout << "¿Seguro que desea dar de baja el usuario: " << user_admin[i] << "?\n";
                            cout << "1. Sí\n";
                            cout << "2. No\n";
                            cin >> opc;
                            switch (opc) {
                                case 1:
                                {
                                    st_admin[i] = 0;
                                    cout << "El usuario ha sido dado de baja exitosamente\n";
                                }
                                    break;
                                case 2:
                                    break;
                                default: cout << "Opción Inválida\n";
                            }
                            if (opc < 3)
                                break;
                        }
                    }
                }
            }
                break;
            case 2:
            {
                while (true) {
                    cout << "Ingrese usuario: ";
                    cin>>usuario;
                    if (usuario == "*")
                        break;
                    pos = buscar_v(usuario);
                    if (pos == -1)
                        cout << "El usuario: " << usuario << ", no existe\n";
                    else
                        if (pos == -2)
                        cout << "El usuario: " << usuario << ", ya está dado de baja\n";
                    else {
                        i = pos;
                        while (true) {
                            cout << "¿Seguro que desea dar de baja el usuario: " << user_seller[i] << "?\n";
                            cout << "1. Sí\n";
                            cout << "2. No\n";
                            cin >> opc;
                            switch (opc) {
                                case 1:
                                {
                                    st_seller[i] = 0;
                                    cout << "El usuario ha sido dado de baja exitosamente\n";
                                }
                                    break;
                                case 2:
                                    break;
                                default: cout << "Opción Inválida\n";
                            }
                            if (opc < 3)
                                break;
                        }
                    }
                }
            }
                break;
            case 3:
                break;
            default: cout << "Opción Inválida\n";
        }
        break;
    } while (opc != 3);
}

void Consultas_u() {
    int i;
    int pos;
    int opc;
    int pass1;
    int pass2;
    string usuario;
    cout << "Consulta de Usuarios\n";
    do {
        cout << "¿El usuario a dar de Baja es Administador o Vendedor?\n";
        cout << "1. Administrador\n";
        cout << "2. Vendedor\n";
        cout << "3. Regresar\n";
        cin>>opc;
        switch (opc) {
            case 1:
            {
                while (true) {
                    cout << "Ingrese usuario: ";
                    cin>>usuario;
                    if (usuario == "*")
                        break;
                    pos = buscar_a(usuario);
                    if (pos == -1) {
                        i = total_admin;
                        while (true) {
                            cout << "El usuario " << usuario << " no existe. ¿Desea darlo de Alta?\n";
                            cout << "1. Sí\n" << "2. No\n";
                            cin >> opc;
                            switch (opc) {
                                case 1:
                                {
                                    do {
                                        cout << "Ingrese contraseña del usuario " << usuario << ": ";
                                        cin>>pass1;
                                        cout << "Confirme la contraseña: ";
                                        cin>>pass2;
                                        if (pass1 == pass2) {
                                            pass_a[i] = pass2;
                                            break;
                                        } else
                                            cout << "Las contraseñas no coinciden, intente de nuevo\n";
                                    } while (pass1 != pass2);
                                    user_admin[i] = usuario;
                                    st_admin[i] = 1;
                                    cout << pass_a[i];
                                    i++;
                                    total_admin = i;
                                    cout << "El usuario ha sido dado de alta exitosamente\n";
                                }
                                    break;
                                case 2:
                                    break;
                                default: cout << "Opción Inválida\n";
                            }
                            if (opc < 3)
                                break;
                        }
                    } else
                        if (pos == -2) {
                        i = i_ba;
                        while (true) {
                            cout << "El usuario " << usuario << " está dado de baja, ¿Desea Reactivarlo?\n";
                            cout << "1. Sí\n";
                            cout << "2. No\n";
                            cin >> opc;
                            switch (opc) {
                                case 1:
                                {
                                    do {
                                        cout << "Ingrese contraseña del usuario " << usuario << ": ";
                                        cin>>pass1;
                                        cout << "Confirme la contraseña: ";
                                        cin>>pass2;
                                        if (pass1 == pass2) {
                                            pass_a[i] = pass2;
                                            break;
                                        } else
                                            cout << "Las contraseñas no coinciden, intente de nuevo\n";
                                    } while (pass1 != pass2);
                                    st_admin[i] = 1;
                                    cout << pass_a[i];
                                    cout << "El usuario ha sido reactivado exitosamente\n";
                                }
                                    break;
                                case 2:
                                    break;
                                default: cout << "Opción Inválida\n";
                            }
                            if (opc < 3)
                                break;
                        }
                    } else {
                        i = pos;
                        cout << "Información del Usuario: " << user_admin[i] << endl;
                        cout << setw(6) << "Nombre" << setw(14) << "Contraseña" << setw(8) << "Tipo" << endl;
                        cout << setw(5) << user_admin[i] << setw(10) << pass_a[i] << setw(20) << "Administrador" << endl;
                    }
                }
            }
                break;
            case 2:
            {
                while (true) {
                    cout << "Ingrese usuario: ";
                    cin>>usuario;
                    if (usuario == "*")
                        break;
                    pos = buscar_v(usuario);
                    if (pos == -1) {
                        i = total_seller;
                        while (true) {
                            cout << "El usuario " << usuario << " no existe. ¿Desea darlo de Alta?\n";
                            cout << "1. Sí\n" << "2. No\n";
                            cin >> opc;
                            switch (opc) {
                                case 1:
                                {
                                    do {
                                        cout << "Ingrese contraseña del usuario " << usuario << ": ";
                                        cin>>pass1;
                                        cout << "Confirme la contraseña: ";
                                        cin>>pass2;
                                        if (pass1 == pass2) {
                                            pass_v[i] = pass2;
                                            break;
                                        } else
                                            cout << "Las contraseñas no coinciden, intente de nuevo\n";
                                    } while (pass1 != pass2);
                                    user_seller[i] = usuario;
                                    st_seller[i] = 1;
                                    cout << pass_v[i];
                                    i++;
                                    total_seller = i;
                                    cout << "El usuario ha sido dado de alta exitosamente\n";
                                }
                                    break;
                                case 2:
                                    break;
                                default: cout << "Opción Inválida\n";
                            }
                            if (opc < 3)
                                break;
                        }
                    } else
                        if (pos == -2) {
                        i = i_ba;
                        while (true) {
                            cout << "El usuario " << usuario << " está dado de baja, ¿Desea Reactivarlo?\n";
                            cout << "1. Sí\n";
                            cout << "2. No\n";
                            cin >> opc;
                            switch (opc) {
                                case 1:
                                {
                                    do {
                                        cout << "Ingrese contraseña del usuario " << usuario << ": ";
                                        cin>>pass1;
                                        cout << "Confirme la contraseña: ";
                                        cin>>pass2;
                                        if (pass1 == pass2) {
                                            pass_v[i] = pass2;
                                            break;
                                        } else
                                            cout << "Las contraseñas no coinciden, intente de nuevo\n";
                                    } while (pass1 != pass2);
                                    st_seller[i] = 1;
                                    cout << pass_a[i];
                                    cout << "El usuario ha sido reactivado exitosamente\n";
                                }
                                    break;
                                case 2:
                                    break;
                                default: cout << "Opción Inválida\n";
                            }
                            if (opc < 3)
                                break;
                        }
                    } else {
                        i = pos;
                        cout << "Información del Usuario: " << user_seller[i] << endl;
                        cout << setw(6) << "Nombre" << setw(14) << "Contraseña" << setw(8) << "Tipo" << endl;
                        cout << setw(5) << user_seller[i] << setw(10) << pass_v[i] << setw(20) << "Vendedor" << endl;
                    }
                }
            }
                break;
            case 3:
                break;
            default: cout << "Opción Inválida\n";
        }
        break;
    } while (opc != 3);
}

void Modificaciones_u() {
    int i;
    int opc;
    int pos;
    string usuario;
    cout << "Modificacion de Usuarios\n";
    do {
        cout << "¿El usuario a dar de Baja es Administador o Vendedor?\n";
        cout << "1. Administrador\n";
        cout << "2. Vendedor\n";
        cout << "3. Regresar\n";
        cin>>opc;
        switch (opc) {
            case 1:
            {
                while (true) {
                    cout << "Ingrese usuario a Modificar: ";
                    cin>>usuario;
                    if (usuario == "*")
                        break;
                    pos = buscar_a(usuario);
                    if (pos == -1)
                        cout << "El usuario: " << usuario << ", no existe\n";
                    else
                        if (pos == -2)
                        cout << "El usuario: " << user_admin[pos] << ", está dado de baja\n";
                    else {
                        i = pos;
                        while (true) {
                            cout << "Qué desea Modificar?\n";
                            cout << "1. Nombre de Usuario\n";
                            cout << "2. Contraseña\n";
                            cout << "3. Regresar\n";
                            cin>>opc;
                            switch (opc) {
                                case 1:
                                {
                                    cout << "El nombre actual es: " << user_admin[i] << endl;
                                    cout << "Ingrese el nuevo nombre de usuario: ";
                                    cin >> user_admin[i];
                                    cout << "El nombre del usuario ha sido modificado\n";
                                }
                                    break;
                                case 2:
                                {
                                    cout << "La contraseña actual es: " << pass_a[i] << endl;
                                    cout << "Ingrese la nueva contraseña para " << user_admin[i] << ": ";
                                    cin >> pass_a[i];
                                    cout << "La contraseña del usuario ha sido modificada\n";
                                }
                                    break;
                                case 3:
                                    break;
                                default: cout << "Opción Inválida\n";
                            }
                            if (opc == 3)
                                break;
                        }
                    }
                }
            }
                break;
            case 2:
            {
                while (true) {
                    cout << "Ingrese usuario a Modificar: ";
                    cin>>usuario;
                    if (usuario == "*")
                        break;
                    pos = buscar_v(usuario);
                    if (pos == -1)
                        cout << "El usuario: " << usuario << ", no existe\n";
                    else
                        if (pos == -2)
                        cout << "El usuario: " << user_seller[pos] << ", está dado de baja\n";
                    else {
                        i = pos;
                        while (true) {
                            cout << "Qué desea Modificar?\n";
                            cout << "1. Nombre de Usuario\n";
                            cout << "2. Contraseña\n";
                            cout << "3. Regresar\n";
                            cin>>opc;
                            switch (opc) {
                                case 1:
                                {
                                    cout << "El nombre actual es: " << user_seller[i] << endl;
                                    cout << "Ingrese el nuevo nombre de usuario: ";
                                    cin >> user_seller[i];
                                    cout << "El nombre del usuario ha sido modificado\n";
                                }
                                    break;
                                case 2:
                                {
                                    cout << "La contraseña actual es: " << pass_v[i] << endl;
                                    cout << "Ingrese la nueva contraseña para " << user_seller[i] << ": ";
                                    cin >> pass_v[i];
                                    cout << "La contraseña del usuario ha sido modificada\n";
                                }
                                    break;
                                case 3:
                                    break;
                                default: cout << "Opción Inválida\n";
                            }
                            if (opc == 3)
                                break;
                        }
                    }
                }
            }
                break;
            case 3:
                break;
            default: cout << "Opción Inválida\n";
        }
        break;
    } while (opc != 3);
}

void Mostrar_u() {
    int i;
    int opc;
    string salir;
    while (true) {
        cout << "Información de Usuarios\n";
        cout << "1. Mostrar Usuarios Administradores\n";
        cout << "2. Mostrar Usuarios Vendedores\n";
        cout << "3. Salir\n";
        cin>>opc;
        switch (opc) {
            case 1:
            {
                cout << "Información de Usuarios Administradores:\n";
                cout << setw(6) << "Nombre" << setw(14) << "Contraseña" << setw(8) << "Tipo" << endl;
                for (i = 0; i < total_admin; i++) {
                    if (st_seller[i] == 1)
                        cout << setw(5) << user_admin[i] << setw(10) << pass_a[i] << setw(20) << "Administrador" << endl;
                }
                while (true) {
                    cout << "Presione ''*'' para salir\n";
                    cin>>salir;
                    if (salir == "*")
                        break;
                }
            }
                break;
            case 2:
            {
                cout << "Información de Usuarios Vendedores:\n";
                cout << setw(6) << "Nombre" << setw(14) << "Contraseña" << setw(8) << "Tipo" << endl;
                for (i = 0; i < total_seller; i++) {
                    if (st_seller[i] == 1)
                        cout << setw(5) << user_seller[i] << setw(10) << pass_v[i] << setw(15) << "Vendedor" << endl;
                }
                while (true) {
                    cout << "Presione ''*'' para salir\n";
                    cin>>salir;
                    if (salir == "*")
                        break;
                }
            }
                break;
            case 3:
                break;
            default: cout << "Opción inválida\n";
        }
        break;
    }
}

void Ventas() {
    int i;
    int j;
    int k;
    int c = 0;
    int pos;
    int opc;
    int cant;
    int subtotal[100] = {};
    int suma_subtotal;
    string nombre;
    int total_cliente[100] = {};
    cout << "Menú Ventas\n";
    while (true) {
        cout << "Ingrese nombre del cliente: ";
        cin >> cliente[c];
        if (cliente[c] == "*")
            break;
        suma_subtotal = 0;
        while (true) {
            cout << "Ingrese producto a vender: ";
            cin>>nombre;
            if (nombre == "*")
                break;
            pos = buscar(nombre);
            if (pos == -1)
                cout << "El producto " << nombre << " no existe\n";
            else
                if (pos == -2)
                cout << "El producto " << nombre << " está dado de baja\n";
            else
                if (existencia[pos] < 1)
                cout << "No hay existencia disponible de este producto\n";
            else {
                i = pos;
                cout << "Ingrese cantidad a vender: ";
                cin>>cant;
                if (cant > existencia[i]) {
                    do {
                        cout << "No hay " << cant << " piezas disponibles, únicamente hay " << existencia[i] << ". ¿Desea realizar venta?\n";
                        cout << "1. Sí\n";
                        cout << "2. No\n";
                        cin>>opc;
                        switch (opc) {
                            case 1:
                            {
                                subtotal[i] = existencia[i] * pv[i];
                                cantidad[i] = existencia[i] + cantidad[i];
                                existencia[i] = 0;
                            }
                                break;
                            case 2:
                                break;
                            default:
                                cout << "Opción Inválida\n";
                        }
                    } while (opc > 2);
                } else {
                    subtotal[i] = cant * pv[i];
                    existencia[i] = existencia[i] - cant;
                    cantidad[i] = cant + cantidad[i];
                }
                subtotal_2[i] = subtotal[i] + subtotal_2[i];
                suma_subtotal = subtotal[i] + suma_subtotal;
            }
        }
        total_cliente[c] = suma_subtotal;
        c++;
        check_sell = 1;
    }
    for (j = 0; j != c; j++){
        total_vendedor[i_bv] = total_cliente[j] + total_vendedor[i_bv];
        egresos_vendedor[i_bv]=cantidad[i]*pc[i];
    }
    cout << endl;
    cout << "Vendedor: " << user_seller[i_bv] << endl;
    cout << "Producto" << setw(10) << "Cantidad" << setw(16) << "Precio Unitario" << setw(10) << "Subtotal\n";
    for (i = 0; i < total; i++)
        if (st[i] == 1 && cantidad[i] > 0)
            cout << setw(8) << producto[i] << setw(10) << cantidad[i] << setw(16) << pv[i] << setw(10) << subtotal_2[i] << endl;
    cout << setw(41) << "Total: $" << total_vendedor[i_bv] << endl;
}


