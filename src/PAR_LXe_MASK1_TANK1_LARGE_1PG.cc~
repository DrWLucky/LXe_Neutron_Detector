//-------- GEANT4
#include "G4Event.hh"
#include "G4ParticleGun.hh"
#include "G4ParticleTable.hh"
#include "G4ParticleDefinition.hh"
#include "globals.hh"
#include "Randomize.hh"
//-------- User
#include "PAR_LXe_MASK1_TANK1_LARGE_1PG.hh"
//
#include <sys/time.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
extern FILE *out_file;
//
double acum_Py 		= 0.0;
double acum_Pz 		= 0.0;
double event_count 	= 0.0;
double impinging_count 	= 0.0;
double P_energy = 0.0;
double y_TT         = 0.0;
double z_TT         = 0.0;

PAR_LXe_MASK1_TANK1_LARGE_1PG::PAR_LXe_MASK1_TANK1_LARGE_1PG()
{
  G4int n_particle = 1;
  particleGun = new G4ParticleGun(n_particle);
  G4ParticleTable* particleTable = G4ParticleTable::GetParticleTable();
  G4String particleName;
  particleGun->SetParticleDefinition(particleTable->FindParticle(particleName="neutron"));
//  particleGun->SetParticleEnergy(8.0*MeV);
}

PAR_LXe_MASK1_TANK1_LARGE_1PG::~PAR_LXe_MASK1_TANK1_LARGE_1PG()
{
  delete particleGun;
}

void PAR_LXe_MASK1_TANK1_LARGE_1PG::GeneratePrimaries(G4Event* anEvent)
{
  struct timeval hTimeValue;
  gettimeofday(&hTimeValue, NULL);
 // DDD CLHEP::HepRandom::setTheEngine(new CLHEP::DRand48Engine);
 // DDD CLHEP::HepRandom::setTheSeed(hTimeValue.tv_usec);
 
// ======================Energy=====================
////For NEUTRONS
//  P_energy = ( 6 + (-2*G4UniformRand()*4) + 4 );  //for neutron- continiuos spectrum between 2-10 MeV

////For GAMMA     //for gamma- specific energy [MeV]
//P_energy = 4.4; //[MeV]
// if (G4UniformRand()<=0.5)
//  {P_energy = 15.1;}   //[MeV]                       

////SPECIFIC ENERGY [MeV]
//P_energy = 7.75;  //[MeV]

//////SPECIFIC ENERGIES - 1 [MeV]
////G4double step1 =0.07692307692307692307692307692308;//=1/13;
//G4double step1 =0.07142857142857142857142857142857;//=1/14;
//G4double rand_num =G4UniformRand();
//if (rand_num<=1*step1)
//  {P_energy = 2;}   //[MeV]
//if (rand_num>1*step1 && rand_num<=(2*step1))
//  {P_energy = 3;}   //[MeV]
//if (rand_num>2*step1 && rand_num<=(3*step1))
//  {P_energy = 4;}   //[MeV]
//if (rand_num>3*step1 && rand_num<=(4*step1))
//  {P_energy = 5;}   //[MeV]
//if (rand_num>4*step1 && rand_num<=(5*step1))
//  {P_energy = 6;}   //[MeV]
//if (rand_num>5*step1 && rand_num<=(6*step1))
//  {P_energy = 7;}   //[MeV]
//if (rand_num>6*step1 && rand_num<=(7*step1))
//  {P_energy = 8;}   //[MeV]
//if (rand_num>7*step1 && rand_num<=(8*step1))
//  {P_energy = 9;}   //[MeV]
//if (rand_num>8*step1 && rand_num<=(9*step1))
//  {P_energy = 10;}   //[MeV]
//if (rand_num>9*step1 && rand_num<=(10*step1))
//  {P_energy = 11;}   //[MeV]
//if (rand_num>10*step1 && rand_num<=(11*step1))
//  {P_energy = 12;}   //[MeV]
//if (rand_num>11*step1 && rand_num<=(12*step1))
//  {P_energy = 13;}   //[MeV]
//if (rand_num>12*step1 && rand_num<=(13*step1))
//  {P_energy = 14;}   //[MeV]
//if (rand_num>13*step1 && rand_num<=(14*step1))
//  {P_energy = 15;}   //[MeV]
//

////SPECIFIC ENERGIES - 2 [MeV]
G4double step1 =0.11111111111111111111111111111111;//=1/9;
G4double rand_num =G4UniformRand();
if (rand_num<=1*step1)
  {P_energy = 0.1;}   //[MeV]
if (rand_num>1*step1 && rand_num<=(2*step1))
  {P_energy = 0.25;}   //[MeV]
if (rand_num>2*step1 && rand_num<=(3*step1))
  {P_energy = 0.5;}   //[MeV]
if (rand_num>3*step1 && rand_num<=(4*step1))
  {P_energy = 1;}   //[MeV]
if (rand_num>4*step1 && rand_num<=(5*step1))
  {P_energy = 5;}   //[MeV]
if (rand_num>5*step1 && rand_num<=(6*step1))
  {P_energy = 10;}   //[MeV]
if (rand_num>6*step1 && rand_num<=(7*step1))
  {P_energy = 20;}   //[MeV]
if (rand_num>7*step1 && rand_num<=(8*step1))
  {P_energy = 50;}   //[MeV]
if (rand_num>8*step1 && rand_num<=(9*step1))
  {P_energy = 100;}   //[MeV]


  particleGun->SetParticleEnergy(P_energy*MeV);
  
    //===================Position===================
  //particleGun->SetParticlePosition(G4ThreeVector(-0.5*cm, 0.0, 0.0));
  
//  G4double capillary_r = 0.25*mm; //in mm
    G4double capillary_r = 0.5*mm; //in mm
//  G4double capillary_r = 0.3*cm;// Capillary radius     <================================
  G4double capillary_spacer = capillary_r*0.2; //in mm
  G4double square_HalfWall = capillary_r+capillary_spacer;
  G4double DetectorSurface = 12.0*cm;//10.0*cm;//9.0*cm;//5.0*cm;
  
  //random square position
  //For random positoin in the center-capillary cell
//  G4double y_ran = ((G4UniformRand()*square_HalfWall*2)-square_HalfWall)*mm;
//  G4double z_ran = ((G4UniformRand()*square_HalfWall*2)-square_HalfWall)*mm;
  //For random position in all detector position
  G4double y_ran = ((G4UniformRand()*DetectorSurface*2)-DetectorSurface);
  G4double z_ran = ((G4UniformRand()*DetectorSurface*2)-DetectorSurface);
//  G4cout << "y_ran " << y_ran << " z_ran "<< z_ran << G4endl;
//EEEE G4cout <<  y_ran << " " << z_ran << G4endl;

//  //random circle position
//////  G4double Theta = twopi*G4UniformRand();
//////  G4double Ra = capillary_r*G4UniformRand();
//////  G4double y_ran = Ra*cos(Theta)*mm;
//////  G4double z_ran = Ra*sin(Theta)*mm;
// G4double RR=0.5*mm;  //capillay radius in mm
// G4double r2 = RR*sqrt(G4UniformRand());
// G4double theta2=2*pi*G4UniformRand();
//   //convert to cartesian
//    G4double y_ran=r2*cos(theta2);
//    G4double z_ran=r2*sin(theta2);
//G4cout <<  "===="<<y_ran << " " << z_ran << G4endl;
  particleGun->SetParticlePosition(G4ThreeVector(-5.9*m, y_ran, z_ran));
  //===================END OF Position===================
  
//===================Momentum===================
  G4ThreeVector v(1.0,0.0,0.0);
  particleGun->SetParticleMomentumDirection(v);

////creating isotropic source
//  G4double cosTheta = -1.0+2.0*G4UniformRand();
//  G4double phi = twopi*G4UniformRand();
//  G4double sinTheta = sqrt(1-cosTheta*cosTheta);
//  //these are the cosines for an isotropic direction
//  particleGun -> SetParticleMomentumDirection(G4ThreeVector(sinTheta*cos(phi),
//							    sinTheta*sin(phi),
//							    cosTheta));
							    
	//===================END OF Momentum===================	
//	G4cout << "2000  2000  2000  2000  "<< G4endl;
// ---fprintf(out_file,"2000  2000  2000  2000\n");	
 
 acum_Py = 0.0;
 acum_Pz = 0.0;		
 event_count = 0.0 ;
 y_TT    = 0.0;
 z_TT    = 0.0;
 impinging_count=impinging_count+1;		    
  particleGun->GeneratePrimaryVertex(anEvent);

}


