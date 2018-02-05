/*
** EPITECH PROJECT, 2018
** initstruct
** File descriion:
** initstruct 
*/

#include "./include/my.h"

void initobstacle(o_t *o)
{
	o->scactus = sfSprite_create();
	o->tcactus = sfTexture_createFromFile("./img/cactus.png", NULL);
	o->scactus1 = sfSprite_create();
	o->tcactus1 = sfTexture_createFromFile("./img/cactus.png", NULL);
	o->scactus2 = sfSprite_create();
	o->tcactus2 = sfTexture_createFromFile("./img/cactus.png", NULL);
	o->scactus3 = sfSprite_create();
	o->tcactus3 = sfTexture_createFromFile("./img/cactus.png", NULL);
	o->font = sfFont_createFromFile("game_over.ttf");
	o->text = sfText_create();
}

pr_t initplayerrun(pr_t pr, o_t *o)
{
	for (int i = 0; i != 9; i++)
		pr.spr[i] = sfSprite_create();
	pr.tpr[0] = sfTexture_createFromFile("./img/run/2.png", NULL);
	pr.tpr[1] = sfTexture_createFromFile("./img/run/3.png", NULL);
	pr.tpr[2] = sfTexture_createFromFile("./img/run/4.png", NULL);
	pr.tpr[3] = sfTexture_createFromFile("./img/run/5.png", NULL);
	pr.tpr[4] = sfTexture_createFromFile("./img/run/6.png", NULL);
	pr.tpr[5] = sfTexture_createFromFile("./img/run/7.png", NULL);
	pr.tpr[6] = sfTexture_createFromFile("./img/run/8.png", NULL);
	pr.tpr[7] = sfTexture_createFromFile("./img/run/9.png", NULL);
	pr.tpr[8] = sfTexture_createFromFile("./img/run/10.png", NULL);
	for (int i = 0; i != 9; i++)
		sfSprite_setTexture(pr.spr[i], pr.tpr[i], sfTrue);
	initobstacle(o);
	return (pr);
}

pg_t initplayerjump(pg_t pj)
{
	pj.y = 362;
	pj.saut = 1;
	for (int i = 0; i != 12; i++)
		pj.spj[i] = sfSprite_create();
	pj.tpj[0] = sfTexture_createFromFile("./img/jump/1.png", NULL);
	pj.tpj[1] = sfTexture_createFromFile("./img/jump/2.png", NULL);
	pj.tpj[2] = sfTexture_createFromFile("./img/jump/3.png", NULL);
	pj.tpj[3] = sfTexture_createFromFile("./img/jump/4.png", NULL);
	pj.tpj[4] = sfTexture_createFromFile("./img/jump/5.png", NULL);
	pj.tpj[5] = sfTexture_createFromFile("./img/jump/6.png", NULL);
	pj.tpj[6] = sfTexture_createFromFile("./img/jump/7.png", NULL);
	pj.tpj[7] = sfTexture_createFromFile("./img/jump/8.png", NULL);
	pj.tpj[8] = sfTexture_createFromFile("./img/jump/9.png", NULL);
	pj.tpj[9] = sfTexture_createFromFile("./img/jump/12.png", NULL);
	pj.tpj[10] = sfTexture_createFromFile("./img/jump/13.png", NULL);
	pj.tpj[11] = sfTexture_createFromFile("./img/jump/14.png", NULL);
	pj.tpj[12] = sfTexture_createFromFile("./img/jump/15.png", NULL);
	for (int i = 0; i != 12; i++)
		sfSprite_setTexture(pj.spj[i], pj.tpj[i], sfTrue);
	return (pj);
}

pg_t initplayergliss(pg_t pg)
{
	pg.secondsg = 0;
	pg.secondsj = 0;
	pg.countj = 0;
	pg.jg = 0;
	pg.booleang = 0;
	pg.clockj = sfClock_create();
	pg.clockg = sfClock_create();
	for (int i = 0; i != 4; i++)
		pg.spg[i] = sfSprite_create();
	pg.tpg[0] = sfTexture_createFromFile("./img/gliss/1.png", NULL);
	pg.tpg[1] = sfTexture_createFromFile("./img/gliss/2.png", NULL);
	pg.tpg[2] = sfTexture_createFromFile("./img/gliss/3.png", NULL);
	pg.tpg[3] = sfTexture_createFromFile("./img/gliss/4.png", NULL);
	pg.tpg[4] = sfTexture_createFromFile("./img/gliss/5.png", NULL);
	for (int i = 0; i != 4; i++)
		sfSprite_setTexture(pg.spg[i], pg.tpg[i], sfTrue);
	pg = initplayerjump(pg);
	return (pg);
}

p_t initvariable(p_t p)
{
	p.i = 0;
	p.j = 0;
	p.k = 0;
	p.start = 1;
	p.boolean = 0;
	p.seconds = 0;
	p.clock = sfClock_create();
	p.posplayer.x = 200;
	p.posplayer.y = 360;
	return (p);
}