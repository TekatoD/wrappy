//
// Created by tekatod on 6/28/16.
//

#include "WrapPy.h"

WrapPy::WrapPy(char* py_file, char* py_class, std::string mod_p) {
    module_path(mod_p);
    dict_initialize(py_file, py_class);
    if(pClass != NULL) {
        if(PyCallable_Check(pClass)) {
            pInstance = PyObject_CallObject(pClass, NULL);
        }
        PyErr_Print();
    }
    Py_DECREF(pModule);
    Py_DECREF(pName);
}

/////////////////////////////////////////////////////////////

void WrapPy::dict_initialize(char *py_file, char *py_class) {
//    Py_Initialize();
//            pName = PyBytes_FromString((char*)py_file);
    pName = PyUnicode_DecodeFSDefault(py_file);
    if(pName != NULL) {
        pModule = PyImport_Import(pName);
        PyErr_Print();
    }
    if(pModule != NULL) {
        pDict = PyModule_GetDict(pModule);
        PyErr_Print();
    }
    if(pDict != NULL) {
        pClass = PyDict_GetItemString(pDict, py_class);
        PyErr_Print();
    }
}

/////////////////////////////////////////////////////////////

void WrapPy::call_py_func(char *py_method) {
    if(pInstance != NULL) {
        pValue = PyObject_CallMethod(pInstance, py_method, NULL);
        Py_DECREF(pValue);
    }
}

/////////////////////////////////////////////////////////////

void WrapPy::module_path(std::string mod_p){
    std::string m_p = "import sys\nsys.path.insert(0, \"" + mod_p + "\")";
    Py_Initialize();
    PyRun_SimpleString(m_p.c_str());
};

/////////////////////////////////////////////////////////////

WrapPy::~WrapPy() {
    Py_Finalize();
}