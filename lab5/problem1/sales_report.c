#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LINES 12
#define MAX_LEN 100

void print_monthly(){

}

void print_summary(){

}

void six_month_avg(){

}

void print_reprot(){

}

int main(){
  FILE* fptr;
  char monthly_sales[MAX_LINES][MAX_LEN];

  fptr = fopen("sales.txt", "r");

  if (fptr == NULL) {
    printf("Error opening file.\n");
    return 1;
  }

  int line = 0; 

  while (!feof(fptr) && !ferror(fptr))
    if (fgets(monthly_sales[line], MAX_LEN, fptr) != NULL)
      line++;
  fclose(fptr);

  for (int i = 0; i < line; i++)
    printf("%s", monthly_sales[i]);
  
  return 0;

}

