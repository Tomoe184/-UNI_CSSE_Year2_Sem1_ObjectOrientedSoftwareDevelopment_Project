#include <cstdio>
#include <stdio.h>
#include <iostream>
#include<ctime>
#include<string.h>
#include<fstream>
#include <iomanip>
#include "classProduct.h" 
#include "classCustomer.h" 

using namespace std;

using std::cout;
using std::cin;
using std::endl;
using std::string;

// class user method
int customer::registration() {

    cout << "Please use your email address (xxxxx@email.com) to register as username.\n";
    cout << "# Please enter username: ";
    getchar();
    getline(cin, username);
    
    size_t at = username.find('@');
    size_t dot = username.find('.', at + 1);
    if (at == string::npos)
    {
        cout << "*** Invalid email address entered! Missing @ symbol ***\n\n";
        return 1;
    }

    else if (dot == string::npos)
    {
        cout << "*** Invalid email address entered! Missing . symbol after @ ***\n\n";
        return 2;
    }

    cout << "# Please enter password: ";
    cin >> password;

    ofstream MyFile("Registration.txt", ios::app);
    MyFile << username << endl;
    MyFile << password << endl;
    MyFile.close();

    cout << "\nSuccessfully register. Your username and password are shown below:";
    cout << "\n# Username: " << username;
    cout << "\n# Password: " << password; 
    cout << endl << endl;
}

int customer::login() {
    cout <<"WELCOME BACK!"<<endl;
    cout <<"Please enter your username (xxxxx@email.com) and password to login"<<endl;
    cout <<endl;
    cout <<"# Username: ";
    getchar();
    getline(cin, InputUsername);

    size_t at = InputUsername.find('@');
    if (at == string::npos)
    {
        cout << "Invalid email address entered! Missing @ symbol\n\n"<<endl;
        return 1;
    }

    size_t dot = InputUsername.find('.', at + 1);
    if (dot == string::npos)
    {
        cout << "Invalid email address entered! Missing . symbol after @\n\n"<<endl;
        return 2;
    }
    
    cout << "# Password: ";
    getline(cin, InputPassword);
}

int customer::validate() {
    int n = 0;

    ifstream MyReadFile("Registration.txt");
    while (!MyReadFile.eof()) {
        MyReadFile >> username >> password;
        n++;
        if (InputUsername == username && InputPassword == password) {
            return n;
        }
        else if (InputUsername == "test111@gmail.com" && InputPassword == "test111") {
            return n;
        }
        else if (InputUsername == "test222@gmail.com" && InputPassword == "test222") {
            return n;
        }
        else if (InputUsername == "test333@gmail.com" && InputPassword == "test333") {
            return n;
        }
    }

    MyReadFile.close();

    return 0;
}

int customer::update() {
    string newusername, newpass, un, pw;

    ifstream myfile2;
    myfile2.open("Registration.txt");
    ofstream temp;
    temp.open("temp.txt");

    while(myfile2 >> un >> pw) {
        if (un != InputUsername && pw != InputPassword) {
            temp << un << endl;
            temp << pw << endl;
        }
    }

    myfile2.close();
    temp.close();
    remove("Registration.txt");
    rename("temp.txt", "Registration.txt");
    
    cout << "\n# Enter new username: ";

    getline(cin, newusername);

    size_t at = newusername.find('@');
    if (at == string::npos) {
        cout << "*** Invalid email address entered! Missing @ symbol ***\n\n" << endl;
        return 1;
    }

    size_t dot = newusername.find('.', at + 1);
    if (dot == string::npos) {
        cout << "*** Invalid email address entered! Missing . symbol after @ ***\n\n"<<endl;
        return 2;
    }

    cout << "# Enter new password: ";
    getline(cin, newpass);

    ofstream myfile;
    myfile.open("Registration.txt", ios::app | ios::out);
    myfile << newusername << endl;
    myfile << newpass << endl;

    myfile.close();


    cout << "Your username and password are successfully updated! Thank you." << endl;
    cout << endl;
    cout << "Your new username: " << newusername << endl;
    cout << "Your new password: " << newpass << endl;
    system("pause");
}

void customer::viewProduct(product prolist[], int size, int input, product p){
	p.printDetails(prolist, 12, input);
}

void customer :: addItem(product prolist[], int size, int preset, cart cartlist[], int csize){
	cartlist[preset].addToCart(prolist, 12, preset);
}

void customer :: removeItem(cart cartlist[], int size, int preset){
	cartlist[preset].removeCart(cartlist, 100, preset);
}

void customer :: viewCart(cart cartlist[], int size, int preset, cart c){
	c.printDetails(cartlist,100, preset);
}

void customer :: makepay(payment paylist[], int size, int paypreset, int preset){
	paylist[paypreset].makePayment(paypreset, preset);
}

void customer :: manageOrder(order orderlist[], int size, int orpreset, order sta1, order sta4, order o){
	o.cancelOrder(orderlist, 100, orpreset, sta1, sta4);
}

// class product Method
void product :: setDetails(int id, string ty,  string na, string des, int quan, string status, double pri ) {
    productID = id;
    productType = ty;
    productName = na;
    productDescription = des;
    productQuantity = quan;
    productStatus = status;
    productPrice = pri;	
};

void product :: setType(string ty){
    productType = ty;
}

void product :: getType(){
    cout << productType << endl;
}
int product :: getID(){
    return productID;
}
string product :: getName(){
    return productName;
}

double product :: getPrice(){
    return productPrice;
}

void product :: printDetails(product prolist[], int size, int input) {
    if (input == 1){
        cout <<"________________________________________________________________________________________________________________"<<endl;
        cout <<"					Condiments: "<<endl;
        cout <<"________________________________________________________________________________________________________________"<<endl;
            for (int i=1; i<=3; i++){
        cout <<"					"<<i<<". ";
        cout <<prolist[i].productName<<endl;	
        }
        cout <<"________________________________________________________________________________________________________________"<<endl;
    }
    else if (input == 2){
        cout << "________________________________________________________________________________________________________________"<< endl;
        cout <<"					Canned Food: "<<endl;
        cout << "________________________________________________________________________________________________________________" << endl;
        for (int i=4; i<=6; i++){
        cout << "					" << i << ". ";
        cout <<prolist[i].productName<<endl;	
        }
        cout << "________________________________________________________________________________________________________________" << endl;
    }
    else if (input == 3) {
        cout << "________________________________________________________________________________________________________________" << endl;
        cout << "					Dairy: " << endl;
        cout << "________________________________________________________________________________________________________________" << endl;
        for (int i = 7; i <= 9; i++){
            cout << "					" << i << ". ";
            cout << prolist[i].productName << endl;
        }
        cout << "________________________________________________________________________________________________________________" << endl;
    }
    else if (input == 4){
        cout << "________________________________________________________________________________________________________________" << endl;
        cout << "					Snacks: " << endl;
        cout << "________________________________________________________________________________________________________________" << endl;

        for (int i = 10; i <= 12; i++) {
            cout << "					" << i << ". ";
            cout << prolist[i].productName << endl;
        }
        cout << "________________________________________________________________________________________________________________" << endl;
    }
}

void product :: printDetails(product prolist[], int size, int category, int proch) {
    int detch;

    if (proch == 1){
        cout << endl;

        det:
        cout << "# Select product to view details: ";
        cin >> detch;

        if (category == 1) {
            if (detch <1) {
                cout << "Invalid Product!" << endl;
                goto det;
            }
            else if (detch >3) {
                cout <<"Invalid Product!" << endl;
                goto det;
            }
            else {
                for (int i = 1; i <= 3; i++){
                    if (i == detch){
                    cout << endl;
                    cout << "________________________________________________________________________________________________________________" << endl;
                    cout << setw(5) << prolist[i].productName<<endl;
                    cout << "________________________________________________________________________________________________________________" << endl;
                    cout <<"Product ID: "<<prolist[i].productID << endl;
                    cout <<"Category: "<<prolist[i].productType << endl;
                    cout <<"Product Description: "<<prolist[i].productDescription << endl;
                    cout <<"Quantity: "<<prolist[i].productQuantity << endl;
                    cout<<"Status: "<<prolist[i].productStatus << endl;
                    cout <<"Price: "<<prolist[i].productPrice << endl;
                    cout << "________________________________________________________________________________________________________________" << endl << endl;
                    }
                }
            }
        }

        else if (category == 2) {
            if (detch < 4){
                cout << "Invalid Product!" << endl;
                goto det;
            }
            else if (detch > 6) {
                cout << "Invalid Product!" << endl;
                goto det;
            }
            else{

            for (int i = 4; i <= 6; i++){
                if (i == detch){
                    cout<<endl;
                    cout <<"________________________________________________________________________________________________________________"<<endl;
                    cout <<setw(5)<<prolist[i].productName<<endl;
                    cout <<"________________________________________________________________________________________________________________"<<endl;
                    cout <<"Product ID: "<<prolist[i].productID <<endl;
                    cout <<"Category: "<<prolist[i].productType<<endl;
                    cout <<"Product Description: "<<prolist[i].productDescription<<endl;
                    cout <<"Quantity: "<<prolist[i].productQuantity<<endl;
                    cout<<"Status: "<<prolist[i].productStatus<<endl;
                    cout <<"Price: "<<prolist[i].productPrice<<endl;
                    cout <<"________________________________________________________________________________________________________________"<<endl;
                    cout <<endl;
                }
            }
        }

        }
        else if (category == 3){
            if (detch <7){
                cout <<"Invalid Product!"<<endl;
                goto det;
            }
            else if (detch >9){
                cout <<"Invalid Product!"<<endl;
                goto det;
            }
            else {
                
            for (int i = 7; i <= 9; i++){
                if (i == detch){
                cout<<endl;
                cout <<"________________________________________________________________________________________________________________"<<endl;
                cout <<setw(5)<<prolist[i].productName<<endl;
                cout <<"________________________________________________________________________________________________________________"<<endl;
                cout <<"Product ID: "<<prolist[i].productID <<endl;
                cout <<"Category: "<<prolist[i].productType<<endl;
                cout <<"Product Description: "<<prolist[i].productDescription<<endl;
                cout <<"Quantity: "<<prolist[i].productQuantity<<endl;
                cout<<"Status: "<<prolist[i].productStatus<<endl;
                cout <<"Price: "<<prolist[i].productPrice<<endl;		
                cout <<"________________________________________________________________________________________________________________"<<endl;
                cout <<endl;
                }
            }
        }

        }
        else if (category == 4){
            if (detch < 10){
                cout << "Invalid Product!" << endl;
                goto det;
            }
            else if (detch >12){
                cout << "Invalid Product!" << endl;
                goto det;
            }
            else{
                for (int i=10; i<=12; i++) {
                    if (i == detch) {
                    cout << endl;
                    cout <<"________________________________________________________________________________________________________________" << endl;
                    cout << setw(5) << prolist[i].productName << endl;
                    cout << "________________________________________________________________________________________________________________" << endl;
                    cout << "Product ID: " << prolist[i].productID << endl;
                    cout << "Category: " << prolist[i].productType << endl;
                    cout << "Product Description: " << prolist[i].productDescription << endl;
                    cout << "Quantity: " << prolist[i].productQuantity << endl;
                    cout << "Status: " << prolist[i].productStatus << endl;
                    cout << "Price: " << prolist[i].productPrice << endl;
                    cout << "________________________________________________________________________________________________________________" << endl;
                    cout << endl;
                    }
                }
            }
    }
    }
}

// cart method
    int cart :: getCartID() {
        return cartID;
    }
    int cart :: getID() {
        return productID;
    }
    string cart :: getName() {
        return productName;
    }
    double cart :: getPrice() {
        return productPrice;
    }
    int cart :: getQuanAdded() {
        return quanAdded;
    }
    double cart :: getTotalPrice() {
        return productPrice * quanAdded;
    }

    void cart :: setDetails(int cid, int pid, string pname, double ppri, int qAdd, double totP){
        cartID = cid;
        productID = pid;
        productName = pname;
        productPrice = ppri;
        quanAdded = qAdd;
        totP = totP;
    }

// Add item to cart product list
void cart :: printDetails(product prolist[], int size, int input){
    if (input == 1){
        cout << "Product List: " << endl;
            for (int i=1; i<=12; i++){
        cout << i <<". ";
        cout << prolist[i].getName() << endl;
        cout << endl;
        }
    }
}

void cart :: printDetails(cart cartlist[], int size, int preset){
    cout <<"					Your cart list: "<<endl;
    cout <<"________________________________________________________________________________________________________________"<<endl;
    cout <<setw(5)<<"Item"<<setw(13)<<"Cart ID"<<setw(15)<<"Product ID"<<setw(18)<<"Product Name"<<setw(18)<<"Price (RM)"<<setw(20)<<"Quantity Added"<<setw(20)<<"Total Price(RM)"<<endl;
    cout <<"________________________________________________________________________________________________________________"<<endl;

    for (int i=1; i<=preset; i++){
        cout <<setw(3)<<i<<setw(13)<<cartlist[i].cartID<<setw(13)<<cartlist[i].productID<<setw(20)<<cartlist[i].productName<<setw(16)
        <<cartlist[i].productPrice<<setw(17)<<cartlist[i].quanAdded<<setw(20)<< cartlist[i].productPrice * cartlist[i].quanAdded<<endl;	
        cout <<endl;
    }

    cout <<"________________________________________________________________________________________________________________"<<endl << endl;
}

void cart :: addToCart(product prolist[],int psize,int preset){
    int addch;

    add:
    cout <<"# Select your product to add to cart: ";
    cin>> addch;
    if (addch <=0 ){
        cout <<"***Invalid input!***"<<endl;
        goto add;
    }
    else if (addch > 12){
        cout <<"***Invalid input!***"<<endl;
        goto add;
    }
    else{
        for (int i = 1; i <= 12; i++){ 
            if (i == addch){
                quan: // label
                cout <<endl;
                cout <<"# Enter the quantity you would like to add: ";
                cin >> quanAdded;

                if (quanAdded > 5){
                    cout <<"You can only add maximum of 5 for this item"<<endl;
                    goto quan;
                }
                else if (quanAdded <0){
                    cout <<"you must at least add one to the cart"<<endl;
                    goto quan;
                }
                else{
                    cartID = preset;
                    productID = prolist[i].getID();
                    productName = prolist[i].getName();
                    productPrice = prolist[i].getPrice();
                    quanAdded = quanAdded;
                    totP= prolist[i].getPrice() * quanAdded;
                
                    cout <<endl;
                    cout <<"Item added to Cart!"<<endl;
                    cout <<endl;
                    
                    system("pause");
                }
            }
        }
    }
    return;
};

void cart :: removeCart(cart cartlist[], int size ,int preset){
    int deletech, pro, pro2;

    del:
    cout <<"# Select the item you would like to delete: ";
    cin >>deletech;

    if (deletech <= 0){
        cout <<"Please select a valid item "<<endl;
        cout <<endl;
        goto del;
    }
    else if (deletech > preset) {
        cout <<"Please select a valid item"<<endl;
        cout <<endl;
        goto del;
    }
    else {
        for (int i=1; i<=preset; i++){
            if (i==deletech){
                for (int j=i; j<=preset; j++){
                    cartlist[j] = cartlist[j+1];
                }
            }
        }

    cout <<"Item removed from cart!"<<endl;
    cout <<endl;

    system("pause");
    }
}

// payment method
int payment :: getPayID(){
    return paymentID;
}
void payment :: setPaymentMethod(string paymet){
    if (paymet == "Master Card" || paymet == "Visa Card"){
        paymentMethod = paymet;
    }
    
}
string payment :: getPaymentMethod(){
    return paymentMethod;
}
double payment :: getFinalAm(){
    return tax + shipping + totalAm;
}

double payment :: getTax(){
    return 0.06 * totalAm;
}
double payment :: getShipping (){
    return 10;
}

void payment :: checkout(cart cartlist[], int size, int preset){
    totalAm = 0;
    for (int j=1; j<=preset; j++){
        totalAm = totalAm + cartlist[j].getTotalPrice();
        }
        tax = getTax();;
        shipping = getShipping();
        cout <<endl;
        
        cout << "Your total product is : " << preset << endl;
        cout << "Tax: RM " << tax << endl;
        cout << "Shipping: RM " << shipping << endl;
        cout << "The total amount you need to pay is : " << getFinalAm() << setprecision(3) << endl;
        cout << endl;
};


void payment :: makePayment(int paypreset, int preset){
    int cardch;

    p:
    cout << " \nSelect which payment method you would like to use" << endl
    << " 1 - Master Card" << endl
    << " 2. - Visa Card" << endl;
    cout << "\n# Enter your Payment Method: ";
    cin >>cardch;
    
    if ( cardch == 1){
        paymentID = paypreset;
        totalProduct = preset;
        finAm = finAm;
        setPaymentMethod("Master Card");
    }
    else if (cardch == 2){
        paymentID = paypreset;
        totalProduct = preset;
        finAm = finAm;
        setPaymentMethod("Visa Card");
    }
    else{
        cout <<"***Invalid payment method***"<<endl;
        goto p;
    }
};

void payment::displayPaymentDate(){
    // To get date
    time_t now = time(0);
    tm *ltm = localtime(&now);

    // Display date
    cout <<"Payment Date: "<< ltm->tm_mday<< "/"<< 1+ ltm->tm_mon<< "/"<< 1900 + ltm->tm_year<<endl;
};

void payment :: printReceipt(cart cartlist[], int size, int preset){
    cout <<"________________________________________________________________________________________________________________"<<endl;
    cout <<"Product ID 		Product Name		Quantity		Product Price		Total Price"<<endl;
    cout <<"________________________________________________________________________________________________________________"<<endl;

    for (int i=1; i<=preset; i++){
        cout <<setw(5)<<cartlist[i].getID()<<setw(30)<<cartlist[i].getName()<<setw(18)<<cartlist[i].getQuanAdded()<<setw(27)<<cartlist[i].getPrice()<<setw(23)<<cartlist[i].getTotalPrice()<<endl;
        cout <<endl;
    }
    cout <<endl;
    cout <<setw(85)<<"Tax: "<<tax << setw(17) <<"Shipping: "<<shipping<<endl;
    cout <<endl;
    cout <<setw(101)<<"Total Amount : "<<getFinalAm()<<endl;

    ofstream file("Receipt.txt", ios::app);
    file <<"________________________________________________________________________________________________________________"<<endl;
    file <<"Product ID 		Product Name		Quantity		Product Price		Total Price"<<endl;
    file <<"________________________________________________________________________________________________________________"<<endl;
    for (int i=1; i<=preset; i++){
        file <<setw(5)<<cartlist[i].getID()<<setw(30)<<cartlist[i].getName()<<setw(18)<<cartlist[i].getQuanAdded()<<setw(27)<<cartlist[i].getPrice()<<setw(23)<<cartlist[i].getTotalPrice()<<endl;
        file <<endl;
    }
    file <<setw(85)<<"Tax: "<<tax << setw(20) <<"Shipping: "<<shipping<<endl;
    file <<setw(101)<<"Total Amount : "<<getFinalAm()<<endl;

    return;
}

void payment :: printPayment(){
    cout <<"________________________________________________________________________________________________________________"<<endl;
    cout <<"Payment ID: "<<paymentID<<setw(30)<<"Payment Method: "<<paymentMethod<<setw(45)<<"Total Product: "<<totalProduct<<endl;
    cout <<"________________________________________________________________________________________________________________"<<endl;

    ofstream file("Receipt.txt", ios::app);
    file <<"________________________________________________________________________________________________________________"<<endl;
    file <<"Payment ID: "<<paymentID<<setw(20)<<"Payment Method: "<<paymentMethod<<setw(40)<<"Total Product: "<<totalProduct<<setw(18)<<endl;
    file <<"________________________________________________________________________________________________________________"<<endl;
        file.close();
};

// order method
void order :: setOrder(int oid, string osta, int pid, string pay, double totAm){
    orderID =  oid;
    setStatus(osta);
    payID = pid;
    paymethod = pay;
    finalAm = totAm;
}

void order :: setStatus(string status){
    if (status == "Pending" || status == "Dispatched" || status =="Completed" || status == "Cancelled"){
        orderStatus = status; 
    }
}

string order :: getStatus(){
    return orderStatus;
}

void order :: addToOrder(order orderlist[], int size,  int orpreset){
    for (int i=1; i<=orpreset; i++){
        orderID = orpreset;
        setStatus("Pending");
    }
}

void order :: addToOrder(payment paylist[], int size, int paypreset, int orpreset, payment paym){
    for (int i=1; i<=orpreset; i++){
        payID= paylist[paypreset].getPayID();
        paymethod = paylist[paypreset].getPaymentMethod();
        finalAm = paym.getFinalAm();
    }
}

void order :: viewOrder(order orderlist[], int size, int orpreset){
    cout << "_________________________________________Order History____________________________________________" << endl;
    cout <<"Order ID"<<setw(20)<<"Order Status"<<setw(20)<<"Payment ID"<<setw(20)<<"Payment Method"<<setw(25)<<"Total Amount (RM)"<<endl;
    cout <<"___________________________________________________________________________________________________"<<endl;
    for (int i=1; i<=orpreset; i++){
        cout <<setw(5)<<orderlist[i].orderID<<setw(20)<<orderlist[i].orderStatus<<setw(20)<<orderlist[i].payID<<setw(20)<<orderlist[i].paymethod<<setw(20)<<orderlist[i].finalAm<<endl;	
    }
    cout <<"___________________________________________________________________________________________________"<<endl;
}

void order :: cancelOrder(order orderlist[], int size, int orpreset, order sta1, order sta4){
    int c, cancel;

    cancel:
        can:
        cout <<endl;
        cout <<"#Enter the order you would like to cancel: ";
        cin >> c;

    if (c <=0){
        cout <<endl;
        cout <<"***Please enter a valid order***"<<endl;
        goto can;
    }
    else if (c > orpreset){
        cout <<endl;
        cout <<"***Please enter a valid order***"<<endl;
        goto can;
    }
    else{
        if (orderlist[c].orderStatus == sta1.orderStatus){
            orderlist[c].orderStatus =sta4.orderStatus;
            cout <<endl;
            cout <<"Order cancelled!"<<endl;
        }
        else {
            cout <<endl;
            cout <<"Only pending order are allowed to be cancelled!"<<endl;
        }
    }

    pro:
    cout <<endl;
    cout <<"# Enter 1 to proceed cancelling order / 0 to return to menu: ";
    cin >> cancel;
    if (cancel == 1){
        system("cls");
        viewOrder(orderlist, size, orpreset);
        goto can;
    }
    else if (cancel == 0){
        return;
    }
    else{
        cout <<"*** Invalid input! ***"<<endl;
        goto pro;
    }
};
