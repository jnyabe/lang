#include <iostream>

template<class T>
class custom_allocator 
{
 public:
  typedef size_t size_type;
  typedef ptrdiff_t difference_type;
  typedef T* pointer;
  typedef const T* const_pointer;
  typedef T& reference;
  typedef const T& const_reference;
  typedef T value_type;
  
  
  custom_allocator() {}
  custom_allocator(const custom_allocator& x) {}
  
  template<class U> custom_allocator(const custom_allocator<U>& x) {}
  
  pointer allocate(size_type n, const_pointer hint = 0)
  {
    std::cout << "allocate " << n * sizeof(T) << "bytes" << std::endl;
    return (pointer) std::malloc(n * sizeof(T));
  }

  pointer deallocate(pointer ptr, size_type n)
  {
    std::cout << "free pointer " << (void*) ptr << std::endl;
    std::free(ptr);
  }
  
  
  template<class U> struct rebind {
    typedef custom_allocator<U> other;
  };
  
};
