#ifndef __COMMON_COND_H_DEFINED__
#define __COMMON_COND_H_DEFINED__

#include "mutex.h"
#include "config.h"

namespace common
{

class Cond
{
 private:

#ifdef USE_PTHREAD
  pthread_cond_t m_mutex;
#endif /* USE_PTHREAD */

 public:

  enum Option 
  {
    Option_None      = 0,
  };

  /// @brief Default Consturctor
  Cond(Mutex* mutex, const char* name, Option option = Option_None);

  /// @brief Destructor
  virtual ~Cond();
  
  /// @biref Wait for notify
  /// @retval 0 Success
  int32_t Wait(void);

  /// @biref Wait for notify with limited time
  /// @param[in] usec 
  /// @retval 0 Success
  int32_t TimedWait(uint32_t usec);
  
  /// @biref Notify 
  /// @retval 0 Success
  int32_t Notify(void);
  
  /// @biref Notify 
  /// @retval 0 Success
  int32_t NotifyAll(void);
  
};

}

#endif /* __COMMON_COND_H_DEFINED__ */
