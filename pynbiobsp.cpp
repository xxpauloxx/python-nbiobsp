#include <iostream>
#include "pynbiobsp.h"

#include <boost/python/module.hpp>
#include <boost/python/def.hpp>

using namespace boost::python;

// Registering the module methods.
BOOST_PYTHON_MODULE(pynbiobsp)
{
    def("init", nbiobspInit);
    def("capture", nbiobspCapture);
    def("match", nbiobspMatch);
    def("close", nbiobspClose);
}