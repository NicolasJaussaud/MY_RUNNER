/*
** EPITECH PROJECT, 2018
** read
** File description:
** readmap 
*/

#include "./include/my.h"

char *readfile(char *path)
{
	char *file = NULL;
	struct stat buf;
	int fd;
	int ret = 0;

	stat(path, &buf);
	file = malloc(sizeof(char) * buf.st_size + 1);
	if ((fd = open(path, O_RDONLY)) == -1)
		exit(84);
	ret = read(fd, file, buf.st_size);
	if (ret == -1)
		exit(84);
	file[ret] = '\0';
	close(fd);
	return (file);
}

p_t map2char(char *map, int nbLin, int nbCol, p_t p)
{
	char **map2 = (char **)malloc(sizeof(char*) * nbLin);
	char *map1 = (char *)malloc(sizeof(char) * nbCol * nbLin);
	int a = 0;
	float x = 0;
	float y = 0;
	int i = 0;
	int j = 0;

	for(int i = 0 ; i < nbLin ; i++)
		map2[i] = &map1[i * nbCol];
	while (j != nbLin) {
		if (map[i] != '\n') {
			map2[j][a] = map[i];
			i = i + 1;
			a++;
		}
		if (map[i] == '\n') {
			i = i + 1;
			a = 0;
			j = j + 1;
		}
	}
	i = 0;
	j = 0;
	while (j != nbLin) {
		analyseobstacle(map2[j][i], x, y, &p);
		if (i != nbCol) {
			i = i + 1;
			x++;
		}
		if (i == nbCol) {
			i = 0;
			x = 0;
			j = j + 1;
			y++;
		}
	}
	free(map1);
	free(map2);
	return (p);
}

p_t map_reader(p_t p, char *file)
{
	int nbLin = 5;
	int nbCol = 39;
	char *map = readfile(file);

	p = map2char(map, nbLin, nbCol, p);
	return (p);
}
