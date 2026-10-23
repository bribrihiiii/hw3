#ifndef STACK_H
#define STACK_H

#include <vector>
#include <stdexcept>

// Use inheritance from std::vector (choose public/private) as appropriate
template <typename T>
class Stack : private std::vector<T> {

public:
    Stack();
    ~Stack();
    bool empty() const;
    size_t size() const;
    void push(const T& item);
    void pop();  // throws std::underflow_error if empty
    const T& top() const; // throws std::underflow_error if empty
    // Add other members only if necessary
};

template <typename T>
Stack<T>::Stack() {

}

template <typename T>
Stack<T>::~Stack() {

  
}

template <typename T>
bool Stack<T>::empty() const {

    // return size() == 0;   <- this crashed (infinite loop??) have to use vector's
    size_t howMany = std::vector<T>::size();

    if(howMany == 0) {
        return true;
    }

    else if(howMany > 0) {
        return false;

    }

    return false;
}

template <typename T>
size_t Stack<T>::size() const {

  size_t s = std::vector<T>::size();
  return s;
}

template <typename T>
void Stack<T>::push(const T& item) {

    //std::vector<T>::insert(std::vector<T>::begin(), item);  too slow, not O(1)
    std::vector<T>::push_back(item);
}

template <typename T>
void Stack<T>::pop() {

    if(empty() == true){
        throw std::underflow_error("empty stack");
    }
    else{
        std::vector<T>::pop_back();
    }
}

template <typename T>
const T& Stack<T>::top() const {

  if(empty()==true) {
    throw std::underflow_error("empty stack");
  }

  
  size_t theSize = std::vector<T>::size();
  size_t lastIndex = theSize-1;
  return std::vector<T>::at(lastIndex);
}

#endif