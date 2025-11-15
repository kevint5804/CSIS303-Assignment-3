
The first part of this program is a queue using a linked list and demonstrates the different functions of queues. It will create a queue and push the numbers 1-10, then move the first element in the queue to the end.

Part one functions:
push() - adds a new node to the back
pop() - remove the front node
front() - returns value at the front
empty() - checks if the queue is empty
size() - returns the number of nodes in the queue
move_to_rear() - created to remove the value at the front of the create and push it to the rear

The second part uses a vector of integers and a recursive function, linear_search, which was modified to find the last occurrence of the target value instead of the first occurrence. It will fill the vector with 6 integers, then search starting from the last index to find the last occurrence of the target (which is 5). Since this is recursive, it will continue until the base case is reached, which is when the search goes past index 0. 

The third part sorts a queue using insertion sort and a vector. It was slightly modified so that it could sort a queue by using the original source code for ascending insertion sort in vectors. A queue will be created and 5 numbers are pushed into the queue. From the original source code, it creates a vector and pushes the queue into the vector and runs insertion sort on the vector. After the vector is sorted, it pushes all the values from the vector back into the queue in order.
