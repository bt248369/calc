#include "taskCalc.h"
#include "taskMenu.h"
#include <stdio.h>
#include <math.h>
#include "color.h"

int taskCalc_state;
int taskCalc_debugMode;

float taskCalc_varNum1;
float taskCalc_varNum2;
float taskCalc_varResultado;

float var_tmp_AM;
float AM;
float GM;

int cnt;

void taskCalc_init()
{
	taskCalc_state = STT_CALC_WAIT;

	// Depuración
	taskCalc_debugModeOff();
}

void taskCalc_run()
{	
	switch(taskCalc_state)
	{
		case STT_CALC_WAIT:
			if (taskCalc_debugMode)
			{
				setColorBoldCyan(); 
				printf ("\nSTT_CALC_WAIT");
				resetColor();
			}
			// Sic
			break;

		case STT_CALC_SUMA:
			taskCalc_varResultado  = taskCalc_varNum1 + taskCalc_varNum2;
			
			taskCalc_state = STT_CALC_SEND_MSG;
			break;

		case STT_CALC_DIFERENCIA:
			taskCalc_varResultado  = taskCalc_varNum1 - taskCalc_varNum2;
			
			taskCalc_state = STT_CALC_SEND_MSG;
			break;

		case STT_CALC_AGM5:
			AM = taskCalc_varNum1;
			GM = taskCalc_varNum2;
 
			for(cnt = 0 ;cnt <=4 ; cnt=cnt+1)
			{
				var_tmp_AM = AM;
				
				AM = (AM + GM)/2;
				GM = sqrt (var_tmp_AM * GM);
			}
			taskCalc_varResultado = AM;
			
			taskCalc_state = STT_CALC_SEND_MSG;
			break;
		
		case STT_CALC_SEND_MSG:
			if(taskCalc_debugMode)
			{
				char* tmp_sFormat = "\nSTT_CALC_SEND_MESG float %.4f";
				setColorBoldCyan();
				printf(tmp_sFormat,taskCalc_varResultado);
				resetColor();
			}
			taskMenu_message(taskCalc_varResultado);
			
			taskCalc_state = STT_CALC_WAIT;
			break;

		default:
			setColorBoldRed();
			printf("\nSTT CALC");
			resetColor();
	}
}

void taskCalc_setState(int arg_state)
{
	taskCalc_state = arg_state;
}

void taskCalc_message(int arg_opcion, float arg_num1, float arg_num2)
{	
	if (taskCalc_debugMode)
	{
		char* tmp_sFormat = "\ntaskCalc_message(char %d, float %.4f, float %.4f)";
		setColorBoldCyan();
		printf(tmp_sFormat, arg_opcion, arg_num1, arg_num2);
		resetColor();
	}
	
	taskCalc_varNum1 = arg_num1;
	taskCalc_varNum2 = arg_num2;

	switch(arg_opcion)
		
        {
                 case CALC_SUMA:
                	 taskCalc_state = STT_CALC_SUMA;
                	 break;

                 case CALC_DIFERENCIA:
                	 taskCalc_state = STT_CALC_DIFERENCIA;
                	 break;

                 case CALC_AGM5:
                	 taskCalc_state = STT_CALC_AGM5;
                	 break;

                 default:
                	setColorBoldRed();
			printf("\ntaskCalc_message default!");
			resetColor();
                	taskCalc_state = STT_CALC_WAIT;
         }
}

void taskCalc_debugModeOn(){
	taskCalc_debugMode = 1;
}

void taskCalc_debugModeOff(){
        taskCalc_debugMode = 0;
}
