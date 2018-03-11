
void set_floor_variables(void);
float get_current_floor(void);
void print_status(void);

typedef enum state_type { //all possible states for statemachine. NOTE: initialize is not a part of statemachine.
  IDLE = 0,
  DOOR_OPEN = 1,
  DRIVE_UP = 2,
  DRIVE_DOWN=3,
  STOPPED=4,
} state_t;


static state_t current_state;

void set_current_state(state_t state);// sets the variable current_floor to the correct value and emergensy_stop_already_pressed to false
void print_current_state(void);//prints the current state
void print_status(void);//prints queue, current_state, current_floor and current_direction in a ordarly way.
void run_states(void);// Runns a infinite while-loop, checking and swiching between states. 
