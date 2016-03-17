#ifndef PAR_LXe_MASK1_TANK1_LARGE_1PG_h
#define PAR_LXe_MASK1_TANK1_LARGE_1PG_h 1

#include "G4VUserPrimaryGeneratorAction.hh"

class G4ParticleGun;
class G4Event;

class PAR_LXe_MASK1_TANK1_LARGE_1PG : public G4VUserPrimaryGeneratorAction
{
  public:
    PAR_LXe_MASK1_TANK1_LARGE_1PG();
    ~PAR_LXe_MASK1_TANK1_LARGE_1PG();

  public:
    void GeneratePrimaries(G4Event* anEvent);

  private:
    G4ParticleGun* particleGun;
};

#endif


