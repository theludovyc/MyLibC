Tab tabChar0(Tab *t, unsigned int i){
	return tab(t,i,sizeof(char));
}

tabChar_setEl(Tab *t, unsigned int i, char c){
	char *c1=tab_getEl(t,i);
	*c1=c;
}

Tab tabChar1(Tab *t, char c[]){
	unsigned int i=0;
	while(c[i]!=0){
		i++;
	};
	tabChar0(t,i);
	int i1;
	for(i1=0;i1<(*t).nbEl;i1++){
		tabChar_setEl(t,i1,c[i1]);
	}
	return *t;
}

Tab tabChar2(Tab *t, int i){
	int i1=1;
	int i2=1;
	char c=0;
	while((i/i1)>=10){
		i1*=10;
		i2++;
	}
	tabChar0(t,i2+1);
	int i3=0;
	do{
		c='0'+i/i1;
		tabChar_setEl(t,i3,c);
		i=i-i1*(i/i1);
		i1/=10;
		i3++;
		if(i3==i2-1&&i==0){
			tabChar_setEl(t,i3,'0');
			i3++;
			break;
		}
	}while(i>0);
	tabChar_setEl(t,i2,'\0');
}

char tabChar_getEl(Tab t, unsigned int i){
	char *c=tab_getEl(&t,i);
	return *c;
}

int tabChar_search(Tab t,char c){
	int i;
	for(i=0;i<t.nbEl;i++){
		if(tabChar_getEl(t,i)==c){
			return i;
		}
	}
	return -1;
}

tabChar_goToTab(Tab t,char c[]){
	int i;
	for(i=0;i<t.nbEl;i++){
		c[i]=tabChar_getEl(t,i);
	}
}