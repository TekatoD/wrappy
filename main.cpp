#include <iostream>
#include "WrapPy.h"

using namespace std;

int main() {
    int x = 100;
    int y = 5;
//    double c[5] = {1, 2, 3, 4, 5};
//    PyObject *nP = PyTuple_New(5);
//    for (int i = 0; i < 5; ++i) {
//        PyTuple_SetItem(nP, i, PyFloat_FromDouble(c[i]));
//    }
    WrapPy py_mult_by("privet", "mult", "(i)", "/home/tekatod/ClionProjects/wrappy/", x);
    py_mult_by.call_py_func("multiply", "(i)", y);
//    py_mult_by.call_py_func("calculate_super_sin", "(dd)", 3.14, 1.57);
//    py_mult_by.call_py_func("print_arr", "(O)", nP);
    py_mult_by.call_py_func("info");
    /*
     LD_PRELOAD=/usr/lib/libtcmalloc.so.4.3.0 HEAPCHECK=normal /home/tekatod/.CLion2016.1/system/cmake/generated/wrappy-4965967c/4965967c/Debug/wrappy
*/
    return 0;
}