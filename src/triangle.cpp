#include "triangle.h"
#include <cmath>
#include <iostream>

Triangle::Triangle(std::pair<int, int> n1, std::pair<int, int> n2, std::pair<int, int> n3) {

	bool isACW = isAntiClockwise(n1, n2, n3);

	A = n1;
	B = isACW ? n2 : n3;
	C = isACW ? n3 : n2;
	edges = { edge(A, B),edge(B, C),edge(A, C) };
	vertices = { A,B,C };
	computeCircumcenter();
	computeCircumradius();
};

void Triangle::computeCircumcenter() {

	//see wikipedia article for Circumcircle equations

	float D = 2 * (A.first * (B.second - C.second) + B.first * (C.second - A.second) + C.first * (A.second - B.second));

	auto Ux = (1 / D) * ((std::pow(A.first, 2) + std::pow(A.second, 2)) * (B.second - C.second) + (std::pow(B.first, 2) + std::pow(B.second, 2)) * (C.second - A.second) + (std::pow(C.first, 2) + std::pow(C.second, 2)) * (A.second - B.second));
	auto Uy = (1 / D) * ((std::pow(A.first, 2) + std::pow(A.second, 2)) * (C.first - B.first) + (std::pow(B.first, 2) + std::pow(B.second, 2)) * (A.first - C.first) + (std::pow(C.first, 2) + std::pow(C.second, 2)) * (B.first - A.first));

	circumcenter = std::make_pair<float, float>(Ux, Uy);
}

void Triangle::computeCircumradius() {
	circumradius = sqrt(pow((A.first - circumcenter.first), 2) + pow(A.second - circumcenter.second, 2));
}

bool Triangle::ContainsEdge(edge e) {
	int sharedVertices = 0;
	for (const auto vertex : vertices) {
		if (vertex == e.first || vertex == e.second)
			sharedVertices++;
		if (sharedVertices == 2)
			return true;
	}
	return false;
}

bool isAntiClockwise(std::pair<int, int> A, std::pair<int, int> B, std::pair<int, int> C) {
	auto X = B.first * A.second + C.first * B.second + A.first * C.second; 
	auto Y = A.first * B.second + B.first * C.second + C.first * A.second;
	return X < Y ? true : false; 
}

bool operator!=(Triangle a, Triangle b)
{
	return (a.A != b.A) && (a.B != b.B) && (a.C != b.C);
}

bool operator==(Triangle a, Triangle b)
{
	return (a.A == b.A) && (a.B == b.B) && (a.C == b.C);
}

std::ostream& operator<<(std::ostream& stream, Triangle const& t) {
	stream << "Triangle: "
		<< "A( " << t.A.first << " ; " << t.A.second << " ) "
		<< "B( " << t.B.first << " ; " << t.B.second << " ) "
		<< "C( " << t.C.first << " ; " << t.C.second << " ) "
		<< std::endl;
	return stream;
}