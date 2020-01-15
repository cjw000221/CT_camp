#pragma once

#ifndef dfa_header
#define dfa_header

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool fsm_skeleton(char current);
void set_state();
int choose_test();
int test_fsm(int number);
void problem_1(bool *test);
void problem_2(bool *test);
void problem_3(bool *test);
void problem_4(bool *test);
void problem_5(bool *test);

#endif