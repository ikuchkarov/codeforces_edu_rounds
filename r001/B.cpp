#include <iostream>
#include <string>

int main() {
	std::ios_base::sync_with_stdio(0);
	
	std::string s;
	std::cin >> s;
	
	int m;
	std::cin >> m;
	while (m-- > 0) {
		int left, right, shift;
		std::cin >> left >> right >> shift;
		
		int substr_length = right - left + 1;
		shift %= substr_length;
		
		--left, --right; //to C-style index (starting with 0)
		
		s = s.substr(0, left) + 
			s.substr(right - shift + 1, shift) +
			s.substr(left, right - shift - left + 1) +
			s.substr(right + 1);
	}
	
	std::cout << s;
}
