#include "Sys.h"

int ErrorControl();
void menuClient();
void createTestFile();

Sys::Sys()
{
    this->cantCategories = 0; this->thirdAgeRange = 0; this->handicappedRange = 100; this->pregnantRange = 1000; this-> normalRange = 10000;
    cf = new clientFactory(thirdAgeRange, handicappedRange, pregnantRange, normalRange);
    categories = new category ("tercera edad"); cantCategories++; addCategory("discapacidad"); addCategory("embarazadas"); addCategory("normal");
}

void Sys::run()
{
    if (loadData()){
        cout << "Bienvenido al sistema, los numero segun rango de preferencia seran los siguientes: " << endl;
        cout << "-Tercera edad:  " << thirdAgeRange << "-" <<handicappedRange-1 << endl;
        cout << "-Discapacitados:  " << handicappedRange << "-" <<pregnantRange-1 << endl;
        cout << "-Embarazadas:  " << pregnantRange << "-" <<normalRange-1 << endl;
        cout << "-Normales:  " <<  normalRange << " en adelante" << endl;
        bool continuar = true;
        while(continuar){
            showMenu();
        }
    }
    else
    {cout << "Error loading data" << endl;}
}

void Sys::addCategory(string name){
    category *aux = categories;
    category *newCategory = new category(name);
    for (int i = 0; i < cantCategories-1; i++)
    {
        aux = aux->getNext();
    }
    aux->setNext(newCategory);
    cantCategories++;
}

bool Sys::loadData(){
    cout << "Loading data..." << endl;
    ifstream file("Bodega.txt");
    if (!file.is_open()) {
        createTestFile();
    }
    // Read data from file and process it
    string category, subCategory;
    double price;
    int id;
    while (file >> category >> subCategory >> price >> id) {
        // Process the data here
        // For example, you can create a new product object and add it to your system
    }
    file.close();
    cout << "Data loaded successfully" << endl;
    return true;
}


bool Sys::saveData(){ cout << "Saving data... "; return true;}


//Product Menu Options
//Option 1
void Sys::addProduct(){
}
void Sys::generateSellTickets(){}

//Menu options
void Sys::showMenu(){
    cout << "Menu: \n1)Menu clientes\n2)Menu productos" << endl;
    int opt = 0; cin >> opt;
    if (opt == 1)
        showMenuManageClients();
    else if (opt == 2)
        showMenuManageProducts();
    else
        cout << "Invalid option" << endl;
}

//1) Manage Clients Menu
void Sys::showMenuManageClients(){
    client *currentClient = NULL;
    bool continuar = true;
    while(continuar){
        cout << "\nManage Users menu: \n1) Llamar al siguiente cliente\n2) Ingresar cliente a cola\n9)Mostrar todas las colas\n\nq) Ir Atras" << endl;
        string option; cin >> option; //error control
        if (option == "1")
        {
            currentClient = callNextClient();
            if(currentClient != nullptr){
                cout << "Llamando a: " << currentClient->getName() << " | Numero de atencion: " << currentClient->getNumber() << endl;
                menuClient();
            }
            else {
                cout << "No hay clientes en cola" << endl;
            }
        }
        else if(option == "2"){addClientToQueue();}
        else if(option == "9"){ShowQueues();}
        else if(option == "q"){continuar = false;}
        else {cout << "Invalid option" << endl;}
    }
}
//Option 1
client* Sys::callNextClient(){
    client *current = NULL;
    category *aux = categories;
    while(aux->getNext() != nullptr){
        if (!aux->isEmpty()){
            current = aux->getLastClient();
            aux->removeLastClient();
            return current;
        }
        else{ aux = aux->getNext();
        }
    }
    if (!aux->isEmpty()){
        current = aux->getLastClient();
        aux->removeLastClient();
        return current;
    }
    cout << "No clients in queue" << endl;
    return nullptr;
}
//Option 2
void Sys::addClientToQueue(){

    cout << "Ingrese el nombre del nuevo cliente" << endl;
    string name; cin >> name;
    if (isdigit(name[0])) { // Check if the first character of the name is a digit
        cout << "Invalid name" << endl;
        return;
    }
    cout << "Ingrese la edad del nuevo cliente" << endl;
    int age; age=ErrorControl(); //error control
    if (age <= 0){
        cout << "Invalid age" << endl;
        return;
    }
    cout << "Seleccione el tipo de cliente: " << endl;
    cout << "1) Vieja\n2) Discapacitado\n3) Embarazada\n4) Normal" << endl;
    int option; option=ErrorControl();
    if (option <= 0 || option > 4){ //error control
        cout << "Type of client out of range" << endl;
        return;
    }
    client *cliente = cf->createClient(name, age, option); //dar opciones 1,2,3,4 dependiendo del tipo de cliente
    if (typeid(*cliente) == typeid(clientOld))
        {categories->addClient(cliente);}
    else if (typeid(*cliente) == typeid(clientHandicapped))
        {categories->getNext()->addClient(cliente);}
    else if (typeid(*cliente) == typeid(clientPregnant))
        {categories->getNext()->getNext()->addClient(cliente);}
    else if (typeid(*cliente) == typeid(clientNormal))
        {categories->getNext()->getNext()->getNext()->addClient(cliente);}
    cout << "Cliente " << cliente->getName() << " agregado a la cola con exito, numero de atencion: " << cliente->getNumber() << endl;
}
//Option 9
void Sys::ShowQueues(){
                                // TESTEO {
                cout << "INFORMACION DE LAS COLAS:"<< endl;
                cout << "'" << categories->getName() << "': ";
                if(categories->isEmpty()){cout << "Cola vacia" << endl;}
                else{cout << "\n"; categories->showClients();}
                cout << "'" << categories->getNext()->getName() << "': ";
                if(categories->getNext()->isEmpty()){cout << "Cola vacia" << endl;}
                else{cout << "\n"; categories->getNext()->showClients();}
                cout << "'" << categories->getNext()->getNext()->getName() << "': ";
                if(categories->getNext()->getNext()->isEmpty()){cout << "Cola vacia" << endl;}
                else{cout << "\n"; categories->getNext()->getNext()->showClients();}
                cout << "'" << categories->getNext()->getNext()->getNext()->getName() << "': ";
                if(categories->getNext()->getNext()->getNext()->isEmpty()){cout << "Cola vacia" << endl;}
                else{cout << "\n"; categories->getNext()->getNext()->getNext()->showClients();}
                cout << "FIN DE LA INFORMACION DE LAS COLAS"<< endl;
                                //}
}
//Client Menu
void menuClient(){
    cout << "Menu de atencion: \n1) Comprar producto\n2) Salir" << endl;
}

//Manage Products Menu
void Sys::showMenuManageProducts(){
    bool continuar = true;
    while(continuar){
        cout << "\nManage Products Menu: \n1) Agregar producto\n2) Generar ticket\n\nq)Ir atras" << endl;
        string option; cin >> option;
        if (option == "1") {addProduct();}
        else if(option == "2"){generateSellTickets();}
        else if(option == "q"){continuar = false;}
        else {cout << "Invalid option" << endl;}
    }
}

//error control fuction
int ErrorControl(){
    int option;
    cin >> option;
        if (cin.fail()) {
            cin.clear(); // limpia el estado de error
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // vacía el búfer de entrada
            option = 0; // establece una respuesta predeterminada que llevará al caso default
        }
    return option;
}


void createTestFile(){
        product *Product;
        cout << "File not found. Creating new file..." << endl;
        ofstream newFile("Bodega.txt");
        Product = new product("Ibuprofeno (400mg)","Medicamentos","Analgésicos",500,1001);
        newFile << Product->getName()<<";"<<Product->getCategory()<<";"<<Product->getSubCategory()<<";"<<Product->getPrice()<<";"<<Product->getId() <<";"<< endl;
        Product = new product("Paracetamol (500mg)","Medicamentos","Analgésicos",350,1002);
        newFile << Product->getName()<<";"<<Product->getCategory()<<";"<<Product->getSubCategory()<<";"<<Product->getPrice()<<";"<<Product->getId() <<";"<< endl;
        Product = new product("Aspirina (500mg)","Medicamentos","Analgésicos",250,1003);
        newFile << Product->getName()<<";"<<Product->getCategory()<<";"<<Product->getSubCategory()<<";"<<Product->getPrice()<<";"<<Product->getId() <<";"<< endl;
        Product = new product("Acetaminofén (500mg)","Medicamentos","Antipiréticos",400,1004);
        newFile << Product->getName()<<";"<<Product->getCategory()<<";"<<Product->getSubCategory()<<";"<<Product->getPrice()<<";"<<Product->getId() <<";"<< endl;
        Product = new product("Ketaprofeno (200mg)","Medicamentos","Antipiréticos",300,1005);
        newFile << Product->getName()<<";"<<Product->getCategory()<<";"<<Product->getSubCategory()<<";"<<Product->getPrice()<<";"<<Product->getId() <<";"<< endl;
        Product = new product("Dipirona (500mg)","Medicamentos","Antipiréticos",450,1006);
        newFile << Product->getName()<<";"<<Product->getCategory()<<";"<<Product->getSubCategory()<<";"<<Product->getPrice()<<";"<<Product->getId() <<";"<< endl;

        Product = new product("Pasta de dientes (100g)","Productos de higiene personal","Cuidado dental",1200,2001);
        newFile << Product->getName()<<";"<<Product->getCategory()<<";"<<Product->getSubCategory()<<";"<<Product->getPrice()<<";"<<Product->getId() <<";"<< endl;
        Product = new product("Cepillo de dientes","Productos de higiene personal","Cuidado dental",800,2002);
        newFile << Product->getName()<<";"<<Product->getCategory()<<";"<<Product->getSubCategory()<<";"<<Product->getPrice()<<";"<<Product->getId() <<";"<< endl;
        Product = new product("Enjuague bucal (250ml)","Productos de higiene personal","Cuidado dental",900,2003);
        newFile << Product->getName()<<";"<<Product->getCategory()<<";"<<Product->getSubCategory()<<";"<<Product->getPrice()<<";"<<Product->getId() <<";"<< endl;
        Product = new product("Crema hidratante (100g)","Productos de higiene personal","Cuidado de la piel",1500,2004);
        newFile << Product->getName()<<";"<<Product->getCategory()<<";"<<Product->getSubCategory()<<";"<<Product->getPrice()<<";"<<Product->getId() <<";"<< endl;
        Product = new product("Jabón líquido (500ml)","Productos de higiene personal","Cuidado de la piel",800,2005);
        newFile << Product->getName()<<";"<<Product->getCategory()<<";"<<Product->getSubCategory()<<";"<<Product->getPrice()<<";"<<Product->getId() <<";"<< endl;
        Product = new product("Protector solar (FPS 50)","Productos de higiene personal","Cuidado de la piel",2000,2006);
        newFile << Product->getName()<<";"<<Product->getCategory()<<";"<<Product->getSubCategory()<<";"<<Product->getPrice()<<";"<<Product->getId() <<";"<< endl;
        
        Product = new product("Multivitamínico","Suplementos alimenticios","Vitaminas",1000,3001);
        newFile << Product->getName()<<";"<<Product->getCategory()<<";"<<Product->getSubCategory()<<";"<<Product->getPrice()<<";"<<Product->getId() <<";"<< endl;
        Product = new product("Vitamina C (1000mg)","Suplementos alimenticios","Vitaminas",500,3002);
        newFile << Product->getName()<<";"<<Product->getCategory()<<";"<<Product->getSubCategory()<<";"<<Product->getPrice()<<";"<<Product->getId() <<";"<< endl;
        Product = new product("Vitamina D (1000 UI)","Suplementos alimenticios","Vitaminas",600,3003);
        newFile << Product->getName()<<";"<<Product->getCategory()<<";"<<Product->getSubCategory()<<";"<<Product->getPrice()<<";"<<Product->getId() <<";"<< endl;
        Product = new product("Calcio (500mg)","Suplementos alimenticios","Minerales",700,3004);
        newFile << Product->getName()<<";"<<Product->getCategory()<<";"<<Product->getSubCategory()<<";"<<Product->getPrice()<<";"<<Product->getId() <<";"<< endl;
        Product = new product("Magnesio (400mg)","Suplementos alimenticios","Minerales",600,3005);
        newFile << Product->getName()<<";"<<Product->getCategory()<<";"<<Product->getSubCategory()<<";"<<Product->getPrice()<<";"<<Product->getId() <<";"<< endl;
        Product = new product("Hierro (65mg)","Suplementos alimenticios","Minerales",400,3006);
        newFile << Product->getName()<<";"<<Product->getCategory()<<";"<<Product->getSubCategory()<<";"<<Product->getPrice()<<";"<<Product->getId() <<";"<< endl;
        
        Product = new product("Vendaje elástico (5m)","Productos de primeros auxilios","Vendajes y apósitos",500,400);
        newFile << Product->getName()<<";"<<Product->getCategory()<<";"<<Product->getSubCategory()<<";"<<Product->getPrice()<<";"<<Product->getId() <<";"<< endl;
        Product = new product("Apósitos adhesivos (caja de 100 unidades)","Productos de primeros auxilios","Vendajes y apósitos",1000,4002);
        newFile << Product->getName()<<";"<<Product->getCategory()<<";"<<Product->getSubCategory()<<";"<<Product->getPrice()<<";"<<Product->getId() <<";"<< endl;
        Product = new product("Gasas estériles (paquete de 10 unidades)","Productos de primeros auxilios","Vendajes y apósitos",600,4003);
        newFile << Product->getName()<<";"<<Product->getCategory()<<";"<<Product->getSubCategory()<<";"<<Product->getPrice()<<";"<<Product->getId() <<";"<< endl;
        Product = new product("Alcohol al 70% (100ml)","Productos de primeros auxilios","Antisépticos y desinfectantes",800,4004);
        newFile << Product->getName()<<";"<<Product->getCategory()<<";"<<Product->getSubCategory()<<";"<<Product->getPrice()<<";"<<Product->getId() <<";"<< endl;
        Product = new product("Agua oxigenada (10 volúmenes)","Productos de primeros auxilios","Antisépticos y desinfectantes",500,4005);
        newFile << Product->getName()<<";"<<Product->getCategory()<<";"<<Product->getSubCategory()<<";"<<Product->getPrice()<<";"<<Product->getId() <<";"<< endl;
        Product = new product("Povidona yodada (10%)","Productos de primeros auxilios","Antisépticos y desinfectantes",700,4006);
        newFile << Product->getName()<<";"<<Product->getCategory()<<";"<<Product->getSubCategory()<<";"<<Product->getPrice()<<";"<<Product->getId() <<";"<< endl;
        
        Product = new product("Pañales desechables (talla M)","Cuidado del bebé","Higiene del bebé",4000,5001);
        newFile << Product->getName()<<";"<<Product->getCategory()<<";"<<Product->getSubCategory()<<";"<<Product->getPrice()<<";"<<Product->getId() <<";"<< endl;
        Product = new product("Toallitas húmedas para bebé (paquete de 100 unidades)","Cuidado del bebé","Higiene del bebé",2500,5002);
        newFile << Product->getName()<<";"<<Product->getCategory()<<";"<<Product->getSubCategory()<<";"<<Product->getPrice()<<";"<<Product->getId() <<";"<< endl;
        Product = new product("Crema para cambiar pañales (100g)","Cuidado del bebé","Higiene del bebé",1800,5003);
        newFile << Product->getName()<<";"<<Product->getCategory()<<";"<<Product->getSubCategory()<<";"<<Product->getPrice()<<";"<<Product->getId() <<";"<< endl;
        Product = new product("Leche de fórmula (180g)","Cuidado del bebé","Alimentación del bebé",5500,5004);
        newFile << Product->getName()<<";"<<Product->getCategory()<<";"<<Product->getSubCategory()<<";"<<Product->getPrice()<<";"<<Product->getId() <<";"<< endl;
        Product = new product("Biberón (260ml)","Cuidado del bebé","Alimentación del bebé",1500,5005);
        newFile << Product->getName()<<";"<<Product->getCategory()<<";"<<Product->getSubCategory()<<";"<<Product->getPrice()<<";"<<Product->getId() <<";"<< endl;
        Product = new product("Chupete de silicona","Cuidado del bebé","Alimentación del bebé",800,5006);
        newFile << Product->getName()<<";"<<Product->getCategory()<<";"<<Product->getSubCategory()<<";"<<Product->getPrice()<<";"<<Product->getId() <<";"<< endl;

        newFile.close();
}