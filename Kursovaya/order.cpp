#include "order.h"
#include <cstdio>
#include <iostream>
#include <limits>
#include <iomanip>
#include <algorithm>
#include <unordered_map>

using namespace std;

void readOrdersFromFile(std::unordered_map<int, Order>& ordersMap, const std::string& filename) {
    FILE* inputFile = fopen(filename.c_str(), "r");
    if (!inputFile) {
        cerr << "Error " << filename << endl;
        return;
    }

    int id, clientId;
    double total;

    while (fscanf(inputFile, "%d %d %lf", &id, &clientId, &total) == 3) {
        ordersMap[id] = Order(id, clientId,total);
     
    }

    fclose(inputFile);
}
void saveOrdersToFile(const std::unordered_map<int, Order>& ordersMap, const std::string& filename) {
    FILE* outputFile = fopen(filename.c_str(), "w");
    if (!outputFile) {
        cerr << "Error opening file: " << filename << endl;
        return;
    }

    for (const auto& pair : ordersMap) {
        fprintf(outputFile, "%d %d %.2f\n", pair.second.id, pair.second.clientId, pair.second.total);
    }

    fclose(outputFile);
}




void readOrderDetailsFromFile(std::unordered_map<int, Order>& ordersMap, std::unordered_map<int, Book>& booksMap, const std::string& filename) {
    FILE* inputFile = fopen(filename.c_str(), "r");
    if (!inputFile) {
        cerr << "Error " << filename << endl;
        return;
    }

    int orderId, bookId, quantity;
    double subtotal;

    while (fscanf(inputFile, "%d %d %d %lf", &orderId, &bookId, &quantity, &subtotal) == 4) {
        if (ordersMap.find(orderId) != ordersMap.end()) {
            ordersMap[orderId].details.push_back(OrderDetail(bookId, quantity, subtotal));
            if (booksMap.find(bookId) == booksMap.end()) {
                cerr << "Warning: Book with ID " << bookId << " not found for order " << orderId << endl;
            }
        } else {
            cerr << "Warning: Order with ID " << orderId << " not found for order detail." << endl;
        }
    }

    fclose(inputFile);
}

void saveOrderDetailsToFile(const std::unordered_map<int, Order>& ordersMap, const std::string& filename) {
    FILE* outputFile = fopen(filename.c_str(), "w");
    if (!outputFile) {
        cerr << "Error " << filename << endl;
        return;
    }

    for (const auto& orderPair : ordersMap) {
        for (const auto& detail : orderPair.second.details) {
            fprintf(outputFile, "%d %d %d %.2f\n", orderPair.first, detail.bookId, detail.quantity, detail.subtotal);
        }
    }

    fclose(outputFile);
}




void menu_orders(std::unordered_map<int, Client>& clientsMap, std::unordered_map<int, Book>& booksMap, std::unordered_map<int, Order>& ordersMap) {
    int opt;

    do {
        cout << left;
        cout << setw(20) << "\n --- MANAGMENT OF ORDERS ---" << endl;
        cout << "\nSelect an option from [1-4] according to the menu:" << endl;
        cout << "[1]. Insert order" << endl;
        cout << "[2]. Print list of orders" << endl;
        cout << "[3]. Delete order detail" << endl; // Added this line
        cout << "[4]. Exit" << endl;
        cout << "-----------------------------------------------" << endl;
        cout << "Enter option: ";
        cin >> opt;

        switch (opt) {
            case 1:     // insert order
                insert_order(clientsMap, booksMap, ordersMap);
                break;
            case 2:     // print orders/details
                print_list_orders(clientsMap, booksMap, ordersMap);
                break;
            case 3:     // delete order detail
                delete_order_detail_flow(ordersMap, booksMap);
                break;
            case 4:
                cout << "Exiting to main menu..." << endl;
                break;
            default:
                cout << "\nInvalid option" << endl;
                break;
        }
    } while (opt != 4);    
}

void insert_order(std::unordered_map<int, Client>& clientsMap, std::unordered_map<int, Book>& booksMap, std::unordered_map<int, Order>& ordersMap) {
    string search_name, cont;
    int clientId;

    cout << "\n*** Insert new Order ***" << endl;

    cout << "\nClient name: ";
    cin >> search_name;

    clientId = search_client(search_name, clientsMap);
    if (clientId == -1) {
        cout << "\nClient not found!" << endl;
        return;
    }

    int orderId;
    if (ordersMap.empty()) {
        orderId = 1;
    } else {
        orderId = std::max_element(ordersMap.begin(), ordersMap.end(),
                                [](const auto& p1, const auto& p2) {
                                    return p1.first < p2.first;
                                })->first + 1;
    }

    ordersMap[orderId] = Order(orderId, clientId);
    Order& order = ordersMap[orderId]; 

    do {
        insert_order_detail(order, booksMap); 

        cout << "Do you want to add another order detail? (y/n): ";
        cin >> cont;
    } while (cont == "y" || cont == "Y");

    cout << "Order successfully added.\n";
}

   void insert_order_detail(Order& order, std::unordered_map<int, Book>& booksMap) {
       string search_title;
       int bookId, quantity;

       cout << "\n*** New Order Detail ***" << endl;
       cout << "\nBook title: ";
       cin >> search_title;

       // Поиск ID книги по названию
       bookId = search_book(search_title, booksMap);  // Используй функцию search_book

       if (bookId == -1) { // Книга не найдена
           cout << "\nBook not found!" << endl;
           return;
       }

       auto& book = booksMap.at(bookId);

       do {
           cout << "Quantity: ";
           cin >> quantity;
       } while (quantity <= 0 || quantity > book.getQuantity());

       double subtotal = book.getPrice() * quantity;
       order.details.push_back(OrderDetail(bookId, quantity, subtotal));
       order.total += subtotal;

       book.setQuantity(book.getQuantity() - quantity); // Обновляем количество на складе
   }
 void print_list_orders(const std::unordered_map<int, Client>& clientsMap, 
                           std::unordered_map<int, Book>& booksMap, 
                           const std::unordered_map<int, Order>& ordersMap) {
       cout << "\n*** List of Orders ***" << endl;

       if (ordersMap.empty()) {
           cout << "No orders found.\n";
           return;
       }

       for (const auto& orderPair : ordersMap) {
           print_order(orderPair.second, clientsMap, booksMap);
       }
   }

void print_order(const Order& order, const unordered_map<int, Client>& clientsMap, unordered_map<int, Book>& booksMap) {
    cout << "Order ID: " << order.id << endl;

    auto clientIt = clientsMap.find(order.clientId);
        if (clientIt != clientsMap.end()) {
            cout << "Client: " << clientIt->second.getName() << endl;
        } else {
            cout << "Client: Not found (ID: " << order.clientId << ")" << endl;
        }

        cout << "-------------------------------------------------------------" << endl;
        cout << left;
        cout << setw(10) << "Item" << setw(30) << "Book" << setw(15) << "Unit Price"
            << setw(10) << "Quantity" << setw(10) << "Subtotal" << endl;
        cout << "-------------------------------------------------------------" << endl;

        int item = 1;
        double total = 0; // Инициализация переменной для подсчёта итоговой суммы
        for (const auto& detail : order.details) {
            auto bookIt = booksMap.find(detail.bookId);
            string bookTitle = (bookIt != booksMap.end()) ? bookIt->second.getName() : "Not found";

            double unitPrice = detail.subtotal / detail.quantity; // Вычисление цены за единицу
            
            cout << setw(10) << item++ <<
                setw(30) << bookTitle <<
                setw(15) << unitPrice <<
                setw(10) << detail.quantity <<
                setw(10) << detail.subtotal << endl;

            total += detail.subtotal; // Суммирование для итоговой суммы
        }

        cout << "\nTotal: " << total << endl << endl; // Вывод итоговой суммы
}


    void delete_order_detail_flow(std::unordered_map<int, Order>& ordersMap, std::unordered_map<int, Book>& booksMap) {
    int orderId, detailIndex;

    cout << "\nEnter the Order ID: ";
    cin >> orderId;

    auto orderIt = ordersMap.find(orderId);
    if (orderIt == ordersMap.end()) {
        cout << "Order not found!" << endl;
        return;
    }

    Order& order = orderIt->second;

    if (order.details.empty()) {
        cout << "No details to delete in this order." << endl;
        return;
    }
    
    cout << "Enter the index of the detail to delete (starting from 0): ";
    cin >> detailIndex;

    if (detailIndex < 0 || detailIndex >= order.details.size()) {
        cout << "Invalid detail index!" << endl;
        return;
    }

    // Restore book quantity
    auto& detail = order.details[detailIndex];
    auto bookIt = booksMap.find(detail.bookId);
    if (bookIt != booksMap.end()) {
        bookIt->second.setQuantity(bookIt->second.getQuantity() + detail.quantity);
    }

    // Update order total
    order.total -= detail.subtotal;

    // Remove the detail
    order.details.erase(order.details.begin() + detailIndex);

    cout << "Order detail removed successfully." << endl;
}