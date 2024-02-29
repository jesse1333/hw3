#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>
using namespace std;

template <typename T, typename PComparator = std::less<T>>
class Heap
{
private:
  /// Add whatever helper functions and data members you need below
  vector<T> heap;
  unsigned int childrenCount;
  PComparator comp;

  void trickleUp(int index);
  void trickleDown(int index);

public:
  /**
   * @brief Construct a new Heap object
   *
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m = 2, PComparator c = PComparator());

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
  void push(const T &item);

  /**
   * @brief Returns the top (priority) item
   *
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const &top() const;

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
};

template <typename T, typename PComparator>
void Heap<T, PComparator>::trickleUp(int index)
{
  while (index != 0)
  {
    std::size_t parent_index = (index - 1) / childrenCount;
    T &current = heap[index];
    T &parent = heap[parent_index];
    if (comp(current, parent))
    {
      std::swap(current, parent);
      index = parent_index;
    }
    else
    {
      break;
    }
  }
}

template <typename T, typename PComparator>
void Heap<T, PComparator>::trickleDown(int index)
{
  int firstChild = 0;
  int bestChild = firstChild;

  while (true)
  {
    firstChild = childrenCount * index + 1;
    bestChild = firstChild;

    // checking if first child exists (left child of node)
    if (firstChild > int(heap.size() - 1))
    {
      break;
    }

    // if child exists
    else
    {
      for (int i = firstChild + 1; i < firstChild + childrenCount; i++)
      {
        if (i > int(heap.size()) - 1)
        {
          break;
        }

        else if (comp(heap[i], heap[bestChild]))
        {
          bestChild = i;
        }
      }

      if (comp(heap[bestChild], heap[index]))
      {
        swap(heap[index], heap[bestChild]);
        index = bestChild;
      }

      else
      {
        return;
      }
    }
  }
}

template <typename T, typename PComparator>
Heap<T, PComparator>::Heap(int m, PComparator c)
{
  childrenCount = m;
  comp = c;
}

template <typename T, typename PComparator>
Heap<T, PComparator>::~Heap()
{
}

template <typename T, typename PComparator>
void Heap<T, PComparator>::push(const T &item)
{
  heap.push_back(item);
  trickleUp(heap.size() - 1);
}

// Add implementation of member functions here

// We will start top() for you to handle the case of
// calling top on an empty heap
template <typename T, typename PComparator>
T const &Heap<T, PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if (empty())
  {
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("Empty Heap!");
  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
  else
  {
    return heap[0];
  }
}

// We will start pop() for you to handle the case of
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T, PComparator>::pop()
{
  if (empty())
  {
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("Empty Heap!");
  }

  else
  {
    heap[0] = heap[heap.size() - 1];
    heap.pop_back();

    if (heap.size() == 0)
    {
      return;
    }

    trickleDown(0);
  }
}

template <typename T, typename PComparator>
bool Heap<T, PComparator>::empty() const
{
  if (heap.size() == 0)
  {
    return true;
  }
  else
  {
    return false;
  }
}

template <typename T, typename PComparator>
size_t Heap<T, PComparator>::size() const
{
  return heap.size();
}

#endif
