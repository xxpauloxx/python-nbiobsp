#include <iostream>
#include "pynbiobsp.h"

#include <boost/python/module.hpp>
#include <boost/python/def.hpp>

using namespace boost::python;

// Registrando os métodos do módulo.
BOOST_PYTHON_MODULE(pynbiobsp)
{
    def("init", pynbiobspInit);
    def("capture", pynbiobspCapture);
    def("match", pynbiobspMatch);
    def("close", pynbiobspClose);
}