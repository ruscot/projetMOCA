#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include "CuTest.h"
#include "charFunc.h"
#include "maillon.h"
#include "dataStruct.h"

void testStringToMaillonCuTest(CuTest *tc){
	char *input = strdup("intergouvernementalisations");
	maillon_t *tmp = stringToMaillon(input);
	char *actual = maillonToString(tmp);
	CuAssertStrEquals(tc, input, actual);

	char *input2 = strdup("aaaaaaaaaaaaaaaaaaa");
	maillon_t *tmp2= stringToMaillon(input2);
	char *actual2 = maillonToString(tmp2);
	CuAssertStrEquals(tc, input2, actual2);

	char *input3 = strdup("");
	maillon_t *tmp3 = stringToMaillon(input3);
	char *actual3 = maillonToString(tmp3);
	CuAssertStrEquals(tc, input3, actual3);
	
	char *input5 = strdup("a");
	maillon_t *tmp5 = stringToMaillon(input5);
	char *actual5 = maillonToString(tmp5);
	CuAssertStrEquals(tc, input5, actual5);
	

	//Les majuscules et les nombres ne sont pas pris 
	char *input6 = strdup("Aazer");
	maillon_t *tmp6 = stringToMaillon(input6);
	char *actual6 = maillonToString(tmp6);
	CuAssertStrEquals(tc, input6, actual6);

	char *input4 = strdup("testmot1111");
	maillon_t *tmp4 = stringToMaillon(input4);
	char *actual4 = maillonToString(tmp4);
	CuAssertStrEquals(tc, input4, actual4);
}

void testMaillonSizeCuTest (CuTest * tc){
	maillon_t *test = NULL;
	int expected = 0;
	int actual = getSizeMaillon(test);
	CuAssertIntEquals(tc, expected, actual);
	
	char *input = strdup("test");
	maillon_t *tmp = stringToMaillon(input);
	int expected3 = 4;
	int actual3 = getSizeMaillon(tmp);
	CuAssertIntEquals(tc, expected3, actual3);
	
	char *input2 = strdup("plusdelettre");
	maillon_t *tmp2 = stringToMaillon(input2);
	int expected4 = 12;
	int actual4 = getSizeMaillon(tmp2);
	CuAssertIntEquals(tc, expected4, actual4);

	char *input3 = strdup("a");
	maillon_t *tmp3 = stringToMaillon(input3);
	int expected5 = 1;
	int actual5 = getSizeMaillon(tmp3);
	CuAssertIntEquals(tc, expected5, actual5);

	char *input4 = strdup("");
	maillon_t *tmp4 = stringToMaillon(input4);
	int expected6 = 0;
	int actual6 = getSizeMaillon(tmp4);
	CuAssertIntEquals(tc, expected6, actual6);
}

CuSuite *MaTestSuite (){
	CuSuite *suite = CuSuiteNew ();
  	SUITE_ADD_TEST (suite, testStringToMaillonCuTest);
	SUITE_ADD_TEST (suite, testMaillonSizeCuTest);
  	return suite;
}

