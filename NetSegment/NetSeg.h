#ifndef NETSEG_H
#define NETSEG_H

#include <string>
#include <iostream>

typedef struct ip
{
	int first;
	int second;
	int three;
	int fouth;
} IP;

int judgeIp( std::string ipSubNet, IP &ip );
void checkNetSegment( );


#endif // !NETSEG_H

#pragma once
