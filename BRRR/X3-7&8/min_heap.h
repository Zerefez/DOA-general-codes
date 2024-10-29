#pragma once 

#include <iostream> 
#include <vector>   
#include <stdexcept>

using namespace std;

/**
 * @brief Min-Heap Class
 *
 * @tparam T
 */

template<typename T>
class MinHeap {

    template <typename T>
    struct Node {
        T data;
        Node* left;
        Node* right;

        // Constructor 
        Node(T value) {
            data = value;
            left = right = nullptr;
        }
    };

private:
    Node<T>* root;
    vector<Node<T>*> nodes;

    /**
     * @brief Restores the heap property by moving a node up the tree
     *
     * @param index The index of the node to heapify up
     */
    void heapifyUp(int index) {
        if (index == 0) return;                              // If the node is the root, do nothing as it has no parent 
        int parentIndex = (index - 1) / 2;                   // Calculate the index of the parent node 
        if (nodes[index]->data < nodes[parentIndex]->data) { // If the current node is smaller than its parent 
            swap(nodes[index], nodes[parentIndex]);          // Swap the current node with its parent 
            heapifyUp(parentIndex);                          // Recursively heapify up from the parent index 
        }
    }

    /**
     * @brief Restores the heap property by moving a node down the tree
     *
     * @param index The index of the node to heapify down
     */
    void heapifyDown(int index) {
        int leftChildIndex = 2 * index + 1;  // Calculate the index of the left child
        int rightChildIndex = 2 * index + 2; // Calculate the index of the right child 
        int smallest = index;                // Initialize smallest as the current index 

        // Check if the left child exists and is smaller than the current node
        if (leftChildIndex < nodes.size() && nodes[leftChildIndex]->data < nodes[smallest]->data) {
            smallest = leftChildIndex; // Update smallest if left child is smaller
        }

        // Check if the right child exists and is smaller than the smallest node so far
        if (rightChildIndex < nodes.size() && nodes[rightChildIndex]->data < nodes[smallest]->data) {
            smallest = rightChildIndex; // Update smallest if right child is smaller 
        }

        // If the smallest is not the current node, swap and continue heapifying down
        if (smallest != index) {
            swap(nodes[index], nodes[smallest]); // Swap current node with the smallest node found (left or right child) 
            heapifyDown(smallest);               // Recursively heapify down from the smallest index (left or right child)
        }
    }

public:
    MinHeap() : root(nullptr) {}

    ~MinHeap() {
        for (Node<T>* node : nodes) {
            delete node;  // Delete each node to free memory
        }
    }

    /**
     * @brief Inserts an element and updates the Heap
     *
     * @param x Element to insert
     */
    void insert(const T& x) {
        Node<T>* newNode = new Node<T>(x);  // Create a new node with the provided value
        nodes.push_back(newNode);           // Add the new node to the vector
        heapifyUp(nodes.size() - 1);        // Restore the heap property by heapifying up from the new node's index
    }

    /**
      * @brief Remove minimum (top) element and update Heap
      *
      */
    void remove() {
        if (isEmpty()) {                           // Check if the heap is empty
            throw runtime_error("Heap is empty"); // Throw an exception if it is
        }


        swap(nodes[0], nodes.back()); // Swap the root node with the last element in the vector (the rightmost leaf)
        delete nodes.back();          // Delete the last element (which is now the old root) to free memory
        nodes.pop_back();             // Remove it from the vector

        heapifyDown(0);               // Restore the heap property by heapifying down from the root
    }

    /**
     * @brief Inspect if Heap is empty
     *
     * @return true Heap is empty
     * @return false Heap is not empty
     */
    bool isEmpty() const {
        return nodes.empty(); // Return true if the vector of nodes is empty
    }

    /**
     * @brief Access the minimum (top) element of the Heap
     *
     * @return T Minimum element in Heap
     */
    T peek() {
        if (isEmpty()) {                            // Check if the heap is empty
            throw runtime_error("Heap is empty");   // Throw an exception if it is
        }
        return nodes[0]->data;                      // Return the data of the root node (minimum element)
    }

    void printHeap() const {
        cout << "Heap elements: ";
        for (const auto& node : nodes) {
            cout << node->data << " ";
        }
        cout << endl;
    }
};
