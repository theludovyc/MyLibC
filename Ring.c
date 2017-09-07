struct Case{
	struct Case *pre;
	struct Case *post;
};
typedef struct Case Case;

struct Ring{
	Case *cursor;
	unsigned char pos;
	unsigned char nbEl;
};
typedef struct Ring Ring;

Ring ring0(Ring *r){
	(*r).pos=0;
	(*r).nbEl=0;
	return *r;
}

void *ring_get(Ring r){
	return r.cursor+sizeof(Case)-1;
}

void *ring_add(Ring *r, size_t size){
	Case *c=malloc(sizeof(Case)+size);
	if(c==NULL){
		printf("Ring add: Allocation mémoire refusée");
		exit(0);
	}
	(*r).cursor=c;
	(*r).nbEl=1;
	return ring_get(*r);
}

Ring ring1(Ring *r, size_t size){
	ring_add(r,size);
	(*r).pos=0;
	return *r;
}

char ring_getPos(Ring r){
	return r.pos;
}

char ring_getNbEl(Ring r){
	return r.nbEl;
}

void *ring_rollUp(Ring *r){
	(*r).cursor=(*(*r).cursor).post;
	if(ring_getPos(*r)+1==ring_getNbEl(*r)){
		(*r).pos=0;
	}else{
		(*r).pos++;
	}
	return ring_get(*r);
}

void *ring_addUp(Ring *r, size_t size){
	if(ring_getNbEl(*r)==0){
		return ring_add(r,size);
	}else if(ring_getNbEl(*r)==1){
		Case *c=malloc(sizeof(Case)+size);
		if(c==NULL){
			printf("Ring addUp: Allocation mémoire refusée");
			exit(0);
		}
		(*(*r).cursor).pre=c;
		(*(*r).cursor).post=c;
		(*c).pre=(*r).cursor;
		(*c).post=(*r).cursor;
		(*r).cursor=c;
		(*r).pos=1;
		(*r).nbEl=2;
		return ring_get(*r);
	}else{
		Case *c=malloc(sizeof(Case)+size);
		if(c==NULL){
			printf("Ring addUp: Allocation mémoire refusée");
			exit(0);
		}
		(*c).pre=(*r).cursor;
		(*c).post=(*(*r).cursor).post;
		(*(*r).cursor).post=c;
		(*r).nbEl++;
		ring_rollUp(r);
		(*(*(*r).cursor).post).pre=(*r).cursor;
		return ring_get(*r);
	}
}

void *ring_rollDown(Ring *r){
	(*r).cursor=(*(*r).cursor).pre;
	if(ring_getPos(*r)==0){
		(*r).pos=ring_getNbEl(*r)-1;
	}else{
		(*r).pos--;
	}
	return ring_get(*r);
}

ring_remUp(Ring *r){
	if(ring_getNbEl(*r)==1){
		free((*r).cursor);
		(*r).cursor=NULL;
		(*r).pos=0;
		(*r).nbEl=0;
	}else if(ring_getNbEl(*r)==2){
		free((*(*r).cursor).post);
		(*(*r).cursor).post=NULL;
		(*(*r).cursor).pre=NULL;
		(*r).pos=0;
		(*r).nbEl=1;
	}else{
		Case *c=(*(*r).cursor).post;
		free(c+sizeof(c));
		(*(*r).cursor).post=(*c).post;
		free(c);
		if(ring_getPos(*r)!=0&&ring_getPos(*r)==ring_getNbEl(*r)-1){
			(*r).pos--;
		}
		(*r).nbEl--;
	}
}

ring_remDown(Ring *r){
	if(ring_getNbEl(*r)==1){
		free((*r).cursor);
		(*r).cursor=NULL;
		(*r).pos=0;
		(*r).nbEl=0;
	}else if(ring_getNbEl(*r)==2){
		free((*(*r).cursor).pre);
		(*(*r).cursor).post=NULL;
		(*(*r).cursor).pre=NULL;
		(*r).pos=0;
		(*r).nbEl=1;
	}else{
		Case *c=(*(*r).cursor).pre;
		free(c+sizeof(c));
		(*(*r).cursor).pre=(*(*(*r).cursor).pre).pre;
		free(c);
		if(ring_getPos(*r)!=0){
			(*r).pos--;
		}
		(*r).nbEl--;
	}
}

ring_remAndUp(Ring *r){
	if(ring_getNbEl(*r)==1){
		free((*r).cursor);
		(*r).cursor=NULL;
		(*r).pos=0;
		(*r).nbEl=0;
	}else if(ring_getNbEl(*r)==2){
		Case *c=(*(*r).cursor).post;
		free((*r).cursor);
		(*r).cursor=c;
		(*(*r).cursor).post=NULL;
		(*(*r).cursor).pre=NULL;
		(*r).pos=0;
		(*r).nbEl=1;
	}else{
		Case *c=(*(*r).cursor).post;
		Case *c1=(*(*r).cursor).pre;
		free((*r).cursor);
		(*r).cursor=c;
		(*(*r).cursor).pre=c1;
		if(ring_getPos(*r)==ring_getNbEl(*r)-1){
			(*r).pos=0;
		}
		(*r).nbEl--;
	}
}

ring_remAndDown(Ring *r){
	if(ring_getNbEl(*r)==1){
		free((*r).cursor);
		(*r).cursor=NULL;
		(*r).pos=0;
		(*r).nbEl=0;
	}else if(ring_getNbEl(*r)==2){
		Case *c=(*(*r).cursor).pre;
		free((*r).cursor);
		(*r).cursor=c;
		(*(*r).cursor).post=NULL;
		(*(*r).cursor).pre=NULL;
		(*r).pos=0;
		(*r).nbEl=1;
	}else{
		Case *c=(*(*r).cursor).pre;
		Case *c1=(*(*r).cursor).post;
		free((*r).cursor);
		(*r).cursor=c;
		(*(*r).cursor).post=c1;
		if(ring_getPos(*r)!=0){
			(*r).pos--;
		}
		(*r).nbEl--;
	}
}

ring_goToFirst(Ring *r){
	if(ring_getPos(*r)==ring_getNbEl(*r)-1){
		ring_rollUp(r);
	}else if(ring_getPos(*r)>(ring_getNbEl(*r)-1)/2){
		while(ring_getPos(*r)!=0){
			ring_rollUp(r);
		}
	}else{
		while(ring_getPos(*r)!=0){
			ring_rollDown(r);
		}
	}
}

ring_goToLast(Ring *r){
	if(ring_getPos(*r)==0){
		ring_rollDown(r);
	}else if(ring_getPos(*r)>(ring_getNbEl(*r)-1)/2){
		while(ring_getPos(*r)!=ring_getNbEl(*r)-1){
			ring_rollUp(r);
		}
	}else{
		while(ring_getPos(*r)!=ring_getNbEl(*r)-1){
			ring_rollDown(r);
		}
	}
}

ring_freeUp(Ring *r){
	while(ring_getNbEl(*r)>0){
		ring_remUp(r);
	}
}

ring_freeDown(Ring *r){
	while(ring_getNbEl(*r)>0){
		ring_remDown(r);
	}
}

ring_freeAndUp(Ring *r){
	while(ring_getNbEl(*r)>0){
		ring_remAndUp(r);
	}
}

ring_freeAndDown(Ring *r){
	while(ring_getNbEl(*r)>0){
		ring_remAndDown(r);
	}
}