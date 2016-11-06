// Copyright 2016 Vinicius Macelai

#include "./array_list.h"

namespace structures {

template<typename T>
//! Classe Árvore binária.
/*!
*/
class BinaryTree {
 public:
    ~BinaryTree() {
        if (!empty()) {
            // root->clear();
        }
        size_ = 0;
    }
//! Inserir um dado na árvore.
/*!
\param data um generico do dado.
\sa empty()
*/
    void insert(const T& data) {
        if (empty()) {
            root = new Node(data);
        } else {
            root->insert(data);
        }
        ++size_;
    }
//! Retira um dado.
/*!
\param data generico do dado a ser retirado.
\sa empty()
*/
    void remove(const T& data) {
        bool b = false;
        if (empty()) {
            return;
        } else {
            b = root->remove(data);
        }
        if (b)
            --size_;
    }
//! Verifica se contém um dado.
/*!
\param data um generico do dado.
\return um boolean.
\sa empty()
*/ 
    bool contains(const T& data) const {
        if (empty()) {
            return false;
        } else {
            return root->contains(data);
        }
    }
//! Verifica se está vazio.
/*!
\return um boolean.
*/
    bool empty() const {
		return size_ == 0;
	}
//! Verifica o tamanho.
/*!
\return o tamanho.
*/
    std::size_t size() const {
		return size_;
	}
//! Gera lista pré-ordem.
/*!
\return lista.
\sa empty()
*/
    ArrayList<T> pre_order() const {
        structures::ArrayList<T> list{};
        if (!empty()) {
            root->pre_order(list);
        }
        return list;
    }
//! Gera lista em ordem.
/*!
\return lista.
\sa empty()
*/
    ArrayList<T> in_order() const {
        structures::ArrayList<T> list{};
        if (!empty()) {
            root->in_order(list);
        }
        return list;
    }
//! Gera lista pós-ordem.
/*!
\return lista.
\sa empty()
*/
    ArrayList<T> post_order() const {
        structures::ArrayList<T> list{};
        if (!empty()) {
            root->post_order(list);
        }
        return list;
    }

 private:
    struct Node {
        explicit Node(const T& data_):
            data{data_}
        {}

        T data;
        Node* left = nullptr;
        Node* right = nullptr;

        void clear() {
            if (right != nullptr)
                right->clear();
            if (left != nullptr)
                left->clear();
            delete this;
        }

        void insert(const T& data_) {
            if (data < data_) {
                if (right == nullptr) {
                    right = new Node(data_);
                } else {
                    right->insert(data_);
                }
            } else {
                if (left == nullptr) {
                    left = new Node(data_);
                } else {
                    left->insert(data_);
                }
            }
        }

        bool remove(const T& data_) {
            if (data == data_) {
                if (right != nullptr && left != nullptr) {
                    auto tmp = minimo(right);
                    data = tmp->data;
                    return right->remove(data);
                } else {
                    if (right != nullptr) {
                        data = right->data;
                        return right->remove(data);
                    } else {
                        if (left != nullptr) {
                            data = left->data;
                            return left->remove(data);
                        } else {
                            delete this;
                            return true;
                        }
                    }
                }
            } else {
                if (data_ > data && right != nullptr) {
                    return right->remove(data_);
                } else {
                    if (data_ < data && left != nullptr) {
                        return left->remove(data_);
                    }
                }
            }
            return false;
        }

        Node* minimo(Node* node) {
            while (node->left != nullptr) {
                node = node->left;
            }
            return node;
        }

        bool contains(const T& data_) const {
            if (data == data_) {
                return true;
            } else {
                if (data < data_ && right != nullptr) {
                    return right->contains(data_);
                } else if (data > data_ && left != nullptr) {
                    return left->contains(data_);
                }
            }
            return false;
        }

        void pre_order(ArrayList<T>& v) const {
            v.push_back(data);
            if (left != nullptr) {
                left->pre_order(v);
            }
            if (right != nullptr) {
                right->pre_order(v);
            }
        }

        void in_order(ArrayList<T>& v) const {
            if (left != nullptr) {
                left->in_order(v);
            }
            v.push_back(data);
            if (right != nullptr) {
                right->in_order(v);
            }
        }

        void post_order(ArrayList<T>& v) const {
            if (left != nullptr) {
                left->post_order(v);
            }
            if (right != nullptr) {
                right->post_order(v);
            }
            v.push_back(data);
        }
    };

    Node* root;
    std::size_t size_;
};

}  // namespace structures

