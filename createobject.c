/*
** EPITECH PROJECT, 2018
** createobject
** File description:
** createobject 
*/

#include "./include/my.h"

struct_t *create_object(const char *path_to_spritesheet, sfVector2f pos, sfIntRect rect)
{
	struct_t *object = malloc(sizeof(*object));

	sfSprite *sprite = sfSprite_create();
	object->sprite = sprite;
	sfTexture *texture = sfTexture_createFromFile(path_to_spritesheet, NULL);
	object->texture = texture;
	sfSprite_setTexture(object->sprite, object->texture, sfTrue);
	object->vector = pos;
	sfSprite_setPosition(object->sprite, object->vector);
	object->rect = rect;
	sfSprite_setTextureRect(object->sprite, object->rect);
	return (object);
}

struct_t **tab()
{
	struct_t **tab = malloc(sizeof(*tab) * 3);

	tab[0] = create_object("./img/bg.png", (sfVector2f){1, 1}, (sfIntRect){0, 0, 2560, 640});
	tab[1] = create_object("./img/ground.png", (sfVector2f){1 , 1}, (sfIntRect){0, 0, 2560, 640});
	tab[2] = create_object("./img/ground.png", (sfVector2f){1 , 1}, (sfIntRect){0, 0, 1600, 600});
	return (tab);
}

void parallax(struct_t **object)
{
	move(&object[0]->rect, 0, 1280);
	move(&object[1]->rect, 1, 1280);
	move(&object[2]->rect, 1, 1280);
	sfSprite_setTextureRect (object[0]->sprite, object[0]->rect);
	sfSprite_setTextureRect (object[1]->sprite, object[1]->rect);
	sfSprite_setTextureRect (object[2]->sprite, object[2]->rect);
}