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

#include "eris_connection.h"
#include "eris_account.h"
#include "eris_avatar.h"
#include "eris_view.h"
#include "eris_polldefault.h"

#include <Eris/Log.h>

#include <sigc++/functors/functors.h>

#include <iostream>

void log_output(Eris::LogLevel lvl, const std::string &msg)
{
    std::cout << "[ErisLog] " << msg << std::endl << std::flush;
}

static PyMethodDef no_methods[] = {
    {NULL,          NULL}                       /* Sentinel */
};

PyMODINIT_FUNC
initkallisti()
{
    PyObject * kallisti = Py_InitModule("kallisti", no_methods);

    if (kallisti == NULL) {
        return;
    }

    PyObject * eris = PyModule_New("eris");

    if (eris == NULL) {
        return;
    }

    if (PyType_Ready(&PyErisConnection_Type) < 0) {
        // ????
        return;
    }
    PyModule_AddObject(eris, "Connection", (PyObject *)&PyErisConnection_Type);

    if (PyType_Ready(&PyErisAccount_Type) < 0) {
        // ????
        return;
    }
    PyModule_AddObject(eris, "Account", (PyObject *)&PyErisAccount_Type);

    if (PyType_Ready(&PyErisAvatar_Type) < 0) {
        // ????
        return;
    }
    PyModule_AddObject(eris, "Avatar", (PyObject *)&PyErisAvatar_Type);

    if (PyType_Ready(&PyErisView_Type) < 0) {
        // ????
        return;
    }
    PyModule_AddObject(eris, "View", (PyObject *)&PyErisView_Type);

    PyObject * polldefault = Py_InitModule("polldefault", polldefault_methods);

    if (polldefault == NULL) {
        return;
    }
    // We have a borrowed reference, and PyModule_AddObject steals a reference
    Py_INCREF(polldefault);
    PyModule_AddObject(eris, "polldefault", polldefault);

    PyModule_AddObject(kallisti, "eris", eris);

    Eris::setLogLevel(Eris::LOG_DEBUG);
    Eris::Logged.connect(sigc::ptr_fun(&log_output));
}
