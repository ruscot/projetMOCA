#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include "CuTest.h"
#include "charFunc.h"
#include "maillon.h"
#include "dataStruct.h"

char *StrToUpper (char *str){
  return str;
}

void PremierTestPourJouerAvecFrameworkCuTest (CuTest * tc){
  char *input = strdup ("hello world");
  char *actual = StrToUpper (input);
  char *expected = "HELLO WORLD";
  CuAssertStrEquals (tc, expected, actual);
}

void testIsAvailableCuTest (CuTest * tc){
	char input = 'a';
	int actual = isAvailable(input);
	int expected = 1;
	CuAssertIntEquals(tc, expected, actual);
	
	char input2 = '1';
	int actual2 = isAvailable(input2);
	int expected2 = 1;
	CuAssertIntEquals(tc, expected2, actual2);
}

void testMaillonSizeCuTest (CuTest * tc){
	maillon_t *test = NULL;
	int expected = 0;
	int actual = getSizeMaillon(test);
	CuAssertIntEquals(tc, expected, actual);
	printf("Test passé\n");

	maillon_t *test2 = malloc(sizeof(maillon_t));
	test2->next = NULL;
	test2->elem = 'a';
	int expected2 = 1;
	int actual2 = getSizeMaillon(test2);
	CuAssertIntEquals(tc, expected2, actual2);
	
}

CuSuite *MaTestSuite (){
	CuSuite *suite = CuSuiteNew ();
  	SUITE_ADD_TEST (suite, PremierTestPourJouerAvecFrameworkCuTest);
	SUITE_ADD_TEST (suite, testIsAvailableCuTest);
	SUITE_ADD_TEST (suite, testMaillonSizeCuTest);
  	return suite;
}

