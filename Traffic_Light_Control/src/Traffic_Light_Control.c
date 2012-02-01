/*
 ============================================================================
 Name        : Traffic_Light_Control.c
 Author      : Frederik Bjerg
 Version     :
 Copyright   : Your copyright notice
 Description : Control of traffic light states in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

// State definitions
enum states { RED, YELLOW, GREEN };
// Event definitions
enum events { TIMEPASSED, TIMELEFT, TICK };

int TS_State = RED;

// forward function declarations
void Do( int State );
void OnEnter( int State);
void OnExit( int State);
void TurnstileSM(int event);
//------------------------------

int main()
{	// By sending hardcoded events to the SM, it is possible to
	// simulate how it works.
    TurnstileSM( TICK );
    TurnstileSM( TIMEPASSED );
    TurnstileSM( TIMELEFT );
    TurnstileSM( TIMEPASSED );

    int t;
    for (t=0; t<5; t++) TurnstileSM( TICK );

    /* In an actual system it would look more like this:
     *
     * while (1)
     * {
     * 		event = Input();
     * 		TurnstileSM( event );
     * }
     *
     */
    return 0;
}


/* The SM does not know anything about the system. This way it can be tested on a
 * different C compiler very easily.
 */
void TurnstileSM( int event )
{
    int NextState = TS_State;
    static int TicksCount = 0;

    switch( TS_State )
    {
        case RED:
            switch (event )
            {
                case TIMEPASSED:
                    NextState = YELLOW;
                    break;
                default:
                    break;
            }
            break;
        case YELLOW:
            switch (event )
            {
                case TIMELEFT:
                    NextState = RED;
                    break;
                case TICK:
                	TicksCount++;
                	if (TicksCount > 4)
                	{
                		NextState = RED;
                		TicksCount = 0;
                	}
                	break;
                default:
                    break;
            }
            break;
        default:
            break;
            // The program should never get here !
    }

    if (NextState != TS_State)
    {
        OnExit(TS_State);
        OnEnter(NextState);
        TS_State = NextState;
    }

    Do( TS_State );
}

/* The 3 functions OnEnter, OnExit and Do are were all the fun happens.
 * Theee functions are written specifically for this system, and must be replaced
 * if the SM is used somewhere else - say on an embedded system.
 *
 * For simulating the SM a bunch of printf statements should be put here.
 */
void OnEnter( int State )
{

}

void OnExit( int State)
{

}

void Do( int State)
{
    switch (State)
    {
        case RED:
            printf("Door is Locked!\n");
            break;
        case YELLOW:
            printf("Door is unlocked.\n");
            break;
    }
}
