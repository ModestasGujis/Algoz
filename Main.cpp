#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "Graph.h"
#include "Edge.h"
#include "DSU.h"

using namespace std;
namespace py = pybind11;

PYBIND11_MODULE(main, m) {
	py::class_<Graph>(m, "Graph")
	.def(py::init<int, bool>(), py::arg("_vertexCnt") = 1, py::arg("_weighted") = false)
	.def(py::init<int, vector<int>, vector<int>, vector<int>>())
	.def(py::init<int, vector<int>, vector<int>>())
	.def("addVertex", &Graph::addVertex)
	.def("getEdgeCnt", &Graph::getEdgeCnt)
	.def("addEdge", &Graph::addEdge, py::arg("a"), py::arg("b"), py::arg("w") = 1)
	.def("getVertexCnt", &Graph::getVertexCnt)
	.def("shortestDistance", &Graph::shortestDistance)
	.def("shortestPath", &Graph::shortestPath);

	py::class_<DSU>(m, "DSU")
	.def(py::init<int>())
	.def("getSize", static_cast<int (DSU::*)()>(&DSU::getSize))
	.def("getSize", static_cast<int (DSU::*)(int)>(&DSU::getSize))
	.def("findSet", &DSU::findSet)
	.def("isSameSet", &DSU::isSameSet)
	.def("unionSet", &DSU::unionSet);
}