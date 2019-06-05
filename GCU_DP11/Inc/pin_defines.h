#ifndef PINDEF_INCLUDE
#define PINDEF_INCLUDE

#include "main.h"
//se il nome del pin e della define coincidono, commentare la riga della define
//(segnandosi per� che il nome � uguale)

//Definizione pin per GearMotor
#define GPIO_GEAR_MOTOR GPIOE
#define GPIO_GEAR_MOTOR_B GPIOE //provvisorio
#define GEAR_MOTOR_IN1 GEAR_MOTOR_IN1_Pin
#define GEAR_MOTOR_IN2 GEAR_MOTOR_IN2_Pin
#define GEAR_MOTOR_INHIBIT GEAR_MOTOR_INHIBIT_Pin

//Definizione pin per EFI
#define EFI_UPCUT_GPIO_PORT   EFI_COM_1_GPIO_Port
#define EFI_RPM_LIMITER_GPIO_PORT EFI_COM_3_GPIO_Port
#define EFI_UPCUT_Pin   EFI_COM_1_Pin
#define EFI_RPM_LIMITER_Pin EFI_COM_3_Pin
#define EFI_MAP_GPIO_Port EFI_COM_2_GPIO_Port
#define EFI_MAP_Pin	EFI_COM_2_Pin
//Definizione pin per livello olio
//#define L_OIL_GPIO_Port L_OIL_GPIO_Port
//#define L_OIL_Pin       L_OIL_Pin

//Definizione pwm per clutch
#define TIM_CLUTCH_CHANNEL TIM_CHANNEL_2
#define hClutchTim htim2
#define CCR_CLUTCH CCR2

//Definizione pwm per buzzer
#define TIM_BUZZER_CHANNEL TIM_CHANNEL_4
#define hBuzzerTim htim5
#define CCR_BUZZER CCR4

//Definizione pwm per pompa benzina
#define TIM_PUMP_CHANNEL  TIM_CHANNEL_1
#define hPumpTim	htim1
#define CCR_PUMP CCR1

//Definizione pwm per stop light
#define TIM_STOP_CTRL_CHANNEL	TIM_CHANNEL_4
#define hStopTim htim1
#define CCR_STOP_CTRL	CCR4

//Definizione uart utilizzata per debug
#define huartDebug huart4

//Definizione del CAN utilizzato
#define hcan_active hcan2

//Definizione timer utilizzato per logica
#define htim_1khz htim6
#define TIM_1KHZ TIM6

//Definizione ADC per sensori
#define hadc_sensors hadc1
#define ADC_SENSORS ADC1

//Definizione i2c eeprom
#define hi2cEeprom hi2c1

//Definizione pin per KEYON
#define KEY_ON_GPIO_Port	KEY_CTRL_GPIO_Port
#define KEY_ON_Pin				KEY_CTRL_Pin
#define KEY_START_GPIO_Port STARTER_CTRL_GPIO_Port
#define KEY_START_Pin		STARTER_CTRL_Pin

//Definizione led ausiliari su scheda
#define RedLed_GPIO_Port LED_RED_GPIO_Port 
#define BlueLed_GPIO_Port LED_YELLOW_GPIO_Port
#define GreenLed_GPIO_Port LED_GREEN_GPIO_Port
#define RedLed_Pin LED_RED_Pin
#define BlueLed_Pin LED_YELLOW_Pin
#define GreenLed_Pin LED_GREEN_Pin


#endif
