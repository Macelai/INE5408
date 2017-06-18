//! Classe fila.
/*! Fornece a estrutura de dados FIFO.
* \author Vinicius Macelai.
* \since 23/08/16
* \version 1.0
*/

#ifndef STRUCTURES_ARRAY_QUEUE_H
#define STRUCTURES_ARRAY_QUEUE_H

#include <cstdint> // std::size_t
#include <stdexcept> // C++ Exceptions

namespace structures {

template<typename T>
class ArrayQueue {
public:
    ArrayQueue();

    ArrayQueue(std::size_t max);

    ~ArrayQueue();

    void enqueue(const T& data);

    T dequeue();

    T& back();

    void clear();

    std::size_t size();

    std::size_t max_size();

    bool empty();

    bool full();

private:
    T* contents;
    std::size_t size_;
    std::size_t max_size_;
    T first;
   
    const static auto DEFAULT_SIZE = 10u;
};

}

#endif
//! Construtor da classe.
/*!
*/

template<typename T>
structures::ArrayQueue<T>::ArrayQueue(){
	max_size_=DEFAULT_SIZE;
	contents = new T[max_size_];
	size_=0;
}
//! Construtor da classe com parametro.
/*!
\param max um size_t que representa tamanho do array.
*/

template<typename T>
structures::ArrayQueue<T>::ArrayQueue(std::size_t max){
	max_size_=max;
	contents = new T[max_size_];
	size_=0;
}
//! Destrutor da classe.
/*!
*/

template<typename T>
structures::ArrayQueue<T>::~ArrayQueue(){
	delete []contents;
}
//! Enfileiramento, adicionar dados
/*!
\param data do tipo gênerico que contem o dado
\sa full()
*/

template<typename T>
void structures::ArrayQueue<T>::enqueue(const T& data){
	if(full())
		throw std::out_of_range("fila cheia");

	contents[size_]=data;
	size_++;
}	
//! Desenfileirar, retirar um dado e mover todos uma posição a frente.
/*!
\return um gênerico dado
\sa empty()
*/

template<typename T>    
T structures::ArrayQueue<T>::dequeue(){
	if(empty())
		throw std::out_of_range("fila vazia");

	first = contents[0];
	size_--;
	for(int i=0;i<=size_;i++){
	    contents[i]=contents[i+1];
	}
	return first;
}
//! Último da fila
/*!
\return um gênerico com o último dado
\sa empty()
*/

template<typename T>
T& structures::ArrayQueue<T>::back(){
	if(empty())
		throw std::out_of_range("fila vazia");

	return contents[size_-1];
}
//! Limpa a fila
/*!
*/

template<typename T>
void structures::ArrayQueue<T>::clear(){
	size_=0;
}
//! Tamanho da fila
/*!
\return um size_t com o tamanho da filha
*/

template<typename T>
std::size_t structures::ArrayQueue<T>::size(){
	return size_ ;
}
//! Tamanho máximo da fila
/*!
\return um size_t com tamanho máximo da fila.
*/

template<typename T>
std::size_t structures::ArrayQueue<T>::max_size(){
	return max_size_;
}
//! Verifica se a fila está vazia
/*!
\return um boolean
*/

template<typename T>
bool structures::ArrayQueue<T>::empty(){
	return size_ == 0;
}
//! Verifica se a fila está cheia.
/*!
\return um boolean.
*/

template<typename T>
bool structures::ArrayQueue<T>::full(){
	return size_ == max_size_;
}