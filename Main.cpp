#include <pybind11/pybind11.h>
#include "Graph.h"
#include "Edge.h"

using namespace std;
namespace py = pybind11;

struct Pet {
	Pet(const string &name) : name(name) {
		ed = Edge(5, 3);
	}
	void setName(const string &name_) { name = name_; }
	const string &getName() const { return name; }
	int getFrom() { return ed.getFrom(); }
	Edge ed;
	string name;
};

PYBIND11_MODULE(main, m) {
	py::class_<Pet>(m, "Pet")
	.def(py::init<const std::string &>())
	.def("setName", &Pet::setName)
	.def("getName", &Pet::getName)
	.def("getFrom", &Pet::getFrom);
}