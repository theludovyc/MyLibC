Ring ringInt(Ring *r, int i){
	ring1(r,sizeof(int));
	int *tmp=ring_get(*r);
	*tmp=i;
	return *r;
}

int ringInt_get(Ring r){
	int *tmp=ring_get(r);
	return *tmp;
}

ringInt_set(Ring *r, int i){
	int *tmp=ring_get(*r);
	*tmp=i;
}

int ringInt_rollUp(Ring *r){
	int *tmp=ring_rollUp(r);
	return *tmp;
}

ringInt_addUp(Ring *r,int i){
	int *tmp=ring_addUp(r,sizeof(int));
	*tmp=i;
}

int ringInt_rollDown(Ring *r){
	int *tmp=ring_rollDown(r);
	return *tmp;
}

int ringInt_remUp(Ring *r){
	int i;
	ring_remUp(r,&i,sizeof(int));
	return i;
}

int ringInt_remDown(Ring *r){
	int i;
	ring_remDown(r,&i,sizeof(int));
	return i;
}