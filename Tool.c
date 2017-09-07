#define null NULL

tool_memCopy(void*v,void*v1,size_t size){
	unsigned int i;
	for(i=0;i<size;i++){
		char *c=v+i;
		char *c1=v1+i;
		*c1=*c;
	}
}

int tool_getCharTabSize(char c[]){
	int i=0;
	while(c[i]!=0){
		i++;
	}
	return i;
}

/*char *tool_intToCharTab(int i){
	int i1=1;
	int i2=1;
	char c=0;
	while((i/i1)>=10){
		i1*=10;
		i2++;
	}
	char c1[i2+1];
	int i3=0;
	do{
		c='0'+i/i1;
		c1[i3]=c;
		i=i-i1*(i/i1);
		i1/=10;
		i3++;
		if(i3==i2-1&&i==0){
			c1[i3]='0';
			i3++;
			break;
		}
	}while(i>0);
	c1[i2]='\0';
	return c1;
}*/