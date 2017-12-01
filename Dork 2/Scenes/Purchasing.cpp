//
//  Purchasing.cpp
//  Dork 2
//
//  Created by Alessandro Vinciguerra on 01/12/2017.
//      <alesvinciguerra@gmail.com>
//Copyright (C) 2017 Arc676/Alessandro Vinciguerra

//This program is free software: you can redistribute it and/or modify
//it under the terms of the GNU General Public License as published by
//the Free Software Foundation (version 3)

//This program is distributed in the hope that it will be useful,
//but WITHOUT ANY WARRANTY; without even the implied warranty of
//MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//GNU General Public License for more details.

//You should have received a copy of the GNU General Public License
//along with this program.  If not, see <http://www.gnu.org/licenses/>.
//See README and LICENSE for more details

#include "Purchasing.h"

void Purchasing::activate() {
	statViewer->reloadData();
	orxObject_SetPosition(selectorArrow, &defaultPos);
	currentSelection = 0;
}

void Purchasing::deactivate() {}

SceneType Purchasing::update(const orxCLOCK_INFO* clockInfo) {
	orxVECTOR pos;
	orxObject_GetPosition(selectorArrow, &pos);
	if (getKeyDown((orxSTRING)"GoDown") && currentSelection < selectionLimit) {
		pos.fY += 60;
		orxObject_SetPosition(selectorArrow, &pos);
		currentSelection++;
	} else if (getKeyDown((orxSTRING)"GoUp") && currentSelection > 0) {
		pos.fY -= 60;
		orxObject_SetPosition(selectorArrow, &pos);
		currentSelection--;
	} else if (getKeyDown((orxSTRING)"Enter")) {
		if (currentSelection == POTIONCOUNT) {
			return EXPLORATION;
		}
		if (makePurchase()) {
			orxObject_AddSound(player->getEntity(), "Kaching");
		}
	}
	return getSceneType();
}
