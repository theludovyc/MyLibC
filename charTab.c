int charTab_length(const char c[]){
	int i=0;
	while(c[i]!='\0'){
		i++;
	}
	return i;
}

int charTab_toInt(const char c[]){
	int i=0;
	int i1;
	int i2=1;
	for(i1=charTab_length(c)-1;i1>-1;i1--){
		if(i1==0){
			if(c[i1]==45){
				i*=-1;
				break;
			}else if(c[i1]==43){
				break;
			}else{
				i+=(c[i1]-'0')*i2;
				break;
			}
		}else{
			i+=(c[i1]-'0')*i2;
			i2*=10;
		}
	}
	return i;
}

void charTab_withInt(char *c, int i){
	int i1=1;
	int i2=1;
	int i3=0;
	char c1=0;
	while((i/i1)>=10){
		i1*=10;
		i2++;
	}
	do{
		c1='0'+i/i1;
		c[i3]=c1;
		i=i-i1*(i/i1);
		i1/=10;
		i3++;
	}while(i3<i2);
}