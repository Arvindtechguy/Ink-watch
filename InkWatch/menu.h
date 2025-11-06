/*
 * Menu system
 */

#ifndef MENU_H
#define MENU_H

#include "config.h"

extern int currentMenuItem;

void initMenu();
void displayMenu();
void menuUp();
void menuDown();
SystemState menuSelect();

#endif
