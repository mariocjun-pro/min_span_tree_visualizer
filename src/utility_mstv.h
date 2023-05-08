#pragma once 
#include "node.h"
#include <vector>

class Node;

using SharedNodePtr = std::shared_ptr<class Node>;

namespace mstv_utility {

	SharedNodePtr BinarySearch(std::vector<SharedNodePtr>& node_list_sorted, std::pair<int, int> coord);
	void SortNodeVector(std::vector<SharedNodePtr>& node_list_unsorted);
	void PrintPoints(std::vector<std::pair<int, int>>& points);
	
	template <class T>
	const char * ConvertToStr(T var) {
	
	}

}