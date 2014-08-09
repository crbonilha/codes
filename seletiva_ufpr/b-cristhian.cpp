#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <math.h>
using namespace std;
const int MAXN = 50001;

int n;
pair<int, int> shrek, v[MAXN];
int vs, vc;
double sum[MAXN];

int bb(double goal);
double my_abs(double a);

int main() {
	scanf("%d %d %d", &n, &shrek.first, &shrek.second);
	for(int i=0; i<n; i++) {
		scanf("%d %d", &v[i].first, &v[i].second);
	}
	scanf("%d %d", &vs, &vc);
	
	double ini = 0, mid, end = sum[0] = 0;
	for(int i=1; i<n; i++) {
		end += hypot( double(my_abs(v[i].first-v[i-1].first)),
	                  double(my_abs(v[i].second-v[i-1].second)) )/vc;
	    sum[i] = end;
	}
	
	bool ok = false;
	double ans = sum[n-1]+1;
	for(int i=0; i<64; i++) {
		mid = (ini+end)/2.0;
		
		int j = bb(mid)-1;
		double perc = ((mid-sum[j])*100.0)/(sum[j+1]-sum[j]);
		pair<double, double> p = make_pair(
			double(v[j].first + double(v[j+1].first-v[j].first)*perc/100.0),
			double(v[j].second + double(v[j+1].second-v[j].second)*perc/100.0)
		);
		
		if(double(hypot( my_abs(p.first-shrek.first), my_abs(p.second-shrek.second) ))/vs <= mid) {
			ans = min(ans, mid);
			ok = true;
			end = mid;
		} else {
			ini = mid;
		}
	}
	
	if(!ok) printf("impossivel\n");
	else printf("%.2lf\n", ans);
}

int bb(double goal) {
	int ini = 0, mid, end = n, ans = n+1;
	
	while(ini < end) {
		mid = (ini+end)/2;
		
		if(goal <= sum[mid]) {
			ans = min(ans, mid);
			end = mid;
		} else {
			ini = mid+1;
		}
	}
	
	return ans;
}

double my_abs(double a) {
	return (a >= 0.0 ? a : -a);
}
