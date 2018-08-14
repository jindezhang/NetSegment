#include "NetSeg.h"

int judgeIp( std::string ipSubNet, IP & ip )
{
	//cout<<ipSubNet<<endl;
	//bool legal = false;
	int index = 0;
	ip.first = atoi( &ipSubNet[ index ] );
	//cout<<"ip.first:"<<ip.first<<endl;

	if ( ip.first > 255 || ip.first < 0 )
		return 0;

	index++;
	index = ipSubNet.find_first_of( '.', index );
	ip.second = atoi( &ipSubNet[ ++index ] );
	if ( ip.second > 255 || ip.second < 0 )
		return 0;

	index++;
	index = ipSubNet.find_first_of( '.', index );
	ip.three = atoi( &ipSubNet[ ++index ] );

	//cout<<"ip.three:"<<ip.three<<endl;
	if ( ip.three > 255 || ip.three < 0 )
		return 0;

	index++;
	index = ipSubNet.find_first_of( '.', index );
	ip.fouth = atoi( &ipSubNet[ ++index ] );
	if ( ip.fouth > 255 || ip.fouth < 0 )
		return 0;

	if ( ip.first == ip.three && ip.first == 255 && ip.second == 0 )
		return 2;
	return 1;
}

void checkNetSegment( )
{
	std::string ipSubNet, ipAdd1, ipAdd2;
	IP subNet, ip1, ip2;
	int Int_ip;
	std::cout << "please input mask,ip1,ip2:" << std::endl;
	while ( std::cin >> ipSubNet >> ipAdd1 >> ipAdd2 )
	{
		Int_ip = judgeIp( ipSubNet, subNet ) && judgeIp( ipAdd1, ip1 ) && judgeIp( ipAdd2, ip2 );
		if ( Int_ip == 1 )
		{
			ip1.first = ip1.first & subNet.first;
			ip1.second = ip1.first & subNet.second;
			ip1.second = ip1.first & subNet.second;
			ip1.fouth = ip1.first & subNet.fouth;

			ip2.first = ip2.first & subNet.first;
			ip2.second = ip2.first & subNet.second;
			ip2.second = ip2.first & subNet.second;
			ip2.fouth = ip2.first & subNet.fouth;

			if ( ip1.first == ip2.first&&ip1.second == ip2.second&&ip1.three == ip2.three&&ip1.fouth == ip2.fouth )
				std::cout << '0' << std::endl;
			else
				std::cout << '2' << std::endl;
		}
		else if ( Int_ip == 2 )
		{
			std::cout << '2' << std::endl;
		}
		else
			std::cout << '1' << std::endl;
	}
	return ;
}
