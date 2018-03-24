/*
	bcontrol
	Just a little program I made to change brightness of my screen.
	assumes you use x windows. it uses xranr.

	USAGE -
	bcontrol BRIGHTNESS	- makes the screen brightness be
				  BRIGHTNESS percent. for example,
				  bcontrol 50 will make the screen
				  half the maximum brightness.
	bcontrol +BRIGHTNESS
	bcontrol -BRIGHTNESS	- makes the screen brighter/dimmer by
				  BRIGHTNESS percent

	made by DaKnig 2018
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc,char** argv){
	FILE *temp;
	int i='E',b='E';
	char str[2][100]={0};
	float f=0;

	if(argc<2){
		printf("Not enough arguments \nUsage: \nbcontrol percent\nbcontrol +percent\nbcontrol -percent\n");
		return 0;
	}
	if(argc>2){
		puts("too many args");
		return 0;
	}
	//str[0]=active screen name
	{	temp=popen("xrandr -q | grep ' connected'","r");
		fscanf(temp,"%s ",str[0]);
		pclose(temp);
	}
	//b=brightness
	{	temp=popen("xrandr --current --verbose | grep 'Bright'","r");
                fscanf(temp," Brightness: %f",&f);
                b=f*100;
                pclose(temp);

		switch(argv[1][0]){
			case '+':
			case '-': b += atoi(argv[1]); break;
			default:  b  = atoi(argv[1]);		}
		if (b>100)	b=100;
		if (b<5)	b=5;	//under 5 you cant see anything...
	}
	sprintf(str[1],"xrandr --output %s  --brightness %f",str[0],(float)b/100);
	system(str[1]);
}
