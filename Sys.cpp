#include "Sys.h"

int ErrorControl();
void createTestFile(Hashmap *productForCategory, Hashmap *productForSubCategory);

/**
 * Constructor for the Sys class.
 * 
 * This constructor initializes the system by creating a hashmap for products by category and subcategory.
 * It also initializes the client categories and the client factory.
 */
Sys::Sys()
{
    productForCategory = new Hashmap(15);
    productForSubCategory = new Hashmap(15);
    this->cantCategories = 0; this->thirdAgeRange = 0; this->handicappedRange = 100; this->pregnantRange = 1000; this-> normalRange = 10000;
    cf = new clientFactory(thirdAgeRange, handicappedRange, pregnantRange, normalRange);
    clientCategories = new clientCategory ("tercera edad"); cantCategories++; addCategory("discapacidad"); addCategory("embarazadas"); addCategory("normal");
}

/**
 * Runs the system.
 * 
 * This function loads the data from the file "Bodega.txt" and displays the main menu.
 * The main menu allows the user to manage clients, manage products, and save the data before exiting the system.
 * The function also displays the ranges for each client category based on the number of clients in the system.
 */
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
            cout << "Menu: \n1)Menu clientes\n2)Menu Ventas\n9)Guardar y salir" << endl;
            int opt = ErrorControl();
            if (opt == 1){showMenuManageClients();}
            else if (opt == 2){showMenuManageProducts();}
            else if (opt == 9){
                if(saveData()){ cout << "Se han guardado los datos con exito" << endl; continuar = false;}
                else { cout << "Ha ocurrido un error al guardar los datos" << endl;}
            }
            else{
                cout << "Invalid option" << endl;
            }
        }
    }
    else {cout << "Error loading data" << endl;}
}

/**
 * Displays the main menu.
 * 
 * This function displays the main menu options, allowing the user to manage clients, manage products, and save the data before exiting the system.
 */
void Sys::addCategory(string name){
    clientCategory *aux = clientCategories;
    clientCategory *newCategory = new clientCategory(name);
    for (int i = 0; i < cantCategories-1; i++)
    {
        aux = aux->getNext();
    }
    aux->setNext(newCategory);
    cantCategories++;
}

/**
 * Displays the main menu.
 * 
 * This function displays the main menu options, allowing the user to manage clients, manage products, and save the data before exiting the system.
 */
bool Sys::loadData(){
    cout << "Loading data..." << endl;
    ifstream file("Bodega.txt");
    if (!file.is_open()) {
        createTestFile();
    }
    else {
        string name, category, subCategory;
        double price;
        int id;

        
        while (getline(file, name, ';')) {
            product *Product;
            size_t pos = name.find('\n');
            if (pos != string::npos) {
                name.erase(pos, 1); // Elimina el carácter de nueva línea
            }
            getline(file, category, ';');
            pos = category.find('\n');
            if (pos != string::npos) {
                category.erase(pos, 1); // Elimina el carácter de nueva línea
            }
            getline(file, subCategory, ';');
            pos = subCategory.find('\n');
            if (pos != string::npos) {
                subCategory.erase(pos, 1); // Elimina el carácter de nueva línea
            }
            file >> price;
            file.ignore();
            file >> id;
            file.ignore();
            Product = new product(name, category, subCategory, price, id);
            productForCategory->insertar(Product->getCategory(), *Product);
            productForSubCategory->insertar(Product->getSubCategory(), *Product);
        }
        
        file.close();
        cout << "Data loaded successfully" << endl;
    }
    
    return true;
}

/**
 * Saves the data to the file "Bodega.txt".
 * 
 * This function saves the data from the product hashmap to the file "Bodega.txt".
 * It writes the product name, category, subcategory, price, and ID to the file.
 * 
 * @return true if the data is saved successfully, false otherwise.
 */
bool Sys::saveData(){
    cout << "Saving data..." << endl;
    ofstream file("Bodega.txt");

    if (!file.is_open()) {
        cout << "Error opening file" << endl;
        return false;
    }
    
    for (int i = 0; i < productForCategory->getTamano(); i++) {
        productNode* currentNode = productForCategory->getTabla()[i];
        while (currentNode != nullptr) {
            product currentProduct = currentNode->getCurrentProduct();
            file << currentProduct.getName() << ";"
                 << currentProduct.getCategory() << ";"
                 << currentProduct.getSubCategory() << ";"
                 << currentProduct.getPrice() << ";"
                 << currentProduct.getId() << endl;
            
            currentNode = currentNode->getNext();
        }
    }
    
    file.close();
    cout << "Data saved successfully" << endl;
    return true;
}

// MENU 1) Manage Clients Menu
/**
 * Displays the menu for managing clients and performs the corresponding actions based on user input.
 */
void Sys::showMenuManageClients(){
    client *currentClient = nullptr;
    bool continuar = true;
    while(continuar){
        cout << "\nManage Users menu: \n1) Llamar al siguiente cliente\n2) Ingresar cliente a cola\n9) Mostrar todas las colas\n\nq) Ir Atras" << endl;
        string option; cin >> option; //error control
        if (option == "1")
        {
            currentClient = callNextClient();
            if(currentClient != nullptr){
                cout << "Llamando a: " << currentClient->getName() << " | Numero de atencion: " << currentClient->getNumber() << endl;
                cin.ignore();
                menuClient(currentClient);
            }
            else {
                cout << "No clients in queue" << endl;
            }
        }
        else if(option == "2"){addClientToQueue();}
        else if(option == "9"){ShowQueues();}

        else if(option == "q"){continuar = false;}
        else {cout << "Invalid option" << endl;}
    }
}

//Manage Clients Menu Options
//Option 1
/**
 * Calls the next client in the queue.
 * 
 * This function retrieves the next client from the client categories list and displays a message with the client's name and assigned number.
 * If there are no clients in the queue, it displays a message indicating that the queue is empty.
 * 
 * @return A pointer to the client object that was called, or nullptr if the queue is empty.
 */
client* Sys::callNextClient(){
    client *current = nullptr;
    clientCategory *aux = clientCategories;
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
    return nullptr;
}

//Option 2
/**
 * Adds a new client to the queue.
 * 
 * This function prompts the user to enter the name, age, and type of client (old, handicapped, pregnant, or normal).
 * It then creates a new client object based on the user input and adds it to the corresponding client category queue.
 */
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
    cout << "1) Viejo\n2) Discapacitado\n3) Embarazada\n4) Normal" << endl;
    int option; option=ErrorControl();
    if (option <= 0 || option > 4){ //error control
        cout << "Type of client out of range" << endl;
        return;
    }
    client *cliente = cf->createClient(name, age, option); //dar opciones 1,2,3,4 dependiendo del tipo de cliente
    if (typeid(*cliente) == typeid(clientOld))
        {clientCategories->addClient(cliente);}
    else if (typeid(*cliente) == typeid(clientHandicapped))
        {clientCategories->getNext()->addClient(cliente);}
    else if (typeid(*cliente) == typeid(clientPregnant))
        {clientCategories->getNext()->getNext()->addClient(cliente);}
    else if (typeid(*cliente) == typeid(clientNormal))
        {clientCategories->getNext()->getNext()->getNext()->addClient(cliente);}
    cout << "Cliente " << cliente->getName() << " agregado a la cola con exito, numero de atencion: " << cliente->getNumber() << endl;
}

//Option 9
/**
 * Displays the queues for each client category.
 * 
 * This function displays the clients in each client category queue, showing the name and number of each client.
 */
void Sys::ShowQueues(){
                                // TESTEO {
                cout << "INFORMACION DE LAS COLAS:"<< endl;
                cout << "'" << clientCategories->getName() << "': ";
                if(clientCategories->isEmpty()){cout << "Cola vacia" << endl;}
                else{cout << "\n"; clientCategories->showClients();}
                cout << "'" << clientCategories->getNext()->getName() << "': ";
                if(clientCategories->getNext()->isEmpty()){cout << "Cola vacia" << endl;}
                else{cout << "\n"; clientCategories->getNext()->showClients();}
                cout << "'" << clientCategories->getNext()->getNext()->getName() << "': ";
                if(clientCategories->getNext()->getNext()->isEmpty()){cout << "Cola vacia" << endl;}
                else{cout << "\n"; clientCategories->getNext()->getNext()->showClients();}
                cout << "'" << clientCategories->getNext()->getNext()->getNext()->getName() << "': ";
                if(clientCategories->getNext()->getNext()->getNext()->isEmpty()){cout << "Cola vacia" << endl;}
                else{cout << "\n"; clientCategories->getNext()->getNext()->getNext()->showClients();}
                cout << "FIN DE LA INFORMACION DE LAS COLAS"<< endl;
                                //}
}

// MENU 1) Manage Clients Menu
/**
 * Displays the menu for managing clients and performs the corresponding actions based on user input.
 * 
 * @param client A pointer to the client object that is currently being attended.
 */
void Sys::menuClient(client *client){
    string ans;
    venta Venta(client);
    int total = 0;
    queue<product> *products = new queue<product>();
    bool continuar = true;
    while(continuar==true){
        cout << "Menu de atencion: \n1) Comprar productos\n2) Ver Carrito\n3) Finalizar compra\nq) Abortar" << endl;
        getline(cin,ans);
        if(ans == "1"){
            bool continuarCompra = true;
            while(continuarCompra){
                cout<< "1)Mostrar productos por categoria\n2)Mostrar Productos por subcategoria\n3)Agregar productos al carrito\n4)Ver Carrito\nq)Ir Atras"<<endl;
                getline(cin, ans);
                if(ans == "1"){cout <<"imprimiendo por categoria" << endl;
                                productForCategory->printAll();}
                else if(ans == "2"){cout <<"imprimiendo por subcategoria" << endl;
                                productForSubCategory->printAll();}
                else if(ans == "3"){
                    while (true) {
                        cout << "Ingrese id del producto que quiere agregar al carrito (o presione q para salir)" << endl;
                        string input;
                        getline(cin, input);
                        if (input == "q") {
                            continuarCompra = false;
                            break;
                        }
                        int id = stoi(input);
                        product producto = productForCategory->buscar(id);
                        if(producto.getId() != -1){
                            cout << "Encontrado!! " << producto.getName() << " ha sido agregado con éxito" << endl;
                            products->push(producto);
                            total += producto.getPrice();
                            productForCategory->remove(id, producto.getCategory());
                            productForSubCategory->remove(id, producto.getCategory());
                        }
                        else {
                            cout << "Producto no encontrado" << endl;
                        }
                    }
                }
                else if(ans =="4"){
                    if (products->empty()) {
                        cout << "No hay productos en el carrito" << endl;
                    }
                    else {
                        cout << " carrito: " <<endl;
                        queue<product> tempQueue = *products; // Create a temporary queue to preserve the original queue
                        while (!tempQueue.empty())
                        { 
                            product p = tempQueue.front(); 
                            cout << p.getName() << ":" << p.getPrice() << endl; 
                            tempQueue.pop(); 
                        }
                        cout << " precio total: " << total<< "$" <<endl; 
                    }
                }
                
                else if(ans =="q"){continuarCompra = false;}
                else{cout << "Invalid option" << endl;}
            }
        }
        else if(ans == "2"){
            
            if (products->empty()) {
                cout << "No hay productos en el carrito" << endl;
            }
            else {
                cout << " carrito: " <<endl;
                queue<product> tempQueue = *products; // Create a temporary queue to preserve the original queue
                while (!tempQueue.empty())
                { 
                    product p = tempQueue.front(); 
                    cout << p.getName() << ":" << p.getPrice() << endl; 
                    tempQueue.pop(); 
                }
                cout << " precio total: " << total<< "$" <<endl; 
            } 
        }
        else if(ans == "3"){
            if (products->empty()) {
            cout << "No hay productos en el carrito" << endl;
            } else {
            Venta.setProducts(products);
            client->addVenta(Venta);
            cout << "Venta realizada!" << endl;
            ventas.push(Venta);
            //TESTEO
            cout << "Productos comprados: " << endl;
            Venta.printProducts();
            cout << "Precio total: " << total << endl;
            cout << "USUARIO:" << endl;
            cout << "Nombre: " << Venta.getClient()->getName() << endl;
            continuar==false;
            break;
            }
        }
        else if(ans == "q"){
            while (!products->empty()) {
                product p = products->front();
                productForCategory->insertar(p.getCategory(), p);
                productForSubCategory->insertar(p.getSubCategory(), p);
                products->pop();
            }
            cout << "Venta cancelada" << endl;
            continuar = false;
            break;
        }
        else{cout << "Invalid option" << endl;}
    }
}

// MENU 2) Manage Products Menu
/**
 * Displays the menu for managing products and performs the corresponding actions based on user input.
 */
void Sys::showMenuManageProducts(){
    bool continuar = true;
    while(continuar){
        cout << "\nManage Products Menu: \n1) Agregar producto\n2) Generar boletas de venta\n\nq)Ir atras" << endl;
        string option; cin >> option;
        if (option == "1") {addProduct();}
        else if(option == "2"){generateSellTickets();}
        else if(option == "q"){continuar = false;}
        else {cout << "Invalid option" << endl;}
    }
}

//Manage Products Menu Options
//Option 1
/**
 * Adds a new product to the product hashmap.
 * 
 * This function prompts the user to enter the name, category, subcategory, price, and ID of the product.
 * It then creates a new product object based on the user input and adds it to the product hashmap.
 */
void Sys::addProduct(){
    string name, category, subCategory;
    int price, id;
    cout << "Enter the name of the product: ";
    cin.ignore(); // Clear the input buffer
    getline(cin, name);
    cout << "Enter the category of the product: ";
    getline(cin, category);
    cout << "Enter the subcategory of the product: ";
    getline(cin, subCategory);
    cout << "Enter the price of the product: ";
    price = ErrorControl();
    cout << "Enter the ID of the product: ";
    id = ErrorControl();

    if (productForCategory->buscar(id).getId() != -1) {
        cout << "Product with ID " << id << " already exists. try again" << endl;
        return;
    }
        if (productForSubCategory->buscar(id).getId() != -1) {
        cout << "Product with ID " << id << " thisalready exists. try again" << endl;
        return;
    }

    product *Product = new product(name, category, subCategory, price, id);
    productForCategory->insertar(Product->getCategory(), *Product);
    productForSubCategory->insertar(Product->getSubCategory(), *Product);

    cout << "Product added successfully" << endl;
    productForCategory->imprimir(Product->getCategory());
}

//Option 2
/**
 * Generates sell tickets for the sales made.
 * 
 * This function generates sell tickets for each sale made by printing the client name, products purchased, and total price.
 * If there are no sales, it displays a message indicating that no sales have been made.
 */
void Sys::generateSellTickets(){
    if (ventas.empty()) {
        cout << "No se han realizado ventas." << endl;
        return;
    }
    
    queue<venta> tempVentas = ventas; // Create a temporary queue to preserve the original queue
    int ticketId = 1; // Initialize the ticket ID
    while (!tempVentas.empty()) {
        venta v = tempVentas.front();
        cout << "\nBOLETA DE VENTA #" << ticketId << endl; // Print the ticket ID
        cout << "-Cliente: " << v.getClient()->getName() << endl;
        cout << "-Productos comprados: " << endl;
        v.printProducts();
        cout << "-Precio de venta: " << v.getTotalPrice() << endl;
        tempVentas.pop();
        ticketId++; // Increment the ticket ID for the next ticket
    }
}

//Error Control
/**
 * Error control function for integer inputs.
 * 
 * This function checks if the input is an integer and returns the input value.
 * If the input is not an integer, it clears the input buffer and returns -1.
 * 
 * @return The integer input value or -1 if the input is not an integer.
 */
int ErrorControl(){
    int option;
    cin >> option;
        if (cin.fail()) {
            cin.clear(); // limpia el estado de error
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // vacía el búfer de entrada
            option = -1; // establece una respuesta predeterminada que llevará al caso default
        }
    return option;
}

//Create Test File
/**
 * Creates a test file with sample product data.
 * 
 * This function creates a new file "Bodega.txt" and writes sample product data to it.
 * The product data includes the name, category, subcategory, price, and ID of each product.
 */
void Sys::createTestFile(){
        product *Product;
        cout << "File not found. Creating new file..." << endl;
        ofstream newFile("Bodega.txt");
        Product = new product("Ibuprofeno (400mg)","Medicamentos","Analgésicos",500,1001);newFile << Product->getName()<<";"<<Product->getCategory()<<";"<<Product->getSubCategory()<<";"<<Product->getPrice()<<";"<<Product->getId() <<";"<< endl; productForCategory->insertar(Product->getCategory(), *Product); productForSubCategory->insertar(Product->getCategory(), *Product);
        Product = new product("Paracetamol (500mg)","Medicamentos","Analgésicos",350,1002);newFile << Product->getName()<<";"<<Product->getCategory()<<";"<<Product->getSubCategory()<<";"<<Product->getPrice()<<";"<<Product->getId() <<";"<< endl; productForCategory->insertar(Product->getCategory(), *Product); productForSubCategory->insertar(Product->getCategory(), *Product);
        Product = new product("Aspirina (500mg)","Medicamentos","Analgésicos",250,1003);newFile << Product->getName()<<";"<<Product->getCategory()<<";"<<Product->getSubCategory()<<";"<<Product->getPrice()<<";"<<Product->getId() <<";"<< endl; productForCategory->insertar(Product->getCategory(), *Product); productForSubCategory->insertar(Product->getCategory(), *Product);
        Product = new product("Acetaminofén (500mg)","Medicamentos","Antipiréticos",400,1004);newFile << Product->getName()<<";"<<Product->getCategory()<<";"<<Product->getSubCategory()<<";"<<Product->getPrice()<<";"<<Product->getId() <<";"<< endl; productForCategory->insertar(Product->getCategory(), *Product); productForSubCategory->insertar(Product->getCategory(), *Product);
        Product = new product("Ketaprofeno (200mg)","Medicamentos","Antipiréticos",300,1005);newFile << Product->getName()<<";"<<Product->getCategory()<<";"<<Product->getSubCategory()<<";"<<Product->getPrice()<<";"<<Product->getId() <<";"<< endl; productForCategory->insertar(Product->getCategory(), *Product); productForSubCategory->insertar(Product->getCategory(), *Product);
        Product = new product("Dipirona (500mg)","Medicamentos","Antipiréticos",450,1006);newFile << Product->getName()<<";"<<Product->getCategory()<<";"<<Product->getSubCategory()<<";"<<Product->getPrice()<<";"<<Product->getId() <<";"<< endl; productForCategory->insertar(Product->getCategory(), *Product); productForSubCategory->insertar(Product->getCategory(), *Product);

        Product = new product("Pasta de dientes (100g)","Productos de higiene personal","Cuidado dental",1200,2001);newFile << Product->getName()<<";"<<Product->getCategory()<<";"<<Product->getSubCategory()<<";"<<Product->getPrice()<<";"<<Product->getId() <<";"<< endl; productForCategory->insertar(Product->getCategory(), *Product); productForSubCategory->insertar(Product->getCategory(), *Product);
        Product = new product("Cepillo de dientes","Productos de higiene personal","Cuidado dental",800,2002);newFile << Product->getName()<<";"<<Product->getCategory()<<";"<<Product->getSubCategory()<<";"<<Product->getPrice()<<";"<<Product->getId() <<";"<< endl; productForCategory->insertar(Product->getCategory(), *Product); productForSubCategory->insertar(Product->getCategory(), *Product);
        Product = new product("Enjuague bucal (250ml)","Productos de higiene personal","Cuidado dental",900,2003);newFile << Product->getName()<<";"<<Product->getCategory()<<";"<<Product->getSubCategory()<<";"<<Product->getPrice()<<";"<<Product->getId() <<";"<< endl; productForCategory->insertar(Product->getCategory(), *Product); productForSubCategory->insertar(Product->getCategory(), *Product);
        Product = new product("Crema hidratante (100g)","Productos de higiene personal","Cuidado de la piel",1500,2004);newFile << Product->getName()<<";"<<Product->getCategory()<<";"<<Product->getSubCategory()<<";"<<Product->getPrice()<<";"<<Product->getId() <<";"<< endl; productForCategory->insertar(Product->getCategory(), *Product); productForSubCategory->insertar(Product->getCategory(), *Product);
        Product = new product("Jabón líquido (500ml)","Productos de higiene personal","Cuidado de la piel",800,2005);newFile << Product->getName()<<";"<<Product->getCategory()<<";"<<Product->getSubCategory()<<";"<<Product->getPrice()<<";"<<Product->getId() <<";"<< endl; productForCategory->insertar(Product->getCategory(), *Product); productForSubCategory->insertar(Product->getCategory(), *Product);
        Product = new product("Protector solar (FPS 50)","Productos de higiene personal","Cuidado de la piel",2000,2006);newFile << Product->getName()<<";"<<Product->getCategory()<<";"<<Product->getSubCategory()<<";"<<Product->getPrice()<<";"<<Product->getId() <<";"<< endl; productForCategory->insertar(Product->getCategory(), *Product); productForSubCategory->insertar(Product->getCategory(), *Product);
        
        Product = new product("Multivitamínico","Suplementos alimenticios","Vitaminas",1000,3001);newFile << Product->getName()<<";"<<Product->getCategory()<<";"<<Product->getSubCategory()<<";"<<Product->getPrice()<<";"<<Product->getId() <<";"<< endl; productForCategory->insertar(Product->getCategory(), *Product); productForSubCategory->insertar(Product->getCategory(), *Product);
        Product = new product("Vitamina C (1000mg)","Suplementos alimenticios","Vitaminas",500,3002);newFile << Product->getName()<<";"<<Product->getCategory()<<";"<<Product->getSubCategory()<<";"<<Product->getPrice()<<";"<<Product->getId() <<";"<< endl; productForCategory->insertar(Product->getCategory(), *Product); productForSubCategory->insertar(Product->getCategory(), *Product);
        Product = new product("Vitamina D (1000 UI)","Suplementos alimenticios","Vitaminas",600,3003);newFile << Product->getName()<<";"<<Product->getCategory()<<";"<<Product->getSubCategory()<<";"<<Product->getPrice()<<";"<<Product->getId() <<";"<< endl; productForCategory->insertar(Product->getCategory(), *Product); productForSubCategory->insertar(Product->getCategory(), *Product);
        Product = new product("Calcio (500mg)","Suplementos alimenticios","Minerales",700,3004);newFile << Product->getName()<<";"<<Product->getCategory()<<";"<<Product->getSubCategory()<<";"<<Product->getPrice()<<";"<<Product->getId() <<";"<< endl; productForCategory->insertar(Product->getCategory(), *Product); productForSubCategory->insertar(Product->getCategory(), *Product);
        Product = new product("Magnesio (400mg)","Suplementos alimenticios","Minerales",600,3005);newFile << Product->getName()<<";"<<Product->getCategory()<<";"<<Product->getSubCategory()<<";"<<Product->getPrice()<<";"<<Product->getId() <<";"<< endl; productForCategory->insertar(Product->getCategory(), *Product); productForSubCategory->insertar(Product->getCategory(), *Product);
        Product = new product("Hierro (65mg)","Suplementos alimenticios","Minerales",400,3006);newFile << Product->getName()<<";"<<Product->getCategory()<<";"<<Product->getSubCategory()<<";"<<Product->getPrice()<<";"<<Product->getId() <<";"<< endl; productForCategory->insertar(Product->getCategory(), *Product); productForSubCategory->insertar(Product->getCategory(), *Product);
        
        Product = new product("Vendaje elástico (5m)","Productos de primeros auxilios","Vendajes y apósitos",500,4001);newFile << Product->getName()<<";"<<Product->getCategory()<<";"<<Product->getSubCategory()<<";"<<Product->getPrice()<<";"<<Product->getId() <<";"<< endl; productForCategory->insertar(Product->getCategory(), *Product); productForSubCategory->insertar(Product->getCategory(), *Product);
        Product = new product("Apósitos adhesivos (caja de 100 unidades)","Productos de primeros auxilios","Vendajes y apósitos",1000,4002);newFile << Product->getName()<<";"<<Product->getCategory()<<";"<<Product->getSubCategory()<<";"<<Product->getPrice()<<";"<<Product->getId() <<";"<< endl; productForCategory->insertar(Product->getCategory(), *Product); productForSubCategory->insertar(Product->getCategory(), *Product);
        Product = new product("Gasas estériles (paquete de 10 unidades)","Productos de primeros auxilios","Vendajes y apósitos",600,4003);newFile << Product->getName()<<";"<<Product->getCategory()<<";"<<Product->getSubCategory()<<";"<<Product->getPrice()<<";"<<Product->getId() <<";"<< endl; productForCategory->insertar(Product->getCategory(), *Product); productForSubCategory->insertar(Product->getCategory(), *Product);
        Product = new product("Alcohol al 70% (100ml)","Productos de primeros auxilios","Antisépticos y desinfectantes",800,4004);newFile << Product->getName()<<";"<<Product->getCategory()<<";"<<Product->getSubCategory()<<";"<<Product->getPrice()<<";"<<Product->getId() <<";"<< endl; productForCategory->insertar(Product->getCategory(), *Product); productForSubCategory->insertar(Product->getCategory(), *Product);
        Product = new product("Agua oxigenada (10 volúmenes)","Productos de primeros auxilios","Antisépticos y desinfectantes",500,4005);newFile << Product->getName()<<";"<<Product->getCategory()<<";"<<Product->getSubCategory()<<";"<<Product->getPrice()<<";"<<Product->getId() <<";"<< endl; productForCategory->insertar(Product->getCategory(), *Product); productForSubCategory->insertar(Product->getCategory(), *Product);
        Product = new product("Povidona yodada (10%)","Productos de primeros auxilios","Antisépticos y desinfectantes",700,4006);newFile << Product->getName()<<";"<<Product->getCategory()<<";"<<Product->getSubCategory()<<";"<<Product->getPrice()<<";"<<Product->getId() <<";"<< endl; productForCategory->insertar(Product->getCategory(), *Product); productForSubCategory->insertar(Product->getCategory(), *Product);
        
        Product = new product("Pañales desechables (talla M)","Cuidado del bebé","Higiene del bebé",4000,5001);newFile << Product->getName()<<";"<<Product->getCategory()<<";"<<Product->getSubCategory()<<";"<<Product->getPrice()<<";"<<Product->getId() <<";"<< endl; productForCategory->insertar(Product->getCategory(), *Product); productForSubCategory->insertar(Product->getCategory(), *Product);
        Product = new product("Toallitas húmedas para bebé (paquete de 100 unidades)","Cuidado del bebé","Higiene del bebé",2500,5002);newFile << Product->getName()<<";"<<Product->getCategory()<<";"<<Product->getSubCategory()<<";"<<Product->getPrice()<<";"<<Product->getId() <<";"<< endl; productForCategory->insertar(Product->getCategory(), *Product); productForSubCategory->insertar(Product->getCategory(), *Product);
        Product = new product("Crema para cambiar pañales (100g)","Cuidado del bebé","Higiene del bebé",1800,5003);newFile << Product->getName()<<";"<<Product->getCategory()<<";"<<Product->getSubCategory()<<";"<<Product->getPrice()<<";"<<Product->getId() <<";"<< endl; productForCategory->insertar(Product->getCategory(), *Product); productForSubCategory->insertar(Product->getCategory(), *Product);
        Product = new product("Leche de fórmula (180g)","Cuidado del bebé","Alimentación del bebé",5500,5004);newFile << Product->getName()<<";"<<Product->getCategory()<<";"<<Product->getSubCategory()<<";"<<Product->getPrice()<<";"<<Product->getId() <<";"<< endl; productForCategory->insertar(Product->getCategory(), *Product); productForSubCategory->insertar(Product->getCategory(), *Product);
        Product = new product("Biberón (260ml)","Cuidado del bebé","Alimentación del bebé",1500,5005);newFile << Product->getName()<<";"<<Product->getCategory()<<";"<<Product->getSubCategory()<<";"<<Product->getPrice()<<";"<<Product->getId() <<";"<< endl; productForCategory->insertar(Product->getCategory(), *Product); productForSubCategory->insertar(Product->getCategory(), *Product);
        Product = new product("Chupete de silicona","Cuidado del bebé","Alimentación del bebé",800,5006);newFile << Product->getName()<<";"<<Product->getCategory()<<";"<<Product->getSubCategory()<<";"<<Product->getPrice()<<";"<<Product->getId() <<";"<< endl; productForCategory->insertar(Product->getCategory(), *Product); productForSubCategory->insertar(Product->getCategory(), *Product);

        newFile.close();
}