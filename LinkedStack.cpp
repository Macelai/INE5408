// Copyright 2016 Vinicius Macelai
#include <cstdint>
#include <stdexcept>

namespace structures {

template<typename T>
//! Classe da Pilha encadeada.
/*!
*/
class LinkedStack {
 public:
//! Construtor padrão.
/*!
*/
    LinkedStack() {
    	top_ = nullptr;
    	size_ = 0;
    }
//! Destrutor padrão.
/*!
*/
    ~LinkedStack() {
    	clear();
    }
//! Limpa a pilha.
/*!
*/
    void clear() {
    	Node *atual, *anterior;
    	atual = top_;
    	while(atual != nullptr) {
        	anterior = atual;
        	atual = atual->next();
        	delete anterior;
    	}
    	size_ = 0;
    	top_ = nullptr;
    }
//! Inserir um dado na pilha.
/*!
\param data um generico do dado.
*/
    void push(const T& data) {
    	Node *novo = new Node(data, top_);
    	if(novo == nullptr)
        	throw std::out_of_range("Full");

    	top_ = novo;
    	++size_;
    }
//! Retira um dado da pilha.
/*!
\return um dado.
\sa empty()
*/
    T pop() {
    	if(empty())
        	throw std::out_of_range("Empty");

	    Node *saiu = top_;
    	T volta = saiu->data();
    	top_ = top_->next();
    	--size_;
    	delete saiu;
    	return volta;
    }
//! Verifica o topo da pilha.
/*!
\return um dado.
\sa empty()
*/
    T& top() const {
        if (empty())
            throw std::out_of_range("Empty");
    	return top_->data();
    }
//! Verifica se a pilha está vazia.
/*!
\return um boolean.
*/
    bool empty() const {
    	return size_ == 0;
    }
//! Verifica o tamanho da pilha.
/*!
\return um size_t.
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

    Node* top_;
    std::size_t size_;
};

}  // namespace structures
