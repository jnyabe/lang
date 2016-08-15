#ifndef __COMMON_THREAD_H_DEFINED__
#define __COMMON_THREAD_H_DEFINED__

#include <stdint.h>
#include "config.h"

namespace common
{

class Thread
{
 private:
  
  bool m_is_canceld;
#ifdef USE_PTHREAD
  pthread_t m_thread;
#endif /* USE_PTHREAD */
  

  static void* startRoutine(void* arg);
  
 public:
  /// @brief Default Consturctor
  Thread();

  /// @brief Destructor
  virtual ~Thread();

  /// @brief Check if thread is canceled
  /// @retval true Canceled
  /// @retval fals Not Canceled
  bool IsCanceled(void);

  /// @brief Start the thread
  int32_t Start(void);

  /// @brief Thread routine
  virtual void Run(void) = 0;

  /// @brief Cancel thread
  void Cancel(void);

  /// @brief Join thread
  int32_t Join(void);

};

}

#endif /* __COMMON_THREAD_H_DEFINED__ */
