#include <iostream>
#include <cmath>
#include <vector>
#include <utility>
#include <algorithm>

struct Point {
	long long x;
	long long y;
	
	Point(long long x, long long y)
		:x(x)
		,y(y) {}
	
	bool inTop() const {
		return y > 0 || (y == 0 && x > 0);
	}
	
	long long cross(const Point& other) const {
		return x * other.y - y * other.x;
	}
	
	long long dot(const Point& other) const {
		return x * other.x + y * other.y;
	}
	
	//compare by angle with OX
	bool operator<(const Point& other) const {
		//check upper and lower half-planes
		if (inTop() != other.inTop()) {
			//in different half-planes
			return inTop();
		} else {
			//in same half-planes
			return cross(other) > 0;
		}
	}
};

bool isFirstAngleLess(const std::pair<Point, Point> & p1, const std::pair<Point, Point> & p2) {
	Point projection1(p1.first.dot(p1.second), abs(p1.first.cross(p1.second)));
	Point projection2(p2.first.dot(p2.second), abs(p2.first.cross(p2.second)));
	return projection1 < projection2;	
}


int main() {
	std::ios_base::sync_with_stdio(0);
	
	long long n;
	std::cin >> n;
	
	std::vector<std::pair<Point, long long> > points;
	
	for (long long i = 1; i <= n; ++i) {
		long long x, y;
		std::cin >> x >> y;		
		points.push_back(std::make_pair(Point(x,y), i));
	}
	
	std::sort(points.begin(), points.end());
	
	std::pair<Point, Point> best_pair = std::make_pair(points[0].first, points[n-1].first);
	std::pair<long long, long long> best_indices(points[0].second, points[n-1].second);
	for (long long i = 1; i < n; ++i) {
		std::pair<Point, Point> cur_pair = std::make_pair(points[i].first, points[i-1].first);
		if (isFirstAngleLess(cur_pair, best_pair)) {
			best_pair = cur_pair;
			best_indices = std::make_pair(points[i].second, points[i-1].second);
		}
	}
	
	std::cout << best_indices.first << " " << best_indices.second << std::endl;
	
	return 0;
}
