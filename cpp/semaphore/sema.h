#ifndef _SEMA_H_DEFINED_
#define _SEMA_H_DEFINED_

#include <semaphore.h>

class Sema
{
 private:
  sem_t* m_semaphore;
  
 public:
  Sema(const char* name, int permits);
  virtual ~Sema();
  void Aquire(int permits = 1);
  void Release(int permits = 1);
};

#endif /* _SEMA_H_DEFINED_ */
