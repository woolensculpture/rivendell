// btacs82.h
//
// A Rivendell switcher driver for the BroadcastTools ACS 8.2
//
//   (C) Copyright 2002-2008,2016 Fred Gleason <fredg@paravelsystems.com>
//
//   This program is free software; you can redistribute it and/or modify
//   it under the terms of the GNU General Public License version 2 as
//   published by the Free Software Foundation.
//
//   This program is distributed in the hope that it will be useful,
//   but WITHOUT ANY WARRANTY; without even the implied warranty of
//   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//   GNU General Public License for more details.
//
//   You should have received a copy of the GNU General Public
//   License along with this program; if not, write to the Free Software
//   Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
//

#ifndef BTACS82_H
#define BTACS82_H

#include <rd.h>
#include <rdmatrix.h>
#include <rdmacro.h>
#include <rdtty.h>
#include <rdoneshot.h>

#include <switcher.h>

#define BTACS82_UNIT_ID 0
#define BTACS82_POLL_INTERVAL 100
#define BTACS82_GPIO_PINS 16

class BtAcs82 : public Switcher
{
 Q_OBJECT
 public:
  BtAcs82(RDMatrix *matrix,QObject *parent=0);
  ~BtAcs82();
  RDMatrix::Type type();
  unsigned gpiQuantity();
  unsigned gpoQuantity();
  bool primaryTtyActive();
  bool secondaryTtyActive();
  void processCommand(RDMacro *cmd);

 private slots:
  void processStatus();
  void gpiOneshotData(int value);
  void gpoOneshotData(int value);

 private:
  RDTTYDevice *bt_device;
  RDOneShot *bt_gpi_oneshot;
  RDOneShot *bt_gpo_oneshot;
  int bt_matrix;
  int bt_inputs;
  int bt_outputs;
  int bt_gpis;
  int bt_gpos;
  int bt_istate;
  bool bt_gpi_state[BTACS82_GPIO_PINS];
  bool bt_gpi_mask[BTACS82_GPIO_PINS];
};


#endif  // BTACS82_H
