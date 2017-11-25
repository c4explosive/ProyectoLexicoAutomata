#include "parserBridge.h"

int readBridge(char * argv)
{

    MC::MC_Driver driver;
   /* if (argc == 2)
    {*/
		std::string str1(argv,strlen(argv));
		//std::cout<<"WORK:: "<<str1<<"\n";
		std::istringstream is1(str1);
		//std::cout<<"STREAM:: "<<is1.rdbuf()<<"\n";
        //driver.parse(argv[1]);
		std::istream ist1(is1.rdbuf());
		driver.parse(ist1);	
		driver.print(std::cout) << "\n";
    /*}
    else
		return ( EXIT_FAILURE );*/

    return ( EXIT_SUCCESS );
}

