#define UP_DIRECTION 'w'
#define DOWN_DIRECTION 's'
#define RIGHT_DIRECTION 'd'
#define LEFT_DIRECTION 'a'

int game_ended();
void move(char command_direction);
int is_valid_direction(char command_direcion);
void ghosts();
