# $Id: GNUmakefile,v 1.1 February 2011 
# --------------------------------------------------------------
# GNUmakefile for LXe module.  Marco Corte, 09/02/2011.
# --------------------------------------------------------------

name := PAR_LXe_MASK1_TANK1_LARGE_1
G4TARGET := $(name)
G4EXLIB := true

ifndef G4INSTALL
  G4INSTALL = ../../..
endif

#ifndef G4TMP
#  G4TMP = /home3/cortesi_m/g4/exe/tmp
#endif

#ifndef G4BIN
#  G4BIN = /home3/cortesi_m/g4/exe/bin
#endif

.PHONY: all
all: lib bin

include $(G4INSTALL)/config/binmake.gmk

