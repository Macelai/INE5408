<<<<<<< HEAD
=======
//! Classe estrutura de dado, Lista encadeada.
/*!
* \author Vinicius Macelai.
* \since 08/09/16
* \version 1.0
*/

>>>>>>> 9e67f470c8f94b7c87a14d6ecd7276e83710668e
#ifndef STRUCTURES_LINKED_LIST_H
#define STRUCTURES_LINKED_LIST_H

#include <cstdint>


namespace structures {

template<typename T>
//! Classe da Lista encadeada.
/*!
*/
class LinkedList {
public:
<<<<<<< HEAD
    LinkedList() // construtor padrão
    ~LinkedList() // destrutor
    void clear() // limpar lista
    void push_back(const T& data) // inserir no fim
    void push_front(const T& data) // inserir no início
    void insert(const T& data, std::size_t index)  // inserir na posição
    void insert_sorted(const T& data) // inserir em ordem
    T& at(std::size_t index) // acessar um elemento na posição index
    T pop(std::size_t index) // retirar da posição
    T pop_back() // retirar do fim
    T pop_front() // retirar do início
    void remove(const T& data) // remover específico
    bool empty() const // lista vazia
    bool contains(const T& data) const // contém
    std::size_t find(const T& data) const // posição do dado
    std::size_t size() const // tamanho da lista
=======
//! Construtor da classe padrÃ£o .
/*!
*/
    LinkedList();
//! Destrutor da classe.
/*!
*/
    ~LinkedList();
//! Limpa a fila.
/*!
*/
    void clear();
//! Inserir um dado na lista na última posição.
/*!
\param data um generico do dado.
\sa insert()
*/
    void push_back(const T& data);
//! Inserir um dado na lista na primeira posição.
/*!
\param data um generico do dado.
*/
    void push_front(const T& data);
//! Inserir um dado na lista em posição determinado.
/*!
\param data um generico do dado.
\param index um size_t que representa o endereço para colocar na posição.
*/
    void insert(const T& data, std::size_t index);
//! Inserir um dado na lista em ordem.
/*!
\param data um generico do dado.
*/
    void insert_sorted(const T& data);
//! Verifica dado em posição
/*!
\param index um size_t que representa o endereço.
\return um generico
\sa empty()
*/
    T& at(std::size_t index);
//! Retira um dado de uma posição
/*!
\param index um size_t que representa o endereço.
\return um dado.
\sa empty()
*/
    T pop(std::size_t index);
//! Retira um dado da última posição.
/*!
\return um dado.
\sa empty(), pop()
*/
    T pop_back();
//! Retira um dado da primeira posição
/*!
\return um dado.
\sa empty()
*/
    T pop_front(); 
//! Remove um dado percorrendo até descobrir.
/*!
\param data um gênerico do dado.
\sa empty(),find(),pop()
\return um dado.
*/
    void remove(const T& data);
//! Verifica se está vazio
/*!
\return um boolean.
*/
    bool empty() const;
//! Verifica se contém um dado.
/*!
\param data um generico do dado.
\return um boolean.
\sa empty(), find()
*/  
    bool contains(const T& data) const;
//! Acha um dado na lista.
/*!
\param data um generico do dado.
\return um boolean.
\sa empty()
*/
    std::size_t find(const T& data) const;
//! Verifica o tamanho.
/*!
\return o tamanho.
*/
    std::size_t size() const;
>>>>>>> 9e67f470c8f94b7c87a14d6ecd7276e83710668e
private:
    class Node { // Elemento
    public:
        Node(const T& data):
            data_{data}
        {}

        Node(const T& data, Node* next):
            data_{data},
            next_{next}
        {}

        T& data() { // getter: dado
            return data_;
        }

        const T& data() const { // getter const: dado
            return data_;
        }

        Node* next() { // getter: próximo
            return next_;
        }

        const Node* next() const { // getter const: próximo
            return next_;
        }

        void next(Node* node) { // setter: próximo
            next_ = node;
        }
    private:
        T data_;
        Node* next_{nullptr};
    };

    Node* end() { // último nodo da lista
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

<<<<<<< HEAD
=======
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
    Node *atual, *anterior;
    atual=head;
    while(atual != nullptr){
        anterior=atual;
        atual=atual->next();
        delete anterior;
    }
    size_=0;
    head=nullptr;
}

template<typename T>
void structures::LinkedList<T>::push_back(const T& data){
    insert(data, size_);
}

template<typename T>
void structures::LinkedList<T>::push_front(const T& data){
    Node *novo = new Node(data, head);
    if(novo == nullptr)
        throw std::out_of_range("Full");

    head=novo;
    ++size_; 
}

template<typename T>
void structures::LinkedList<T>::insert(const T& data, std::size_t index){
    if(index > size_)
        throw std::out_of_range("Index out of bounds");

    if(index == 0)
        return push_front(data);

    Node *anterior = head;
    for (int i = 0; i < index-1; ++i){
        anterior=anterior->next();
    }
    anterior->next(new Node(data, anterior->next()));
    ++size_;    
}

template<typename T>
void structures::LinkedList<T>::insert_sorted(const T& data){
    if(empty())
        return push_front(data);

    Node* atual=head;
    int index=0;
    while(atual->next() != nullptr && data > atual->data()){
        atual=atual->next();
        ++index;
    }
    if(data > atual->data())
        return insert(data, index+1);
    else return insert(data, index);
}

template<typename T>
 T& structures::LinkedList<T>::at(std::size_t index){
    if(index > size_)
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
    if(index >= size_)
        throw std::out_of_range("Index out of bounds");
    
    if(empty())
        throw std::out_of_range("Empty pop");

    if(index == 0)
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
    return pop(size_-1);
}

template<typename T>
T structures::LinkedList<T>::pop_front(){
    if(empty())
        throw std::out_of_range("Empty popfront");

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
        throw std::out_of_range("Empty remove");

    pop(find(data));
}

template<typename T>
bool structures::LinkedList<T>::empty() const{
    return size_ == 0;
}

template<typename T>
bool structures::LinkedList<T>::contains(const T& data) const{
    if(empty())
        throw std::out_of_range("Empty contains");

    if(find(data) == size_) return false;
    return true;
}

template<typename T>
std::size_t structures::LinkedList<T>::find(const T& data) const{
    if(empty())
        throw std::out_of_range("Empty find");

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
>>>>>>> 9e67f470c8f94b7c87a14d6ecd7276e83710668e
