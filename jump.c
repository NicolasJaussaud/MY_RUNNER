/*
** EPITECH PROJECT, 2018
** jump
** File description:
** jump 
*/

#include "./include/my.h"

p_t anim5(p_t p, pg_t *pg, sfVector2f *ppj)
{
	pg->timej = sfClock_getElapsedTime(pg->clockj);
	pg->secondsj = pg->timej.microseconds / 1000000.0;
	if (pg->secondsj > 0.06) {
		pg->countj = pg->countj + 1;
		if (pg->countj == 12)
			pg->countj = 0;
		sfClock_restart(pg->clockj);
	}
	sfSprite_setPosition(pg->spj[pg->countj], *ppj);
	sfRenderWindow_drawSprite(p.window, pg->spj[pg->countj], NULL);
	return (p);
}

p_t anim4(p_t p, pg_t *pg, sfVector2f *ppj)
{
	if ((pg->y == 209 && pg->saut == 4) ||
	    (pg->saut == 5 && pg->y < 362)) {
		pg->saut = 5;
		pg->y = pg->y + 1.4;
		ppj->y = pg->y;
	}
	if (pg->y > 362 && pg->saut == 5) {
		pg->saut = 1;
		p.boolean = 0;
		pg->jg = 0;
		pg->booleang = 0;
		pg->y = 362;
		pg->countj = 0;
	}
	p = anim5(p, pg, ppj);
	return (p);
}

p_t anim3(p_t p, pg_t *pg, sfVector2f *ppj)
{
	if ((pg->y == 180 || pg->saut == 4) && pg->y < 209) {
		pg->saut = 4;
		pg->y = pg->y + 0.5;
		ppj->y = pg->y;
	}
	p = anim4(p, pg, ppj);
	return (p);
}

p_t anim2(p_t p, pg_t *pg, sfVector2f *ppj)
{
	if (p.boolean == 2) {
		if (pg->y > 250 && pg->saut == 1) {
			pg->y = pg->y - 3;
			ppj->y = pg->y;
		}
		if ((pg->y == 248 || pg->saut == 2) &&
		    pg->y > 210 && pg->saut != 5) {
			pg->saut = 2;
			pg->y = pg->y - 1;
			ppj->y = pg->y;
		}
		if ((pg->y == 210 || pg->saut == 3) &&
		    pg->y > 180 && pg->saut != 5) {
			pg->saut = 3;
			pg->y = pg->y - 0.5;
			ppj->y = pg->y;
		}
		p = anim3(p, pg, ppj);
	}
	return (p);
}

p_t anim1(p_t p, pg_t *pg, pr_t pr)
{
	sfVector2f ppg = {200, 420};
	sfVector2f ppj = {200, pg->y};
	
	if (p.boolean == 0)
		p = drawplayer(p, pr);
	if (p.boolean == 1) {
		pg->timeg = sfClock_getElapsedTime(pg->clockg);
		pg->secondsg = pg->timeg.microseconds / 1000000.0;
		if (pg->secondsg > 0.06) {
			if (pg->jg != 3)
				pg->jg = pg->jg + 1;
			else {
				pg->jg = 0;
				pg->booleang = pg->booleang + 1;;
			}
			if (pg->booleang == 2 && pg->jg == 3) {
				pg->jg = 0;
				p.boolean = 0;
				pg->booleang = 0;
				pg->y = 362;
				pg->saut = 1;
			}
			sfClock_restart(pg->clockg);
		}
		sfSprite_setPosition(pg->spg[pg->jg], ppg);
		sfRenderWindow_drawSprite(p.window, pg->spg[pg->jg], NULL);
	}
	p = anim2(p, pg, &ppj);
	return (p);
}
