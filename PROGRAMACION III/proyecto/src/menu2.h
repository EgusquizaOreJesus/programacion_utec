//
// Created by Jesus on 15/02/2023.
//

#ifndef EXAMPLES_MENU2_H
#define EXAMPLES_MENU2_H

#include "global.h"

class Menu {
public:
    OptionEvent option;
};

Menu *initMenu(void);

void updateMenu(Menu *const menu);

void drawMenu(const Menu *const menu);

void freeMenu(Menu **menu);

OptionEvent finishMenu(void);

#endif //EXAMPLES_MENU2_H
