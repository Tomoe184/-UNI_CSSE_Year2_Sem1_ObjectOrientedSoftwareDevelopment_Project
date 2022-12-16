#include <iostream>
#include <iomanip>
#include <cstring>
#include "Implementation.cpp"
#include <iomanip>
#include <string>

using namespace std;

int menu();

int main() {
    customer r;
    int choice;
    system("cls");
    cout << "_______________________________~ Welcome to ECP System ~_______________________________" << endl;
    cout << "The system is developed by: -" << endl;
    cout << "1. SHERENE SAW TYNG XIN (76757)" << endl;
    cout << "2. SOO KIAN AN (76879)" << endl;
    cout << "3. THAN YE HONG (76990)" << endl;
    cout << "4. YUKI CHUNG PEI YING (77237)" << endl;
    cout << "5. JEGGADISHVAAREN A/L ANNATHURAI (77300)" << endl << endl;

    // login menu
    invalidlog:  // label
    cout << "_______________________________________________________________________________________" << endl;
    cout << "\t\t\t\t~ MAIN PAGE ~" << endl;
    cout << "_______________________________________________________________________________________" << endl;
    cout << "\t\t\t1. Register a New Account" << endl;
    cout << "\t\t\t2. Login an Account" << endl;
    cout << "_______________________________________________________________________________________" << endl;

    cout << "# Enter your choice: ";
    cin >> choice;
    cout << endl;

    // register or login validation
    reg:
    while (!(choice == 1 || choice == 2)) {
        cout << "Invalid input!" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cout << endl;
    }

    switch(choice) {
        // registeration
        case 1:
            r.registration();
            system("pause");
            system("cls");
            main();
        break;

        // login
        case 2:
            int n = 0;
            r.login();
            if (r.validate() != 0) {
                menu();
            }
            // validation
            else {
                cout << "*** Wrong username or password entered! Please try again ***." << endl;
                system("pause");
                system("cls");
                main();
            }
            goto reg;
        break;
    }
    return 0;
}

int menu(){
    // variable declaration 
    int input, categorych, proch,detch,cartch, subproch, addch, quanAdd, deletech, remID, pay, check, cardch, retch, cancel, ch, n, logout, checkout, proceed, ordch, ret;

    // counter initialization
    int preset = 2;  // cart
    int orpreset = 3;  // order
    int paypreset= 3;  // payment

    // class object declaration
    customer r;
    product prolist[15], proTy[4],p;
    cart cartlist[100], c;
    payment paylist[100], paymet1, paymet2, paym;
    order orderlist[100], sta1, sta2, sta3, sta4, o;

    // product categories
    proTy[1].setType("Condiments");
    proTy[2].setType("Canned Food");
    proTy[3].setType("Dairy");
    proTy[4].setType("snacks");

    // product details
    prolist[1].setDetails(1,"Condiments","Ketchup","This is a sauce right for everyones' tummy", 20, "In Stock", 6.00 );
    prolist[2].setDetails(2,"Condiments", "Chilli Sauce", "This sauce would burn numb your tongue and burn your tummy", 50, "In stock", 8.00);
    prolist[3].setDetails(3,"Condiments","Mustard","Sauce for salad, toast and everything", 45, "In Stock", 12.00 );
    prolist[4].setDetails(4,"Canned Food", "Mushroom Soup", "Italian mushroom soup served with dried mushroom", 30, "In stock", 5.99);
    prolist[5].setDetails(5,"Canned Food","Baked beans","Beans Served for your breakfast", 55, "In Stock", 8.60 );
    prolist[6].setDetails(6,"Canned Food", "Canned Eggplant", "Nicely marinated eggplant from the countryside", 20, "In stock", 7.50);
    prolist[7].setDetails(7,"Dairy","Cheese","Mozarella cheese imported from Belgium",48, "In Stock", 12.50 );
    prolist[8].setDetails(8,"Dairy", "Butter", "Imported fresh from New Zealand", 40, "In stock", 7.50);
    prolist[9].setDetails(9,"Dairy", "Eggs",  "Eggs collected from barn", 78, "In stock", 10.00);
    prolist[10].setDetails(10,"Snack","Chips","Sweet potato crisp for your netflix",48, "In Stock", 12.00 );
    prolist[11].setDetails(11,"Snack", "Energy Bar", "Get all your delpleted energy from our bar", 38, "In stock", 17.50);
    prolist[12].setDetails(12,"Snack", "Chocolate",  "Low Fat chocolate for dieters", 28, "In stock", 20.00);

    // cart details
    cartlist[1].setDetails(1, 1, "Ketchup", 6.00, 2, 12.00);
    cartlist[2].setDetails(2, 5, "Baked Beans", 8.60, 1, 8.60);

    paymet1.setPaymentMethod("MasterCard");
    paymet2.setPaymentMethod("Visa Card");

    // order
    orderlist[1].setOrder(1,"Completed", 1,"Master Card",45.00);
    orderlist[2].setOrder(2, "Pending", 2,"Visa",15.00);
    orderlist[3].setOrder(3,"Dispatched", 3,"Master Card", 75.80);

    sta1.setStatus("Pending");
    sta2.setStatus("Dispatched");
    sta3.setStatus("Completed");
    sta4.setStatus("Cancelled");

    menu:  // label
    system("cls");
    cout << "_______________________________________________________________________________________" << endl;
    cout << "\t\t\t\t~ HOME PAGE ~"<<endl;
    cout << "_______________________________________________________________________________________" << endl;
    cout << "\t\t\t\t1. Product" << endl;
    cout << "\t\t\t\t2. Shopping Cart" << endl;
    cout << "\t\t\t\t3. Orders" << endl;
    cout << "\t\t\t\t4. Account" << endl;
    cout << "\t\t\t\t5. Log Out" << endl;
    cout << "_______________________________________________________________________________________" << endl;
    cout << endl;
    cout << "# Enter your input: ";
    cin >> input;
    cout << endl;

    // menu validation
    while (!(input == 1 || input == 2 || input == 3 || input == 4 || input == 5)){
        cout << "*** Invalid input! ***" << endl;
        cout << endl;
        goto menu;
    }

    switch (input){
        // view product
        case 1:
            category:
            system("cls");

            // category menu
            cout << "_______________________________________________________________________________________"<< endl;
            cout << "\t\t\t\tPRODUCT CATEGORY: "<<endl;
            cout << "_______________________________________________________________________________________"<< endl;
                for (int i=1; i<=4; i++){
                    cout <<"\t\t\t\t"<<i<<". ";
                    proTy[i].getType();
                }
            cout << "\t\t\t\t5. Return to menu "<<endl;
            cout << "_______________________________________________________________________________________"<< endl << endl;

            invalidcat:  // label

            cout <<"# Enter your choice for category: ";
            cin >> categorych;
            cout << endl;

            // validation for category
            while (!(categorych == 1 || categorych ==2 || categorych == 3 || categorych== 4 || categorych == 5)) {
                cout <<"Invalid input!"<<endl;
                goto invalidcat;
                cout <<endl;
            }

            for (int i = 1; i <= 4; i++) {
                if (i == categorych) {
                submenu:  // label

                    system("cls");

                    // print category
                    r.viewProduct(prolist, 100, categorych, p);

                    cout << endl;
                    cout << "# Enter 1 to view product details / 0 to return to category menu: ";
                    cin >> proch;

                    if (proch == 1){
                        // print product details
                        p.printDetails(prolist, 12, categorych, proch);

                        cont://label
                        cout <<"# Enter 0 to return: ";
                        cin >> retch;

                        if (retch ==0 ){
                            goto submenu;
                        }
                        else{
                            cout <<"*** Invalid input! ***"<< endl;
                            goto cont;
                        }
                    }
                    else if (proch == 0) {
                        goto category;
                    }
                    else{
                        cout <<"*** Invalid input! ***"<< endl;
                        system("pause");
                        goto submenu;
                    }
                }
                else if (categorych == 5){
                    goto menu;
                }
            }
        break;

        // cart method
        case 2:
            cartMenu:  // label
            system("cls");
            cout <<"_______________________________________________________________________________________"<<endl;
            cout <<"\t\t\t~ MANAGE YOUR SHOPPING CART ~"<<endl;
            cout <<"_______________________________________________________________________________________"<<endl;
            cout <<"\t\t\t1. Add item to Cart"<<endl;
            cout <<"\t\t\t2. Remove item"<<endl;
            cout <<"\t\t\t3. View Cart"<<endl;
            cout <<"\t\t\t4. Return to menu"<<endl;
            cout <<"_______________________________________________________________________________________"<<endl;

            cartchoice:
            cout <<"# Enter your choice: ";
            cin >> cartch;
            cout <<endl;

            // validation 
            while (!(cartch == 1 || cartch ==2 || cartch == 3 || cartch == 4)){
                cout <<"*** Invalid input ***"<<endl;
                goto cartchoice;
            }

            // add to cart
            if (cartch == 1){
                system("cls");
                c.printDetails(prolist,100, cartch);

                // increase counter by 1
                preset++;

                // add to shopping cart
                r.addItem(prolist, 12, preset, cartlist, 100);
                
                goto cartMenu;	
            }

            // remove cart
            else if (cartch == 2){
                cout <<endl;
                // print cart details
                system("cls");
                c.printDetails(cartlist, 100, preset);

                // disallow delete due to 0 item in cart
                if (preset == 0){
                    cout <<"You have no item to remove from cart!"<<endl;
                    system("pause");
                    goto cartMenu;
                }
                else{
                    // delete item from cart	
                    r.removeItem(cartlist,100, preset);
                }

                // decrease the counter
                preset--;
                goto cartMenu;
            }

            //view cart
            else if (cartch == 3){
                cout << endl;
                //print cart details
                system("cls");
                r.viewCart(cartlist, 100, preset, c);

                cout << endl;
                if (preset == 0){
                    cout << endl;
                    cout << "You have not added any new item in your cart!" << endl;
                    system("pause");
                    goto cartMenu;
                }

                recheck:  // label
                cout << "# Enter 1 to checkout your cart / 0 to proceed shopping: ";
                cin >> check;

                // validation
                while (!(check == 1 || check == 0)){
                    cout <<"*** Invalid input! ***"<<endl;
                    goto recheck;
                }

                if (check ==1){
                    // print cart details
                    system("cls");
                    r.viewCart(cartlist, 100, preset, c);
                    cout <<endl;

                    // checkout cart
                    paym.checkout(cartlist, 100, preset);

                    // payment 
                    a1:  // label
                    cout <<"# Enter 1 to proceed to payment / 0 to return to cart: ";
                    cin >> pay;

                    // validation for pay
                    while (!(pay == 1 || pay == 0)){
                        cout <<"*** Invalid input! ***"<<endl;
                        goto a1;
                    }

                    if (pay == 1){
                        // increase counter by 1
                        paypreset++;
                        orpreset++;

                        // make payment
                        r.makepay(paylist, 100, paypreset, preset);

                        // add to list of orders
                        orderlist[orpreset].addToOrder(orderlist, 100, orpreset);
                        orderlist[orpreset].addToOrder(paylist, 100, paypreset, orpreset, paym);
                        cout << endl;

                        view:
                        cout << "# Enter 1 to view receipt / 2 to return to menu: ";
                        cin >> cardch;
                        
                        //validation
                        while (!(cardch == 1 || cardch ==2)){
                            cout << "*** Invalid input! ***" << endl;
                            goto view;
                        }

                        if (cardch == 1){
                            system("cls");
                            //diplay payment date
                            paym.displayPaymentDate();

                            //print payment receipt
                            paym.printReceipt(cartlist, 100, preset);
                            paylist[paypreset].printPayment();
                            
                            preset = 0;//set cart counter to zero
                            
                            system("pause");
                        }
                        else if (cardch == 2){
                            preset = 0;//set cart counter to zero	
                            goto menu;
                        }
                        goto menu;
                    }
                    else if (pay ==0) {
                        goto cartMenu;
                    }
                }
                else if (check == 0) {
                    goto cartMenu;
                }
            }
            else if (cartch == 4) {
                goto menu;
            }
            else{
            }
        break;

        case 3:
            // display list of order
            system("cls");
            o.viewOrder(orderlist, 100, orpreset);

            o1:  // label
            cout << "# Enter 1 to cancel order / 0 to return to main menu: ";
            cin >> cancel;

            // order validation
            while (!(cancel == 1 || cancel == 0)){
                cout << "*** Invalid input! ***"<<endl;
                goto o1;
            }

            if (cancel == 1){
                if (orpreset == 0){
                    cout <<"*** You have not placed any orders before. ***"<<endl;
                    system("pause");
                    goto menu;
                }
                else{
                    // cancel order
                    r.manageOrder(orderlist, 100, orpreset, sta1, sta4, o);
                }
            }
            else {
                goto menu;
            }
            goto menu;
        break;

        case 4:
            cout << "# Enter 1 to change username and password: ";
            cin >> n;
            if (n == 1) {
                // update password
                system("cls");

                cout << "Please reenter your username and password: " << endl;
                r.login();

                if(r.validate() != 0) {
                    cout << "Correct username and password entered.";
                    r.update();
                    goto menu;
                }
                else {
                    cout << "The username or password entered are not match! Please try again." << endl;
                    system("pause");
                    goto menu;
                }
            }
            else {
                goto menu;
            }
        break;

        case 5:
            logout:
            cout <<"# Enter 1 to proceed to log out / 0 to return to menu: ";
            cin >> logout;
            if (logout == 1){
                cout << endl;
                cout << "__________________________________PROGRAM TERMINATED__________________________________"<< endl;
                cout << "\t\t\t  Thank You for using our ECP System!" << endl << endl;
                system("pause");
                exit(1);
            }
            else if (logout == 0){
                goto menu;
            }
            else{
                cout << "*** Invalid input! ***" << endl;
                goto logout;
            }
        break;
    }
}
