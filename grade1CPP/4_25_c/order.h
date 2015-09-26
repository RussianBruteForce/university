#ifndef ORDER_H
#define ORDER_H

#include <string>

typedef struct {
    unsigned int payer_account;
    unsigned int recipient_account;
    unsigned int amount;
    std::string currency;
} Order;

#endif // ORDER_H
