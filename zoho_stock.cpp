#include<bits/stdc++.h>
using namespace std;
class Product{
    private:
        int id;
        string name;
        string category;
        int quantity;
        double price;
        string supplier;

    public:
        Product(int i, string n, string c, int q, double p, string s){
            id = i;
            name = n;
            category = c;
            quantity = q;
            price = p;
            supplier = s;
        }
    // Getters
    int getId() const { return id; }
    string getName() const { return name; }
    string getCategory() const { return category; }
    int getQuantity() const { return quantity; }
    double getPrice() const { return price; }
    string getSupplier() const { return supplier; }

    bool updateQuantity(int change){
        if(quantity + change < 0) return false;
        quantity += change;
        return true;
    }
    void updateProductDetails(string n, string c, double p, string s){
        name = n;
        category = c;
        price = p;
        supplier = s;
    }
    void display(){
        cout << "ID: " << id
             << " | Name: " << name
             << " | Category: " << category
             << " | Qty: " << quantity
             << " | Price: " << price
             << " | Supplier: " << supplier << endl;
    }
};
class Transaction{
    private:
    int transactionId;
    int productId;
    string type; // Sale / Purchase
    int quantity;
    string date;
    Transaction(int i, int p, string t, int q, string d){
        transactionId = i;
        productId p;
        type = t;
        quantity = q;
        date = d;
    }

    int getProductId() const { return productId; }
    string getType() const { return type; }
    int getQuantity() const { return quantity; }
};
class StockManagement{
    private:
    vector<Product> product;
    vector<Transaction> transaction;
    int txnCounter = 1;
    bool productIdExist(int id){
        for(auto &p : product){
            if(p.getId() == id) return true;
        }
        return false;
    }
    public:
    void addProduct(){
        int id, qty;
        double price;
        string name, cat, sup;
        cout<<"Enter product id";
        cin>>id;
        if(productIdExist(id)){
            cout<<"Id is already exist";
            return;
        }
        
        cout<<"Enter quantity:";
        cin>>qty;
        cout<<"Enter price:"
        cin>>price;
        cin.ignore();
        cout<<"Enter product name:";
        getline(cin, name);
        cout<<"Enter category:";
        getline(cin, cat);
        cout<<"Enter supplier name:";
        getline(cin, sup);

        Product p(id, name, cat, qty, price, sup);
        product.push_back(p);
    }

    Product* findProductId(int id){
        for(auto& p : product){
            if(p.getId == id) return p;
        }
        return nullptr;
    }
    Product* findProductName(string name){
        for(auto& p : product){
            if(p.getName() == name) return p;
        }
        return nullptr;
    }
    Product* findProductCat(string cat){
        for(auto& p : product){
            if(p.getCategory() == cat) return p;
        }
        return nullptr;
    }
    
    void updateStock() {
        int id, change;
        cout<<"Enter the product id";
        cin>>id;
        Product *p = findProductId(id);
        if(!p){
            cout << "❌ Product Not Found\n";
            return;
        }
        cout << "Enter quantity (+Purchase / -Sale): ";
        cin >> change;
        if(!p->updateQuantity(change)){
            cout << "❌ Insufficient Stock\n";
            return;
        }
        string type = (change > 0) ? "Purchase" : "Sale";

    }
    void searchProduct(){
        int choice;
        
        bool found = false;
        cout << "Search By: 1.ID  2.Name  3.Category : ";
        cin >> choice;
        cin>>ignore();

        if(choice == 1){
            int id;
            cout<<"Enter the product id:";
            cin>>id;
            cin.ignore();
            Product* p = findProductId(id);
            if(p){
                p->display();
                found = true;
            }
        }
        else if(choice == 2){
            string name;
            cout<<"Enter the product name:";
            getline(cin, name);
            Product* p = findProductName(name);
            if(p){
                p->display();
                found = true;
            }
        }
        else if(choice == 3){
            string cat;
            cout<<"Enter the category:";
            getline(cin, cat);
            Product* p = findProductCat(cat);
            if(p){
                p->display();
                found = true;
            }
        }
          if (!found)
            cout << "❌ No Product Found\n";
    }
   void start() {
        int choice;
        do {
            cout << "\n====== STOCK MANAGEMENT SYSTEM ======\n";
            cout << "1. Add Product\n";
            cout << "2. Update Stock\n";
            cout << "3. Search Product\n";
            cout << "4. Track Sales / Purchases\n";
            cout << "5. Generate Reports\n";
            cout << "6. Update Product Details\n";
            cout << "7. Exit\n";
            cout << "Enter Choice: ";
            cin >> choice;
            switch(choice){
                case 1: addProduct(); break;
                case 2: updateProduct(); break;
                case 3: searchProduct(); break;
                case 4: trackSales(); break;
                case 5: generateReports(); break;
                case 6: updateProductDetails(); break;
                case 7: cout<<"Thank you for contacting"; break;
            }
        }
        while(choice != 7);
    }
};
int main(){
    StockManagement system;
    system.start();
    return 0;
}