ringChar_addUp(Ring *r,char c){
	char *c1=ring_addUp(r,sizeof(char));
	*c1=c;
}

char ringChar_get(Ring r){
	char *c1=ring_get(r);
	return *c1;
}

ringChar_set(Ring r,char c){
	char *c1=ring_get(r);
	*c1=c;
}

ringChar_inTab(Ring r,char c[]){
	if(getNbEl(r)<=sizeof(c)-1){
		ring_goToFirst(r);
		int i=0;
		do{
			c[i]=ringChar_get(r);
			i++;
		}while(ring_getPos(r)!=0);
	}else{
		printf("ringChar_inTab: Size of tab is too much!!!");
		exit(1);
	}
}