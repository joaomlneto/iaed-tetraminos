#include "t_location.h"

t_location* createTLocation(GameArea *gameArea, tetromino *t) {
	t_location *loc = malloc(sizeof(t_location));
	int i;
	setTLocationHashPos(loc, getTHashPos(t));
	setTLocationNumLines(loc, getLineSpan(t));
	setTLocationLines(loc, malloc(getLineSpan(t)*sizeof(Line*)));
	for(i=0; i<getLineSpan(t); i++)
		getTLocationLines(loc)[i] = getGameLine(gameArea, getPieceLine(t) - i);
	return loc;
}

int getTLocationHashPos(t_location *loc) {
	return loc->hash_pos;
}

int getTLocationNumLines(t_location *loc) {
	return loc->num_lines;
}

Line** getTLocationLines(t_location *loc) {
	return loc->lines;
}

void setTLocationHashPos(t_location *loc, int pos) {
	loc->hash_pos = pos;
	return;
}

void setTLocationNumLines(t_location *loc, int num) {
	loc->num_lines = num;
	return;
}

void setTLocationLines(t_location *loc, Line* *lines) {
	loc->lines = lines;
	return;
}


