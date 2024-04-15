#ifndef MSCHEDULER_PRIVATE_H_
#define MSCHEDULER_PRIVATE_H_

static void SCHEDULER_SchedulerWork(void);

typedef struct{
	void (*pf)(void);
	u32 TaskPeriodiccity;
	u32 TaskFirstDelay;
}TCB_t;


#endif /* MSCHEDULER_PRIVATE_H_ */
