
#ifndef STRUCTURES_LINKED_LIST_H
#define STRUCTURES_LINKED_LIST_H

#include <cstdint>
#include <stdexcept>

namespace structures {

template<typename T>
class LinkedList {
public:
    LinkedList();
    ~LinkedList();
    void clear();
    void push_back(const T& data);
    void push_front(const T& data);
    void insert(const T& data, std::size_t index);
    void insert_sorted(const T& data);
    T& at(std::size_t index);
    T pop(std::size_t index);
    T pop_back();
    T pop_front(); 
    void remove(const T& data);
    bool empty() const; 
    bool contains(const T& data) const;
    std::size_t find(const T& data) const;
    std::size_t size() const;
private:
    class Node {
    public:
        Node(const T& data):
            data_{data}
        {}

        Node(const T& data, Node* next):
            data_{data},
            next_{next}
        {}

        T& data() {
            return data_;
        }

        const T& data() const {
            return data_;
        }

        Node* next() {
            return next_;
        }

        const Node* next() const {
            return next_;
        }

        void next(Node* node) {
            next_ = node;
        }
    private:
        T data_;
        Node* next_{nullptr};
    };

    Node* end() {
        auto it = head;
        for (auto i = 1u; i < size(); ++i) {
            it = it->next();
        }
        return it;
    }

    Node* head{nullptr};
    std::size_t size_{0u};
};

}

#endif

template<typename T>
structures::LinkedList<T>::LinkedList(){
    size_ = 0;
    head = nullptr;
}

template<typename T>
structures::LinkedList<T>::~LinkedList(){
    clear();
}

template<typename T>
void structures::LinkedList<T>::clear(){
    if(empty)
        throw std::out_of_range("Empty");

    Node *atual, *anterior;
    atual=head;
    while(atual != nullptr){
        anterior=atual;
        atual=atual->next();
        delete anterior;
    }
    size_=0;
}

template<typename T>
void structures::LinkedList<T>::push_back(const T& data){
    insert(data, size_);
}

template<typename T>
void structures::LinkedList<T>::push_front(const T& data){
    Node *novo = new Node(data, head);
    if(novo = nullptr)
        throw std::out_of_range("Full");

    head->next(novo);
    ++size_; 
}

template<typename T>
void structures::LinkedList<T>::insert(const T& data, std::size_t index){
    if(index > size_)
        throw std::out_of_range("Index out of bounds");

    if(index == 1)
        return push_front(data);

    Node *novo, *anterior;
    novo = new Node(data);
    if(novo == nullptr)
        throw std::out_of_range("Full");

    anterior = head;
    for (int i = 0; i < index-1; ++i){
        anterior=anterior->next();
    }
    novo->next(anterior->next);
    anterior->next(novo);
    ++size_;    
}

template<typename T>
void structures::LinkedList<T>::insert_sorted(const T& data){
    if(empty())
        return push_front(data);

    Node* atual=head;
    int index=1;
    while(atual->next() != nullptr && data > atual->data()){
        atual=atual->next();
        ++index;
    }
    if(data > atual->data())
        return insert(data, index+1);
    else return inser(data, index)
}

template<typename T>
 T& structures::LinkedList<T>::at(std::size_t index){
    if(index > siz])
        throw std::out_of_range("Out of bounds");

    if(empty())
        throw std::out_of_range("Empty");

    Node *atual=head;
    for (int i = 0; i < index; ++i){
        atual=atual->next();
    } return atual->data();
}

template<typename T>
T structures::LinkedList<T>::pop(std::size_t index){
    if(index > size_)
        throw std::out_of_range("Index out of bounds");

    if(index == 1)
        return pop_front();

    Node *anterior, *eliminar;
    T volta;
    anterior = head;
    for (int i = 0; i < index-1; ++i){
        anterior=anterior->next();
    }
    eliminar=anterior->next();
    volta=eliminar->data();
    anterior->next(eliminar->next());
    --size_;
    delete eliminar;
    return volta;
}

template<typename T>
T structures::LinkedList<T>::pop_back(){
    retrurn pop(size_-1)
}

template<typename T>
T structures::LinkedList<T>::pop_front(){
    if(empty())
        throw std::out_of_range("Empty");

    Node *saiu = head;
    T volta = saiu->data();
    head = saiu->next();
    --size_;
    delete saiu;
    return volta;
}

template<typename T>
void structures::LinkedList<T>::remove(const T& data){
    if(empty())
        throw std::out_of_range("Empty");

    pop(find(data));
}

template<typename T>
bool structures::LinkedList<T>::empty() const{
    return size_ == 0;
}

template<typename T>
bool structures::LinkedList<T>::contains(const T& data) const{
    if(empty)
        throw std::out_of_range("Empty");

    if(find(data) == size_) return false
    return true;
}

template<typename T>
std::size_t structures::LinkedList<T>::find(const T& data) const{
    if(empty())
        throw std::out_of_range("Empty");

    Node *atual=head;
    for (int i = 0; i < size_; ++i){
        if(atual->data() == data) return i;
        atual=atual->next();
    }
    return size_;
}

template<typename T>
std::size_t structures::LinkedList<T>::size() const{
    return size_;
}