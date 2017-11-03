#include "recover.h"
#include <stdlib.h>
#include <unistd.h>


/***************************************************************************
Name		: recoverDisk
Input Param	: char *
Output Param	: void
Description	: This functions recovers the data present in disk that has crashed, with the help of all other disk's data.
 ***************************************************************************/
void recoverDisk(int disk_num)
{
	FILE *f[5];
	string destination_filepath[5];
	int n = 5;
	destination_filepath[0]="./raid_files/f1";
	destination_filepath[1]="./raid_files/f2";
	destination_filepath[2]="./raid_files/f3";
	destination_filepath[3]="./raid_files/f4";
	destination_filepath[4]="./raid_files/f5";
	for(int i = 0 ; i < n ; ++i)
	{
		if(i != disk_num)
		{
			f[i] = fopen(destination_filepath[i].c_str(),"rb");
			if(NULL == f[i])
			{
				printf("Disk access for disk %d denied", i);
			}
		}
	}
	f[disk_num] = fopen(destination_filepath[disk_num].c_str(),"wb");
	

	unsigned char buff[4][256];
	unsigned char parity[256];
	while(1)
	{
		int j = 0;
		
		int fno;
		char proclnk[512];
		char filename[512];
		int nread[4] = {0,0,0,0};
		for(int i=0 ; i < n ; ++i)
		{
			if(i != disk_num)
			{

/***************************************************************************/	

	cout << j;
	fno = fileno(f[i]);
        sprintf(proclnk, "/proc/self/fd/%d", fno);
        ssize_t r = readlink(proclnk, filename, 512);
        if (r < 0)
        {
            printf("failed to readlink\n");
            exit(1);
        }
        filename[r] = '\0';
        printf("fp -> fno -> filename: %p -> %d -> %s\n",
                f[i], fno, filename);
	

/**************************************************************************/



				nread[j] = fread(buff[j],1,255,f[i]);
				++j;


/******************************************************************************/

buff[j-1][nread[j-1]] =(unsigned char) '\0';
cout << buff[j-1] << endl << endl;

/******************************************************************************/



	


			}




		}
		printf("nread :- %d %d %d %d\n",nread[0],nread[1],nread[2],nread[3]);
		if(nread[0])
		{
			for(int i = 0 ; i < nread[0] ; ++i)
			{

				parity[i] = buff[0][i]^buff[1][i]^buff[2][i]^buff[3][i];
			}
			fwrite(parity, 1 , nread[0] , f[disk_num]);
		}
		else
		{
			break;
		}
	}

	for(int i = 0 ; i < n ; ++i)
	{
		fclose(f[i]);
	}

	printf("Over\n");
	

}


int main()
{
	recoverDisk(2);
	return 0;
}
