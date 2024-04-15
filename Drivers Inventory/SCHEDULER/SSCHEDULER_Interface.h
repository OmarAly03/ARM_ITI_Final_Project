#ifndef MSCHEDULER_INTERFACE_H_
#define MSCHEDULER_INTERFACE_H_

void SCHEDULER_voidSchedulerStop(void){
	MSTK_voidDisableSTK();
}

void SCHEDULER_SchedulerCreateTask(u8 copy_u8TaskPriority, u8 copy_u32TaskPeriodicity)
{
	if(copy_u8TaskPriority > NO_OF_TASKS){

	}
}

static void SCHEDULER_SchedulerWork(void){
	u8 Local_u8counter;

	for(Local_u8counter = 0 ; Local_u8counter < NO_OF_TASKS ; Local_u8counter++){
		if(TASKS_ARR[Local_u8counter].TaskFirstDelay == 0){
			if(TASKS_ARR[Local_u8counter].pf != NULL){
				TASKS_ARR[Local_u8counter].pf();
			}
			TASKS_ARR[Local_u8counter].TaskFirstDelay = TASKS_ARR[Local_u8counter].TaskPeriodicityDelay - 1
			else{
				/* Do Nothing */
			}
		}
	}
}





#endif /* MSCHEDULER_INTERFACE_H_ */
