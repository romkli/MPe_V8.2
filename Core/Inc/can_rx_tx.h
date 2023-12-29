/*
 * can_rx_tx.h
 *
 *  Created on: Dec 16, 2023
 *      Author: romkli
 */

#ifndef INC_CAN_RX_TX_H_
#define INC_CAN_RX_TX_H_

enum CAN_ADDRESS{
	SOC_OF_TOTAL_VOL_CUR 	= 0x90,			// SOC of total voltage Current
	MAX_MIN_VOL 			= 0x91,			// Maximum & Minimum voltage
	MAX_MIN_TEMP			= 0x92,			// Maximum & Minimum temperature
	CH_DISCH_MOS_S			= 0x93,			// Charge & discharge MOS status
	STA_INFO_1				= 0x94,			// Status information 1
	CELL_VOL				= 0x95,			// Cell balance State 1~48
	CELL_TEMP				= 0x96,			// Cell temperature 1~16
	CELL_BAL_ST				= 0x97,			// Cell balance State 1~48
	BAT_FAIL_ST				= 0x98,			// Battery failure status
};

typedef struct{
//	0x90
	uint8_t Cum_Tot_Vol1;					// Byte0~1:Cumulative total voltage (0.1 V)
	uint8_t Cum_Tot_Vol2;
	uint8_t Geth__Tot_Vol1;					// Byte2~3:Gather total voltage (0.1 V)
	uint8_t Geth__Tot_Vol2;
	uint8_t Current1;						// Byte4~5:Current (30000 Offset ,0.1A)
	uint8_t Current2;
	uint8_t SOC1;							// Byte6~7:SOC (0.1%)
	uint8_t SOC2;
//	0x91
	uint8_t Max_Cell_Vol1;					// Byte0~1:Maximum cell voltage value (mV)
	uint8_t Max_Cell_Vol2;
	uint8_t No_Cell_Max_Vol;				// Byte2:No of cell with Maximum voltage
	uint8_t Min_Cell_Vol1;					// Byte3~4:Minimum cell voltage value (mV)
	uint8_t Min_Cell_Vol2;
	uint8_t No_Cell_Min_Vol;				// Byte5:No of cell with Minimum voltage
											// Byte6~7 Reserved
//	0x92
	uint8_t Max_Temp;						// Byte0: Maximum temperature value (40 Offset ,°C)
	uint8_t No_Cell_Max_Temp;				// Byte1: Maximum temperature cell No
	uint8_t Min_Temp;						// Byte2: Minimum temperature value (40 Offset ,°C)
	uint8_t No_Cell_Min_Temp;				// Byte3: Minimum temperature cell No
											// Byte4~7: Reserved
//	0x93
	uint8_t State;							// Byte0:State (0 stationary 1 charge 2 discharge)
	uint8_t Charge_MOS;						// Byte1:Charge MOS state
	uint8_t Discharge_MOS;					// Byte2:Discharge MOS status
	uint8_t Cycle;							// Byte3:BMS life (0~255 cycles)
	uint8_t Remain_Capacity0;				// Byte4~Byte7:Remain capacity (mAH)
	uint8_t Remain_Capacity1;
	uint8_t Remain_Capacity2;
	uint8_t Remain_Capacity3;

//	0x94
	uint8_t No_Bat_Str;			            // Byte0: No of battery string
	uint8_t No_Temp;		                // Byte1: No of Temperature
	uint8_t Charge_Stat;	                // Byte2: Charger status (0 disconnect 1 access)
	uint8_t Load_Stat;		                // Byte3: Load status (0 disconnect 1 access)
	/*********************************************************************
	 * 				Sta_Info_4_t
	 * 				Status information 1 4th bytes
	 *********************************************************************/
	union{
		struct {
			uint8_t DI1_STATE : 1;           // BIT0: DI1_STATE
			uint8_t DI2_STATE : 1;           // BIT1: DI2_STATE
			uint8_t DI3_STATE : 1;           // BIT2: DI3_STATE
			uint8_t DI4_STATE : 1;           // BIT3: DI4_STATE
			uint8_t DO1_STATE : 1;           // BIT4: DO1_STATE
			uint8_t DO2_STATE : 1;           // BIT5: DO2_STATE
			uint8_t DO3_STATE : 1;           // BIT6: DO3_STATE
			uint8_t DO4_STATE : 1;           // BIT7: DO4_STATE
		};
		uint8_t Sta_Info_1_Rx4;
	};

//	0x95
	uint8_t Cel_Vol_Frame_No_B0;			// 16 Bytes times 2 bytes
	uint8_t Cel_Vol_Frame_No_B1;			// The voltage of each monomer is 2 byte, according to the actual number of cell, the maximum96 byte, is sent in 16 frames
	uint8_t Cel_Vol_Frame_B2;				// Byte0:frame number, starting from0,0xFF invalid Byte1~6:Cell voltage (1 mV)
	uint8_t Cel_Vol_Frame_B3;				// Byte7:
	uint8_t Cel_Vol_Frame_B4;
	uint8_t Cel_Vol_Frame_B5;
	uint8_t Cel_Vol_Frame_B6;

//	0x96
	uint8_t Cel_Temp_Frame_No_B0;			// Byte1~7:cell temperature(40 Offset ,℃)
	uint8_t Cel_Temp_Frame_B1;				// Byte 1: temperature 1
	uint8_t Cel_Temp_Frame_B2;				// Byte 1: temperature 2
	uint8_t Cel_Temp_Frame_B3;				// Byte 1: temperature 3
	uint8_t Cel_Temp_Frame_B4;				// Byte 1: temperature 4
	uint8_t Cel_Temp_Frame_B5;				// Byte 1: temperature 5
	uint8_t Cel_Temp_Frame_B6;				// Byte 1: temperature 6
	uint8_t Cel_Temp_Frame_B7;				// Byte 1: temperature 7

	/*********************************************************************
	 * 				0x97 Byte0
	 * 				Bit 0~7: Cell 1~8 balance state
	 *********************************************************************/
	union{
		struct{
			uint8_t CELL_01_BAL_ST			: 1;	// Bit 0: Cell 1 balance state
			uint8_t CELL_02_BAL_ST			: 1;	// Bit 1: Cell 2 balance state
			uint8_t CELL_03_BAL_ST			: 1;	// Bit 2: Cell 3 balance state
			uint8_t CELL_04_BAL_ST			: 1;	// Bit 3: Cell 4 balance state
			uint8_t CELL_05_BAL_ST			: 1;	// Bit 4: Cell 5 balance state
			uint8_t CELL_06_BAL_ST			: 1;	// Bit 5: Cell 6 balance state
			uint8_t CELL_07_BAL_ST			: 1;	// Bit 6: Cell 7 balance state
			uint8_t CELL_08_BAL_ST			: 1;	// Bit 7: Cell 8 balance state
		};
		uint8_t Cel_Bal_St_B0;
	};

	/*********************************************************************
	 * 				0x97 Byte1
	 * 				Bit 0~7: Cell 9~16 balance state
	 *********************************************************************/
	union{
		struct{										//
			uint8_t CELL_09_BAL_ST			: 1;	// Bit 0: Cell 9 balance state
			uint8_t CELL_10_BAL_ST			: 1;	// Bit 1: Cell 10 balance state
			uint8_t CELL_11_BAL_ST			: 1;	// Bit 2: Cell 11 balance state
			uint8_t CELL_12_BAL_ST			: 1;	// Bit 3: Cell 12 balance state
			uint8_t CELL_13_BAL_ST			: 1;	// Bit 4: Cell 13 balance state
			uint8_t CELL_14_BAL_ST			: 1;	// Bit 5: Cell 14 balance state
			uint8_t CELL_15_BAL_ST			: 1;	// Bit 6: Cell 15 balance state
			uint8_t CELL_16_BAL_ST			: 1;	// Bit 7: Cell 16 balance state
		};
		uint8_t Cel_Bal_St_B1;
	};

	/*********************************************************************
	 * 				0x97 Byte2
	 * 				Bit 0~7: Cell 17~24 balance state
	 *********************************************************************/
	union{
		struct{
			uint8_t CELL_17_BAL_ST			: 1;	// Bit 0: Cell 17 balance state
			uint8_t CELL_18_BAL_ST			: 1;	// Bit 1: Cell 18 balance state
			uint8_t CELL_19_BAL_ST			: 1;	// Bit 2: Cell 19 balance state
			uint8_t CELL_20_BAL_ST			: 1;	// Bit 3: Cell 20 balance state
			uint8_t CELL_21_BAL_ST			: 1;	// Bit 4: Cell 21 balance state
			uint8_t CELL_22_BAL_ST			: 1;	// Bit 5: Cell 22 balance state
			uint8_t CELL_23_BAL_ST			: 1;	// Bit 6: Cell 23 balance state
			uint8_t CELL_24_BAL_ST			: 1;	// Bit 7: Cell 24 balance state
		};
		uint8_t Cel_Bal_St_B2;
	};

	/*********************************************************************
	 * 				0x97 Byte3
	 * 				Bit 0~7: Cell 1~8 balance state
	 *********************************************************************/
	union{
		struct{
			uint8_t CELL_25_BAL_ST			: 1;	// Bit 0: Cell 25 balance state
			uint8_t CELL_26_BAL_ST			: 1;	// Bit 1: Cell 26 balance state
			uint8_t CELL_27_BAL_ST			: 1;	// Bit 2: Cell 27 balance state
			uint8_t CELL_28_BAL_ST			: 1;	// Bit 3: Cell 28 balance state
			uint8_t CELL_29_BAL_ST			: 1;	// Bit 4: Cell 29 balance state
			uint8_t CELL_30_BAL_ST			: 1;	// Bit 5: Cell 30 balance state
			uint8_t CELL_31_BAL_ST			: 1;	// Bit 6: Cell 31 balance state
			uint8_t CELL_32_BAL_ST			: 1;	// Bit 7: Cell 32 balance state
		};
		uint8_t Cel_Bal_St_B3;
	};

	/*********************************************************************
	 * 				0x97 Byte4
	 * 				Battery failure status 0 byte
	 *********************************************************************/
	union{
		struct{										// Bit 0~7: Cell 1~8 balance state
			uint8_t CELL_33_BAL_ST			: 1;	// Bit 0: Cell 33 balance state
			uint8_t CELL_34_BAL_ST			: 1;	// Bit 1: Cell 34 balance state
			uint8_t CELL_35_BAL_ST			: 1;	// Bit 2: Cell 35 balance state
			uint8_t CELL_36_BAL_ST			: 1;	// Bit 3: Cell 36 balance state
			uint8_t CELL_37_BAL_ST			: 1;	// Bit 4: Cell 37 balance state
			uint8_t CELL_38_BAL_ST			: 1;	// Bit 5: Cell 38 balance state
			uint8_t CELL_39_BAL_ST			: 1;	// Bit 6: Cell 39 balance state
			uint8_t CELL_40_BAL_ST			: 1;	// Bit 7: Cell 40 balance state
		};
		uint8_t Cel_Bal_St_B4;
	};

	/*********************************************************************
	 * 				0x97 Byte5
	 * 				Bit 0~7: Cell 1~8 balance state
	 *********************************************************************/
	union{
		struct{
			uint8_t CELL_41_BAL_ST			: 1;	// Bit 0: Cell 41 balance state
			uint8_t CELL_42_BAL_ST			: 1;	// Bit 1: Cell 42 balance state
			uint8_t CELL_43_BAL_ST			: 1;	// Bit 2: Cell 43 balance state
			uint8_t CELL_44_BAL_ST			: 1;	// Bit 3: Cell 44 balance state
			uint8_t CELL_45_BAL_ST			: 1;	// Bit 4: Cell 45 balance state
			uint8_t CELL_46_BAL_ST			: 1;	// Bit 5: Cell 46 balance state
			uint8_t CELL_47_BAL_ST			: 1;	// Bit 6: Cell 47 balance state
			uint8_t CELL_48_BAL_ST			: 1;	// Bit 7: Cell 48 balance state
		};
		uint8_t Cel_Bal_St_B5;
	};



//	0x98
	/*********************************************************************
	 * 				0x98 Byte0
	 * 				Battery failure status 0 byte
	 *********************************************************************/
	union{
	    struct{
	    	uint8_t CELL_VOL_HI_LEVEL1			: 1;	// Bit 0: Cell volt high level 1
	    	uint8_t CELL_VOL_HI_LEVEL2			: 1;	// Bit 1: Cell volt high level 2
	    	uint8_t CELL_VOL_LO_LEVEL1			: 1;	// Bit 2: Cell volt low level 1
	    	uint8_t CELL_VOL_LO_LEVEL2			: 1;	// Bit 3: Cell volt low level 2
	    	uint8_t SUM_VOL_HI_LEVEL1			: 1;	// Bit 4: Sum volt high level 1
	    	uint8_t SUM_VOL_HI_LEVEL2			: 1;	// Bit 5: Sum volt high level 2
	    	uint8_t SUM_VOL_LO_LEVEL1			: 1;	// Bit 6: Sum volt low level 1
	    	uint8_t SUM_VOL_LO_LEVEL2			: 1;	// Bit 7: Sum volt low level 2
	    };
	    uint8_t Bat_Fail_St_B0;
	};
	/*********************************************************************
	 * 				0x98 Byte1
	 * 				Battery failure status 1st byte
	 *********************************************************************/
	union{
	    struct{
	    	uint8_t CH_TEMP_HI_LEVEL1 				: 1;	// Bit 0: Chg temp high level 1
	    	uint8_t CH_TEMP_HI_LEVEL2 				: 1;	// Bit 1: Chg temp high level 2
	    	uint8_t CH_TEMP_LO_LEVEL1				: 1;	// Bit 2: Chg temp low level 1
	    	uint8_t CH_TEMP_LO_LEVEL2				: 1;	// Bit 3: Chg temp low level 2
	    	uint8_t DISCH_TEMP_HI_LEVEL1			: 1;	// Bit 4: Dischg temp high level 1
	    	uint8_t DISCH_TEMP_HI_LEVEL2			: 1;	// Bit 5: Dischg temp high level 2
			uint8_t DISCH_TEMP_LO_LEVEL1			: 1;	// Bit 6: Dischg temp low level 1
			uint8_t DISCH_TEMP_LO_LEVEL2			: 1;	// Bit 7: Dischg temp low level 2
	    };
	    uint8_t Bat_Fail_St_B1;
	};
	/*********************************************************************
	 * 				0x98 Byte2
	 * 				Battery failure status 2nd byte
	 *********************************************************************/
	union{
	    struct{
	    	uint8_t CH_OVERCUR_LEVEL1 				: 1;	// Bit 0: Chg overcurrent level 1
	    	uint8_t CH_OVERCUR_LEVEL2 				: 1;	// Bit 1: Chg overcurrent level 2
	    	uint8_t DISCH_OVERCUR_LEVEL1			: 1;	// Bit 2: Dischg overcurrent level 1
	    	uint8_t DISCH_OVERCUR_LEVEL2			: 1;	// Bit 3: Dischg overcurrent level 2
	    	uint8_t SOC_HI_LEVEL1					: 1;	// Bit 4: SOC high level 1
	    	uint8_t SOC_HI_LEVEL2					: 1;	// Bit 4: SOC high level 2
	    	uint8_t SOC_LO_LEVEL1					: 1;	// Bit 4: SOC low level 1
	    	uint8_t SOC_LO_LEVEL2					: 1;	// Bit 4: SOC low level 2
	    };
	    uint8_t Bat_Fail_St_B2;
	};
	/*********************************************************************
	 * 				0x98 Byte3
	 * 				Battery failure status 3rd byte
	 *********************************************************************/
	union{
	    struct{
	    	uint8_t DIFF_VOL_LEVEL1 				: 1;	// Bit 0: Diff volt level 1
			uint8_t DIFF_VOL_LEVEL2 				: 1;	// Bit 1: Diff volt level 2
			uint8_t DIFF_TEMP_LEVEL1				: 1;	// Bit 2: Diff temp level 1
			uint8_t DIFF_TEMP_LEVEL2				: 1;	// Bit 3: Diff temp level 2
	    };
	    uint8_t Bat_Fail_St_B3;
	};
	/*********************************************************************
	 * 				0x98 Byte4
	 * 				Battery failure status 4th byte
	 *********************************************************************/
	union{
	    struct{
	    	uint8_t CH_MOS_TEMP_HI_ALARM			: 1;	// Bit 0: Chg MOS temp high alarmBit
	    	uint8_t DISCH_MOS_TEMP_HI_ALARM 		: 1;	// Bit 1: Dischg MOS temp high alarm
	    	uint8_t CH_MOS_TEMP_SENSOR_ERR			: 1;	// Bit 2: Chg MOS temp sensor err
	    	uint8_t DISCH_MOS_TEMP_SENSOR_ERR		: 1;	// Bit 3: Dischg MOS temp sensor err
	    	uint8_t CH_MOS_TEMP_ADHESION_ERR		: 1;	// Bit 4: Chg MOS adhesion err
	    	uint8_t DISCH_MOS_TEMP_ADHESION_ERR		: 1;	// Bit 5: Dischg MOS adhesion err
	    	uint8_t CH_MOS_TEMP_CIRCUIT_ERR			: 1;	// Bit 6: Chg MOS open circuit err
	    	uint8_t DISCH_MOS_TEMP_CIRCUIT_ERR		: 1;	// Bit 7: Discrg MOS open circuit err
	    };
	    uint8_t Bat_Fail_St_B4;
	};
	/*********************************************************************
	 * 				0x98 Byte5
	 * 				Battery failure status 5 byte
	 *********************************************************************/
	union{
	    struct{
	    	uint8_t AFE_COL_CHIP_ERR				: 1;	// Bit 0: AFE collect chip err
	    	uint8_t VOLTAGE_COL_DROPPED		 		: 1;	// Bit 1: Voltage collect dropped
	    	uint8_t CELL_TEMP_SENSOR_ERR			: 1;	// Bit 2: Cell temp sensor err
	    	uint8_t EPPROM_ERR						: 1;	// Bit 3: EEPROM err
	    	uint8_t RTC_ERR							: 1;	// Bit 4: RTC err
	    	uint8_t PRECHARGE_FAILURE				: 1;	// Bit 5: Precharge failure
	    	uint8_t COMMUNICATION_FAILURE			: 1;	// Bit 6: Communication failure
	    	uint8_t INTERNAL_COMMUNICATION_FAILURE	: 1;	// Bit 7: Internal communication failure
	    };
	    uint8_t Bat_Fail_St_B5;
	};
	/*********************************************************************
	 * 				0x98 Byte6
	 * 				Battery failure status 6th byte
	 *********************************************************************/
	union{
	    struct{
	    	uint8_t CUR_MODULE_FAULT 				: 1;	// Bit 0: Current module fault
			uint8_t SUM_VOL_DETECT_FAULT			: 1;	// Bit 1: Sum voltage detect fault
			uint8_t SHORT_CIRCUIT_PROTECT_FAILT		: 1;	// Bit 2: Short circuit protect fault
			uint8_t LO_VOL_FORBIDDEN_CH_FAULT		: 1;	// Bit 3: Low volt forbidden chg fault
	    };
	    uint8_t Bat_Fail_St_B6;
	};
}CAN_DALY_DATA_T;



void HAL_CAN_RxFifo1MsgPendingCallback(CAN_HandleTypeDef *hcan);
void config_can(void);
void can_check(void);
#endif /* INC_CAN_RX_TX_H_ */
