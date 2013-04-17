#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc,char* argv[])
{
	FILE* fp=NULL;
	int sz;
	int i,j;
	int ct,no;
	char name[256];	
	char arg_name[256];	
	unsigned char*p;
	
	int ss=2048;
	
	
	if(argc<2){
		printf("error:bin2vb filename\n");
		return 1;
	}
	fp=fopen(argv[1],"rb");
	if(fp==NULL){
		printf("error:fopen error\n");
		return 1;		
	}
	fseek(fp,0,SEEK_END);
	sz=ftell(fp);
	fseek(fp,0,SEEK_SET);
	
	strcpy(name,argv[1]);
	strcpy(arg_name,argv[1]);
	p=strchr(name,'.');
	if(p)*p=0;

	while(p=strchr(name,'\\')){
		*p='_';
	}
	while(p=strchr(arg_name,'\\')){
		*p='/';
	}
	while(p=strchr(name,'/')){
		*p='_';
	}
	
	if(sz<1){
		printf("error:size error\n");
		return 1;		
	}
	ct=(sz-1+ss)/ss;
	p=malloc(sz);
	fread(p,1,sz,fp);
	
	for(j=0;j<ct;j++){

		printf("Sub WriteFile_%s_%d\n",name,j);
		no=sz-ss*j;
		if(no>=ss)no=ss;
	
		printf("Dim a(0 To %d) As Byte\n",no-1);
		
		for(i=0;i<no;i++){
			printf("a(%d)=%d",i,p[ss*j+i]);
			if(i%8==7)printf("\n");
			else printf(": ");
		}
		printf("\n");
    	printf("Dim file As Integer\n");
	    printf("file = FreeFile\n");
    	printf("Open \"%s\" For Binary As #file\n",arg_name);
	    printf("Put #file,%d , a\n",j*ss+1);
    	printf("Close #file\n");
	 	printf("\n");
 	
		printf("End Sub\n\n");	
	}
	printf("Sub WriteFile_%s\n",name);
	for(j=0;j<ct;j++){
		printf("WriteFile_%s_%d\n",name,j);
	}
	printf("End Sub\n\n");	

		
	free(p);
	fclose(fp);

	return 0;
}

