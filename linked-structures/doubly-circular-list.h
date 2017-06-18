// Copyright 2016 Vinicius Macelai

#include <cstdint>
#include <stdexcept>

namespace structures {

template<typename T>
//! Classe Lista Circulas Simples.
/*!
*/
class DoublyCircularList {
 public:
    DoublyCircularList() {
        size_ = 0;
        head = nullptr;
    }

    ~DoublyCircularList() {
        clear();
    }
//! Limpa a lista.
/*!
*/
    void clear() {
        auto d = size_;
        for (int i = 0; i < d; ++i) {
            pop_back();
        }
    }
//! Inserir um dado no final da lista.
/*!
\param data um generico do dado.
\sa empty()
*/
    void push_back(const T& data) {
        if (empty())
            return push_front(data);

        Node *aux = head;
        for (int i = 0; i < size_-1; ++i) {
            aux = aux->next();
        }
        Node *novo = new Node(data, aux->next(), aux);
        aux->next(novo);
        ++size_;
    }
//! Inserir um dado no começo da lista.
/*!
\param data um generico do dado.
*/
    void push_front(const T& data) {
        Node *novo = new Node(data);
        novo->next(head);
        Node *aux = head;
        for (int i = 0; i < size_; ++i) {
            aux = aux->next();
        }
        novo->prev(aux);
        head = novo;
        ++size_;
    }
//! Inserir um dado na lista em posição determinada.
/*!
\param data um generico do dado.
\param index um size_t que representa o endereço para colocar na posição.
*/
    void insert(const T& data, std::size_t index) {
        if (index > size_)
            throw std::out_of_range("Index out of bounds");

        if (index == 0)
            return push_front(data);

        Node *anterior = head;
        for (int i = 0; i < index-1; ++i) {
            anterior = anterior->next();
        }
        Node *novo = new Node(data, anterior->next());
        anterior->next()->prev(novo);
        anterior->next(novo);
        ++size_;
    }
//! Inserir um dado na lista em ordem.
/*!
\param data um generico do dado.
*/
    void insert_sorted(const T& data) {
        if (empty())
            return push_front(data);

        Node* atual = head;
        int index = 0;
        while (index < size_ && data > atual->data()) {
            atual = atual->next();
            ++index;
        }
        if (index == size_)
            return push_back(data);
        return insert(data, index);
    }
//! Retira um dado de uma posição.
/*!
\param index um size_t que representa o enderço.
\return um dado.
\sa empty()
*/
    T pop(std::size_t index) {
        if (index >= size_)
            throw std::out_of_range("Index out of bounds");

        if (empty())
            throw std::out_of_range("Empty pop");

        if (index == 0)
            return pop_front();

        Node *anterior, *eliminar;
        T volta;
        anterior = head;
        for (int i = 0; i < index-1; ++i) {
            anterior = anterior->next();
        }
        eliminar = anterior->next();
        volta = eliminar->data();
        anterior->next(eliminar->next());
        --size_;
        delete eliminar;
        return volta;
    }
//! Retira um dado da última posição.
/*!
\return um dado.
\sa pop()
*/
    T pop_back() {
        return pop(size_-1);
    }
//! Retira um dado da primeira posição.
/*!
\return um dado.
\sa empty(), pop()
*/
    T pop_front() {
        if (empty())
            throw std::out_of_range("Empty");

        auto *saiu = head;
        T volta;
        volta = saiu->data();
        head = saiu->next();
        --size_;
        delete saiu;
        return volta;
    }
//! Remove um dado percorrendo até descobrir.
/*!
\param data um gênerico do dado.
\sa empty(),find(),pop()
\return um dado.
*/
    void remove(const T& data) {
        if (empty())
            throw std::out_of_range("Empty remove");

        pop(find(data));
    }
//! Verifica se contém um dado.
/*!
\return boolean.
*/
    bool empty() const {
        return size_ == 0;
    }
//! Verifica se contém um dado.
/*!
\return boolean.
*/
    bool contains(const T& data) const {
        if (empty())
            throw std::out_of_range("Empty contains");

        if (find(data) == size_) return false;
        return true;
    }
//! Acessa dado em índice determinado.
/*!
\param index um size_t que representa o endereço.
\return um dado.
\sa empty()
*/
    T& at(std::size_t index) {
        if (index > size_)
            throw std::out_of_range("Out of bounds");

        if (empty())
            throw std::out_of_range("Empty");

        Node *atual = head;
        for (int i = 0; i < index; ++i) {
            atual = atual->next();
        } return atual->data();
    }
//! Acessa dado em índice determinado(sem checagens).
/*!
\param index um size_t que representa o endereço.
\return um dado.
*/
    const T& at(std::size_t index) const {
        Node *atual = head;
        for (int i = 0; i < index; ++i) {
            atual = atual->next();
        } return atual->data();
    }
//! Acha um dado na lista.
/*!
\param data um generico do dado.
\return um boolean.
\sa empty()
*/
    std::size_t find(const T& data) const {
        if (empty())
           throw std::out_of_range("Empty find");

        Node *atual = head;
        for (int i = 0; i < size_; ++i) {
            if (atual->data() == data) return i;
            atual = atual->next();
        }
        return size_;
    }
//! Verifica o tamanho da lista.
/*!
\return o tamanho.
*/
    std::size_t size() const {
        return size_;
    }

 private:
    class Node {
     public:
        explicit Node(const T& data):
            data_{data}
        {}

        Node(const T& data, Node* next):
            data_{data},
            next_{next}
        {}

        Node(const T& data, Node* next, Node* prev):
            data_{data},
            next_{next},
            prev_{prev}
        {}

        T& data() {
            return data_;
        }

        const T& data() const {
            return data_;
        }

        Node* prev() {
            return prev_;
        }

        const Node* prev() const {
            return prev_;
        }

        void prev(Node* node) {
            prev_ = node;
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
        Node* next_;
        Node* prev_;
    };

    Node* head;
    std::size_t size_;
};

}  // namespace structures
