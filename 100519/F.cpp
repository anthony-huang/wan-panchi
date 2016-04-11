#include <bits/stdc++.h>

using namespace std;

double xa,xb,xc,ya,yb,yc,t1,t2,t3,t4,d,v,w,jarak_ab,jarak_ac,jarak_bc,dimi,petr,alex;

int main() {
	scanf("%lf%lf%lf%lf%lf%lf",&xa,&ya,&xc,&yc,&xb,&yb);
	scanf("%lf%lf",&d,&v);
	scanf("%lf:%lf %lf:%lf",&t1,&t2,&t3,&t4);
	scanf("%lf",&w);
	
	jarak_ab = sqrt((xa-xb)*(xa-xb) + (ya-yb)*(ya-yb));
	jarak_bc = sqrt((xb-xc)*(xb-xc) + (yb-yc)*(yb-yc));
	jarak_ac = sqrt((xa-xc)*(xa-xc) + (ya-yc)*(ya-yc));
	
	alex += jarak_ab / v;
	alex += d / 60.0;
	alex += jarak_bc / v;
	
	dimi += (t1 + t2 / 60.0) - (9.0 + 0.0 / 60.0);
	dimi += (t3 + t4 / 60.0);
	
	petr += jarak_ac / w;
	if (fabs(jarak_ab + jarak_bc - jarak_ac) < 1e-9) petr += d / 60.0;
	
	//printf("alex = %.6lf\n",alex);
	//printf("dimi = %.6lf\n",dimi);
	//printf("petr = %.6lf\n",petr);
	
	if (alex < dimi && alex < petr) printf("Alex\n"); else
	if (dimi < petr) printf("Dmitry\n"); else
	printf("Petr\n");
}