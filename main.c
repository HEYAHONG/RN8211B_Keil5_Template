#include "RN8211.h"
#include "FreeRTOS.h"
#include "task.h"

/*
��������
*/
void vApplicationIdleHook( void )
{
  //ι��
  WDT->EN=0xBB;
}

void main_task1(void *arg)
{
 
  while(1)
  {
    vTaskDelay(5);
  }
}

void main_task2(void *arg)
{
 
  while(1)
  {
     vTaskDelay(5);
  }
}

int main()
{
  
  /*��������*/
  xTaskCreate( main_task1, "main_task1",128, NULL, 1, NULL );
  xTaskCreate( main_task2, "main_task2",128, NULL, 1, NULL );
  
  /* Start the scheduler so the tasks start executing. */
  vTaskStartScheduler();
  while(1);//һ�㲻�ᵽ����
}

