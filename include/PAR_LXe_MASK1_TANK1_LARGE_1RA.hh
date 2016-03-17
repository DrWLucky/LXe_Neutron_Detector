#ifndef __PAR_LXe_MASK1_TANK1_LARGE_1RA_H__
#define __PAR_LXe_MASK1_TANK1_LARGE_1RA_H__

#include "G4UserRunAction.hh"
#include "globals.hh"
#include <vector>

class G4Run;

class PAR_LXe_MASK1_TANK1_LARGE_1RA : public G4UserRunAction
{
public:
  // constructor and destructor
 PAR_LXe_MASK1_TANK1_LARGE_1RA();
  virtual ~PAR_LXe_MASK1_TANK1_LARGE_1RA();

public:
  // virtual method from G4UserRunAction.
  virtual G4Run* GenerateRun();
  virtual void BeginOfRunAction(const G4Run*);
  virtual void EndOfRunAction(const G4Run*);


private:
  // Data member 
  // - vector of MultiFunctionalDetecor names.
  std::vector<G4String> theSDName;  

};

#endif
