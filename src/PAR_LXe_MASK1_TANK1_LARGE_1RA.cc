#include "PAR_LXe_MASK1_TANK1_LARGE_1RA.hh"
#include "PAR_LXe_MASK1_TANK1_LARGE_1Run.hh"

#include "G4Region.hh"
#include "G4ProductionCuts.hh"
#include "G4SDManager.hh"
#include "G4RegionStore.hh"
#include "G4Region.hh"
#include "G4ProductionCuts.hh"
#include "G4ios.hh"
#include "G4UnitsTable.hh"
#include <assert.h>

PAR_LXe_MASK1_TANK1_LARGE_1RA::PAR_LXe_MASK1_TANK1_LARGE_1RA()
{
  theSDName.push_back(G4String("IonPro"));
}

PAR_LXe_MASK1_TANK1_LARGE_1RA::~PAR_LXe_MASK1_TANK1_LARGE_1RA()
{
  theSDName.clear();
}

G4Run* PAR_LXe_MASK1_TANK1_LARGE_1RA::GenerateRun()
{ 
  return new PAR_LXe_MASK1_TANK1_LARGE_1Run(theSDName);
}

void PAR_LXe_MASK1_TANK1_LARGE_1RA::BeginOfRunAction(const G4Run* aRun)
{
 G4cout << "*** Run " << aRun->GetRunID() << " start." << G4endl;
}

void PAR_LXe_MASK1_TANK1_LARGE_1RA::EndOfRunAction(const G4Run* aRun)
{
  static G4String regName = "IonPro";
  PAR_LXe_MASK1_TANK1_LARGE_1Run* PAR_LXe_MASK1_TANK1_LARGE_1R = (PAR_LXe_MASK1_TANK1_LARGE_1Run*)aRun;
}
