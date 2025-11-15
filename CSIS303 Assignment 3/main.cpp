#include <iostream>
#include <vector>
#include "declarations.h"

using namespace std;

int main() {
    //question 1: testing queue
    
    Queue<int> q;

    // puts numbers 1 to 10 in a queue
    for (int i = 1; i <= 10; ++i) {
        q.push(i);
    }

    //show all values in queue
    cout << "Original queue: ";
    int count = q.size();
    for (int i = 0; i < count; ++i) {
        int value = q.front();
        cout << value << " ";
        q.pop();        // take from front
        q.push(value);  // put it back at the end
    }
    cout << endl;

    //moves first element to the end
    q.move_to_rear();

    //prints queue
    cout << "After move_to_rear: ";
    count = q.size();
    for (int i = 0; i < count; ++i) {
        int value = q.front();
        cout << value << " ";
        q.pop();
        q.push(value);
    }
    cout << endl;

    //question 2

    vector<int> nums;
    nums.push_back(3);
    nums.push_back(5);
    nums.push_back(2);
    nums.push_back(5);
    nums.push_back(7);
    nums.push_back(5); 

    int target = 5;

    //prints vector
    cout << "Vector: ";
    for (int i = 0; i < nums.size(); ++i) {
        cout << nums[i] << " ";
    }
    cout << endl;

    //search from the end of the vector
    int last_index = linear_search(nums, target, nums.size() - 1);

    cout << "Last occurrence of " << target << " is at index: "
        << last_index << endl;

    // question 3: sorting a queue
    Queue<int> q2;
    q2.push(20);
    q2.push(65);
    q2.push(30);
    q2.push(10);
    q2.push(70);

    //prints queue before sorting
    cout << "Unsorted queue: ";
    int count2 = q2.size();
    for (int i = 0; i < count2; i++) {
        int value = q2.front();
        cout << value << " ";
        q2.pop();
        q2.push(value);
    }
    cout << endl;

    //sorts the queue
    insertion_sort(q2);

    //prints sorted queue
    cout << "Sorted queue: ";
    count2 = q2.size();
    for (int i = 0; i < count2; i++) {
        int value = q2.front();
        cout << value << " ";
        q2.pop();
        q2.push(value);
    }
    cout << endl;

    return 0;
}
