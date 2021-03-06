/*
 * ***** BEGIN GPL LICENSE BLOCK *****
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 *
 * The Original Code is Copyright (C) 2001-2002 by NaN Holding BV.
 * All rights reserved.
 *
 * The Original Code is: all of this file.
 *
 * Contributor(s): none yet.
 *
 * ***** END GPL LICENSE BLOCK *****
 */

/** \file KX_PythonInit.h
 *  \ingroup ketsji
 */

#ifndef __KX_PYTHONINIT_H__
#define __KX_PYTHONINIT_H__

#include "EXP_Python.h"
#include "STR_String.h"
#include "MT_Vector3.h"

class KX_KetsjiEngine;

#ifdef WITH_PYTHON
PyMODINIT_FUNC initBGE(void);
PyMODINIT_FUNC initApplicationPythonBinding(void);
PyMODINIT_FUNC initGameLogicPythonBinding(void);
PyMODINIT_FUNC initGameKeysPythonBinding(void);
PyMODINIT_FUNC initRasterizerPythonBinding(void);
PyMODINIT_FUNC initVideoTexturePythonBinding(void);
PyObject *initGamePlayerPythonScripting(struct Main *maggie, int argc, char **argv);
PyObject *initGamePythonScripting(struct Main *maggie);

void exitGamePlayerPythonScripting();
void exitGamePythonScripting();
void setupGamePython(KX_KetsjiEngine *ketsjiengine, Main *blenderdata,
                     PyObject *pyGlobalDict, PyObject **gameLogic, PyObject **gameLogic_keys, int argc, char **argv);
void setGamePythonPath(const char *path);
void resetGamePythonPath();
void pathGamePythonConfig(char *path);
int saveGamePythonConfig(char **marshal_buffer);
int loadGamePythonConfig(char *marshal_buffer, int marshal_length);
#endif

void addImportMain(struct Main *maggie);
void removeImportMain(struct Main *maggie);

typedef int (*PyNextFrameFunc)(void *);

struct PyNextFrameState {
	/** can be either a GPG_NextFrameState or a BL_KetsjiNextFrameState */
	void *state;
	/** can be either GPG_PyNextFrame or BL_KetsjiPyNextFrame */
	PyNextFrameFunc func;
};
extern struct PyNextFrameState pynextframestate;

#endif  /* __KX_PYTHONINIT_H__ */
