// rdxport.h
//
// Rivendell web service portal
//
//   (C) Copyright 2010,2014,2016 Fred Gleason <fredg@paravelsystems.com>
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


#ifndef RDXPORT_H
#define RDXPORT_H

#include <qobject.h>

#include <rdaudioconvert.h>
#include <rdconfig.h>
#include <rdformpost.h>
#include <rdstation.h>
#include <rdsvc.h>
#include <rdsystem.h>
#include <rduser.h>

#define STRINGIZE(x) STRINGIZE2(x)
#define STRINGIZE2(x) #x
#define LINE_NUMBER QString(STRINGIZE(__LINE__)).toInt()

class Xport : public QObject
{
 public:
  enum LockLogOperation {LockLogCreate=0,LockLogUpdate=1,LockLogClear=2};
  Xport(QObject *parent=0);

 private:
  bool Authenticate();
  void TryCreateTicket(const QString &name);
  void Export();
  void Import();
  void DeleteAudio();
  void AddCart();
  void ListCarts();
  void ListCart();
  void EditCart();
  void RemoveCart();
  void AddCut();
  void ListCuts();
  void ListCut();
  void EditCut();
  void CheckPointerValidity(int ptr_values[2],bool use_ptrs[2],
			    const QString &type,unsigned max_value);
  void RemoveCut();
  void ListGroups();
  void ListGroup();
  void ExportPeaks();
  void TrimAudio();
  void CopyAudio();
  void AudioInfo();
  void AudioStore();
  void AddLog();
  void DeleteLog();
  void ListLogs();
  void ListLog();
  RDSvc *GetLogService(const QString &svc_name);
  bool ServiceUserValid(const QString &svc_name);
  void Rehash();
  void SaveLog();
  void ListSchedCodes();
  void AssignSchedCode();
  void UnassignSchedCode();
  void ListCartSchedCodes();
  void ListServices();
  void ListSystemSettings();
  void LockLog();
  QString LogLockXml(bool result,const QString &log_name,const QString &guid,
		     const QString &username,const QString &stationname,
		     const QHostAddress addr) const;
  void Exit(int code);
  void XmlExit(const QString &msg,int code,
	       const QString &srcfile="",int line=-1,
	       RDAudioConvert::ErrorCode err=RDAudioConvert::ErrorOk);
  RDFormPost *xport_post;
  RDUser *xport_user;
  RDConfig *xport_config;
  RDSystem *xport_system;
  RDStation *xport_station;
  QString xport_remote_hostname;
  QHostAddress xport_remote_address;
};


#endif  // RDXPORT_H
