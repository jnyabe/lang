#include <assert.h>
#include "mutex.h"

using namespace common;

Mutex::Mutex(const char* name, Option option)
{
  int32_t ret = 0;
  
#ifdef USE_PTHREAD
  pthread_mutexattr_t attr;
  
  ret = pthread_mutexattr_init(&attr);
  assert(ret==0);
  
  ret = pthread_mutex_init(&m_mutex, &attr);
  assert(ret==0);
  
  if(option & Option_Recursvie)
    {
      ret = pthread_mutexattr_settype(&attr, PTHREAD_MUTEX_RECURSIVE);
      assert(ret==0);
    }
  
  ret = pthread_mutexattr_destroy(&attr);
  assert(ret==0);
#else
#error
#endif
  
}

Mutex::~Mutex()
{
  int32_t ret = 0;
#ifdef USE_PTHREAD
  ret = pthread_mutex_destroy(&m_mutex);
  assert(ret==0);
#else
#error
#endif  
}

int32_t Mutex::Lock(void)
{
  int32_t ret = 0;
#ifdef USE_PTHREAD
  ret = pthread_mutex_lock(&m_mutex);
#else
#error
#endif  
  return ret;
}

int32_t Mutex::TimedLock(uint32_t usec)
{
  int32_t ret = 0;
#ifdef USE_PTHREAD
  // TBD
  assert(ret==0);
#else
#error
#endif  
  return ret;  
}

int32_t Mutex::TryLock(void)
{
  int32_t ret = 0;
#ifdef USE_PTHREAD
  ret = pthread_mutex_trylock(&m_mutex);
#else
#error
#endif  
  return ret;  
}

int32_t Mutex::Unlock(void)
{
    int32_t ret = 0;
#ifdef USE_PTHREAD
    ret = pthread_mutex_unlock(&m_mutex);
    assert(ret==0);
#else
#error
#endif  
    return ret;
}



