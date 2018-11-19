
#ifndef BATMAN_HELPER_HELPER_METHODS_H_
#define BATMAN_HELPER_HELPER_METHODS_H_

typedef struct {
	int id;
	char direcrion;
	char right;
}BAT;

void init_monitor();
void arrive(BAT b);
void cross(BAT b);
void leave(BAT b);
void check(BAT b);
void destroy(BAT b);


#endif /* BATMAN_HELPER_HELPER_METHODS_H_ */
