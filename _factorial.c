#include <Python.h>
#include "factorial.h"

/* Docstrings */
static char module_docstring[] =
    "This module provides an interface for calculating the factorial in C.";
static char factorial_docstring[] =
    "Calculate the factorial of some given number";

/* Available functions */
static PyObject *factorial_factorial(PyObject *self, PyObject *args);

/* Module specification */
static PyMethodDef module_methods[] = {
    {"get_factorial", factorial_factorial, METH_VARARGS, factorial_docstring},
    {NULL, NULL, 0, NULL}
};

/* Initialize the module */
PyMODINIT_FUNC initfactorial(void)
{
    PyObject *m = Py_InitModule3("factorial", module_methods, module_docstring);
    if (m == NULL)
        return;

}

static PyObject *factorial_factorial(PyObject *self, PyObject *args)
{
    int n;

    /* Parse the input tuple */
    if (!PyArg_ParseTuple(args, "i", &n))
        return NULL;

    /* Call the external C function to compute the factorial. */
    int value = get_factorial(n);


    if (value < 0) {
        PyErr_SetString(PyExc_RuntimeError,
                    "factorial returned an impossible value.");
        return NULL;
    }

    /* Build the output tuple */
    PyObject *ret = Py_BuildValue("i", value);
    return ret;
}
