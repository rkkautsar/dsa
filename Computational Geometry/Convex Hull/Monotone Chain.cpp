bool cmp(point a,point b){
	if(a.x==b.x) return a.y<b.y;
	return a.x<b.x;
}

vector<point> monotone_chain(vector<point> p){
	sort(p.begin(),p.end(),cmp);
	
	vector<point> upper,lower;
	int n=p.size();
	for(int i=0;i<n;++i){
		while(upper.size()>=2 && cross3(upper[upper.size()-2],upper[upper.size()-1],p[i])<=0) upper.pop_back();
		upper.push_back(p[i]);
	}

	for(int i=n-1;i>=0;--i){
		while(lower.size()>=2 && cross3(lower[lower.size()-2],lower[lower.size()-1],p[i])<=0) lower.pop_back();
		lower.push_back(p[i]);
	}

	for(int i=1;i<lower.size();++i)upper.push_back(lower[i]);

	return upper;
}