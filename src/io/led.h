#ifndef PROJECT_LED_H
#define PROJECT_LED_H

/*  enable clock and Adv. High-Speed Bus for GPIOF  */
void INIT_LED(void);


// Switch LEDs functions
void Switch_LED_RED(void);
void Switch_LED_BLUE(void);
void Switch_LED_GREEN(void);


/*  Reset Function for all LEDs  */
void Reset_LED(void);


#endif //PROJECT_LED_H

