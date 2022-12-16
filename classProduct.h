#ifndef PRODUCT_H
#define PRODUCT_H
#include <cstdio>
#include <iostream>

using std::string;

/****************************************
Class product

Implemented by :
Sherene Saw Tyng Xin (76757)
Soo Kian An (76879)
Than Ye Hong (76990)
Yuki Chung Pei Ying (77237)
Jeggadishvaaren A/L AnnaThurai(77300)
******************************************/

class product{
    protected:
        string productType;
        int productID;
        string productName;
        string productDescription;
        int productQuantity;
        string productStatus;
        double productPrice;

    public:
        void setType(string ty);
        void setDetails(int id, string ty, string na, string des, int quan, string status, double pri ); 
        void getType();
        int getID();
        string getName();
        double getPrice();

        void printDetails(product prolist[], int size, int input);
        void printDetails(product prolist[], int size, int cateogry, int proch);
};

/****************************************
class cart

Implemented by :
Sherene Saw Tyng Xin (76757)
Soo Kian An (76879)
Than Ye Hong (76990)
Yuki Chung Pei Ying (77237)
Jeggadishvaaren A/L AnnaThurai(77300)
******************************************/

class cart: public product{
    private:
        int cartID;
        int quanAdded;
        double totP;

    public:
        void setDetails(int cid, int pid, string pname, double ppri, int quanAdded, double totP);
        void addToCart(product prolist[], int psize, int preset);
        void removeCart(cart cartlist[], int size ,int preset);
        void viewCart();
        void printDetails(product prolist[], int size, int input);
        void printDetails(cart cartlist[], int size, int preset);
        
        // getter
        int getCartID();
        int getID();
        string getName();
        double getPrice();
        int getQuanAdded();
        double getTotalPrice();
        double getTax();
        double getShipping();
};

/****************************************
class payment

Implemented by :
Sherene Saw Tyng Xin (76757)
Soo Kian An (76879)
Than Ye Hong (76990)
Yuki Chung Pei Ying (77237)
Jeggadishvaaren A/L AnnaThurai(77300)
******************************************/

class payment {
    private:
        int paymentID;
        string paymentMethod;
        int totalProduct;

        double finAm;
        string paymentDate;
        double tax;
        double shipping;
        double totalAm;

    public:
        int getPayID();
        string getPaymentMethod();
        double getFinalAm();
        double getTax();
        double getShipping ();
        
        void makePayment( int paypreset, int preset);
        void checkout(cart cartlist[], int size, int preset);
        void displayPaymentDate();
        void printReceipt(cart cartlist[], int size, int preset);
        void printPayment();
        void setPaymentMethod(string paymet);
};

#endif
