#ifndef STATE
#define STATE 1

#define TRUE 1
#define FALSE 0

#define BLANK 0

struct s {
	int box[3][3];
	int cost;
	struct s *parent;
};
typedef struct s state;

#endif