ring1_remUp(Ring *r, void *v, size_t size){
	if(ring_getNbEl(*r)==1){
		tool_memCopy(ring_get(*r),v,size);
		free((*r).cursor);
		(*r).cursor=NULL;
		(*r).pos=0;
		(*r).nbEl=0;
	}else if(ring_getNbEl(*r)==2){
		tool_memCopy((*(*r).cursor).post+sizeof(Case)-1,v,size);
		free((*(*r).cursor).post);
		(*(*r).cursor).post=NULL;
		(*(*r).cursor).pre=NULL;
		(*r).pos=0;
		(*r).nbEl=1;
	}else{
		tool_memCopy((*(*r).cursor).post+sizeof(Case)-1,v,size);
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

ring1_remDown(Ring *r, void *v, size_t size){
	if(ring_getNbEl(*r)==1){
		tool_memCopy(ring_get(*r),v,size);
		free((*r).cursor);
		(*r).cursor=NULL;
		(*r).pos=0;
		(*r).nbEl=0;
	}else if(ring_getNbEl(*r)==2){
		tool_memCopy((*(*r).cursor).pre+sizeof(Case)-1,v,size);
		free((*(*r).cursor).pre);
		(*(*r).cursor).post=NULL;
		(*(*r).cursor).pre=NULL;
		(*r).pos=0;
		(*r).nbEl=1;
	}else{
		tool_memCopy((*(*r).cursor).pre+sizeof(Case)-1,v,size);
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