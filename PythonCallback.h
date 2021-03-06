// Kallisti Online RPG Library Modules for Python
// Copyright (C) 2006 Alistair Riddoch
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
// GNU General Public License for more details.
// 
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software Foundation,
// Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA

#ifndef KALLISTI_PYTHONCALLBACK_H
#define KALLISTI_PYTHONCALLBACK_H

#include <Python.h>

class PythonCallback {
  protected:
    PyObject * m_callback;
  public:
    explicit PythonCallback(PyObject * callable);
    ~PythonCallback();

    void call();
};

template <typename T>
PyObject * wrap(T);

template <typename T>
class PythonCallback1 {
  protected:
    PyObject * m_callback;
  public:
    explicit PythonCallback1(PyObject * callable);
    ~PythonCallback1();

    void call(T);
};

template <typename T, typename U>
class PythonCallback2 {
  protected:
    PyObject * m_callback;
  public:
    explicit PythonCallback2(PyObject * callable);
    ~PythonCallback2();

    // void callPtrs(T *, U *);
    void call(T, U);
    // void callPtr2(T &, U *);
    // void call(T &, U &);
};

#endif // KALLISTI_PYTHONCALLBACK_H
