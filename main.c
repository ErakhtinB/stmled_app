#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int  main(int argc, char* argv[])
{
	if (argc != 3)
	{
		printf("Wrong parameters number\r\n");
		return -1;
	}
	int led_number = atoi(argv[1]);
	if (led_number > 4 || led_number < 1)
	{
		printf("No diode with this number\r\n");
		return -2;
	}
	int state = atoi(argv[2]);
	if (state != 0 && state != 1)
	{
		printf("No such state\r\n");
		return -3;
	}
	//char *dev_file = "/dev/stmled0";
	char *dev_file = "/dev/stmled0";
	char array[2] = {led_number, state};
	int fd = open(dev_file, O_RDWR);
	if (fd == -1)
	{
		printf("Failed to open\n");
		return -4;
	}
	else printf("Succed to open\n");
	int written_bytes = write(fd, array, sizeof(array));
	if (written_bytes != sizeof(array)) 
	{
		printf("Failed to write\n");
		close(fd);
		return -5;
	}
	else printf("Write suceed\n");
	close(fd);
	return 0;
}
	
