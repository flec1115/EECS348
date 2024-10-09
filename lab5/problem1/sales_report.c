#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LINES 12
#define MAX_LEN 100

void print_monthly(float sales[12], char months[12][MAX_LEN]){

}

void print_summary(float sales[12], char months[12][MAX_LEN]){

}

void six_month_avg(float sales[12], char months[12][MAX_LEN]){

}

void print_reprot(float sales[12], char months[12][MAX_LEN]){

}

int main(){
  FILE* fptr;
  char monthly_sales[MAX_LINES][MAX_LEN];
  float real_sales[12];
  char months[12][MAX_LEN] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "Octoberr", "November", "December"};

  fptr = fopen("sales.txt", "r");

  if (fptr == NULL) {
    printf("Error opening file.\n");
    return 1;
  }

  int line = 0; 

  while (!feof(fptr) && !ferror(fptr))  // while loop contiunous while not the end of line and no errors
    if (fgets(monthly_sales[line], MAX_LEN, fptr) != NULL) //apends lines to list 
      line++;  // increments lines 
  fclose(fptr);  //close files

  for (int i = 0; i < line; i++){
    real_sales[i] = atof(monthly_sales[i]);
    printf("%.2f\n", real_sales[i]);
  }
  
  return 0;

}

