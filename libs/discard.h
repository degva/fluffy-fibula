#ifndef _DISCARDT_H
#define _DISCARDT_H

struct fluFlyCartDiscard{
	//fluFlyGame *game;
	TMList *list;
	
};

fluFlyCartDiscard * fluFlyCartDiscard_new();
fluFlyCartDiscard * fluFlyCartDiscard_add_element(fluFlyCartDiscard * discard, fluFlyCart *cart);
fluFlyCartDiscard * fluFlyCartDiscard_shuffle (fluFlyCartDiscard * discard );
