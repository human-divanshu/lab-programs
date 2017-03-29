#ifndef STATE
#define STATE 1

struct s {
	int j1;
	int j2;
	struct s *parent;
};

typedef struct s state;

#endif