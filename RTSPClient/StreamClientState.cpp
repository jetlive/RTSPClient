#include "StdAfx.h"
#include "StreamClientState.h"



// Implementation of "StreamClientState":

CStreamClientState::CStreamClientState(void) : iter(NULL), session(NULL), subsession(NULL), streamTimerTask(NULL), duration(0.0) 
{
}

CStreamClientState::~CStreamClientState(void)
{
	delete iter;
	if (session != NULL) {
		// We also need to delete "session", and unschedule "streamTimerTask" (if set)
		UsageEnvironment& env = session->envir(); // alias

		env.taskScheduler().unscheduleDelayedTask(streamTimerTask);
		Medium::close(session);
	}
}
