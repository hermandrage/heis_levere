void read_command_button(void);//checks if the the comand buttons are pressed, and adds the order to que if it doesn't already exsist
void read_up_and_down_buttons(void);//checks if the the UP and Down buttons are pressed, and adds the order to que if it doesn't already exsist
void read_stop_button(void);//Checks if stop button is pressed, if pressed: Empty que, illuminate stop button and send to state STOPPED. Program doesn't take innput while pressed.
void read_all_buttons(void);//calls the odder read-button-functions
