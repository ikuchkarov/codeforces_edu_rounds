#include <iostream>

using namespace std;

long long calc_next_two_degree(long long n) {
	long long x = 1;
	while (x <= n) {
		x *= 2;
	}
	return x;
}

int main() {
	ios_base::sync_with_stdio(0);
	
	int test_count = 0;
	cin >> test_count;
	while (test_count-- > 0) {
		int n = 0;
		cin >> n;
		
		long long sum_of_arithm_progr = (long long) (1 + n) * n / 2;
		
		long long next_two_degree = calc_next_two_degree(n);
		long long sum_of_geom_progr = (next_two_degree - 1) / (2 - 1);
		
		cout << sum_of_arithm_progr - 2 * sum_of_geom_progr << endl;
	}
	
	
}
