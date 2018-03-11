void start_timer(void);
void stop_timer(void);
int timer_is_timeout(void);//checks if time since "start_timer" is greater than 3 seconds. returns 1 if true, 0 if false and -1 if timer is not yet started.
