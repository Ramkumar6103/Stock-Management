#include<bits/stdc++.h>
using namespace std;
class Product{
    private:
        int prdId = 0;
        string prdName;
        string category;
        int quantity;
        double perPrize;
        string subName;
        public:
        Product(int id, string pname, string catry, int quan, double prize, string sname){
        prdId = id;
        prdName = pname;
        category = catry;
        quantity = quan;
        perPrize = prize;
        subName = sname;
    }
    int getPrdId() const{
        return prdId;
    }
    string getPrdName() const{
        return prdName;
    }
    string getCategory() const{
        return category;
    }
    int getQuantity() const{
        return quantity;
    }
    double getPerPrize() const{
        return perPrize;
    }
    string getSubName() const{
        return subName;
    }
    void displayProduct(){
        cout<<"Id :"<<prdId<<endl;
        cout<<"Product Name :"<<prdName<<endl;
        cout<<"Category :"<<category<<endl;
        cout<<"Quantity :"<<quantity<<endl;
        cout<<"Per Prize :"<<perPrize<<endl;
        cout<<"Subblier Name :"<<subName<<endl;
    }
    void updateProduct(string s, string cat, int q, double p, string sN){
        prdName = s;
        category = cat;
        quantity = q;
        perPrize = p;
        subName = sN;
    }
    bool updateQuantity(int change){
            if (quantity + change < 0) return false;   // stock not enough
        quantity += change;
        return true;
    }
};
int main(){
    vector<Product> pro;
    int choice;
    int proId,quantity;
    double perPrize;
    string proName, sName, category;
    cout<<"Welcome to Ram Stock Management System\n\n";
    do{
        cout<<"Menu\n";
        cout<<"1. Add New Product to Inventory\n";
        cout<<"2. Update Stock Quantity\n";
        cout<<"3. Search Product\n";
        cout<<"4. Track Sales and Purchases\n";
        cout<<"5. Generate Reports\n";
        cout<<"6. Update Product Details\n";
        cout<<"7. Exit\n\n";
        cout<<"Enter your choice :";
        cin>>choice;

        switch(choice){
            case 1:{
               cout<<"Add New Product to Inventory\n";
               cout<<"Enter id :";
               cin>>proId;
               cout<<"Enter Product Name :";
               cin>>proName;
               cout<<"Enter Per Price :";
               cin>>perPrize;
               cout<<"Enter quantity :";
               cin>>quantity;
               cout<<"Enter category :";
               cin>>category;
               cout<<"Enter Supplier Name :";
               cin>>sName;
               Product p1(proId, proName, category, quantity, perPrize, sName);
               pro.push_back(p1);
               p1.displayProduct();
               break;
            }
            case 2:{
                cout<<"Update Stock Quantity\n";
                break;
            }
            case 3:{
                cout<<"Search Product\n";
                break;
            }
            case 4:{
                cout<<"Track Sales and Purchases\n";
                break;
            }
            case 5:{
                cout<<"Generate Reports\n";
                break;
            }
            case 6:{
                cout<<"Update Product Details\n";
                break;
            }
            case 7:{
                cout<<"Thank you for contacting us...";
                break;
            }
            default:{
                cout<<"Invalid input !";
            }
        }
    }while(choice != 7);
    return 0;
}