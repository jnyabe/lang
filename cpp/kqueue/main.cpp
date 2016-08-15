#include <thread>
#include <sys/types.h>
#include <sys/event.h>
#include <sys/time.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "debug.h"

#define USER_EVTID_CANCEL (0)
#define USER_EVTID_EVT1   (1)
#define USER_EVTID_EVT2   (2)
#define USER_EVTID_EVT3   (3)
#define USER_DATA(val)    {val , #val}	
struct UserData
{
	int  id;
	char name[256];
};

void process(int kq)
{
	int ret = 0;
	bool isCanceled = false;
	
	struct kevent kev;
	DBGPRT("Start %s\n", __FUNCTION__);

	while(!isCanceled)
	{
		ret = kevent(kq, nullptr, 0, &kev, 1, nullptr);
		printf("Receive %d\n", ret);
		if(kev.filter == EVFILT_USER)
		{
			switch(kev.ident)
			{
			case USER_EVTID_CANCEL:
				isCanceled = true;
				break;
			default:
				printf("kev.ident:  %lu\n", kev.ident);
				printf("kev.filter: %d\n", kev.filter);
				printf("kev.flags:  %u\n", kev.flags);
				printf("kev.fflags: %u\n", kev.fflags);
				printf("kev.data:   %ld\n", kev.data);
				printf("kev.udata:  %p\n", kev.udata);
				break;
			}
		}
	}
	
	DBGPRT("END %s\n", __FUNCTION__);
}

int sendEvent(const char* line, int kq)
{
	int ret = 0;
	struct kevent kev;
	memset(&kev, 0 ,sizeof(kev));

	UserData userData[4] =
		{
			USER_DATA(USER_EVTID_CANCEL),
			USER_DATA(USER_EVTID_EVT1),
			USER_DATA(USER_EVTID_EVT2),
			USER_DATA(USER_EVTID_EVT3),						
		};
	
	if(!strcmp(line, "cancel"))
	{
		DBGPRT("SEND USER_EVTID_CANCEL\n");
		EV_SET(&kev, USER_EVTID_CANCEL, EVFILT_USER, 0, NOTE_TRIGGER, 0
			   , &userData[0]);
	} else if(!strcmp(line, "1")) {
		DBGPRT("SEND USER_EVTID_EVT1\n");
		EV_SET(&kev, USER_EVTID_EVT1, EVFILT_USER, 0, NOTE_TRIGGER, 0
			   , &userData[1]);
	} else if(!strcmp(line, "2")) {
		DBGPRT("SEND USER_EVTID_EVT2\n");
		EV_SET(&kev, USER_EVTID_EVT2, EVFILT_USER, 0, NOTE_TRIGGER, 0
			   , &userData[2]);
	}else if(!strcmp(line, "3")) {
		DBGPRT("SEND USER_EVTID_EVT3\n");
		EV_SET(&kev, USER_EVTID_EVT3, EVFILT_USER, 0, NOTE_TRIGGER, 0
			   , &userData[3]);
	} else 	{
		return -1;
	}
	
	ret = kevent(kq, &kev, 1, nullptr, 0, nullptr);
	DBGPRT("kevent: %#x\n", ret);
	return ret;
}

int main(int argc, const char* argv[])
{
	int ret;
	int kq = 0;
	struct kevent kev[4];
	char prompt[] = "kevent>";
	char* line = nullptr;
	kq = kqueue();
	if(kq == -1)
	{
		return -1;
	}

	EV_SET(&kev[0], USER_EVTID_CANCEL, EVFILT_USER, EV_ADD|EV_CLEAR, 0, 0, 0);
	EV_SET(&kev[1], USER_EVTID_EVT1,   EVFILT_USER, EV_ADD|EV_CLEAR, 0, 0, 0);
	EV_SET(&kev[2], USER_EVTID_EVT2,   EVFILT_USER, EV_ADD|EV_CLEAR, 0, 0, 0);
	EV_SET(&kev[3], USER_EVTID_EVT3,   EVFILT_USER, EV_ADD|EV_CLEAR, 0, 0, 0);

	ret = kevent(kq, kev, 4, nullptr, 0, nullptr);
	{
		std::thread listener(process, kq);
		while((line = readline(prompt))!=nullptr)
		{
			sendEvent(line, kq);
			add_history(line);
		}
		listener.join();
	}

	return 0;
}
