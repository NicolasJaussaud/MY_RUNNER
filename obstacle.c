/*
** EPITECH PROJECT, 2018
** obstacle
** File description:
** obstacle cactus 
*/

#include "./include/my.h"

p_t drawobstacle2(p_t p, o_t *o)
{
	sfSprite_setPosition(o->scactus, o->poscactus);
	sfSprite_setTexture(o->scactus, o->tcactus, sfTrue);
	sfRenderWindow_drawSprite(p.window, o->scactus, NULL);
	sfSprite_setPosition(o->scactus1, o->poscactus1);
	sfSprite_setTexture(o->scactus1, o->tcactus1, sfTrue);
	sfRenderWindow_drawSprite(p.window, o->scactus1, NULL);
	sfSprite_setPosition(o->scactus2, o->poscactus2);
	sfSprite_setTexture(o->scactus2, o->tcactus2, sfTrue);
	sfRenderWindow_drawSprite(p.window, o->scactus2, NULL);
	sfSprite_setPosition(o->scactus3, o->poscactus3);
	sfSprite_setTexture(o->scactus3, o->tcactus3, sfTrue);
	sfRenderWindow_drawSprite(p.window, o->scactus3, NULL);
	sfRenderWindow_display(p.window);
	return (p);
}

p_t positioncactus(p_t p, o_t *o)
{
	float c = 110;

	o->poscactus.x = (p.xo[0] * c); 
	o->poscactus.y = (p.yo[0] * c);
	o->poscactus1.x = (p.xo[1] * c);
	o->poscactus1.y = (p.yo[1] * c);
	o->poscactus2.x = (p.xo[2] * c);
	o->poscactus2.y = (p.yo[2] * c);
	o->poscactus3.x = (p.xo[3] * c);
	o->poscactus3.y = (p.yo[3] * c);
	return (p);
}

void ifobstacle(o_t *o, pg_t pg, p_t p )
{
	int saut = 0;

	if (o->poscactus.x < 180 && o->poscactus.x > 150) {
		if(pg.y < 220)
			saut = 1;
		else
			saut = 2;
	}
	if (o->poscactus1.x < 180 && o->poscactus1.x > 150) {
		if(pg.y < 220)
			saut = 1;
		else
			saut = 2;
	}
	if (o->poscactus2.x < 180 && o->poscactus2.x > 150) {
		if(pg.y < 220)
			saut = 1;
		else
			saut = 2;
	}
	if (o->poscactus3.x < 180 && o->poscactus3.x > 150) {
		if(pg.y < 220)
			saut = 1;
		else
			saut = 2;
	}
	if (saut == 2) {
			sfRenderWindow_close(p.window);
			exit(0);
	}
}

p_t drawobstacle(p_t p, o_t *o, pg_t pg)
{
	p = positioncactus(p, o);
	p.xo[0] = p.xo[0] - 0.01;
	p.xo[1] = p.xo[1] - 0.01;
	p.xo[2] = p.xo[2] - 0.01;
	p.xo[3] = p.xo[3] - 0.01;
	p = drawobstacle2(p, o);
	ifobstacle(o, pg, p);
	return (p);
}

p_t analyseobstacle(char c, float i, float j, p_t *p)
{
	static int nbo = 0;

	if (c == '2') {
		p->xo[nbo] = i;
		p->yo[nbo] = j;
		nbo++;
	}
	return (*p);
}
