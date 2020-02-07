#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include "CuTest.h"

char *StrToUpper (char *str){
  return str;
}

void PremierTestPourJouerAvecFrameworkCuTest (CuTest * tc){
  char *input = strdup ("hello world");
  char *actual = StrToUpper (input);
  char *expected = "HELLO WORLD";
  CuAssertStrEquals (tc, expected, actual);
}

CuSuite *MaTestSuite (){
  CuSuite *suite = CuSuiteNew ();
  SUITE_ADD_TEST (suite, PremierTestPourJouerAvecFrameworkCuTest);
  return suite;
}



