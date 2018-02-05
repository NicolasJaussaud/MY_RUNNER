/* 
** EPITECH PROJECT, 2017 
** runner 
** File description: 
** My_runner 
*/ 
 
#include "./include/my.h" 
 
void move(sfIntRect *rect, float offset, int max_value) 
{ 
  rect->left = rect->left + offset; 
  if (rect->left > max_value) 
    rect->left = 0; 
} 
 
p_t drawplayer(p_t p, pr_t pr) 
{ 
  p.time = sfClock_getElapsedTime(p.clock); 
  p.seconds = p.time.microseconds / 1000000.0; 
  if (p.seconds > 0.06) { 
    if (p.j != 8) 
      p.j = p.j + 1; 
    else 
      p.j = 0; 
    sfClock_restart(p.clock); 
  } 
  sfSprite_setPosition(pr.spr[p.j], p.posplayer); 
  sfRenderWindow_drawSprite(p.window, pr.spr[p.j], NULL); 
  return (p); 
} 
 
p_t menu(p_t p) 
{ 
  p.bgmenu = sfSprite_create(); 
  p.tmenu = sfTexture_createFromFile("./img/runnerbg.png", NULL); 
  sfSprite_setTexture(p.bgmenu, p.tmenu, sfTrue); 
  sfRenderWindow_drawSprite(p.window, p.bgmenu, NULL); 
  return (p); 
} 
void destroy(p_t p, pr_t pr, pg_t pg, o_t o) 
{ 
  for (int i = 0; i != 9; i++) { 
    sfSprite_destroy(pr.spr[i]); 
    sfTexture_destroy(pr.tpr[i]); 
  } 
  for (int i = 0; i != 4; i++) { 
    sfSprite_destroy(pg.spg[i]); 
    sfTexture_destroy(pg.tpg[i]); 
  } 
  for (int i = 0; i != 12; i++) { 
    sfSprite_destroy(pg.spj[i]); 
    sfTexture_destroy(pg.tpj[i]); 
  } 
  sfSprite_destroy(o.scactus); 
  sfSprite_destroy(o.scactus1); 
  sfSprite_destroy(o.scactus2); 
  sfSprite_destroy(o.scactus); 
  sfTexture_destroy(o.tcactus); 
  sfTexture_destroy(o.tcactus1); 
  sfTexture_destroy(o.tcactus2); 
  sfTexture_destroy(o.tcactus3); 
  sfRenderWindow_destroy(p.window); 
} 
 
int  main(int ac, char **av) 
{ 
  sfVideoMode mode = {1280, 600, 32}; 
  struct_t **object = tab(); 
  o_t o; 
  pr_t pr = initplayerrun(pr, &o); 
  pg_t pg = initplayergliss(pg); 
  p_t p = initvariable(p); 
  int map = 0; 
 
  if (ac == 1) 
    return (84); 
  p.window = sfRenderWindow_create(mode, "MY_RUNNER", sfResize | sfClose, NULL); 
  while (sfRenderWindow_isOpen(p.window)) { 
    if (map != 1) { 
      map = 1; 
      p = map_reader(p, av[1]); 
    } 
    o = score(p, o); 
    p = drawobstacle(p, &o, pg); 
    p = eventfunction(p, object, pr, &pg); 
    parallax(object); 
  } 
  destroy(p, pr, pg, o); 
  return (0); 
}
