#include "fsm_header.h"

int choose_test()
{
	int number;
	printf("----------------------------------------\n");
	printf("Construct DFA with C programming\n");
	printf("----------------------------------------\n");
	printf("Choose the problem number: ");
	scanf("%d", &number);
	printf("\n");
	printf("Problem %d: ", number);
	switch (number)
	{
	case 1: 
		printf("Construct DFA which accepts binary string 01101\n");
		break;
	case 2:
		printf("Construct DFA which has the language L={w | w not containing 11}\n");
		break;
	case 3:
		printf("Construct DFA which accepts binary number divided by 3\n");
		break;
	case 4:
		printf("Construct DFA which accepts binary string whose prefix or suffix is 01\n");
		break;
	case 5:
		printf("Let L be the set of all strings with an equal number of 0��s and 1��s such that no prefix has two more 0��s than 1��s nor two more 1��s than 0��s\n");
		break;
	default: break;
	}
	return number;
}

int test_fsm(int number)
{
	FILE* test_case;
	switch (number)
	{
	case 1: 
		test_case = fopen("problem1.txt", "r");
		break;
	case 2:
		test_case = fopen("problem2.txt", "r");
		break;
	case 3:
		test_case = fopen("problem3.txt", "r");
		break;
	case 4:
		test_case = fopen("problem4.txt", "r");
		break;
	case 5:
		test_case = fopen("problem5.txt", "r");
		break;
	default:
		break;
	}

	char current[100] = {};
	char input[100] = {};
	bool test[100] = {};

	int num = 0;
	bool result = 0;
	int index;

	while (!feof(test_case))
	{
		index = 0;
		set_state();

		fgets(current, 100, test_case);
		while (current[index] != NULL)
		{
			index++;
		}
		for (int i = 0; i < index-1; i++)
		{
			result = fsm_skeleton(current[i]);
			input[i] = current[i];
			current[i] = NULL;
		}

		printf("%s: ", input);
		if (result == 1)
		{
			test[num] = result;
			num++;
			printf("Accept\n");
		}
		else if (result == 0)
		{
			test[num] = result;
			num++;
			printf("Reject\n");
		}
	}

	switch (number)
	{
	case 1:
		problem_1(test);
		break;
	case 2:
		problem_2(test);
		break;
	case 3:
		problem_3(test);
		break;
	case 4:
		problem_4(test);
		break;
	case 5:
		problem_5(test);
		break;
	default:
		break;
	}

	return 0;
}

void problem_1(bool *test)
{
	int num = 0;
	bool testcase_1[11] = { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	for (int i = 0; i < 10; i++)
	{
		if (test[i] == testcase_1[i])
		{
			num++;
		}
	}
	if (num == 10)
	{
		printf("10/10 This DFA accept the grammer \n\n");
	}
	else
	{
		printf("%d/10 Try again! This DFA is not correct \n\n", num);
	}
}

void problem_2(bool *test)
{
	int num = 0;
	bool testcase_2[21] = { 1, 1, 1, 1, 1, 0, 0, 0, 1, 0, 1, 0, 1, 1, 0, 0, 0, 1 , 1, 1 };
	for (int i = 0; i < 20; i++)
	{
		if (test[i] == testcase_2[i])
		{
			num++;
		}
	}
	if (num == 20)
	{
		printf("20/20 This DFA accept the grammer \n\n");
	}
	else
	{
		printf("%d/20 Try again! This DFA is not correct \n\n", num);
	}
}

void problem_3(bool *test)
{
	int num = 0;
	bool testcase_3[11] = { 0, 1, 1, 1, 0, 0, 0, 0, 0, 1};
	for (int i = 0; i < 10; i++)
	{
		if (test[i] == testcase_3[i])
		{
			num++;
		}
	}
	if (num == 10)
	{
		printf("10/10 This DFA accept the grammer \n\n");
	}
	else
	{
		printf("%d/10 Try again! This DFA is not correct \n\n", num);
	}
}

void problem_4(bool *test)
{
	int num = 0;
	bool testcase_4[21] = { 1, 1, 1, 0, 0, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 1, 0, 1};
	for (int i = 0; i < 20; i++)
	{
		if (test[i] == testcase_4[i])
		{
			num++;
		}
	}
	if (num == 20)
	{
		printf("20/20 This DFA accept the grammer \n\n");
	}
	else
	{
		printf("%d/20 Try again! This DFA is not correct \n\n", num);
	}
}

void problem_5(bool *test)
{
	int num = 0;
	bool testcase_5[11] = { 0, 1, 1, 0, 0, 0, 0, 0, 0, 0 };
	for (int i = 0; i < 10; i++)
	{
		if (test[i] == testcase_5[i])
		{
			num++;
		}
	}
	if (num == 10)
	{
		printf("10/10 This DFA accept the grammer \n\n");
	}
	else
	{
		printf("%d/10 Try again! This DFA is not correct \n\n", num);
	}
}

int main()
{
	int test_num;
	test_num = choose_test();
	test_fsm(test_num);
	return 0;
}