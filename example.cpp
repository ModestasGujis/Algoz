#include <pybind11/pybind11.h>
#include "Graph.h"

using namespace std;
namespace py = pybind11;

struct Pet {
	Pet(const string &name) : name(name) { }
	void setName(const string &name_) { name = name_; }
	const string &getName() const { return name; }

	string name;
};

PYBIND11_MODULE(example, m) {
	py::class_<Pet>(m, "Pet")
	.def(py::init<const std::string &>())
	.def("setName", &Pet::setName)
	.def("getName", &Pet::getName);
}

// PYBIND11_MODULE(example, m) {
//     m.doc() = "pybind11 example plugin"; // optional module docstring

//     m.def("add", &add, "A function which adds two numbers");
// }