#ifndef __PAR_LXe_MASK1_TANK1_LARGE_1DC_H__
#define __PAR_LXe_MASK1_TANK1_LARGE_1DC_H__

class G4LogicalVolume;
class G4VPhysicalVolume;

#include "G4VUserDetectorConstruction.hh"

class PAR_LXe_MASK1_TANK1_LARGE_1DC : public G4VUserDetectorConstruction
{
  public:
    PAR_LXe_MASK1_TANK1_LARGE_1DC();
    virtual ~PAR_LXe_MASK1_TANK1_LARGE_1DC();

  public:
    virtual G4VPhysicalVolume* Construct();

  private:
    // Logical volumes
    G4LogicalVolume* experimentalHall_log;
    G4LogicalVolume* TANK_log;
    G4LogicalVolume* NeCH4_wi_log;
    G4LogicalVolume* wi_log;
    G4LogicalVolume* MASK1_log;
    G4LogicalVolume* MASK2_log;
    G4LogicalVolume* MASK3_log;
    G4LogicalVolume* MASK4_log;
    G4LogicalVolume* MASK5_log;
    G4LogicalVolume* MASK6_log;
    G4LogicalVolume* MASK7_log;
    G4LogicalVolume* MASK8_log;
    G4LogicalVolume* MASK9_log;
    G4LogicalVolume* TT_log;
    // Physical volumes
    G4VPhysicalVolume* experimentalHall_phys;
    G4VPhysicalVolume* TANK_phys;
    G4VPhysicalVolume* NeCH4_wi_phys;
    G4VPhysicalVolume* wi_phys;
    G4VPhysicalVolume* MASK1_phys;
    G4VPhysicalVolume* MASK2_phys;
    G4VPhysicalVolume* MASK3_phys;
    G4VPhysicalVolume* MASK4_phys;
    G4VPhysicalVolume* MASK5_phys;
    G4VPhysicalVolume* MASK6_phys;
    G4VPhysicalVolume* MASK7_phys;
    G4VPhysicalVolume* MASK8_phys;
    G4VPhysicalVolume* MASK9_phys;
    G4VPhysicalVolume* TT_phys;

 private:
	void DefineMaterials();
	void ConstructLaboratory();
	void SensitiveDete();
    
};

#endif
