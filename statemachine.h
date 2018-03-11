
void set_floor_variables(void);
int get_current_floor(void);
void print_status(void);

typedef enum state_type { //all possible states for statemachine. NOTE: initialize is not a part of statemachine.
  IDLE = 0,
  DOOR_OPEN = 1,
  DRIVE_UP = 2,
  DRIVE_DOWN=3,
  STOPPED=4,
} state_t;


static state_t current_state;

void set_current_state(state_t state);
void print_current_state(void);
void run_states(void);
