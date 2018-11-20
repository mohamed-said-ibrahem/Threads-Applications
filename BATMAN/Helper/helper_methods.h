
#ifndef BATMAN_HELPER_HELPER_METHODS_H_
#define BATMAN_HELPER_HELPER_METHODS_H_

typedef struct {
	int id;
	char direcrion;
	char right;
}BAT;

void init_monitor();
void arrive(void* bat);
void cross(void* bat);
void leave(void* bat);
void check(void* bat);
void destroy();
void run(void* bat);

#endif /* BATMAN_HELPER_HELPER_METHODS_H_ */
