// #include <iostream>
#include <stdexcept>
#include <vector>
template <typename T> class Deque {
private:
  std::vector<T> front, back;

public:
  Deque(){};
  bool Empty() const { return front.empty() && back.empty(); }
  size_t Size() const { return front.size() + back.size(); }
  T &operator[](size_t index) {
    return (index < front.size() ? front[front.size() - index - 1]
                                 : back[index - front.size()]);
  }
  const T &operator[](size_t index) const {
    return (index < front.size() ? front[front.size() - index - 1]
                                 : back[index - front.size()]);
  }
  T &At(size_t index) {
    if (index >= Size()) {
      throw std::out_of_range("out_of_range");
    }
    return (index < front.size() ? front[front.size() - index - 1]
                                 : back[index - front.size()]);
  }
  const T &At(size_t index) const {
    if (index >= Size()) {
      throw std::out_of_range("out_of_range");
    }
    return (index < front.size() ? front[front.size() - index - 1]
                                 : back[index - front.size()]);
  }
  T &Front() { return (!front.empty() ? front.back() : back.front()); }
  const T &Front() const {
    return (!front.empty() ? front.back() : back.front());
  }
  T &Back() { return (!back.empty() ? back.back() : front.front()); }
  const T &Back() const {
    return (!back.empty() ? back.back() : front.front());
  }
  void PushFront(const T &push) { front.push_back(push); }
  void PushBack(const T &push) { back.push_back(push); }
};

// int main() {
//   Deque<int> dec;
//   std::cout << dec.Empty() << std::endl;
//   //   dec.PushBack(4);
//   //   dec.PushBack(5);
//   //   dec.PushBack(6);
//   dec.PushFront(3);
//   dec.PushFront(2);
//   dec.PushFront(1);
//   dec.PushFront(0);
//   std::cout << dec[3] << std::endl;
//   std::cout << dec.Front() << std::endl;

//   std::cout << dec[0] << std::endl;
//   //   std::cout << dec[6] << std::endl;

//   return 0;
// }