/*
    PROGRAM 02: The mathematical pendulum
    Definition of variables
        - cost: cost
        - n: number of payments
        - i: the interest rate
        - cost_sale: discounted price
        - category_client: category of clients
        - category_product: category of products
        - payment: payment
        - credit_type: type of credit
*/

#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int cost, n, i;
    int cost_sale, summ;
    int category_client, category_product, payment;
    int credit_type;

    cout << "Enter cost" << endl;
    cin >> cost;

    cout << "Enter category_client (1 - excellent, 2 - good, 3 - average, 4 - bad)" << endl;
    cin >> category_client;

    cout << "Enter category_product (1 - A, 2 - B, 3 - C)" << endl;
    cin >> category_product;

    switch(category_product) {
        case 3:
            switch(category_client) {
                case 4:
                    cout << "You can use cash" << endl;
                    cost_sale = cost + cost * 0.1;
                    cout << "cost = " << cost << endl << "cost_sale = " << cost_sale << endl;
                    break;
                case 3:
                    cout << "You can use 1 - cash, 2 - bank" << endl;
                    cin >> payment;
                    switch(payment) {
                        case 1:
                            cost_sale = cost;
                            cout << "cost = " << cost << endl << "cost_sale = " << cost_sale << endl;
                            break;
                        case 2:
                            cout << "Enter quantity of payments: ";
                            cin >> n;
                            cout << "Enter the percentages: ";
                            cin >> i;
                            summ = cost * (1 + (i * n) / 100.0);
                            cost_sale = summ;
                            cout << "cost = " << cost << endl << "cost_sale = " << cost_sale << endl;
                            break;
                    }
                    break;
                case 2:
                    cout << "You can use 1 - cash, 2 - bank, 3 - credit" << endl;
                    cin >> payment;
                    switch(payment) {
                        case 1:
                            cost_sale = cost - cost * 0.1;
                            cout << "cost = " << cost << endl << "cost_sale = " << cost_sale << endl;
                            break;
                        case 2:
                            cout << "Enter quantity of payments: ";
                            cin >> n;
                            cout << "Enter the percentages: ";
                            cin >> i;
                            summ = cost * (1 + (i * n) / 100.0);
                            cost_sale = summ - summ * 0.1;
                            cout << "cost = " << cost << endl << "cost_sale = " << cost_sale << endl;
                            break;
                        case 3:
                            cost_sale = cost - cost * 0.1;
                            cout << "Enter quantity of payments: ";
                            cin >> n;
                            cout << "Enter type of credit 1 - platinum, 2 - business: ";
                            cin >> credit_type;
                            switch(credit_type) {
                                case 1:
                                    i = 2;
                                    summ = cost - cost * 0.1;
                                    cost_sale = cost * pow((1 + i / 100.0), n);
                                    break;
                                case 2:
                                    i = 5;
                                    summ = cost - cost * 0.1;
                                    cost_sale = cost * pow((1 + i / 100.0), n);
                                    break;
                            }
                            cout << "cost = " << cost << endl << "cost_sale = " << cost_sale << endl;
                            break;
                    }
                    break;
                case 1:
                    cout << "You can use 1 - cash, 2 - bank, 3 - credit" << endl;
                    cin >> payment;
                    switch(payment) {
                        case 1:
                            cost_sale = cost - cost * 0.2;
cout << "cost = " << cost << endl << "cost_sale = " << cost_sale << endl;
                            break;
                        case 2:
                            cout << "Enter quantity of payments: ";
                            cin >> n;
                            cout << "Enter the percentages: ";
                            cin >> i;
                            summ = cost * (1 + (i * n) / 100.0);
                            cost_sale = summ - summ * 0.2;
                            cout << "cost = " << cost << endl << "cost_sale = " << cost_sale << endl;
                            break;
                        case 3:
                            cost_sale = cost - cost * 0.2;
                            cout << "Enter quantity of payments: ";
                            cin >> n;
                            cout << "Enter type of credit 1 - platinum, 2 - business: ";
                            cin >> credit_type;
                            switch(credit_type) {
                                case 1:
                                    i = 2;
                                    summ = cost - cost * 0.2;
                                    cost_sale = cost * pow((1 + i / 100.0), n);
                                    break;
                                case 2:
                                    i = 5;
                                    summ = cost - cost * 0.2;
                                    cost_sale = cost * pow((1 + i / 100.0), n);
                                    break;
                            }
                            cout << "cost = " << cost << endl << "cost_sale = " << cost_sale << endl;
                            break;
                    }
                default:
                    cout << "Invalid product category or client category" << endl;
                    break;                        
            break;
            }
            break;
        case 2:
            switch(category_client) {
                case 4:
                    cout << "You can use cash" << endl;
                    cost_sale = cost + cost * 0.05;
                    cout << "cost = " << cost << endl << "cost_sale = " << cost_sale << endl;
                    break;
                case 3:
                    cout << "You can use 1 - cash, 2 - bank" << endl;
                    cin >> payment;
                    switch(payment) {
                        case 1:
                            cost_sale = cost - cost * 0.1;
                            cout << "cost = " << cost << endl << "cost_sale = " << cost_sale << endl;
                            break;
                        case 2:
                            cout << "Enter quantity of payments: ";
                            cin >> n;
                            cout << "Enter the percentages: ";
                            cin >> i;
                            summ = cost * (1 + (i * n) / 100.0);
                            cost_sale = summ - summ * 0.1;
                            cout << "cost = " << cost << endl << "cost_sale = " << cost_sale << endl;
                            break;
                    }
                    break;
                case 2:
                    cout << "You can use 1 - cash, 2 - bank, 3 - credit" << endl;
                    cin >> payment;
                    switch(payment) {
                        case 1:
                            cost_sale = cost - cost * 0.2;
                            cout << "cost = " << cost << endl << "cost_sale = " << cost_sale << endl;
                            break;
                        case 2:
                            cout << "Enter quantity of payments: ";
                            cin >> n;
                            cout << "Enter the percentages: ";
                            cin >> i;
                            summ = cost * (1 + (i * n) / 100.0);
                            cost_sale = summ - summ * 0.2;
                            cout << "cost = " << cost << endl << "cost_sale = " << cost_sale << endl;
                            break;
case 3:
                            cost_sale = cost - cost * 0.2;
                            cout << "Enter quantity of payments: ";
                            cin >> n;
                            cout << "Enter type of credit 1 - platinum, 2 - business: ";
                            cin >> credit_type;
                            switch(credit_type) {
                                case 1:
                                    i = 2;
                                    summ = cost - cost * 0.2;
                                    cost_sale = cost * pow((1 + i / 100.0), n);
                                    break;
                                case 2:
                                    i = 5;
                                    summ = cost - cost * 0.2;
                                    cost_sale = cost * pow((1 + i / 100.0), n);
                                    break;
                            }
                            cout << "cost = " << cost << endl << "cost_sale = " << cost_sale << endl;
                            break;
                    }
                    break;
                case 1:
                    cout << "You can use 1 - cash, 2 - bank, 3 - credit" << endl;
                    cin >> payment;
                    switch(payment) {
                        case 1:
                            cost_sale = cost - cost * 0.3;
                            cout << "cost = " << cost << endl << "cost_sale = " << cost_sale << endl;
                            break;
                        case 2:
                            cout << "Enter quantity of payments: ";
                            cin >> n;
                            cout << "Enter the percentages: ";
                            cin >> i;
                            summ = cost * (1 + (i * n) / 100.0);
                            cost_sale = summ - summ * 0.3;
                            cout << "cost = " << cost << endl << "cost_sale = " << cost_sale << endl;
                            break;
                        case 3:
                            cost_sale = cost - cost * 0.3;
                            cout << "Enter quantity of payments: ";
                            cin >> n;
                            cout << "Enter type of credit 1 - platinum, 2 - business: ";
                            cin >> credit_type;
                            switch(credit_type) {
                                case 1:
                                    i = 2;
                                    summ = cost - cost * 0.3;
                                    cost_sale = cost * pow((1 + i / 100.0), n);
                                    break;
                                case 2:
                                    i = 5;
                                    summ = cost - cost * 0.3;
                                    cost_sale = cost * pow((1 + i / 100.0), n);
                                    break;
                            }
                            cout << "cost = " << cost << endl << "cost_sale = " << cost_sale << endl;
                            break;
                    }               
                default:
                    cout << "Invalid product category or client category" << endl;
                    break;                     
            }
            break;
        case 1:
            switch(category_client) {
                case 4:
                    cout << "You can use cash" << endl;
                    cost_sale = cost;
                    cout << "cost = " << cost << endl << "cost_sale = " << cost_sale << endl;
                    break;
                case 3:
                    cout << "You can use 1 - cash, 2 - bank" << endl;
                    cin >> payment;
                    switch(payment) {
                        case 1:
                            cost_sale = cost - cost * 0.2;
                            cout << "cost = " << cost << endl << "cost_sale = " << cost_sale << endl;
                            break;
                        case 2:
cout << "Enter quantity of payments: ";
                            cin >> n;
                            cout << "Enter the percentages: ";
                            cin >> i;
                            summ = cost * (1 + (i * n) / 100.0);
                            cost_sale = summ - summ * 0.2;
                            cout << "cost = " << cost << endl << "cost_sale = " << cost_sale << endl;
                            break;
                    }
                    break;
                case 2:
                    cout << "You can use 1 - cash, 2 - bank, 3 - credit" << endl;
                    cin >> payment;
                    switch(payment) {
                        case 1:
                            cost_sale = cost - cost * 0.3;
                            cout << "cost = " << cost << endl << "cost_sale = " << cost_sale << endl;
                            break;
                        case 2:
                            cout << "Enter quantity of payments: ";
                            cin >> n;
                            cout << "Enter the percentages: ";
                            cin >> i;
                            summ = cost * (1 + (i * n) / 100.0);
                            cost_sale = summ - summ * 0.3;
                            cout << "cost = " << cost << endl << "cost_sale = " << cost_sale << endl;
                            break;
                        case 3:
                            cost_sale = cost - cost * 0.3;
                            cout << "Enter quantity of payments: ";
                            cin >> n;
                            cout << "Enter type of credit 1 - platinum, 2 - business: ";
                            cin >> credit_type;
                            switch(credit_type) {
                                case 1:
                                    i = 2;
                                    summ = cost - cost * 0.3;
                                    cost_sale = cost * pow((1 + i / 100.0), n);
                                    break;
                                case 2:
                                    i = 5;
                                    summ = cost - cost * 0.3;
                                    cost_sale = cost * pow((1 + i / 100.0), n);
                                    break;
                            }
                            cout << "cost = " << cost << endl << "cost_sale = " << cost_sale << endl;
                            break;
                    }
                        default:
                            cout << "Invalid product category or client category" << endl;
                            break;    
            }
            break;
        default:
            cout << "Invalid product category or client category" << endl;
            break;
    }

    return 0;
}