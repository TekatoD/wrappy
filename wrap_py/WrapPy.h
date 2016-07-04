//
// Created by tekatod on 6/28/16.
//

#ifndef PY_WRAP_WRAPPY_H
#define PY_WRAP_WRAPPY_H

#include <Python.h>
#include <malloc.h>
#include <string>
//#include <iostream>

class WrapPy {
public:
    template<class T, class T1, class T2, class ... Types>
    WrapPy(T py_file, T1 py_class, T2 init_sign, std::string mod_p, Types ... args) {
        module_path(mod_p);
        dict_initialize((char*)py_file, (char*)py_class);
        if(pClass != NULL) {
            if(PyCallable_Check(pClass)) {
                pInstance = PyObject_CallObject(pClass, NULL);
                PyErr_Print();
            }
        }
        Py_DECREF(pModule);
        Py_DECREF(pName);
        call_py_func("rd_init", init_sign, args...);
    }

    WrapPy(char* py_file, char* py_class, std::string mod_p);

    template<class T, class T1, class ... Types>
    void call_py_func(T py_method, T1 signature, Types ... args) {
        if(pInstance != NULL) {
            pValue = PyObject_CallMethod(pInstance, (char *) py_method, signature, args...);
            PyErr_Print();
            Py_DECREF(pValue);
        }
//            std::cout << pValue << std::endl;
    }

    void call_py_func(char* py_method);

    ~WrapPy();

private:
    void dict_initialize(char* py_file, char* py_name);
    void module_path(std::string mod_p);
    PyObject *pInstance, *pName, *pModule, *pDict, *pClass, *pValue;
};


#endif //PY_WRAP_WRAPPY_H
