/* Matin-Moezi 9512058                                              */
/* ---------------------------------------------------------------- */
/* MONITOR  readers_writers_m.h                                     */
/*    This monitor provides the following procedures for a data:    */
/*    (1)  Init()        - initialize the data                      */
/*    (2)  Read()        - read the data                            */
/*    (3)  Write()       - update the data                          */
/* To establish mutual exclusion, a mutex lock is used.             */
/* The counter and the lock are static in this file so that they    */
/* cannot be accessed from outside of this function.                */
/*                                                                  */
/* Although several functions return the value of the counter, this */
/* returned value may not be accurate since before the retrieved    */
/* value can be returned to a thread, the counter may have already  */
/* been reset, increased or decreased.                              */
/* ---------------------------------------------------------------- */

void  Init(int  n);                     /* initialize monitor       */
int   Read(void);                       /* read the data            */
void   Write(int n);                    /* update the data          */
