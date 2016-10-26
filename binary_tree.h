#include "array_list.cpp"

namespace structures {

class BinaryTree {
public:
    ~BinaryTree();

    void insert(const T& data);

    void remove(const T& data);

    bool contains(const T& data) const;

    bool empty() const {
		return size_ == 0;
	}

    std::size_t size() const {
		return size_;
	}

    ArrayList<T> pre_order() const;

    ArrayList<T> in_order() const;

    ArrayList<T> post_order() const;

private:
    struct Node {
        Node(const T& data);

        T data;
        Node* left;
        Node* right;

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

}
