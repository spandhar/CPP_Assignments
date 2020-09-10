//#include <bits/stdc++.h>
#include <unistd.h>
#include <iostream>
#include <array>
#include <vector>
#include <numeric>
#include <cstdlib>
#include <algorithm>
#include <memory>

template<typename T>
class Node {

  public:
    Node() {
        std::cout << " \nNode :" << data_ << " created\n"; 
    };
    ~Node(){
        std::cout << " \nNode :" << data_ << " destroyed\n"; 
    }
    Node(const T& p_data)
    {
        data_ = p_data;
        next_ = nullptr;
    }

    Node(T&& p_data)
    {
        data_ = std::move(p_data);
        next_ = nullptr;
        std::cout << " \nNode :" << data_ << " created\n"; 
    }

    const T& GetData(){
        return data_;
    }

  //private:
    T data_ {};
    std::unique_ptr<Node<T>> next_ {nullptr};
    //friend List<T>;
};

template<typename T>
class List{
    public:
        List() = default;
        ~List(){
            std::cout << "List is destroyed \n";
        }
        void PushFront(const T& p_data)
        {
            auto&& node = new Node(p_data);
            node->next_ = std::move(head_);
            head_ = std::move(node);
        }

        void PushFront(T&& p_data)
        {
            std::unique_ptr<Node<T>> node = std::make_unique<Node<T>>(std::move(p_data));
            node->next_ = std::move(head_);
            head_ = std::move(node);
        }

        void Print()
        {
            if(head_ == nullptr){
                std::cout << " \nlist is empty\n"; 
                return;
            }
            
            auto&& ele = head_.get();
            do{
                std::cout << " " << ele->GetData();
                ele = ele->next_.get();
            }while(ele != nullptr);
            
            std::cout << std::endl;
        }

    private:
        std::unique_ptr<Node<T>> head_ {nullptr};
};


int main(){
    List<int> l1 {};
    l1.PushFront(0);
    l1.PushFront(10);
    l1.PushFront(20);
    l1.Print();
    l1.Print();

    l1.PushFront(999);
    l1.Print();
}
