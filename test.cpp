#include "test.hpp"

#include<memory>

int Order::s_next_order_id_ = 0;

bool Order::NewOrder(const Order& p_order)
{
    order_id_ = s_next_order_id_++;
    return true;
}

bool Order::ModifyOrder(const Order& p_order)
{
    qty_ = p_order.qty_;
    return true;
}

