/*
** EPITECH PROJECT, 2018
** score
** File description:
** score 
*/

#include "./include/my.h"

o_t score(p_t p, o_t o)
{
	static char *score = "0";

	if (p.start == 0) {
		if (o.poscactus.x < 120 && o.poscactus.x > 118)
			score = "1";
		if (o.poscactus1.x < 120 && o.poscactus1.x > 118)
			score = "2";
		if (o.poscactus2.x < 120 && o.poscactus2.x > 118)
			score = "3";
		if (o.poscactus3.x < 120 && o.poscactus3.x > 118)
			score = "4";
		sfText_setString(o.text, score);
		sfText_setFont(o.text, o.font);
		sfText_setCharacterSize(o.text, 200);
		sfRenderWindow_drawText(p.window, o.text, NULL);
	}
	return (o);
}
