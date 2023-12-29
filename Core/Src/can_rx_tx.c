/*
 * can_rx_tx.c
 *
 *  Created on: Dec 16, 2023
 *      Author: romkli
 */

#include "main.h"
#include "can.h"
#include "can_rx_tx.h"

CAN_DALY_DATA_T Can_Daly_Data;

CAN_TxHeaderTypeDef TxHeader;
CAN_RxHeaderTypeDef RxHeader;

uint8_t TxData[8];
uint8_t RxData[8];

uint32_t TxMailbox;

int datacheck = 0;

void HAL_CAN_RxFifo1MsgPendingCallback(CAN_HandleTypeDef *hcan){
	HAL_CAN_GetRxMessage(hcan, CAN_RX_FIFO1, &RxHeader, RxData);
	if (RxHeader.DLC == 2)	{
		datacheck = 1;
	}
}

void config_can(void){

		TxHeader.DLC = 2;  // data length
		TxHeader.IDE = CAN_ID_STD;
		TxHeader.RTR = CAN_RTR_DATA;
		TxHeader.StdId = 0x103;  // ID


		TxData[0] = 200;  // ms delay
		TxData[1] = 20;  // loop rep

}

void can_check(void){
	if (datacheck){			// blink the LED// blink the LED
		for (int i=0; i<RxData[1]; i++){
			HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_13);
			HAL_Delay(RxData[0]);
		}
		datacheck = 0;
		HAL_CAN_AddTxMessage(&hcan, &TxHeader, TxData, &TxMailbox);
	}
}
