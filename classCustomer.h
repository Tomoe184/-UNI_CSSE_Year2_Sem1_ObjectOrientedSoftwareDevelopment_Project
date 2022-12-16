#include <cstdio>
#include <iostream>
#include "classOrder.h"

using std::string;

/************************************
Class Customer

Implemented by :
Sherene Saw Tyng Xin (76757)
Soo Kian An (76879)
Than Ye Hong (76990)
Yuki Chung Pei Ying (77237)
Jeggadishvaaren A/L AnnaThurai(77300)
**************************************/

class customer{
    public:
        string username;
        string password;
        string InputUsername;
        string InputPassword;
        
        int registration();
        int login();
        int validate();
        int update();
        customer() {
            username = "\0";
            password = "\0";
        }
        void viewProduct(product prolist[], int size, int input, product p);
		void addItem(product prolist[], int size, int preset, cart cartlist[], int csize);
		void removeItem(cart cartlist[], int size, int preset);
		void viewCart(cart cartlist[], int size, int preset, cart c);
		void makepay(payment paylist[], int size, int paypreset, int preset);
		void manageOrder(order orderlist[], int size, int orpreset, order sta1, order sta4, order o);
};

