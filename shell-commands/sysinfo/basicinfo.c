/******************************************/
/* Author       : Navin kumar.N           */
/* Date         : 13-3-2019               */
/* Filename     : UNAME                   */
/* Description  : Details of PC           */
/******************************************/
#include "basicinfo.h"
int main()
{
	time_t t =time(NULL);
	struct tm tm =*localtime(&t);
	struct utsname data;
	/*  get name and information about current kernel */
	uname(&data);
	struct sysinfo sys_data;
	/* sysinfo - return system information */
	sysinfo(&sys_data);



	printf("\n\n");
	if(tm.tm_sec <20)
	{
	printf("        A Computer is Like Air Conditioning it Become useless      \n");
	printf("                        When You Open Windows                      \n");
	printf("                                                    -Linux Torvalds\n");
	}
	else if (tm.tm_sec <40)
	{
	printf("		Talk is Cheap.Show Me The Code                     \n");
	printf("                                                    -Linux Torvalds\n");
	}
	else if(tm.tm_sec <60)
	{
	printf("	UNIX is Simple. It Just Takes a Genius to Understand       \n");
	printf("			Its Simplicity                             \n");
	printf("                                                    -Dennis Ritchie\n");
	}

	printf(wit"--------------------------------------------------------------------\n"clr);

	printf( meg"DATE : %d-%d-%d                                     TIME: %d:%d:%d \n"clr,tm.tm_year+1900,tm.tm_mon+1,tm.tm_mday,tm.tm_hour>12?tm.tm_hour+12:tm.tm_hour,tm.tm_min,tm.tm_sec);	
	printf(DAY"                            SYSTEM INFORMATION                      \n"clr);;
	printf(wit"--------------------------------------------------------------------\n"clr);
	/*  get name and information about current kernel */
	printf(wit "    SYSTEM NAME : %s\n",data.sysname);
	/*  get name and information about current kernel */
	printf(wit "    DEVICE NAME : %s\n",data.nodename);
	/*  get name and information about current kernel */
	printf(wit "    RELEASE     : %s\n",data.release);
	/*  get name and information about current kernel */
	printf(wit "    VERSION     : %s\n",data.version);
	/*  get name and information about current kernel */
	printf(wit "    ARCHITECTURE: %s\n",data.machine);
	/* sysinfo - return system information */
	printf(wit "    UP-TIME     : %ld Minutes\n",sys_data.uptime/60);
	/* sysinfo - return system information */
	printf(wit "    RAM         : %2.ld\n\n"clr,sys_data.totalram/1024/1024/1024+1);
	printf(yel"                            BATTERY STATE                           \n"clr);
	printf(wit"--------------------------------------------------------------------\n"clr);

	/* sysinfo - return system information */
	system("upower -i $(upower -e | grep BAT ) | grep --color=never -E state");
	/* sysinfo - return system information */
	system("upower -i $(upower -e | grep BAT ) | grep --color=never -E empty");
	/* sysinfo - return system information */
	system("upower -i $(upower -e | grep BAT ) | grep --color=never -E percentage");
	printf("\n");
	printf(red"                            BATTERY INFO                            \n"clr);;
	printf(wit"--------------------------------------------------------------------\n"clr);
	/* sysinfo - return system information */
	system("upower -i /org/freedesktop/UPower/devices/battery_BAT0");

}
