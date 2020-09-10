#include<iostream>
#include "test.hpp"

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

std::unique_ptr<Order> CreateOrder()
{
    std::unique_ptr<Order> order(new Order());
    order->NewOrder(*order);
    return std::move(order);
}

void ModifyOrder(std::unique_ptr<Order> p_order)
{
    std::cout << "Enter modify qty : \n";
    int qty = 0;
    std::cin >> qty;
    std::unique_ptr<Order> temp_order (new Order(qty));
    if(p_order->ModifyOrder(*temp_order))
    {
        std::cout << "Order modified \n";
    }
}

std::shared_ptr<Order> CreateOrderS()
{
    std::shared_ptr<Order> order(new Order());
    order->NewOrder(*order);
    return order;
}

void ModifyOrder(std::shared_ptr<Order> p_order)
{
    std::cout << "Enter modify qty : \n";
    int qty = 0;
    std::cin >> qty;
    std::unique_ptr<Order> temp_order (new Order(qty));
    if(p_order->ModifyOrder(*temp_order))
    {
        std::cout << "Order modified 1\n";
    }
}

int main()
{
   auto&& order = CreateOrder();
   ModifyOrder(std::move(order));
    
    auto&& s_order = CreateOrderS();
    ModifyOrder(s_order);
    
    return 1;


}

