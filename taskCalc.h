#define	STT_CALC_WAIT		0
#define STT_CALC_SUMA		1
#define STT_CALC_DIFERENCIA	2
#define STT_CALC_AGM5		3
#define STT_CALC_SEND_MSG	4
#define STT_CALC_RECEIVE_MSG	5


#define CALC_SUMA	1
#define CALC_DIFERENCIA 2
#define CALC_AGM5	3

void taskCalc_init(void);
void taskCalc_run(void);

void taskCalc_setState(int arg_state);
void taskCalc_message(int arg_opcion, float arg_num1, float arg_num2);

void taskCalc_debugModeOn(void);
void taskCalc_debugModeOff(void);
