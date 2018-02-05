/*
** EPITECH PROJECT, 2018
** event
** File description:
** all event 
*/

#include "./include/my.h"

p_t eventfunction2(p_t p, struct_t **object, pr_t pr, pg_t *pg)
{
	if (p.start == 0) {
		while (p.i != 3) {
			sfRenderWindow_drawSprite(p.window, object[p.i]->sprite, NULL);
			p.i = p.i + 1;
		}
		p.i = 0;
		p = anim1(p, pg, pr);
	} else
		p = menu(p);
	return (p);
}

p_t eventfunction(p_t p, struct_t **object, pr_t pr, pg_t *pg)
{
	while (sfRenderWindow_pollEvent(p.window, &p.event)) {
		if (p.event.type == sfEvtClosed) {
			sfRenderWindow_close(p.window);
			exit(0);
		}
		if (sfKeyboard_isKeyPressed(sfKeyDown))
			p.boolean = 1;
		if (sfKeyboard_isKeyPressed(sfKeyReturn) && p.start == 1)
			p.start = 0;
		if (sfKeyboard_isKeyPressed(sfKeyUp))
			p.boolean = 2;
	}
	p = eventfunction2(p, object, pr, pg);
	return (p);
}
