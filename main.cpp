#include <iostream>
#include <clocale>
#include <string>
#include <vector>

using namespace std;

using namespace std;

class Product{
private:
    string name;
    int price;
    int quantity;
public:
    Product(string productName, int productPrice, int productQuantity)
        : name(productName),
         price(productPrice),
         quantity(productQuantity){
        
    }

    int calculateCost() const {
        return price * quantity;
    }
    void print() const {
        cout << "Название товара: " << name << endl;
        cout << "Цена товара: " << price << endl;
        cout << "Количество товара: " << quantity << endl;
    }
    int getPrice() const{
         return price;
    }
    string getName() const{
         return name;
    }   
};

int findMostExpensive(const vector<Product>& products){
        int maxIndex = 0;

        for(int i = 1; i < products.size(); i++){
            if(products[i].getPrice() > products[maxIndex].getPrice()){
            maxIndex = i;
        }
        }
        return maxIndex;
}

int calculateTotalCost( const vector<Product>& products){
    int totalCost = 0;
    for ( int i = 0; i < products.size(); i++){
        totalCost += products[i].calculateCost();
    }
    return totalCost;
}

int findProductByName(
    const vector<Product>& products,
    const string& searchName
){
    for(int i = 0; i < products.size(); i++){
        if(searchName == products[i].getName()){
            return i;

        }          
    }
    return -1;
}

int main(){
    setlocale(LC_ALL, "RU");
    int size;
    cout << "Введите сколько товаров: ";
    cin >> size;
    if(size <= 0){
        cout << "Количество товаров должно быть положительным числом." << endl;
        return 1;
    }
    vector<Product> products;

    for(int i = 0; i < size; i++){
    cout << "\nТовар: " << i + 1 << endl;

    string name;
    int price;
    int quantity;

    cout << "Введите название товара: ";
    getline(cin >> ws, name);

    do{
        cout << "Введите цену товара: ";
        cin >> price;
        if (price <= 0){
            cout << "Цена должна быть больше нуля. Введите ещё раз: ";
        }
    }while(price <= 0);
    
    do{
        cout << "Введите количество товара: ";
        cin >> quantity;
        if (quantity < 0){
             cout << "Количество товара не может быть отрицательным: ";
        }
    }while(quantity < 0);

    products.push_back(Product(name, price, quantity));
}
    cout << "\nИнформация о товарах:\n";
    for(int i = 0; i < size; i++){
        products[i].print();
    }

    string searchName;

    cout << "\nВведите товар который хотите найти: ";
    getline(cin >> ws, searchName);

    int foundIndex = findProductByName(products, searchName);

    if(foundIndex != -1){
        cout << "\nТовар  найден: ";
        products[foundIndex].print();
    }else {
        cout << "\nТовар не найден:";
    }

    int totalCost = calculateTotalCost(products);

    cout << "\nстоимость всех товаров в месте: "<< totalCost << endl;
    
    int maxIndex = findMostExpensive(products);

    cout << "\nСамый дорогой товар:\n";
    products[maxIndex].print();
    return 0;
}  