#include <iostream>
#include <cstdlib>


template<typename T>

class vector

{

  int capacity_;
  int size_;
  T* data_;

public:

  explicit vector() : capacity_{1}, size_{0}, data_{static_cast<T*>(malloc(sizeof(T) * capacity_))} {  }

  ~vector() { std::free(data_) }

  void push_back(T ch)
  {
    size_++;
    if (capacity_ == size_)
    {
      capacity_ = capacity_ * 2;
      data_ = static_cast<T*>(realloc(data_, capacity_));
    }
    data_[size_ - 1] = ch;
  }

  int size() const{ return size_; }

  int capacity() const { return capacity_; }

  char back() const { return data_[size_ - 1]; }

  char& at(int i) const { return data_[i]; }

};





int main()

{

  constexpr int size = 3;

  vector<char> lines[size];

  char ch;



  for (int i = 0; i < size; i++)

  {

    do

    {

      ch = std::getchar();

      lines[i].push_back(ch);

    }

    while (ch != '\n');



    for (int row = 0; row < size; ++row)

    {

      for (int column = 0; column < lines[row].size(); ++column)

      {

	std::putchar(lines[row].at(column));

      }

    }

  }



  return 0;

}
