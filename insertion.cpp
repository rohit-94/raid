#include <bits/stdc++.h>
using namespace std;

void insert(string filepath)
{
	//int extension=get_filename(filepath);
	int parity_index=4,n=5;char parity;
	string destination_filepath1="/home/rohit/Dropbox/raid/raid_files/f1";
	string destination_filepath2="/home/rohit/Dropbox/raid/raid_files/f2";
	string destination_filepath3="/home/rohit/Dropbox/raid/raid_files/f3";
	string destination_filepath4="/home/rohit/Dropbox/raid/raid_files/f4";
	string destination_filepath5="/home/rohit/Dropbox/raid/raid_files/f5";
	FILE *fp = fopen(filepath.c_str(),"rb");
	FILE *f1 = fopen(destination_filepath1.c_str(),"wb");
	FILE *f2 = fopen(destination_filepath2.c_str(),"wb");
	FILE *f3 = fopen(destination_filepath3.c_str(),"wb");
	FILE *f4 = fopen(destination_filepath4.c_str(),"wb");
	FILE *f5 = fopen(destination_filepath5.c_str(),"wb");
    if(fp==NULL)
    {
        printf("File open error");
        return;
    }   

    while(1)
    {
        unsigned char buff[4]={0};
        int nread = fread(buff,1,4,fp);
        //printf("Bytes read %d \n", nread);        

        if(nread > 0)
        {
        	parity=buff[0]^buff[1]^buff[3]^buff[4];
        	int j=0;
        	for(int i=0;i<n;i++)
        	{
        		switch(i)
        		{
        			case 0:if(i==parity_index)
        					{
        						fwrite(&parity,1,1 ,f1);
        						parity_index=(parity_index-1)%n;
        					}
        					else
        						{
        							fwrite(buff+j,1,1 ,f1);
        							j++;
        						}
        					break;
        			case 1:if(i==parity_index)
        					{
        						fwrite(&parity,1,1 ,f2);
        						parity_index=(parity_index-1)%n;
        					}
        					else
        						{
        							fwrite(buff+j,1,1 ,f2);
        							j++;
        						}
        					break;
        			case 2:if(i==parity_index)
        					{
        						fwrite(&parity,1,1 ,f3);
        						parity_index=(parity_index-1)%n;
        					}
        					else
        						{
        							fwrite(buff+j,1,1 ,f3);
        							j++;
        						}
        					break;
        			case 3:if(i==parity_index)
        					{
        						fwrite(&parity,1,1 ,f4);
        						parity_index=(parity_index-1)%n;
        					}
        					else
        						{
        							fwrite(buff+j,1,1 ,f4);
        							j++;
        						}
        					break;
        			case 4:if(i==parity_index)
        					{
        						fwrite(&parity,1,1 ,f5);
        						parity_index=(parity_index-1)%n;
        					}
        					else
        						{
        							fwrite(buff+j,1,1 ,f5);
        							j++;
        						}
        					break;
        			default:break;

        		}
        	}        	

        }
        if (nread < 4)
        {
            if (feof(fp))
                printf("file saved\n");
            if (ferror(fp))
                printf("Error reading\n");
            break;      
        }
    }
}
int main()
{
	string filepath;
	cout<<"Enter file path: ";
	cin>>filepath;
	insert(filepath);
	return 0;
}