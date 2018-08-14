#ifndef MYNETSEG_H
#define MYNETSEG_H

#include <iostream>
#include <string>

typedef struct segment
{
	int first;
	int second;
	int three;
	int fouth;

} SEG;


bool mysubstr(std::string str, int len = 4);
bool checkSegment( std::string str, SEG &ip );
void show();
#endif


#pragma once
