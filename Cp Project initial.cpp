#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct Product {
    string type;
    string name;
    string quantity;
    string price;
};

Product products[100];
int productCount = 0;

void addProduct() {
    if (productCount >= 100) {
        cout << "Product list is full." << endl;
        return;
    }
    cout << "Enter product type (Gun, Rifle, Pistol): ";
    cin >> products[productCount].type;
    cout << "Enter product name: ";
    cin >> products[productCount].name;
    cout << "Enter quantity: ";
    cin >> products[productCount].quantity;
    cout << "Enter price: ";
    cin >> products[productCount].price;
    productCount++;
}

void displayProducts() {
    if (productCount == 0) {
        cout << "No products to display." << endl;
        return;
    }
    cout << "Product List:" << endl;
    cout << "-----------------------------------------" << endl;
    cout << "| Type | Name | Quantity | Price |" << endl;
    cout << "-----------------------------------------" << endl;
    for (int i = 0; i < productCount; i++) {
        cout << "| " << products[i].type << " | " << products[i].name << " | " << products[i].quantity << " | $" << products[i].price << " |" << endl;
        cout << "-----------------------------------------" << endl;
    }
}

void updateProduct() {
    if (productCount == 0) {
        cout << "No products to update." << endl;
        return;
    }
    int index;
    cout << "Enter product number to update: ";
    cin >> index;
    if (index > 0 && index <= productCount) {
        cout << "Enter new quantity: ";
        cin >> products[index - 1].quantity;
        cout << "Enter new price: ";
        cin >> products[index - 1].price;
    } else {
        cout << "Invalid product number." << endl;
    }
}

void deleteProduct() {
    if (productCount == 0) {
        cout << "No products to delete." << endl;
        return;
    }
    int index;
    cout << "Enter product number to delete: ";
    cin >> index;
    if (index > 0 && index <= productCount) {
        for (int i = index - 1; i < productCount - 1; i++) {
            products[i] = products[i + 1];
        }
        productCount--;
    } else {
        cout << "Invalid product number." << endl;
    }
}

void searchProduct() {
    if (productCount == 0) {
        cout << "No products to search." << endl;
        return;
    }
    string name;
    cout << "Enter product name to search: ";
    cin >> name;
    for (int i = 0; i < productCount; i++) {
        if (products[i].name == name) {
            cout << "Product found!" << endl;
            cout << "Type: " << products[i].type << endl;
            cout << "Name: " << products[i].name << endl;
            cout << "Quantity: " << products[i].quantity << endl;
            cout << "Price: " << products[i].price << endl;
            return;
        }
    }
    cout << "Product not found!" << endl;
}

void saveToFile() {
    if (productCount == 0) {
        cout << "No products to save." << endl;
        return;
    }
    ofstream file("products.txt");
    if (file.is_open()) {
        for (int i = 0; i < productCount; i++) {
            file << products[i].type << "," << products[i].name << "," << products[i].quantity << "," << products[i].price << endl;
        }
        file.close();
        cout << "Products saved to file successfully!" << endl;
    } else {
        cout << "Unable to open file." << endl;
    }
}

void loadFromFile() {
    ifstream file("products.txt");
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            size_t pos = line.find(",");
            string type = line.substr(0, pos);
            line.erase(0, pos + 1);
            pos = line.find(",");
            string name = line.substr(0, pos);
            line.erase(0, pos + 1);
            pos = line.find(",");
            string quantity = line.substr(0, pos);
            line.erase(0, pos + 1);
            string price = line;
            products[productCount].type = type;
            products[productCount].name = name;
            products[productCount].quantity = quantity;
            products[productCount].price = price;
            productCount++;
        }
        file.close();
        cout << "Products loaded from file successfully!" << endl;
    } else {
        cout << "Unable to open file." << endl;
    }
}

int main() {
    int choice;
    while (true) {
        cout << "Inventory Management System" << endl;
        cout << "1. Add Product" << endl;
        cout << "2. Display Products" << endl;
        cout << "3. Update Product" << endl;
        cout << "4. Delete Product" << endl;
        cout << "5. Search Product" << endl;
        cout << "6. Save Products to File" << endl;
        cout << "7. Load Products from File" << endl;
        cout << "8. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                addProduct();
                break;
            case 2:
                displayProducts();
                break;
            case 3:
                updateProduct();
                break;
            case 4:
                deleteProduct();
                break;
            case 5:
                searchProduct();
                break;
            case 6:
                saveToFile();
                break;
            case 7:
                loadFromFile();
                break;
            case 8:
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
    return 0;
}