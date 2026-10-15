for(auto it=mp.begin();it!=mp.end();){
	if(it->se<50) it=mp.erase(it);
	else ++it;
	show("sz",mp.size());
}
