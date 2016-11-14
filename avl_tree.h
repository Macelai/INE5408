// Copyright Vinicius Macelai 2016
#include "array_list.h"

namespace structures {
template<typename T>
//! Classe Arvore AVL.
/*!
*/
class AVLTree {
public:
    ~AVLTree();

    void insert(const T& data);

    void remove(const T& data);

    bool contains(const T& data) const;

    bool empty() const;

    std::size_t size() const;

    ArrayList<T> pre_order() const;

    ArrayList<T> in_order() const;

    ArrayList<T> post_order() const;

private:
    struct Node {
        explicit Node(const T& data):
            data{data}
        {}

        T data;
        std::size_t height_;
        Node* left;
        Node* right;

        std::size_t height() const;

        void height(std::size_t height);

        void insert(const T& data_);

        bool remove(const T& data_);

        bool contains(const T& data_) const;

        void pre_order(ArrayList<T>& v) const;

        void in_order(ArrayList<T>& v) const;

        void post_order(ArrayList<T>& v) const;
    };

    Node* root;
    std::size_t size_;
};

}  // namespace structures

