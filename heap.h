#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>

template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator());

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap();

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;

private:
  /// Add whatever helper functions and data members you need below

    std::vector<T> items;
    int M;
    PComparator compare;
    int count; // not using this anymore



};

// Add implementation of member functions here

template <typename T, typename PComparator>
Heap<T,PComparator>::Heap(int m, PComparator c){
  M = m;
  compare = c;
  count = 0;
}

template <typename T, typename PComparator>
Heap<T,PComparator>::~Heap()
{

}

template <typename T, typename PComparator>
bool Heap<T,PComparator>::empty() const
{
    if(items.size() == 0) {
      return true;
    }
    else {
      return false;
    }
}

template <typename T, typename PComparator>
size_t Heap<T,PComparator>::size() const
{
  return items.size();
}

////////////

// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const {


  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================

    throw std::underflow_error("heap is empty");
  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element

  return items[0];
}

//////////////////////////////

template <typename T, typename PComparator>
void Heap<T,PComparator>::push(const T& item)
{
  items.push_back(item);
  //std::cout << "pushed, size is now " << items.size() << std::endl;

  size_t i = items.size() - 1;
  bool keepGoing = true;

  while(keepGoing == true){
    if(i == 0)
    {
      keepGoing = false;
      break;
    }
    // parent = (i-1)/m   (NOT i/2, that was for the 1-indexed one in lecture)
    size_t parent = (i - 1) / M;

    if(compare(items[i], items[parent]) == true) {
      T temp = items[i];
      items[i] = items[parent];
      items[parent] = temp;
      i = parent;
    }
    else{
      keepGoing = false;
    }
  }
}


// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================

    throw std::underflow_error("heap is empty");
  }

  size_t last = items.size() - 1;
  items[0] = items[last];
  items.pop_back();

  if(items.size() == 0) {
    return; // nothing left
  }

  size_t current = 0;
  bool done = false;

  while(!done)
  {
      size_t firstKid = M*current + 1;
      //std::cout << "current: " << current << " firstKid: " << firstKid << std::endl;

      if(firstKid >= items.size()) {
          done = true;
      }
      else
      {
          size_t best = firstKid;
          // check the other kids (there might not be M of them!! segfaulted here before)
          for(int k = 1; k < M; k++){
              size_t kid = firstKid + k;
              if(kid < items.size())
              {
                  if(compare(items[kid], items[best]) == true){
                      best = kid;
                  }
              }
              else {
                  break;
              }
          }

          if(compare(items[best], items[current]) == true)
          {
              T temp2 = items[current];
              items[current] = items[best];
              items[best] = temp2;
              current = best;
          }
          else {
            done = true;
          }
      }
  }





}



#endif

