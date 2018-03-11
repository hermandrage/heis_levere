typedef enum order_direction {
    NO_ORDER = 0,
    ORDER_UP = 1,
    ORDER_DOWN = 2,
    ORDER_WITHOUT_DIRECTION = 3
}order_dir;




void empty_que(void); //sets all orders to floor -1 and direction NO_ORDER
void print_que(void); // prints queue
int read_next_order(void);//reads from que what floor next order is in
//the twofollowing functions returns the POTSITION of the order in que if the order is found. this is because is can be used in the delete-function when a order is finished.
int check_for_order(int floor, order_dir dir);//Checks if order is present (based on floor order and direction) returns the order position (in que) if present, -1 if not. DOES NOT return order_nr on ORDER_WITHOUT_DIRECTION
int check_if_should_stop(int floor, order_dir direcion);//checks if a order is in the direction the elev is mooving. returns the order_number if present, -1 if not. includes ORDER_WITHOUT_DIRECTION and direction sent in input
void add_order_to_que(int floor,order_dir direction);//Checks if the new order already exists, if it doesn't: adds the new order last in the que. prints error-message if invalid input.
void delete_order_from_que(int order_nr);//Deletes order from que, "leftshifts" the que and sets the last position in que to "orderless
void delete_orders_in_floor(int floor);//Deletes all orders in the floor from input
