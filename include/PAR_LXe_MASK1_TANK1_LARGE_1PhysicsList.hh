#ifndef PAR_LXe_MASK1_TANK1_LARGE_1PhysicsList_h
#define PAR_LXe_MASK1_TANK1_LARGE_1PhysicsList_h 1

#include "G4VUserPhysicsList.hh"
#include "globals.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

class PAR_LXe_MASK1_TANK1_LARGE_1PhysicsList: public G4VUserPhysicsList
{
public:
  PAR_LXe_MASK1_TANK1_LARGE_1PhysicsList();
  ~PAR_LXe_MASK1_TANK1_LARGE_1PhysicsList();
  //  virtual ~PhysicsList();


public:
  virtual void SetCuts();


protected:
  // Construct particle and physics
  virtual void ConstructParticle();
  virtual void ConstructProcess();
    
  // these methods Construct physics processes and register them
  virtual void AddTransportation();
  virtual void ConstructGeneral();
  virtual void ConstructEM();
  virtual void ConstructHad();
  virtual void ConstructOp();


  /*
  // these methods Construct all particles in each category
  virtual void ConstructAllBosons();
  virtual void ConstructAllLeptons();
  virtual void ConstructAllMesons();
  virtual void ConstructAllBaryons();
  virtual void ConstructAllIons();
  virtual void ConstructAllShortLiveds();
  */

private:
  G4int VerboseLevel;
  G4int OpVerbLevel;

  G4double cutForGamma;
  G4double cutForElectron;
  G4double cutForPositron;
  G4double cutForProton;
  G4double cutForAlpha;
  G4double cutForGenericIon;

  // these methods Construct particles 
  void ConstructMyBosons();
  void ConstructMyLeptons();
  void ConstructMyHadrons();
  void ConstructMyShortLiveds();

};

#endif
