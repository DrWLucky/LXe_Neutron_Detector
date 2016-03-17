#ifndef PAR_LXe_MASK1_TANK1_LARGE_1SA_h
#define PAR_LXe_MASK1_TANK1_LARGE_1SA_h 1

#include "G4UserSteppingAction.hh"
#include "globals.hh"
#include <vector>

class PAR_LXe_MASK1_TANK1_LARGE_1SA : public G4UserSteppingAction
{
public:
  PAR_LXe_MASK1_TANK1_LARGE_1SA();
  virtual ~PAR_LXe_MASK1_TANK1_LARGE_1SA();

  void UserSteppingAction(const G4Step*);
  G4double m_y;
  G4double m_z;
  G4double cou;
};

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#endif
