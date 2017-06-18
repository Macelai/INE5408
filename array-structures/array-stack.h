//! Classe Pilha.
/*! Fornece a estrutura de dados LIFO.
* \author Vinicius Macelai.
* \since 23/08/16
* \version 1.0
*/

#ifndef STRUCTURES_ARRAY_STACK_H
#define STRUCTURES_ARRAY_STACK_H

#include <cstdint> // std::size_t
#include <stdexcept> // C++ exceptions


namespace structures {

template<typename T>
class ArrayStack {
public:
    ArrayStack();

    ArrayStack(std::size_t max);

    ~ArrayStack();

    void push(const T& data); // empilha

    T pop(); // desempilha

    T& top();

    void clear(); // limpa

    std::size_t size(); // tamanho

    std::size_t max_size();

    bool empty(); // vazia

    bool full(); // cheia

private:
    T* contents;
    int top_;
    std::size_t max_size_;

    const static auto DEFAULT_SIZE = 10u;
};

}

#endif

//! Construtor da classe.
/*!
*/

template <typename T>
structures::ArrayStack<T>::ArrayStack(){
	max_size_=DEFAULT_SIZE;
	contents = new T[max_size_];
	top_=-1;
}

//! Construtor da classe com valor passado por parametro.
/*!
\param max um size_t que representa o tamanho máximo do vetor.
*/


template <typename T>
structures::ArrayStack<T>::ArrayStack(std::size_t max){
	max_size_=max;
	contents = new T[max_size_];
	top_=-1;
}

//! Destrutor da classe.
/*!
*/

template <typename T>
structures::ArrayStack<T>::~ArrayStack(){
	delete []contents;
}

//! Empilha dados.
/*!
\sa full()
\param data um gênerico que consiste no dado a ser armazenado.
*/

template<typename T>
void structures::ArrayStack<T>::push(const T& data){
	if (full())
		throw std::out_of_range("pilha cheia");
    
	top_++;
	contents[top_]=data;	
}

//! Desempilha o dado.
/*!
\sa empty()
\return o dado generico que estava na última posição.
*/

template<typename T>
T structures::ArrayStack<T>::pop(){
	if(empty())
		throw std::out_of_range("pilha vazia");

	top_--;
	return contents[top_+1];
}

//! Último dado inserido.
/*!
\sa empty()
\return o dado gênerico da última posição
*/


template<typename T>
T& structures::ArrayStack<T>::top(){
	if(empty())
		throw std::runtime_error("pilha vazia");

	return contents[top_];
}

//! Limpa a pilha
/*!
 \sa empty()
*/

template<typename T>
void structures::ArrayStack<T>::clear(){
	top_=-1;
}

//! Testa se a pilha está vazia
/*!
\return um boolean.
*/

template<typename T>
bool structures::ArrayStack<T>::empty(){
	return top_ == -1;
}

//! Testa se a pilha está cheia
/*!
\return um boolean.
*/


template<typename T>
bool structures::ArrayStack<T>::full(){
	return top_ == max_size_-1;
}

//! Verificar tamanho atual
/*!
\return um size_t tamanho
*/


template<typename T>
std::size_t structures::ArrayStack<T>::size(){
	return top_+1;
}

//! Verificar o tamanho máximo
/*!
\return um size_t tamanho máx.
*/


template<typename T>
std::size_t structures::ArrayStack<T>::max_size(){
	return max_size_;
}