#ifndef DECLARATIONS_H
#define DECLARATIONS_H

#include <cstddef>   
#include <vector>    

//question 1: queue class

template <typename Item_Type>
class Queue {
private:

    
    struct Node {
        Item_Type data;
        Node* next;
        Node(const Item_Type& item) : data(item), next(nullptr) {}
    };

    Node* front_of_queue;   
    Node* back_of_queue;    
    int   num_items;        

public:

    //constructor, makes an empty queue
    Queue() : front_of_queue(nullptr),
        back_of_queue(nullptr),
        num_items(0) {
    }

    //adds item to the back
    void push(const Item_Type& item) {
        Node* new_node = new Node(item);

        if (front_of_queue == nullptr) {
            //queue was empty
            front_of_queue = back_of_queue = new_node;
        }
        else {
            back_of_queue->next = new_node;
            back_of_queue = new_node;
        }
        num_items++;
    }

    //removes item from the front
    void pop() {
        if (empty()) 
            return;   

        Node* old_front = front_of_queue;
        front_of_queue = front_of_queue->next;
        delete old_front;
        num_items--;

        if (num_items == 0) {
           //queue is now empty
            back_of_queue = nullptr;
        }
    }

    //get the front item
    Item_Type& front() {
        return front_of_queue->data;    
    }

    bool empty() const { return num_items == 0; }
    int  size()  const { return num_items; }

    //move the front item to the back
    void move_to_rear() {
        if (num_items <= 1)
            return;

        Item_Type firstVal = front();
        pop();
        push(firstVal);
    }
};

//question 2
int linear_search(std::vector<int>& items, int target, size_t pos_last)
{
    //base case: went past index 0
    if (pos_last == (size_t)-1)
        return -1;

    //found target
    if (items[pos_last] == target)
        return pos_last;

    //keep looking to the left
    return linear_search(items, target, pos_last - 1);
}

//question 3
void insertion_sort(Queue<int>& q)
{
    //copy items from queue into vector
    std::vector<int> num;
    while (!q.empty()) {
        num.push_back(q.front());
        q.pop();
    }

    //uses the original source code for sorting vectors 
    int i, j, key;
    bool insertionNeeded = false;

    for (j = 1; j < num.size(); j++) {
        key = num[j];
        insertionNeeded = false;

        for (i = j - 1; i >= 0; i--) {
            if (key < num[i]) {
                num[i + 1] = num[i];    
                insertionNeeded = true;
            }
            else
                break;
        }

        if (insertionNeeded)
            num[i + 1] = key;           
    }

    //copies the sorted values in vector back into the queue
    for (int k = 0; k < (num.size()); k++) {
        q.push(num[k]);
    }
}

#endif
