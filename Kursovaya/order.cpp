
#include "order.h"
#include <cstdio>
#include <iostream>
#include <limits>
#include <iomanip>
#include <algorithm>
#include <unordered_map>

using namespace std;

// --- Функции для работы с файлами ---

// Чтение заказов из файла и сохранение их в карту заказов
void readOrdersFromFile(std::unordered_map<int, Order>& ordersMap, const std::string& filename) {
    FILE* inputFile = fopen(filename.c_str(), "r");
    if (!inputFile) {
        cerr << "Error " << filename << endl;
        return;
    }
    
    int id, clientId;
    double total;

    while (fscanf(inputFile, "%d %d %lf", &id, &clientId, &total) == 3) {
        ordersMap[id] = Order(id, clientId);
        ordersMap[id].total = total;  // Присваиваем общую стоимость заказа
    }

    fclose(inputFile);
}

// Сохранение заказов в файл
void saveOrdersToFile(const std::unordered_map<int, Order>& ordersMap, const std::string& filename) {
    FILE* outputFile = fopen(filename.c_str(), "w");
    if (!outputFile) {
        cerr << "Error " << filename << endl;
        return;
    }

    for (const auto& pair : ordersMap) {
        fprintf(outputFile, "%d %d %.2f\n", pair.second.id, pair.second.clientId, pair.second.total);
    }

    fclose(outputFile);
}

// Чтение деталей заказов из файла и обновление карты заказов
void readOrderDetailsFromFile(std::unordered_map<int, Order>& ordersMap, std::unordered_map<int, Book>& booksMap, const std::string& filename) {
    FILE* inputFile = fopen(filename.c_str(), "r");
    if (!inputFile) {
        cerr << "Error " << filename << endl;  // Ошибка при открытии файла
        return;
    }

    int orderId, bookId, quantity;
    double subtotal;

    // Чтение деталей заказа из файла
    while (fscanf(inputFile, "%d %d %d %lf", &orderId, &bookId, &quantity, &subtotal) == 4) {
        if (ordersMap.find(orderId) != ordersMap.end()) {  // Проверка, существует ли заказ
            ordersMap[orderId].details.push_back(OrderDetail(bookId, quantity, subtotal));
            if (booksMap.find(bookId) == booksMap.end()) { // Проверка существования книги
                cerr << "Warning: Book with ID " << bookId << " not found for order " << orderId << endl;
            }
        } else {
            cerr << "Warning: Order with ID " << orderId << " not found for order detail." << endl;
        }
    }

    fclose(inputFile); // Закрытие файла
}

// Сохранение деталей заказов в файл
void saveOrderDetailsToFile(const std::unordered_map<int, Order>& ordersMap, const std::string& filename) {
    FILE* outputFile = fopen(filename.c_str(), "w");
    if (!outputFile) {
        cerr << "Error " << filename << endl;  // Ошибка при открытии файла
        return;
    }

    // Запись деталей заказов в файл
    for (const auto& orderPair : ordersMap) {
        for (const auto& detail : orderPair.second.details) {
            fprintf(outputFile, "%d %d %d %.2f\n", orderPair.first, detail.bookId, detail.quantity, detail.subtotal);
        }
    }

    fclose(outputFile); // Закрытие файла
}

// --- Функции меню и операций ---

// Главное меню для управления заказами
void menu_orders(std::unordered_map<int, Client>& clientsMap, std::unordered_map<int, Book>& booksMap, std::unordered_map<int, Order>& ordersMap) {
    int opt;

    do {
        // Вывод меню
        cout << left;
        cout << setw(20) << "\n --- MANAGMENT OF ORDERS ---" << endl;
        cout << "\nSelect an option from [1-3] according to the menu:" << endl;
        cout << "[1]. Insert order" << endl;
        cout << "[2]. Print list of orders" << endl;
        cout << "[3]. Exit" << endl;
        cout << "-----------------------------------------------" << endl;
        cout << "Enter option: ";
        cin >> opt;


        // Обработка выбора пользователя
        switch (opt) {
            case 1:     // Добавить заказ
                insert_order(clientsMap, booksMap, ordersMap);
                break;
            case 2:     // Печать списка заказов
                print_list_orders(clientsMap, booksMap, ordersMap);
                break;
            case 3:
                cout << "Exiting to main menu..." << endl;
                break;
            default:
                cout << "\nInvalid option" << endl;
                break;
        }
    } while (opt != 3);    // Повтор меню до выбора опции "Выход"
}

// Функция для добавления нового заказа
void insert_order(std::unordered_map<int, Client>& clientsMap, std::unordered_map<int, Book>& booksMap, std::unordered_map<int, Order>& ordersMap) {
    string search_name, cont;
    int clientId;

    cout << "\n*** Insert new Order ***" << endl;

    cout << "\nClient name: ";
    cin >> search_name;

    clientId = search_client(search_name, clientsMap); // Поиск ID клиента по имени
    if (clientId == -1) {
        cout << "\nClient not found!" << endl;
        return;
    }

    // Генерация нового ID заказа
    int orderId;
    if (ordersMap.empty()) {
        orderId = 1;
    } else {
        orderId = std::max_element(ordersMap.begin(), ordersMap.end(),
                                [](const auto& p1, const auto& p2) {
                                    return p1.first < p2.first;
                                })->first + 1;
    }

    ordersMap[orderId] = Order(orderId, clientId); // Добавление нового заказа
    Order& order = ordersMap[orderId]; // Ссылка на новый заказ

    // Добавление деталей к заказу
    do {
        insert_order_detail(order, booksMap); 

        cout << "Do you want to add another order detail? (y/n): ";
        cin >> cont;
    } while (cont == "y" || cont == "Y");

    cout << "Order successfully added.\n";
}

// Добавление деталей к заказу
void insert_order_detail(Order& order, std::unordered_map<int, Book>& booksMap) {
    string search_title;
    int bookId, quantity;

    cout << "\n*** New Order Detail ***" << endl;
    cout << "\nBook title: ";
    cin >> search_title;

    // Поиск ID книги по названию
    bookId = search_book(search_title, booksMap);  // Используем функцию search_book

    if (bookId == -1) { // Книга не найдена
        cout << "\nBook not found!" << endl;
        return;
    }

    auto& book = booksMap.at(bookId); // Получаем книгу по ID

    do {
        cout << "Quantity: ";
        cin >> quantity;
    } while (quantity <= 0 || quantity > book.getQuantity()); // Проверка корректности количества

    double subtotal = book.getPrice() * quantity; // Подсчет стоимости
    order.details.push_back(OrderDetail(bookId, quantity, subtotal)); // Добавляем деталь заказа
    order.total += subtotal; // Обновляем общую стоимость заказа

    book.setQuantity(book.getQuantity() - quantity); // Обновляем количество книг на складе
}

// Печать списка заказов
void print_list_orders(const std::unordered_map<int, Client>& clientsMap, 
                           std::unordered_map<int, Book>& booksMap, 
                           const std::unordered_map<int, Order>& ordersMap) {
       cout << "\n*** List of Orders ***" << endl;

       if (ordersMap.empty()) {
           cout << "No orders found.\n";
           return;
       }

       // Печать каждого заказа
       for (const auto& orderPair : ordersMap) {
           print_order(orderPair.second, clientsMap, booksMap);
       }
   }

// Печать одного заказа и его деталей
void print_order(const Order& order, const std::unordered_map<int, Client>& clientsMap, std::unordered_map<int, Book>& booksMap) {
    cout << "Order ID: " << order.id << endl;

    // Печать имени клиента
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
        for (const auto& detail : order.details) {
            auto bookIt = booksMap.find(detail.bookId);
            string bookTitle = (bookIt != booksMap.end()) ? bookIt->second.getName() : "Not found";

            cout << setw(10) << item++ <<
                setw(30) << bookTitle << 
                setw(15) << detail.subtotal / detail.quantity << // Вычисление цены за единицу
                setw(10) << detail.quantity <<
                setw(10) << detail.subtotal << endl;
        }

        cout << "\nTotal: " << order.total << endl << endl;
    }       
