#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <iomanip>
#include <limits>

using namespace std;

// Enum for warehouse types
enum class WarehouseType {
    CENTER,
    WEST,
    EAST
};

// Product class
class Product {
private:
    string barcode;
    string description;
    double price;
    int quantity;
    double longitude;
    double latitude;

public:
    // Constructors
    Product() : barcode(""), description(""), price(0.0), quantity(0), longitude(0.0), latitude(0.0) {}
    
    Product(string desc, double pr, int qty, double lon, double lat) 
        : description(desc), price(pr), quantity(qty), longitude(lon), latitude(lat) {
        generateBarcode();
    }
    
    Product(const Product& other) 
        : barcode(other.barcode), description(other.description), price(other.price), 
          quantity(other.quantity), longitude(other.longitude), latitude(other.latitude) {}
    
    // Getters
    string getBarcode() const { return barcode; }
    string getDescription() const { return description; }
    double getPrice() const { return price; }
    int getQuantity() const { return quantity; }
    double getLongitude() const { return longitude; }
    double getLatitude() const { return latitude; }
    
    // Setters
    void setDescription(string desc) { description = desc; }
    void setPrice(double pr) { price = pr; }
    void setQuantity(int qty) { quantity = qty; }
    void setLongitude(double lon) { longitude = lon; }
    void setLatitude(double lat) { latitude = lat; }
    
    // Barcode generation
    void generateBarcode() {
        barcode = "460"; // Russia
        int secondPart = (rand() % 9 + 1) * 1000; // 1000-9000
        barcode += to_string(secondPart);
        
        int thirdPart = rand() % 1000000; // 0-999999
        barcode += string(6 - to_string(thirdPart).length(), '0') + to_string(thirdPart);
    }
    
    // Print product info
    void print() const {
        cout << "Barcode: " << barcode << endl;
        cout << "Description: " << description << endl;
        cout << "Price: " << price << " RUB" << endl;
        cout << "Quantity: " << quantity << endl;
        cout << "Coordinates (longitude, latitude): (" << longitude << ", " << latitude << ")" << endl;
    }
};

// Warehouse class
class Warehouse {
private:
    string id;
    WarehouseType type;
    double longitude;
    double latitude;
    int maxCapacity;
    int totalStock;
    vector<Product> products;
    
    static int nextId; // Static variable for ID generation
    
public:
    // Constructors
    Warehouse() : id(""), type(WarehouseType::CENTER), longitude(0.0), latitude(0.0), 
                 maxCapacity(0), totalStock(0) {}
    
    Warehouse(WarehouseType t, double lon, double lat, int capacity) 
        : type(t), longitude(lon), latitude(lat), maxCapacity(capacity), totalStock(0) {
        generateId();
    }
    
    Warehouse(const Warehouse& other) 
        : id(other.id), type(other.type), longitude(other.longitude), latitude(other.latitude),
          maxCapacity(other.maxCapacity), totalStock(other.totalStock), products(other.products) {}
    
    // Getters
    string getId() const { return id; }
    WarehouseType getType() const { return type; }
    double getLongitude() const { return longitude; }
    double getLatitude() const { return latitude; }
    int getMaxCapacity() const { return maxCapacity; }
    int getTotalStock() const { return totalStock; }
    vector<Product> getProducts() const { return products; }
    
    // ID generation
    void generateId() {
        id = "W" + to_string(nextId++);
    }
    
    // Calculate Manhattan distance
    double calculateManhattanDistance(double productLon, double productLat) const {
        return abs(latitude - productLat) + abs(longitude - productLon);
    }
    
    // Add product
    bool addProduct(const Product& product) {
        if (totalStock + product.getQuantity() > maxCapacity) {
            return false;
        }
        
        products.push_back(product);
        totalStock += product.getQuantity();
        return true;
    }
    
    // Remove product by index
    bool removeProduct(int index) {
        if (index < 0 || index >= products.size()) {
            return false;
        }
        
        totalStock -= products[index].getQuantity();
        products.erase(products.begin() + index);
        return true;
    }
    
    // Find products by description
    vector<Product> findProductsByDescription(const string& desc) const {
        vector<Product> result;
        for (const auto& product : products) {
            if (product.getDescription().find(desc) != string::npos) {
                result.push_back(product);
            }
        }
        return result;
    }
    
    // Print warehouse info
    void print() const {
        cout << "Warehouse ID: " << id << endl;
        cout << "Type: ";
        switch (type) {
            case WarehouseType::CENTER: cout << "Center"; break;
            case WarehouseType::WEST: cout << "West"; break;
            case WarehouseType::EAST: cout << "East"; break;
        }
        cout << endl;
        cout << "Coordinates (longitude, latitude): (" << longitude << ", " << latitude << ")" << endl;
        cout << "Max capacity: " << maxCapacity << endl;
        cout << "Current stock: " << totalStock << endl;
        cout << "Number of products: " << products.size() << endl;
    }
    
    // Print product list
    void printProducts() const {
        if (products.empty()) {
            cout << "No products in this warehouse." << endl;
            return;
        }
        
        cout << "Product list in warehouse " << id << ":" << endl;
        for (size_t i = 0; i < products.size(); ++i) {
            cout << "[" << i + 1 << "] ";
            products[i].print();
            cout << "---------------------" << endl;
        }
    }
};

// Initialize static variable
int Warehouse::nextId = 100;

// Function to create warehouses
vector<Warehouse> createWarehouses() {
    vector<Warehouse> warehouses;
    
    // Center warehouse (Moscow)
    warehouses.emplace_back(WarehouseType::CENTER, 37.6176, 55.7558, 1000);
    
    // West warehouse (Saint Petersburg)
    warehouses.emplace_back(WarehouseType::WEST, 30.3351, 59.9343, 800);
    
    // East warehouse (Vladivostok)
    warehouses.emplace_back(WarehouseType::EAST, 131.8856, 43.1155, 600);
    
    return warehouses;
}

// Function to select warehouse by minimal distance
Warehouse* selectWarehouseByDistance(vector<Warehouse>& warehouses, double lon, double lat) {
    if (warehouses.empty()) return nullptr;
    
    Warehouse* selected = &warehouses[0];
    double minDistance = selected->calculateManhattanDistance(lon, lat);
    
    for (size_t i = 1; i < warehouses.size(); ++i) {
        double distance = warehouses[i].calculateManhattanDistance(lon, lat);
        if (distance < minDistance) {
            minDistance = distance;
            selected = &warehouses[i];
        }
    }
    
    return selected;
}

// Function for coordinate input with validation
double inputCoordinate(const string& prompt, double min, double max) {
    double value;
    while (true) {
        cout << prompt;
        cin >> value;
        if (cin.fail() || value < min || value > max) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Error! Please enter a value between " << min << " and " << max << ": ";
        } else {
            break;
        }
    }
    return value;
}

// Main menu
void mainMenu(vector<Warehouse>& warehouses) {
    while (true) {
        cout << "\n=== Warehouse Management System ===" << endl;
        cout << "1. Add product" << endl;
        cout << "2. View products in warehouse" << endl;
        cout << "3. Search product by description" << endl;
        cout << "4. Remove product" << endl;
        cout << "5. View warehouse information" << endl;
        cout << "0. Exit" << endl;
        cout << "Select action: ";
        
        int choice;
        cin >> choice;
        
        if (choice == 0) break;
        
        switch (choice) {
            case 1: {
                // Add product
                cin.ignore();
                string description;
                double price;
                int quantity;
                double longitude, latitude;
                
                cout << "Enter product description (max 50 chars): ";
                getline(cin, description);
                if (description.length() > 50) {
                    description = description.substr(0, 50);
                }
                
                cout << "Enter product price: ";
                cin >> price;
                
                cout << "Enter quantity: ";
                cin >> quantity;
                
                longitude = inputCoordinate("Enter transport longitude (19-169): ", 19, 169);
                latitude = inputCoordinate("Enter transport latitude (41-82): ", 41, 82);
                
                Product newProduct(description, price, quantity, longitude, latitude);
                
                Warehouse* selectedWarehouse = selectWarehouseByDistance(warehouses, longitude, latitude);
                if (selectedWarehouse && selectedWarehouse->addProduct(newProduct)) {
                    cout << "Product successfully added to warehouse " << selectedWarehouse->getId() << endl;
                } else {
                    cout << "Error: Failed to add product (warehouse capacity exceeded)" << endl;
                }
                break;
            }
            
            case 2: {
                // View products
                cout << "\nSelect warehouse:" << endl;
                for (size_t i = 0; i < warehouses.size(); ++i) {
                    cout << i + 1 << ". " << warehouses[i].getId() << " (";
                    switch (warehouses[i].getType()) {
                        case WarehouseType::CENTER: cout << "Center"; break;
                        case WarehouseType::WEST: cout << "West"; break;
                        case WarehouseType::EAST: cout << "East"; break;
                    }
                    cout << ")" << endl;
                }
                cout << "0. Back" << endl;
                cout << "Select warehouse: ";
                
                int warehouseChoice;
                cin >> warehouseChoice;
                
                if (warehouseChoice > 0 && warehouseChoice <= static_cast<int>(warehouses.size())) {
                    warehouses[warehouseChoice - 1].printProducts();
                }
                break;
            }
            
            case 3: {
                // Search product
                cin.ignore();
                string searchTerm;
                cout << "Enter description to search: ";
                getline(cin, searchTerm);
                
                bool found = false;
                for (auto& warehouse : warehouses) {
                    vector<Product> foundProducts = warehouse.findProductsByDescription(searchTerm);
                    if (!foundProducts.empty()) {
                        found = true;
                        cout << "\nFound in warehouse " << warehouse.getId() << ":" << endl;
                        for (const auto& product : foundProducts) {
                            product.print();
                            cout << "---------------------" << endl;
                        }
                    }
                }
                
                if (!found) {
                    cout << "No products found with this description." << endl;
                }
                break;
            }
            
            case 4: {
                // Remove product
                cout << "\nSelect warehouse to remove product from:" << endl;
                for (size_t i = 0; i < warehouses.size(); ++i) {
                    cout << i + 1 << ". " << warehouses[i].getId() << " (";
                    switch (warehouses[i].getType()) {
                        case WarehouseType::CENTER: cout << "Center"; break;
                        case WarehouseType::WEST: cout << "West"; break;
                        case WarehouseType::EAST: cout << "East"; break;
                    }
                    cout << ")" << endl;
                }
                cout << "0. Back" << endl;
                cout << "Select warehouse: ";
                
                int warehouseChoice;
                cin >> warehouseChoice;
                
                if (warehouseChoice > 0 && warehouseChoice <= static_cast<int>(warehouses.size())) {
                    warehouses[warehouseChoice - 1].printProducts();
                    
                    if (!warehouses[warehouseChoice - 1].getProducts().empty()) {
                        cout << "Enter product number to remove (0 to cancel): ";
                        int productChoice;
                        cin >> productChoice;
                        
                        if (productChoice > 0 && productChoice <= static_cast<int>(warehouses[warehouseChoice - 1].getProducts().size())) {
                            if (warehouses[warehouseChoice - 1].removeProduct(productChoice - 1)) {
                                cout << "Product successfully removed." << endl;
                            } else {
                                cout << "Error removing product." << endl;
                            }
                        }
                    }
                }
                break;
            }
            
            case 5: {
                // Warehouse info
                cout << "\nWarehouse information:" << endl;
                for (auto& warehouse : warehouses) {
                    warehouse.print();
                    cout << "---------------------" << endl;
                }
                break;
            }
            
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
}

int main() {
    srand(time(0)); // Random number generator initialization
    
    vector<Warehouse> warehouses = createWarehouses();
    mainMenu(warehouses);
    
    return 0;
}