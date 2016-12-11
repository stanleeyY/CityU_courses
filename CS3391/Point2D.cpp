struct Point2D {
	int x, y;
};
int areaX2(Point2D &a, Point2D &b, Point2D &c) {
	int i1, i2, i3, i4;
	i1 = b.x - a.x;
	i2 = c.y - a.y;
	i3 = c.x - a.x;
	i4 = b.y - a.y;
	int result = i1*i2 - i3*i4;
	return result;
}
int leftSide(Point2D &a, Point2D &b, Point2D &c) {
	return (areaX2(a, b, c) > 0);
}
int leftSideOn(Point2D &a, Point2D &b, Point2D &c) {
	return (areaX2(a, b, c) >= 0);
}
int collinear(Point2D &a, Point2D &b, Point2D &c) {
	return (areaX2(a, b, c) == 0);
}
bool between(Point2D &a, Point2D &b, Point2D &c) {
	Point2D  ba, ca;
	if (!collinear(a, b, c))
		return false;
	if (a.x != b.x) // Line A-B is not Vertical
		return (((a.x <= c.x) && (c.x <= b.x)) ||
			((a.x >= c.x) && (c.x >= b.x)));
	else
		return (((a.y <= c.y) && (c.y <= b.y)) ||
			((a.y >= c.y) && (c.y >= b.y)));
}