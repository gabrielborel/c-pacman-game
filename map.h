#define PACMAN_CHARACTER '@'
#define GHOST_CHARACTER 'F'
#define EMPTY '.'
#define VERTICAL_WALL '|'
#define HORIZONTAL_WALL '-'

struct map
{
	char **matrix;
	int lines, columns;
};

typedef struct map GAME_MAP;

struct position
{
	int x;
	int y;
};

typedef struct position MAP_POSITION;

void read_map(GAME_MAP *game_map);
void allocate_map(GAME_MAP *game_map);
void free_map(GAME_MAP *game_map);
void print_map(GAME_MAP *game_map);
void find_on_map(GAME_MAP *game_map, MAP_POSITION *pacman_position, char find_char);
int is_valid_map_position(GAME_MAP *game_map, int x, int y);
int is_empty_map_position(GAME_MAP *game_map, int x, int y);
void move_on_map(GAME_MAP *game_map, int from_x, int from_y, int to_x, int to_y);
void copy_map(GAME_MAP *toMap, GAME_MAP *fromMap);
