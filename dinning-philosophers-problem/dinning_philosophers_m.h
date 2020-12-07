/* Matin-Moezi 9512058                                              */
/* ---------------------------------------------------------------- */
/* MONITOR  dinning_philosophers_m.h:                               */
/*    This monitor provides the following procedures for a counter: */
/*    (1)  Init()        - initialize the monitor                   */
/*    (2)  Pickup()      - pickup chopstick to eat                  */
/*    (3)  Putdown()     - putdown chopstick to think               */
/*    (4)  Test()        - test if she can eat                      */
/* To establish mutual exclusion, a mutex lock is used.             */
/* The counter and the lock are static in this file so that they    */
/* cannot be accessed from outside of this function.                */
/*                                                                  */
/* Although several functions return the value of the counter, this */
/* returned value may not be accurate since before the retrieved    */
/* value can be returned to a thread, the counter may have already  */
/* been reset, increased or decreased.                              */
/* ---------------------------------------------------------------- */

void  Init(void);                       /* initialize monitor       */
void  Pickup(int i);                    /* pickup a chopstick       */
void  Putdown(int i);                   /* putdown a chopstick      */
void  Test(int  i);                     /* test if can eat          */
