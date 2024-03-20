#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <vector>
#include <queue>
#include <iostream>
#include <string>
#include <set>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

struct Point {
	int x;
	int y;

	bool operator < (const Point& b) const {
		if (x == b.x)
			return y < b.y;
		else
			return x < b.x;
	}
};

vector<Point> pts;

bool xcmp(Point a, Point b) {
	if (a.x == b.x)
		return a.y < b.y;
	else
		return a.x < b.x;
}

bool ycmp(Point a, Point b) {
	return a.y < b.y;
}


int dist(Point a, Point b) {
	return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}


int search_three(int left, int right) {

	int min_result = 0;
	for (int i = left; i <= right - 1; i++)
		for (int j = i + 1; j <= right; j++)
		{
			int dst = dist(pts[i], pts[j]);
			if (min_result == 0 || (min_result > dst))
				min_result = dst;
		}

	return min_result;
}


int search(int left, int right) {

	if (right - left + 1 <= 3)
		return search_three(left, right);

	int mid_point = (left + right) / 2;
	int left_min = search(left, mid_point);
	int right_min = search(mid_point + 1, right);

	int ans = (left_min < right_min ? left_min : right_min);

	// time to search middle area
	vector<Point> middle_area;
	for (int i = left; i <= right; i++)
	{
		int x_dist = pts[i].x - pts[mid_point].x;
		if (x_dist * x_dist < ans)
			middle_area.push_back(pts[i]);
	}

	// only check y*y < ans
	sort(middle_area.begin(), middle_area.end(), ycmp);

	int rest_size = middle_area.size();
	for (int i = 0; i < rest_size - 1; i++)
		for (int j = i + 1; j < rest_size; j++)
		{
			int y_dist = middle_area[j].y - middle_area[i].y;
			if (y_dist * y_dist < ans)
			{
				int value = dist(middle_area[i], middle_area[j]);
				if (value < ans)
					ans = value;
			}
			else // don't need to search rest points which are larger than ans
				break;

		}

	return ans;
}


int main()
{
	int N;
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		Point p;
		scanf("%d %d", &p.x, &p.y);
		pts.push_back(p);
	}

	sort(pts.begin(), pts.end(), xcmp);
	printf("%d\n", search(0, pts.size() - 1));

	return 0;
}