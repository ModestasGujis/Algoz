#include <pybind11/pybind11.h>
#include "Graph.h"
#include "Edge.h"

using namespace std;
namespace py = pybind11;

// struct Pet {
// 	Pet(const string &name) : name(name) {
// 		ed = Edge(5, 3);
// 		g = Graph();
// 	}
// 	void setName(const string &name_) { name = name_; }
// 	const string &getName() const { return name; }
// 	int getFrom() { return ed.getFrom(); }
// 	int addVertex() {}
// 	Edge ed;
// 	string name;
// };

PYBIND11_MODULE(main, m) {
	py::class_<Graph>(m, "Graph")
	.def(py::init<int>())
	.def("addVertex", &Graph::addVertex)
	.def("getEdgeCnt", &Graph::getEdgeCnt)
	.def("addEdge", &Graph::addEdge)
	.def("getVertexCnt", &Graph::getVertexCnt);
}