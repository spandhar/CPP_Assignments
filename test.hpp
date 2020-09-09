#include <iostream>

class Order
{
  public:
    Order()
    {
        std::cout << "Order created @ " << this << "\n";
    }

    Order(int p_qty) : qty_(p_qty) 
    {
        std::cout << "Order created @ " << this << "\n";
    }

    ~Order() 
    {
        std::cout << "End of Order @ [" << this << "], id [" << order_id_ 
                  << "]\n";
    }

    bool NewOrder(const Order& p_order);
    bool ModifyOrder(const Order& p_order);

  private:
    int order_id_;
    int qty_;
    static int s_next_order_id_;
};



