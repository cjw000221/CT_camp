#include <stdio.h>
/*
**Construct FSM with C programming**
You know the current state, current input val
If your fsm accept the state you should set your value result 1, if not 0
Watch out the type of variables
*/


int c_state = 0;

void set_state()
{
	c_state = 0;
}
//printf("State: %d\n", state);
typedef struct {
	int when_0;
	int when_1;
} MyFunction;


bool fsm_skeleton(char current)
{
	static MyFunction arr[4] = { {1, 2}, {3, 0}, {0, 3}, {3, 3} }; // s(f, # of 0 == # of 1) , q1 (# of 0 - # of 1 = 1), q2(# of 0 - # of 1 = -1), fail

	if (current == '0')
		c_state = arr[c_state].when_0;
	else if (current == '1')
		c_state = arr[c_state].when_1;
	else
		return false; // 0, 1�� �ƴ� ��ǲ

	if (c_state == 0)
		return true;
	else
		return false;
}