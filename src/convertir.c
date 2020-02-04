#include <stdio.h>
#include "convertir.h"

void dollar_euro(double dollar) {
  printf("\t%.4lf dollars = %.4lf euros\n", dollar,
	 dollar / TAUX);
}

void euro_dollar(double euro) {
  printf("\t%.4lf euros = %.4lf dollars\n", euro,
	 euro * TAUX);
} 
