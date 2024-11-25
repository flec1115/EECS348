#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LINES 12  //definitions for max line and len, global use
#define MAX_LEN 100

void print_monthly(float sales[12], char months[12][MAX_LEN]){
  printf("%-10s %6s\n", "Month", "Sales");
  for (int i = 0; i < 12; i++){
    printf("%-10s%10.2f\n", months[i], sales[i]);  //prints all months in order formatted  
  }
}

void print_summary(float sales[12], char months[12][MAX_LEN]){
  float max = sales[0];
  float min = sales[0];
  int max_index = 0;
  int min_index = 0;
  int i;
  float avg = 0;

  printf("\nSales Summary Report:");

  for (i=0; i<12; i++){  
    if(sales[i] > max){  //king of hill, if sales[i] is bigger than max, max is sales[i]
      max = sales[i];
      max_index = i;
    }
    if(sales[i] < min){  //same but min
      min = sales[i];
      min_index = i;
    }
  }
  for (int j=0; j<12; j++){ 
    avg = avg + sales[j];
  }
  avg = avg/12;
  
  printf("\n%-5s $%5.2f (%7s)\n%-5s $%5.2f (%7s)\n%-5s $%5.2f\n", "Minimum Sales: ", min, months[min_index], "Maximum Sales: ", max, months[max_index], "Average Sales: ", avg);  //long format stuff
}

void six_month_avg(float sales[12], char months[12][MAX_LEN], int start){ //recursive function, start is the starting index
  if (start == 0){
    printf("\nSix-Month moving average report:\n");  //if program just started, print the header
  }
  float six_avg = 0;
  if(start < 7){    //if the start is less than 7, add up all until 6 month and average
    for (int i=start; i<start+6; i++){
      six_avg = six_avg + sales[i]; 
    }
    six_avg = six_avg/6;
    printf("%-10s-%-10s %.2f\n", months[start], months[start+5], six_avg);
    six_month_avg(sales, months, start + 1);
  }else{
    return;  //once start is greater than 7, reutrns 
  }
}

void print_report(float sales[12], char months[12][MAX_LEN], int counter){
  int i;
  int max_index;
  float max = sales[0];

  if (counter == 11){   //another recrusive function, base case to end at last month
    return;
  }
  else{
    if (counter == 0){
      printf("\nSales Report:\n");  //prints header at start
    }
    for (i = 1; i<12; i++){
      if (sales[i]>max){
	max = sales[i];
	max_index = i; 
      }
    }
  }
  printf("%-10s %10.2f\n", months[max_index], max);
  sales[max_index] = 0;
  print_report(sales, months, counter +1);
}

int main(){
  FILE* fptr;
  char monthly_sales[MAX_LINES][MAX_LEN];  //array for monthly sale numbers
  float real_sales[12];
  char months[12][MAX_LEN] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
  int start = 0;

  fptr = fopen("sales.txt", "r");   //opens file

  if (fptr == NULL) {
    printf("Error opening file.\n"); //error pervention
    return 1;
  }

  int line = 0; 

  while (!feof(fptr) && !ferror(fptr))  // while loop contiunous while not the end of line and no errors
    if (fgets(monthly_sales[line], MAX_LEN, fptr) != NULL) //apends lines to list 
      line++;  // increments lines 
  fclose(fptr);  //close files

  for (int i = 0; i < line; i++){
    real_sales[i] = atof(monthly_sales[i]);
  }

  print_monthly(real_sales, months);  //calling functions
  print_summary(real_sales, months);
  six_month_avg(real_sales, months, start);
  print_report(real_sales, months, start);
  
  return 0;

}

  

