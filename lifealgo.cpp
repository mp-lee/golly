                        /*** /

This file is part of Golly, a Game of Life Simulator.
Copyright (C) 2008 Andrew Trevorrow and Tomas Rokicki.

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.

 Web site:  http://sourceforge.net/projects/golly
 Authors:   rokicki@gmail.com  andrew@trevorrow.com

                        / ***/
#include "lifealgo.h"
#include "string.h"
using namespace std ;
lifealgo::~lifealgo() {
   poller = 0 ;
   maxCellStates = 2 ;
}
int lifealgo::verbose ;
int staticAlgoInfo::nextAlgoId = 0 ;
staticAlgoInfo *staticAlgoInfo::head = 0 ;
staticAlgoInfo::staticAlgoInfo() {
   id = nextAlgoId++ ;
   next = head ;
   head = this ;
}
staticAlgoInfo *staticAlgoInfo::byName(const char *s) {
   for (staticAlgoInfo *i=head; i; i=i->next)
      if (strcmp(i->algoName, s) == 0)
	 return i ;
   return 0 ;
}
int staticAlgoInfo::nameToIndex(const char *s) {
   staticAlgoInfo *r = byName(s) ;
   if (r == 0)
      return -1 ;
   return r->id ;
}
staticAlgoInfo &staticAlgoInfo::tick() {
   return *(new staticAlgoInfo()) ;
}
