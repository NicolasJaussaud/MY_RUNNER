/*
** EPITECH PROJECT, 2017
** my.h
** File description:
** Includes | Functions 
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <SFML/Graphics.h>
#include <SFML/Config.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "spritecreate.h"

pr_t initplayerrun(pr_t pr, o_t *o);
pg_t initplayerjump(pg_t pj);
pg_t initplayergliss(pg_t pg);
p_t initvariable(p_t p);
o_t score(p_t p, o_t o);
p_t menu(p_t p);
p_t eventfunction2(p_t p, struct_t **object, pr_t pr, pg_t *pg);
p_t eventfunction(p_t p, struct_t **object, pr_t pr, pg_t *pg);
struct_t *create_object(const char *path_to_spritesheet, sfVector2f pos, sfIntRect rect);
struct_t **tab();
void parallax(struct_t **object);
void move(sfIntRect *rect, float offset, int max_value);
p_t anim1(p_t p, pg_t *pg, pr_t pr);
p_t drawplayer(p_t p, pr_t pr);
p_t analyseobstacle(char c, float i, float j, p_t *p);
p_t drawobstacle(p_t p, o_t *o, pg_t pg); 
p_t drawobstacle2(p_t p, o_t *o);
p_t map_reader(p_t p, char *file);
p_t map2char(char *map, int nbLin, int nbCol, p_t p);
char *readfile(char *path);
