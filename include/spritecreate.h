/*
** EPITECH PROJECT, 2017
** spritecreate
** File description:
** sprite 
*/

typedef struct struct_s
{
	sfSprite* sprite;
	sfTexture* texture;
	sfVector2f vector;
	sfIntRect rect;
}	struct_t;


typedef struct pr_s
{
	sfSprite* spr[9];
	sfTexture* tpr[9];
	sfVector2f ppr;
}	pr_t;

typedef struct pg_s
{
	sfSprite* spg[4];
	sfTexture* tpg[4];
	sfTime timeg;
	sfClock *clockg;
	float secondsg;
	sfTime timej;
	sfClock *clockj;
	float secondsj;
	int countj;
	float y;
	int saut;
	int jg;
	int booleang;
	sfSprite* spj[12];
	sfTexture* tpj[12];
}	pg_t;

typedef struct p_s
{
	int i;
	int j;
	int k;
	int start;
	int boolean;
	float seconds;
	sfRenderWindow* window;
	sfTime time;
	sfClock *clock;
	sfVector2f posplayer;
	sfEvent event;
	float xo[5];
	float yo[5];
	sfSprite *bgmenu;
	sfTexture *tmenu;
}	p_t;

typedef struct o_s
{
	sfSprite *scactus;
	sfTexture *tcactus;
	sfSprite *scactus1;
	sfTexture *tcactus1;
	sfSprite *scactus2;
	sfTexture *tcactus2;
	sfSprite *scactus3;
	sfTexture *tcactus3;
	sfVector2f poscactus;
	sfVector2f poscactus1;
	sfVector2f poscactus2;
	sfVector2f poscactus3;
	sfFont* font;
	sfText* text;
}	o_t;