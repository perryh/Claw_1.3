#ifndef GLOBAL_H_INCLUDED
#define GLOBAL_H_INCLUDED
#pragma once

#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>

using namespace std;

typedef unsigned char BYTE;
typedef unsigned short WORD;
typedef unsigned long DWORD;

// From Spasm's Autopot
#define GetBYTE(Pointer) *reinterpret_cast<const BYTE*>(Pointer)
#define GetWORD(Pointer) *reinterpret_cast<const WORD*>(Pointer)
#define GetDWORD(Pointer) *reinterpret_cast<const DWORD*>(Pointer)

#endif