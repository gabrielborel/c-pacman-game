#include <stdio.h>
#include <stdlib.h>
#include "game.h"
#include "map.h"

GAME_MAP game_map;
MAP_POSITION pacman_position;

int main()
{
	read_map(&game_map);
	find_on_map(&game_map, &pacman_position, PACMAN_CHARACTER);

	while (!game_ended())
	{
		print_map(&game_map);

		char command_direction;
		scanf(" %c", &command_direction);
		move(command_direction);
		ghosts();
	}

	free_map(&game_map);

	return 0;
}

int game_ended()
{
	return 0;
}

void move(char command_direction)
{
	if (!is_valid_direction(command_direction))
		return;

	int nextX = pacman_position.x;
	int nextY = pacman_position.y;

	switch (command_direction)
	{
	case LEFT_DIRECTION:
	{
		nextY--;
		break;
	}
	case UP_DIRECTION:
	{
		nextX--;
		break;
	}
	case DOWN_DIRECTION:
	{
		nextX++;
		break;
	}
	case RIGHT_DIRECTION:
	{
		nextY++;
		break;
	}
	}

	if (!is_valid_map_position(&game_map, nextX, nextY))
		return;

	if (!is_empty_map_position(&game_map, nextX, nextY))
		return;

	move_on_map(&game_map, pacman_position.x, pacman_position.y, nextX, nextY);
	pacman_position.x = nextX;
	pacman_position.y = nextY;
}

int is_valid_direction(char command_direction)
{
	if (command_direction == LEFT_DIRECTION || command_direction == UP_DIRECTION || command_direction == DOWN_DIRECTION || command_direction == RIGHT_DIRECTION)
		return 1;

	return 0;
}

void ghosts()
{
	GAME_MAP map_copy;
	copy_map(&map_copy, &game_map);

	for (int i = 0; i < game_map.lines; i++)
	{
		for (int j = 0; j < game_map.columns; j++)
		{
			if (map_copy.matrix[i][j] == GHOST_CHARACTER)
			{
				if (is_valid_map_position(&game_map, i, j + 1) && is_empty_map_position(&game_map, i, j + 1))
				{
					move_on_map(&game_map, i, j, i, j + 1);
				}
			}
		}
	}

	free_map(&map_copy);
}
