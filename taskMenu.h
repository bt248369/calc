//#include "main.h"

// MACROS
// PROTOTIPOS
#define STT_MENU_WAIT           0
#define STT_MENU_PRINT_MENU     1
#define STT_MENU_GET_NUMBERS    2
#define STT_MENU_GET_OPTION     3
#define STT_MENU_PRINT_RESULT   4
#define STT_MENU_SEND_MSG	5
#define STT_MENU_RECEIVE_MSG	6
#define STT_MENU_PROCESS_OPTION 7
#define STT_MENU_EXIT		8

void taskMenu_init(void);
void taskMenu_run(void);

void taskMenu_setState(int arg_stt);
void taskMenu_message(float arg_resultado);

void taskMenu_debugModeOn(void);
void taskMenu_debugModeOff(void);
