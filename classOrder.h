#ifndef ORDER_H
#define ORDER_H
#include <cstdio>
#include <iostream>
#include "classProduct.h"

using std::string;

/************************************
class Order

Implemented by :
Sherene Saw Tyng Xin (76757)
Soo Kian An (76879)
Than Ye Hong (76990)
Yuki Chung Pei Ying (77237)
Jeggadishvaaren A/L AnnaThurai(77300)
**************************************/

class order{
    private:
        int orderID;
        string orderStatus;
        int totalProduct;
        double finalAm;
        int payID;
        string paymethod;
        
    public:
        void setOrder(int oid, string osta, int pid, string pay, double totAm);
        void viewOrder(order orderlist[], int size, int orpreset);
        void addToOrder(order orderlist[], int size, int orpreset);
        void addToOrder(payment paylist[], int size, int paypreset, int orpreset,payment paym);
        void cancelOrder(order orderlist[], int size, int orpreset,order sta1, order sta2);
        void setOrderStatus(int status);
        void setStatus(string status);
        string getStatus();
};

#endif
