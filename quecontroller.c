#include "statemachine.h"
#include "elev.h"
#include "io.h"
#include "quecontroller.h"

#include <stdio.h>
#include <stdlib.h>


const int Number_of_floors=4;

const int nr_possible_orders=Number_of_floors+(2*(Number_of_floors-1));
static int que[nr_possible_orders][2];//que containing all orders. First row contains floor of order and second contains the direction of the order(given by enum ORDER_DIRECTION)

void empty_que(void){ //sets all orders to floor -1 and direction NO_ORDER
  for (int ord_nr=0; ord_nr<nr_possible_orders; ord_nr++){
    que[ord_nr][0]=-1;
    que[ord_nr][1]=NO_ORDER;
  }
}
int read_next_order(void){//reads from que what floor next order is in
  return que[0][0];

}

//both functions below returns the POTSITION of the order in que if the order is found. this is because is can be used in the delete-function when a order is finished.

//Checks if order is present (based on floor order and direction) returns the order position (in que) if present, -1 if not. DOES NOT return order_nr on ORDER_WITHOUT_DIRECTION
int check_for_order(int floor, order_dir dir){
  for (int order_nr = 0 ; order_nr < nr_possible_orders ; ++order_nr ){
    if (que[order_nr][0] == floor && que[order_nr][1] == dir){// || que[order_nr][1] == ORDER_WITHOUT_DIRECTION)
    return order_nr;
    }
  }
  return -1;
}
//checks if a order is in the direction the elev is mooving. returns the order_number if present, -1 if not. includes ORDER_WITHOUT_DIRECTION and direction sent in input
int check_if_should_stop(int floor, order_dir direction){
  if (read_next_order()==floor){
    return 0;
  }
  if (check_for_order(floor, direction)!=-1){
    return check_for_order(floor, direction);
  }
  if (check_for_order(floor, ORDER_WITHOUT_DIRECTION)!=-1){
    return check_for_order(floor, ORDER_WITHOUT_DIRECTION);
  }
  return -1;
}


void add_order_to_que(int floor,order_dir direction){//Checks if the new order already exists, if it doesn't: adds the new order last in the que. prints error-message if invalid input.
  if (floor<0){
    printf("Error:floor<0");
    return;
  }
  if (direction==NO_ORDER) {
    printf ("ERROR:NO ORDER");
    return;
  }
  if (floor>=Number_of_floors){
    printf("ERROR:floor>=Number_of_floors" );
    return;
  }
  if (check_for_order(floor,direction)!=-1){
    return;
  }
  for (int order_nr = 0 ; order_nr < nr_possible_orders ; ++ order_nr){
    if (que[order_nr][0] == -1 && que[order_nr][1]== NO_ORDER){
      que[order_nr][0] = floor;
      que[order_nr][1]=direction;
      return;
    }
  }
}

void delete_order_from_que(int order_nr){ //Deletes order from que, "leftshifts" the que and sets the last position in que to "orderless
  for(int temp_order_nr=order_nr; temp_order_nr<(nr_possible_orders-1); ++temp_order_nr){
    que[temp_order_nr][0]=que[temp_order_nr+1][0];
    que[temp_order_nr][1]=que[temp_order_nr+1][1];
  }
  que[-1][0]=-1;
  que[-1][1]=NO_ORDER;
}

void delete_orders_in_floor(int floor){//Deletes all orders in the floor from input
  int nr_order=0;
  while(que[nr_order][0]!=-1){
    if(que[nr_order][0]==floor){
      delete_order_from_que(nr_order);
    }
    nr_order++;
  }
}


void print_que(void){ // prints queue
  for (int ord_nr=0; ord_nr<nr_possible_orders; ord_nr++){
    printf("ordernr: %d", ord_nr);
    printf("   floor %d", que[ord_nr][0]);
    printf("   direction: %d", que[ord_nr][1]);
    printf("\n");
  }
}
