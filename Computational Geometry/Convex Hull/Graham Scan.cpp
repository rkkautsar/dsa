//global pivot
point pivot;

bool anglecmp(point a,point b){
	if(cross(pivot,a,b)==0)
		return dist(pivot,a)<dist(pivot,b);
	return cross(pivot,a,b)<0;
}

vector<point> graham(vector<point> p){
    int i,j,n=p.size();
  
    if(n<=3) {
        if(!(p[0]==p[n-1])) p.push_back(p[0]);
        return p;
    }
  	

  	//find the pivot
    int p0=0;
    for(i=1;i<n;++i){
        if(p[p0].y==p[i].y){
            if(p[i].x < p[p0].x) p0=i;
        } else if(p[i].y<p[p0].y) p0=i;
    }
  
    swap(p[p0],p[0]);
  
    pivot=p[0];
  
    sort(++p.begin(),p.end(),anglecmp);
      
    vector<point> s;
  
    s.push_back(p[n-1]);
    s.push_back(p[0]);
    s.push_back(p[1]);
  
  
    i=2;
    while(i<n){
    	j=s.size()-1;
        while(!(cross(s[j-1],s[j],p[i])<0) && s.size()>=2) s.pop_back();
        s.push_back(p[i++]);
    }
      
    return s;
}