struct Tab{
	unsigned int nbEl;
	unsigned char sizeEl;
	unsigned char *ad;
};
typedef struct Tab Tab;

Tab tab(Tab *t, unsigned int i, size_t size){
	(*t).nbEl=i;
	(*t).sizeEl=size;
	(*t).ad=malloc(size*i);
	if((*t).ad==NULL){
		printf("tab: Allocation mémoire refusée!");
		exit(0);
	}
	return *t;
}

void *tab_getEl(Tab *t,unsigned int i){
	if(i<(*t).nbEl){
		return (*t).ad+(*t).sizeEl*i;
	}else{
		printf("tab_getEl: index trog grand!\n");
	}
	return NULL;
}

void *tab_getAd(Tab t){
	return t.ad;
}

tab_free(Tab *t){
	free((*t).ad);
}