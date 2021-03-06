/*
 * Application.c
 *
 *  Created on: 28.01.2012
 *      Author: Erich Styger
 */

#include "Application.h"
#include "LED1.h"
#include "LED2.h"
#include "LED3.h"
#include "LED4.h"
#include "LED5.h"
#include "LED6.h"
#include "LED7.h"
#include "LED8.h"
#include "LED9.h"
#include "WAIT1.h"
#include "FRTOS1.h"

static portTASK_FUNCTION(T1, pvParameters) {
  (void)pvParameters;
  for(;;) {
    LED2_Neg();
    FRTOS1_vTaskDelay(100/portTICK_RATE_MS);
  }
}

static portTASK_FUNCTION(MainTask, pvParameters) {
  (void)pvParameters;
  for(;;) {
    LED1_Neg();
    FRTOS1_vTaskDelay(1000/portTICK_RATE_MS);
  }
}

void APP_Run(void) {
  if (FRTOS1_xTaskCreate(MainTask, (signed portCHAR *)"Main", configMINIMAL_STACK_SIZE, NULL, tskIDLE_PRIORITY, NULL) != pdPASS) {
    for(;;){} /* error, not enough heap? */
  }
  if (FRTOS1_xTaskCreate(T1, (signed portCHAR *)"T1", configMINIMAL_STACK_SIZE, NULL, tskIDLE_PRIORITY, NULL) != pdPASS) {
    for(;;){} /* error, not enough heap? */
  }
  /* testing the LED's */
  LED1_Neg();
  LED2_Neg();
  LED3_Neg();
  LED4_Neg();
  LED5_Neg();
  LED6_Neg();
  LED7_Neg();
  LED8_Neg();
  LED9_Neg();
//    WAIT1_Waitms(1000);
  LED1_Off();
  LED2_Off();
  LED3_Off();
  LED4_Off();
  LED5_Off();
  LED6_Off();
  LED7_Off();
  LED8_Off();
  LED9_Off();
  FRTOS1_vTaskStartScheduler();
}
