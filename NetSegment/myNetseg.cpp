#include "myNetseg.h"

bool mysubstr( std::string str ,int len )
{
	int i = 0;
	while ( str.find_first_of(".") != -1 )
	{
		str = str.substr( str.find_first_of( "." )+1 );
		i++;
	}
	return i==len;
}

bool checkSegment( std::string str, SEG & ip )
{
	int index = 0;
	ip.first = atoi( &str[index]);
	if ( ip.first > 255 || ip.first < 0 )
		return false;

	
	index = str.find_first_of( ".", index );
	ip.second = atoi( &str[ ++index ] );
	if ( ip.second > 255 || ip.second < 0 )
		return false;

	index = str.find_first_of( ".", index );
	ip.three = atoi( &str[ ++index ] );
	if ( ip.three > 255 || ip.three < 0 )
		return false;

	index = str.find_first_of( ".", index );
	ip.fouth = atoi( &str[ ++index ] );
	if ( ip.fouth > 255 || ip.fouth < 0 )
		return false;

	return true;
}

void show()
{
	std::string ipstr1, ipstr2, maskstr;
	SEG ipseg1, ipseg2, maskseg;

	std::cout << "please input mask,ip1,ip2:" << std::endl;
	while (std::cin>>maskstr>>ipstr1>>ipstr2)
	{
		if ( mysubstr( maskstr ) || mysubstr( ipstr2 ) || mysubstr( ipstr1 ) )
		{
			std::cout << '1' << std::endl;
			return;
		}

		if ( checkSegment( ipstr1, ipseg1 ) && checkSegment( ipstr2, ipseg2 ) && checkSegment( maskstr, maskseg ) )
		{
			ipseg1.first = maskseg.first & ipseg1.first;
			ipseg1.second = maskseg.second & ipseg1.second;
			ipseg1.three = maskseg.three & ipseg1.three;
			ipseg1.fouth = maskseg.fouth & ipseg1.fouth;

			ipseg2.first = maskseg.first & ipseg2.first;
			ipseg2.second = maskseg.second & ipseg2.second;
			ipseg2.three = maskseg.three & ipseg2.three;
			ipseg2.fouth = maskseg.fouth & ipseg2.fouth;

			if ( ipseg1.first == ipseg2.first && ipseg1.second == ipseg2.second && ipseg1.three == ipseg2.three && ipseg1.fouth == ipseg2.fouth )
			{
				std::cout << '0' << std::endl;
				return;

			}
			else
			{
				std::cout << '2' << std::endl;
				return;
			}
		}
		else
		{
			std::cout << '1' << std::endl;
			return;
		}		
	}
}
