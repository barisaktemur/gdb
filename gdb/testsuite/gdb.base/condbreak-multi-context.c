/* This testcase is part of GDB, the GNU debugger.

   Copyright 2020 Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

void
func1 (int *value)
{
  int a = 10;
  value += a;
  int b = 1;
#include "condbreak-multi-context-included.c"
}

void
func2 (int *value)
{
  int b = 2;
#include "condbreak-multi-context-included.c"
}

void
func3 (int *value)
{
  int c = 30;
  value += c;
  int b = 3;
#include "condbreak-multi-context-included.c"
}

int
main ()
{
  int val = 0;
  func1 (&val);
  func2 (&val);
  func3 (&val);
  return 0;
}
