#include <stdio.h>
#include <sys/stat.h>
#include "sema.h"

#define DBGPRT(...) {  \
  fprintf(stderr, "[%s:%d] ", __FUNCTION__, __LINE__); \
  fprintf(stderr, __VA_ARGS__); \
  }

Sema::Sema(const char* name, int permits)
  : m_semaphore(0)
{
  const mode_t mode = 0777;
  m_semaphore = sem_open(name, O_CREAT, permits);

}

Sema::~Sema()
{
  sem_close(m_semaphore);
}

void Sema::Aquire(int permits)
{
  DBGPRT("Aquiret: %d\n", permits);
  
}

void Sema::Release(int permits)
{
  DBGPRT("Release: %d\n", permits);
}
