/*
 *   Copyright (C) 2016 by Jonathan Naylor G4KLX
 *
 *   This program is free software; you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation; either version 2 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program; if not, write to the Free Software
 *   Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

#if !defined(HD44780_H)
#define	HD44780_H

#if defined(RASPBERRY_PI)

#include "Display.h"

#include <string>

class CHD44780 : public IDisplay
{
public:
  CHD44780(unsigned int rows, unsigned int cols);
  virtual ~CHD44780();

  virtual bool open();

  virtual void setIdle();

  virtual void setLockout();

  virtual void setDStar();
  virtual void writeDStar(const char* my1, const char* my2, const char* your);
  virtual void clearDStar();

  virtual void setDMR();
  virtual void writeDMR(unsigned int slotNo, unsigned int srdId, bool group, unsigned int dstId, const char* type);
  virtual void clearDMR(unsigned int slotNo);

  virtual void setFusion();
  virtual void writeFusion(const char* source, const char* dest);
  virtual void clearFusion();

  virtual void close();

private:
	unsigned int m_rows;
	unsigned int m_cols;
	int          m_fd;
};

#endif

#endif