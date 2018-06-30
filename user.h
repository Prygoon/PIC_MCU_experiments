/******************************************************************************/
/* User Level #define Macros                                                  */
/******************************************************************************/

/* TODO Application specific user parameters used in user.c may go here */

/******************************************************************************/
/* User Function Prototypes                                                   */
/******************************************************************************/

/* TODO User level functions prototypes (i.e. InitApp) go here */

void InitApp(void); /* I/O and Peripheral Initialization */
bool CheckButton1(void);
bool CheckButton2(void);
bool CheckButton3(void);
bool CheckButton4(void);
void LCDstart();
void Light();
void Vibro();
void Beeper();