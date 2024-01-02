#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "map.h"

void read_map(GAME_MAP *game_map)
{
	FILE *f;
	f = fopen("map.txt", "r");
	if (f == 0)
	{
		printf("error when reading the map");
		exit(1);
	}

	fscanf(f, "%d %d", &(game_map->lines), &(game_map->columns));
	allocate_map(game_map);

	for (int i = 0; i < game_map->lines; i++)
	{
		fscanf(f, "%s", game_map->matrix[i]);
	}

	fclose(f);
}

void free_map(GAME_MAP *game_map)
{
	for (int i = 0; i < game_map->lines; i++)
	{
		free(game_map->matrix[i]);
	}
	free(game_map->matrix);
}

void allocate_map(GAME_MAP *game_map)
{
	game_map->matrix = (char **)malloc(sizeof(char *) * game_map->lines);
	for (int i = 0; i < game_map->lines; i++)
	{
		game_map->matrix[i] = (char *)malloc(sizeof(char) * (game_map->columns + 1));
	}
}

void print_map(GAME_MAP *game_map)
{
	for (int i = 0; i < game_map->lines; i++)
	{
		printf("%s\n", game_map->matrix[i]);
	}
}

void find_on_map(GAME_MAP *game_map, MAP_POSITION *character_position, char find_char)
{
	for (int i = 0; i < game_map->lines; i++)
	{
		for (int j = 0; j < game_map->columns; j++)
		{
			if (game_map->matrix[i][j] == find_char)
			{
				character_position->x = i;
				character_position->y = j;
				break;
			}
		}
	}
}

int is_valid_map_position(GAME_MAP *game_map, int x, int y)
{
	if (x >= game_map->lines)
		return 0;

	if (y >= game_map->columns)
		return 0;

	return 1;
}

int is_empty_map_position(GAME_MAP *game_map, int x, int y)
{
	return game_map->matrix[x][y] == EMPTY;
}

void move_on_map(GAME_MAP *game_map, int from_x, int to_y, int to_x, int to_y)
{
	char character = game_map->matrix[from_x][to_y];
	game_map->matrix[to_x][to_y] = character;
	game_map->matrix[from_x][to_y] = EMPTY;
}

void copy_map(GAME_MAP *to_map, GAME_MAP *from_map)
{
	to_map->lines = from_map->lines;
	to_map->columns = from_map->columns;

	allocate_map(to_map);
	for (int i = 0; i < from_map->lines; i++)
	{
		strcpy(to_map->matrix[i], from_map->matrix[i]);
	}
}
