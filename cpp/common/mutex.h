#ifndef __COMMON_MUTEX_H_DEFINED__
#define __COMMON_MUTEX_H_DEFINED__

#include <stdint.h>
#include "config.h"

namespace common
{

class Mutex
{
 private:

#ifdef USE_PTHREAD
  pthread_mutex_t m_mutex;
#endif /* USE_PTHREAD */

 public:

  enum Option 
  {
    Option_None      = 0,
    Option_Recursvie = (1<<0),
  };

  /// @brief Default Consturctor
  Mutex(const char* name, Option option = Option_None);

  /// @brief Destructor
  virtual ~Mutex();
  
  int32_t Lock(void);

  int32_t TryLock(void);
  
  int32_t TimedLock(uint32_t usec);
  
  int32_t Unlock(void);




  
};

}

#endif /* __COMMON_MUTEX_H_DEFINED__ */
