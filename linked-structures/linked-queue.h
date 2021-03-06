// Copyright 2016 Vinicius Macelai
#include <cstdint>
#include <stdexcept>

namespace structures {

template<typename T>
//! Classe Fila encadeada.
/*!
*/
class LinkedQueue {
 public:
//! Construtor padrão.
/*!
*/
    LinkedQueue() {
        size_ = 0;
        head = nullptr;
        tail = nullptr;
    }
//! Destrutor padrão.
/*!
*/
    ~LinkedQueue() {
        clear();
    }
//! Limpa a fila.
/*!
*/
    void clear() {
        Node *atual, *anterior;
        atual = head;
        while(atual != nullptr) {
            anterior = atual;
            atual = atual->next();
            delete anterior;
        }
        size_ = 0;
        head = nullptr;
        tail = nullptr;
}
//! Adicionar dado na fila, última posição.
/*!
\param data um generico do dado.
*/
    void enqueue(const T& data) {
        Node *novo = new Node(data, nullptr);
        if (size_ == 0) {
            head = novo;
        } else {
            tail->next(novo);
        }
        tail = novo;
        ++size_;
    }
//! Retira um dado da fila.
/*!
\return um dado.
\sa empty()
*/
    T dequeue() {
        Node *saiu;
        T volta;
        if (empty())
            throw std::out_of_range("empty");

        saiu = head;
        volta = saiu->data();
        head = saiu->next();
        if (size_ == 1)
            tail = nullptr;

        --size_;
        delete saiu;
        return volta;
    }
//! Verifica dado da frente.
/*!
\return um dado.
\sa empty()
*/
    T& front() const {
        if (empty())
            throw std::out_of_range("empty");

        return head->data();
    }
//! Verifica dado do final.
/*!
\return um dado.
\sa empty()
*/
    T& back() const {
        if (empty())
            throw std::out_of_range("empty");

        return tail->data();
    }
//! Verifica se a fila está vazia.
/*!
\return um boolean.
*/
    bool empty() const {
        return size_ == 0;
    }
//! Verifica o tamanho da fila.
/*!
\return um size_t tamanho.
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
        Node* next_;
    };
    Node* head;
    Node* tail;
    std::size_t size_;
};

}  // namespace structures
