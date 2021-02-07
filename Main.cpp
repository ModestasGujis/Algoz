#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "Graph.h"
#include "Edge.h"

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
}