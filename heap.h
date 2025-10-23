#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>
#include <algorithm>

template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
  
  Heap(int m=2, PComparator c = PComparator())
    : m_(m), comp_(c) {}

  
  ~Heap(){}

  
  void push(const T& item){
    data_.push_back(item);
    trickleUp((int)data_.size() - 1);
  }


  
  T const & top() const{
    if (empty()){
      throw std::underflow_error("head is empty");
    }
    return data_.front();
  }

  
  void pop(){
    if(empty()){
      throw std::underflow_error("heap is empty");
    }
    std::swap(data_.front(),data_.back());
    data_.pop_back();
    if(!data_.empty())
    {
      trickleDown(0);
    }
  }

  
  bool empty() const{
    return data_.empty();
  }

  size_t size() const{
    return data_.size();
  }

private:

  std::vector<T> data_;
  int m_;
  PComparator comp_;



  void trickleUp(int idx){
    while(idx > 0){
      int parent = (idx - 1) / m_;
      if(comp_(data_[idx], data_[parent])){
        std::swap(data_[idx], data_[parent]);
        idx = parent;
      }
      else{
        break;
      }
    }
  }


  void trickleDown(int idx){
  while(true)
  {
    int best = idx;
    for(int k = 1; k <=m_; ++k){
      int child = m_ * idx + k;
      if(child < (int)data_.size() && comp_(data_[child], data_[best]))
      {
        best = child;
      }
    }
    if(best == idx)
      break;
    
    std::swap(data_[idx], data_[best]);
    idx = best;
  }
}

};





#endif

