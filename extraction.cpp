#include <bits/stdc++.h>
using namespace std;

void extract()
{
	//int extension=get_filename(filepath);
	int parity_index=0,n=5;
    string filepath="/home/rohit/Dropbox/raid/extracted_files/f";
	string source_filepath1="/home/rohit/Dropbox/raid/raid_files/f1";
	string source_filepath2="/home/rohit/Dropbox/raid/raid_files/f2";
	string source_filepath3="/home/rohit/Dropbox/raid/raid_files/f3";
	string source_filepath4="/home/rohit/Dropbox/raid/raid_files/f4";
	string source_filepath5="/home/rohit/Dropbox/raid/raid_files/f5";
	FILE *fp = fopen(filepath.c_str(),"wb");
	FILE *f1 = fopen(source_filepath1.c_str(),"rb");
	FILE *f2 = fopen(source_filepath2.c_str(),"rb");
	FILE *f3 = fopen(source_filepath3.c_str(),"rb");
	FILE *f4 = fopen(source_filepath4.c_str(),"rb");
	FILE *f5 = fopen(source_filepath5.c_str(),"rb");
    if(fp==NULL || f1==NULL ||f2==NULL ||f3==NULL ||f4==NULL ||f5==NULL )
    {
        printf("File open error");
        return;
    }   
    //cout<<endl;

    cout<<"starting extraction..."<<endl;
    while(1)
    {
        unsigned char buff[4]={0},temp;       

    	int j=0,flag=0;
    	for(int i=0;i<n && flag==0;i++)
    	{
            //cout<<"for loop for "<<i<<endl;
    		switch(i)
    		{
    			case 0:if(i==parity_index)
    					{    				        
                            fread(&temp,1,1,f1);
    					}
    					else
						{
							int nread=fread(buff+j,1,1,f1);
							j++;
                            if(nread<=0)
                                flag=1;
							//cout<<"file "<<i<<"   buff "<<j<<": "<<buff[j-1]<<endl;
						}
    					break;
    			case 1:if(i==parity_index)
    					{
    						fread(&temp,1,1,f2);
    					}
    					else
						{
							int nread=fread(buff+j,1,1,f2);
                            j++;
                            if(nread<=0)
                                flag=1;
							//cout<<"file "<<i<<"   buff "<<j<<": "<<buff[j-1]<<endl;
						}
    					break;
    			case 2:if(i==parity_index)
    					{
    						fread(&temp,1,1,f3);
    					}
    					else
						{
							int nread=fread(buff+j,1,1,f3);
                            j++;
                            if(nread<=0)
                                flag=1;
							//cout<<"file "<<i<<"   buff "<<j<<": "<<buff[j-1]<<endl;
						}
    					break;
    			case 3:if(i==parity_index)
    					{
    						fread(&temp,1,1,f4);
    					}
    					else
						{
							int nread=fread(buff+j,1,1,f4);
                            j++;
                            if(nread<=0)
                                flag=1;
							//cout<<"file "<<i<<"   buff "<<j<<": "<<buff[j-1]<<endl;
						}
    					break;
    			case 4:if(i==parity_index)
    					{
    						fread(&temp,1,1,f5);
    					}
    					else
						{
							int nread=fread(buff+j,1,1,f5);
                            j++;
                            if(nread<=0)
                                flag=1;
							//cout<<"file "<<i<<"   buff "<<j<<": "<<buff[j-1]<<endl;
						}
    					break;
    			default:break;

    		}	
    	}
        if(flag==0)
            fwrite(buff,1,4,fp);
        else
        {
            j--;
            if(j!=0)
                fwrite(buff,1,j,fp);
            break;
        }
    	parity_index=(parity_index+1)%n;        	

        /*
        if (nread < 4)
        {
            if (feof(fp))
                printf("file saved\n");
            if (ferror(fp))
                printf("Error reading\n");
            break;      
        }
        */
    }
    fclose(fp);
    fclose(f1);
    fclose(f2);
    fclose(f3);
    fclose(f4);
    fclose(f5);
}
int main()
{
	extract();
    cout<<"file extracted successfully"<<endl;
	return 0;
}