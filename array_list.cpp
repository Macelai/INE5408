//! Classe estrutura de dado, Lista.
/*!
* \author Vinicius Macelai.
* \since 30/08/16
* \version 1.0
*/

#ifndef STRUCTURES_ARRAY_LIST_H
#define STRUCTURES_ARRAY_LIST_H

#include <cstdint>
#include <stdexcept>

namespace structures {

template<typename T>
class ArrayList {
public:
    ArrayList();
    ArrayList(std::size_t max_size);
    ~ArrayList();
    void clear();
    void push_back(T data);
    void push_front(T data);
    void insert(T data, std::size_t index);
    void insert_sorted(T data);
    T pop(std::size_t index);
    T pop_back();
    T pop_front();
    void remove(T data);
    bool full() const;
    bool empty() const;
    bool contains(const T& data) const;
    std::size_t find(const T& data) const;
    std::size_t size() const;
    std::size_t max_size() const;
    T& at(std::size_t index);
    T& operator[](std::size_t index);
    const T& at(std::size_t index) const;
    const T& operator[](std::size_t index) const;

private:
    T* contents;
    std::size_t size_;
    std::size_t max_size_;

    const static auto DEFAULT_MAX = 10u;
};

}

#endif

//! Construtor da classe padrão .
/*!
*/

template<typename T>
structures::ArrayList<T>::ArrayList(){
    size_= 0;
    max_size_= DEFAULT_MAX;
    contents = new T[max_size_];
}

//! Construtor da classe com paramêtro.
/*!
\param max_size um size_t que representa o tamanho do array.
*/

template<typename T>
structures::ArrayList<T>::ArrayList(std::size_t max_size){
    size_= 0;
    max_size_= max_size;
    contents = new T[max_size_];
}

//! Destrutor da classe.
/*!
*/

template<typename T>
structures::ArrayList<T>::~ArrayList(){
    delete []contents;
}

//! Limpa a fila.
/*!
*/

template<typename T>
void structures::ArrayList<T>::clear(){
    size_= 0;
}

//! Inserir um dado na fila em posição determinada.
/*!
\param data um gênerico do dado.
\param index um size_t que representa o endereço para colocar na posição.
\sa full()
*/

template<typename T>
void structures::ArrayList<T>::insert(T data, std::size_t index){
    if (full()){
        throw std::out_of_range("fila cheia");
    }else if(index > size_ || index < 0){
            throw std::out_of_range("erro posição");
        }

    size_++;
    int atual=size_-1;
    while(atual > index){
        contents[atual]= contents[atual-1];
        atual--;
    }
    contents[index]=data;    
}

//! Inserir dado na última posição.
/*!
\param data um gênerico de dado.
\sa insert()
*/

template<typename T>
void structures::ArrayList<T>::push_back(T data){
    structures::ArrayList<T>::insert(data, size_);
}

//! Inserir dado na primeira posição.
/*!
\param data um gênerico de dado.
\sa insert()
*/

template<typename T>
void structures::ArrayList<T>::push_front(T data){
    structures::ArrayList<T>::insert(data, 0);
}

//! Inserir dado em ordem.
/*!
\param data um gênerico de dado.
\sa insert()
*/

template<typename T>
void structures::ArrayList<T>::insert_sorted(T data){
    if(full())
        throw std::out_of_range("lista cheia");
        
    std::size_t t = 0;
    while(t < size_ && data > contents[t]){
        ++t;
    }return structures::ArrayList<T>::insert(data, t);
}

//! Retirar um dado de uma posição específica.
/*!
\param index um size_t representa o índice do valor desejado.
\return um gênerico.
\sa empty()
*/

template<typename T>
T structures::ArrayList<T>::pop(std::size_t index){
    if(empty())
        throw std::out_of_range("lista vazia");
        
    if(size_ <= index)
        throw std::out_of_range("não há dado na posição");
        
    T dado = contents[index];
    for(int i = index; i < size_; ++i){
        contents[i] = contents[i+1];
    }
    size_--;
    return dado;
}

//! Retira o último dado.
/*!
\return um gênerico.
\sa empty()
*/

template<typename T>
T structures::ArrayList<T>::pop_back(){
    if(empty())
        throw std::out_of_range("lista vazia");

    size_--;
    return contents[size_];
}

//! Retira o primeiro dado.
/*!
\return um gênerico.
\sa empty()
*/

template<typename T>
T structures::ArrayList<T>::pop_front(){
    if(empty())
        throw std::out_of_range("fila vazia");

    T first = contents[0];
    size_--;
    for(int i=0;i<=size_;i++){
        contents[i]=contents[i+1];
    }
    return first;
}

//! Remove um dado específico.
/*!
\param data um gênerico que representa o dado a ser tirado da fila.
*/

template<typename T>
void structures::ArrayList<T>::remove(T data){
    for (int i = 0; i < size_-1; ++i){
        if(contents[i] == data){
            size_--;
            for (int k = i; k < size_; ++k){
                 contents[k] = contents[k+1];
             } 
        }
    }
}

//! Verificar se a lista esta cheia.
/*!
\return um boolean.
*/

template<typename T>
bool structures::ArrayList<T>::full() const{
    return size_ == max_size_;
}

//! Verificar se a lista esta vazia.
/*!
\return um boolean.
*/

template<typename T>
bool structures::ArrayList<T>::empty() const{ 
    return size_ == 0;
}

//! Verifica se há um dado específico na lista.
/*!
\param data um gênerico que representa o dado a ser procurado.
\return um boolean.
*/

template<typename T>
bool structures::ArrayList<T>::contains(const T& data) const{
    for (int i = 0; i < size_; ++i){
        if(contents[i] == data){
            return true;
        }
    }
    return false;
}

//! Busca o dado na lista e retorna seu índice.
/*!
\param data um gênerico que representa o dado a ser procurado.
\return um boolean.
*/

template<typename T>
std::size_t structures::ArrayList<T>::find(const T& data) const{
    std::size_t tem= -1;
    for (int i = 0; i < size_; ++i){
        if(contents[i] == data){
            tem=i;
        }
    }
    if(tem==-1){
        return size_;
    }else return tem;
}

//! Tamanho da lista.
/*!
\return um size_t.
*/

template<typename T>
std::size_t structures::ArrayList<T>::size() const{
    return size_;
}

//! Tamanho máximo da lista.
/*!
\return um size_t.
*/

template<typename T>
std::size_t structures::ArrayList<T>::max_size() const{
    return max_size_;
}

//! Dado no indice, com checagens.
/*!
\param index um size_t que representa o índice de consulta desejado.
\return um gênerico.
\sa empty()
*/

template<typename T>
T& structures::ArrayList<T>::at(std::size_t index){
    if (empty()){
        throw std::out_of_range("lista vazia");
    }else if(index > size_ || index < 0){
            throw std::out_of_range("erro posição");
        }else return contents[index];
}

//! Dado no indice, sem checagens.
/*!
\param index um size_t que representa o índice de consulta desejado.
\return um gênerico.
*/

template<typename T>
T& structures::ArrayList<T>::operator[](std::size_t index){
    return contents[index];
}

//! Dado no indice, com checagens e sem mexer no objeto.
/*!
\param index um size_t que representa o índice de consulta desejado.
\return um gênerico.
\sa empty()
*/

template<typename T>
const T& structures::ArrayList<T>::at(std::size_t index) const{
    if (empty()){
        throw std::out_of_range("lista vazia");
    }else if(index > size_ || index < 0){
            throw std::out_of_range("erro posição");
          }else return contents[index];
}

//! Dado no indice, sem checagens e sem mexer no objeto.
/*!
\param index um size_t que representa o índice de consulta desejado.
\return um gênerico.
*/

template<typename T>
const T& structures::ArrayList<T>::operator[](std::size_t index) const{
    return contents[index];
}
