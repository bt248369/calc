#include "taskMenu.h"
#include "taskCalc.h"
#include <stdio.h>
#include <stdlib.h>
#include "color.h"

int taskMenu_state;	// Variable de estado
int taskMenu_debugMode;
int taskMenu_varOpcion;

float taskMenu_varNum1;
float taskMenu_varNum2;
float taskMenu_varResultado;

void taskMenu_init(void)
{
	// Título
	setColorBoldBlue();
	printf("\n CALCULADORA MULTITAREA");
	resetColor();
	
	taskMenu_state = STT_MENU_GET_NUMBERS;

	// depuración
	taskMenu_debugModeOff();
}

void taskMenu_run(void)
{
	switch(taskMenu_state)
	{
		case STT_MENU_WAIT:
			if(taskMenu_debugMode)
			{
				setColorBoldCyan();
				printf("\nSTT_MENU_WAIT");
				resetColor();
			}
			break;
		
		case STT_MENU_PRINT_MENU:
			// Imprimir el menu
			printf("\n N1 = %.4f	N2 = %.4f",taskMenu_varNum1, taskMenu_varNum2);
			printf("\n1. Suma		2. Diferencia");
			printf("\n3. AGM5		4. Modificar números");
			printf("\n5. Salir ");
			taskMenu_state = STT_MENU_GET_OPTION;
			break;
			
		case STT_MENU_GET_NUMBERS:
			printf("\n Ingrese dos números enteros:");
			printf("\n N1 = "); scanf("%f", &taskMenu_varNum1);
			printf("\n N2 = "); scanf("%f", &taskMenu_varNum2);
			
			taskMenu_state = STT_MENU_PRINT_MENU;
			break;
			
		case STT_MENU_GET_OPTION:
			printf("\n Elija una opcion: ");
			scanf("%d", &taskMenu_varOpcion);
			
			taskMenu_state = STT_MENU_PROCESS_OPTION;

			break;
		
		case STT_MENU_PROCESS_OPTION:	
			switch(taskMenu_varOpcion)
			{
				case 1:
					taskMenu_varOpcion = CALC_SUMA;
					taskMenu_state = STT_MENU_SEND_MSG;
					break;

				case 2:
					taskMenu_varOpcion = CALC_DIFERENCIA;
					taskMenu_state = STT_MENU_SEND_MSG;
					break;
				case 3: 
					taskMenu_varOpcion = CALC_AGM5;
					taskMenu_state = STT_MENU_SEND_MSG;
					break;
				case 4:
					taskMenu_state = STT_MENU_GET_NUMBERS;
					break;
				case 5:
					taskMenu_state = STT_MENU_EXIT;
					break;
				default:
					printf("\nOpcion no valida!");
					taskMenu_state = STT_MENU_GET_OPTION;
					
			}
			break;
		
		case STT_MENU_SEND_MSG:
			if (taskMenu_debugMode)
			{
				char* tmp_sFormat = "\nSTT_MENU_SEND_MSG (char %d, float %.4f, float %.4f)";
				setColorBoldCyan();
				printf(tmp_sFormat, taskMenu_varOpcion, taskMenu_varNum1, taskMenu_varNum2);
				resetColor();
			}
			taskCalc_message(taskMenu_varOpcion,taskMenu_varNum1,taskMenu_varNum2);
			
			taskMenu_state = STT_MENU_WAIT;
			break;

		case STT_MENU_PRINT_RESULT:
			printf("\nEl resultado es %.4f", taskMenu_varResultado);
			
			taskMenu_state = STT_MENU_GET_OPTION;
			break;
		
		case STT_MENU_EXIT:
			printf("\n Nos vemos pronto...!! ¬(^0^)/  \n");
			exit(0); // EXIT
			break;
		
		default:
			printf("STT_MENU");
			taskMenu_state = STT_MENU_WAIT;
	}
}

void taskMenu_setState(int arg_stt)
{
	taskMenu_state = arg_stt;
}

void taskMenu_message(float arg_resultado)
{
	if(taskMenu_debugMode)
	{
		setColorBoldCyan();
		printf("\ntaskMenu_message(float %.4f)",arg_resultado);
		resetColor();
	}
	taskMenu_varResultado = arg_resultado;

	taskMenu_state = STT_MENU_PRINT_RESULT;
}

void taskMenu_debugModeOn(){
        taskMenu_debugMode = 1;
}

void taskMenu_debugModeOff(){
        taskMenu_debugMode = 0;
}
