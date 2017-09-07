Tab tabInt(Tab *t, unsigned int i){
	return tab(t,i,sizeof(int));
}

int tabInt_getEl(Tab *t, unsigned int i){
	int *c=tab_getEl(t,i);
	return *c;
}

tabInt_setEl(Tab *t, unsigned int i, int c){
	int *c1=tab_getEl(t,i);
	*c1=c;
}