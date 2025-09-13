// C++ program to demonstrate building
// and inserting in a Fibonacci heap
#include <cstdlib>
#include <iostream>
#include <malloc.h>
using namespace std;

struct node {
    node* parent;
    node* child;
    node* left;
    node* right;
    int key;
};

class Fibonacci_heap{// Creating min pointer as "mini"
    private:
        struct node* mini = NULL;

// Declare an integer for number of nodes in the heap
        int no_of_nodes = 0;

    public:
// Function to insert a node in heap
    Fibonacci_heap(int num_nodes) : no_of_nodes(num_nodes){

    }
    void insertion(int val){
        struct node* new_node = (struct node*)malloc(sizeof(struct node));
        new_node->key = val;
        new_node->parent = NULL;
        new_node->child = NULL;
        new_node->left = new_node;
        new_node->right = new_node;
        if (mini != NULL) {
            (mini->left)->right = new_node;
            new_node->right = mini;
            new_node->left = mini->left;
            mini->left = new_node;
            if (new_node->key < mini->key)
                mini = new_node;
        }
        else {
            mini = new_node;
        }
    }

    // Function to find min node in the heap
    void find_min(){
        cout << "min of heap is: " << mini->key << endl;
    }
};

// Driver code
int main()
{
    Fibonacci_heap fibonacci_heap(7);

    fibonacci_heap.insertion(4);
    fibonacci_heap.insertion(3);
    fibonacci_heap.insertion(7);
    fibonacci_heap.insertion(5);
    fibonacci_heap.insertion(2);
    fibonacci_heap.insertion(1);
    fibonacci_heap.insertion(10);

    fibonacci_heap.find_min();


    return 0;
}