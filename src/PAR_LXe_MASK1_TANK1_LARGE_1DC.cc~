//-------- GEANT4
#include "G4Material.hh"
#include "G4NistManager.hh"
#include "G4Box.hh"
#include "G4Tubs.hh"
#include "G4AssemblyVolume.hh"
#include "G4Transform3D.hh"
#include "G4MultiFunctionalDetector.hh"
#include "G4VPrimitiveScorer.hh"
#include "G4SDParticleFilter.hh"
#include "G4PSEnergyDeposit.hh"
#include "G4OpticalSurface.hh"
#include "G4LogicalSkinSurface.hh"
#include "G4LogicalBorderSurface.hh"
//#include <G4Sphere.hh>
//#include <G4Orb.hh>
//#include <G4Polyhedra.hh>
//#include <G4Polycone.hh>
//#include <G4Ellipsoid.hh>
//#include <G4Trd.hh>
//#include <G4Cons.hh>
//#include <G4UnionSolid.hh>
//#include <G4IntersectionSolid.hh>
//#include <G4SubtractionSolid.hh>
#include "G4LogicalVolume.hh"
#include "G4PVPlacement.hh"
//#include "G4PVParameterised.hh>
#include "G4OpBoundaryProcess.hh"
#include "G4SDManager.hh"
#include "G4ThreeVector.hh"
#include "G4RotationMatrix.hh"
#include "G4VisAttributes.hh"
#include "G4Colour.hh"
#include "globals.hh"

#include "G4Isotope.hh"
#include "G4Element.hh"
#include "G4UnitsTable.hh"
//
//#include <vector>
//#include <numeric>
//#include <sstream>
//#include <algorithm>
//#include <cmath>
//#include <cassert>

//using std::vector;
//using std::stringstream;
//using std::max;

double GPM_Position=0;
double TT_Position=0;

//-------- User
#include "PAR_LXe_MASK1_TANK1_LARGE_1DC.hh"

PAR_LXe_MASK1_TANK1_LARGE_1DC::PAR_LXe_MASK1_TANK1_LARGE_1DC()
 :	experimentalHall_log(0),TANK_log(0),wi_log(0),MASK1_log(0),
    MASK2_log(0),MASK3_log(0),MASK4_log(0),MASK5_log(0),MASK6_log(0),
    MASK7_log(0),MASK8_log(0),MASK9_log(0),TT_log(0),
    experimentalHall_phys(0),TANK_phys(0),wi_phys(0),MASK1_phys(0),
    MASK2_phys(0),MASK3_phys(0),MASK4_phys(0),MASK5_phys(0),MASK6_phys(0),
    MASK7_phys(0),MASK8_phys(0),MASK9_phys(0),TT_phys(0)
{;}

PAR_LXe_MASK1_TANK1_LARGE_1DC::~PAR_LXe_MASK1_TANK1_LARGE_1DC()
{;}

G4VPhysicalVolume* PAR_LXe_MASK1_TANK1_LARGE_1DC::Construct()
{
  DefineMaterials();
  ConstructLaboratory();
  SensitiveDete();
  return experimentalHall_phys;
}

void
PAR_LXe_MASK1_TANK1_LARGE_1DC::DefineMaterials()
{
  G4NistManager* pNistManager = G4NistManager::Instance();
  //================================== elements ===================================
  G4Element *Xe = new G4Element("Xenon",     "Xe", 54., 131.293*g/mole);
  G4Element *H  = new G4Element("Hydrogen",  "H",  1.,  1.0079*g/mole);
  G4Element *C  = new G4Element("Carbon",    "C",  6.,  12.011*g/mole);
  G4Element *N  = new G4Element("Nitrogen",  "N",  7.,  14.007*g/mole);
  G4Element *O  = new G4Element("Oxygen",    "O",  8.,  15.999*g/mole);
  G4Element *F  = new G4Element("Fluorine",  "F",  9.,  18.998*g/mole);
  G4Element *Al = new G4Element("Aluminium", "Al", 13., 26.982*g/mole);
  G4Element *Si = new G4Element("Silicon",   "Si", 14., 28.086*g/mole);
  //G4Element *Cr = new G4Element("Chromium",  "Cr", 24., 51.996*g/mole);
  //G4Element *Mn = new G4Element("Manganese", "Mn", 25., 54.938*g/mole);
  G4Element *Fe = new G4Element("Iron",      "Fe", 26., 55.85*g/mole);
  //G4Element *Ni = new G4Element("Nickel",    "Ni", 28., 58.693*g/mole);
  //G4Element *Cu = new G4Element("Copper",    "Cu", 29., 63.546*g/mole);
  G4Element *Pb = new G4Element("Lead",      "Pb", 82., 207.2*g/mole);
  //G4Element *B  = pNistManager->FindOrBuildElement("B");
  //G4Element *Gd = pNistManager->FindOrBuildElement("Gd");
  G4Element *Ne  = new G4Element("Hydrogen",  "Ne",  10.,  20.18*g/mole);
    G4Element *W  = new G4Element("Tungsten",  "W",  74.,  183.84*g/mole);
    G4Element *U  = new G4Element("Uranium",  "U",  92.,  238.0289*g/mole);
////    G4Element *Pu  = new G4Element("Plutonium",  "Pu",  94.,  244*g/mole);
//     G4Isotope *Pu239  = new G4Isotope("Pu239",  94., 239.0,  239*g/mole);
//     G4Element* Pu = new G4Element("Plutonium", "Pu", 1);
//       Pu->AddIsotope(Pu239, 100.*perCent);

//From Geant4 menual:
//// define an Element from isotopes, by relative abundance
//   G4Isotope* U5 = new G4Isotope(name="U235", iz=92, n=235, a=235.01*g/mole);
//   G4Isotope* U8 = new G4Isotope(name="U238", iz=92, n=238, a=238.03*g/mole);
//   G4Element* elU = new G4Element(name="enriched Uranium", symbol="U", ncomponents=2);
//   elU->AddIsotope(U5, abundance= 90.*perCent);
//   elU->AddIsotope(U8, abundance= 10.*perCent);
   //================================== materials ================================== 
  //------------------------------------- air -------------------------------------
  pNistManager->FindOrBuildMaterial("G4_AIR");
  //----------------------------------- vacuum ------------------------------------
  G4Material *Vacuum = new G4Material("Vacuum", 1.e-20*g/cm3, 2, kStateGas);
  Vacuum->AddElement(N, 0.755);
  Vacuum->AddElement(O, 0.245);
  //-------------------------------- liquid xenon ---------------------------------
  G4Material *LXe = new G4Material("LXe", 2.85*g/cm3, 1, kStateLiquid, 168.15*kelvin, 1.5*atmosphere);
  LXe->AddElement(Xe, 1);
  const G4int iNbEntries = 3;
  G4double pdLXePhotonMomentum[iNbEntries]   = {6.91*eV, 6.98*eV, 7.05*eV};
  G4double pdLXeScintillation[iNbEntries]    = {0.1,     1.0,     0.1};
  G4double pdLXeRefractiveIndex[iNbEntries]  = {1.63,    1.61,    1.58};
  G4double pdLXeAbsorbtionLength[iNbEntries] = {100.*cm, 100.*cm, 100.*cm};
  G4double pdLXeScatteringLength[iNbEntries] = {30.*cm,  30.*cm,  30.*cm};
  G4MaterialPropertiesTable *pLXePropertiesTable = new G4MaterialPropertiesTable();
  pLXePropertiesTable->AddProperty("FASTCOMPONENT", pdLXePhotonMomentum, pdLXeScintillation, iNbEntries);
  pLXePropertiesTable->AddProperty("SLOWCOMPONENT", pdLXePhotonMomentum, pdLXeScintillation, iNbEntries);
  pLXePropertiesTable->AddProperty("RINDEX", pdLXePhotonMomentum, pdLXeRefractiveIndex, iNbEntries);
  pLXePropertiesTable->AddProperty("ABSLENGTH", pdLXePhotonMomentum, pdLXeAbsorbtionLength, iNbEntries);
  pLXePropertiesTable->AddProperty("RAYLEIGH", pdLXePhotonMomentum, pdLXeScatteringLength, iNbEntries);
//  pLXePropertiesTable->AddConstProperty("SCINTILLATIONYIELD", 0.0/keV);
  pLXePropertiesTable->AddConstProperty("SCINTILLATIONYIELD", 20./keV);  // for electron recoil
//  pLXePropertiesTable->AddConstProperty("SCINTILLATIONYIELD", 8.8/keV);   // for nuclear recoil
  pLXePropertiesTable->AddConstProperty("RESOLUTIONSCALE", 1.0);
  pLXePropertiesTable->AddConstProperty("FASTTIMECONSTANT", 3.*ns);
  pLXePropertiesTable->AddConstProperty("SLOWTIMECONSTANT", 27.*ns);
  pLXePropertiesTable->AddConstProperty("YIELDRATIO", 1.0);
  LXe->SetMaterialPropertiesTable(pLXePropertiesTable);
  
  //-------------------------------- gaseous xenon --------------------------------
  G4Material *GXe = new G4Material("GXe", 0.005887*g/cm3, 1, kStateGas, 173.15*kelvin, 1.5*atmosphere);
  GXe->AddElement(Xe, 1);
  G4double pdGXePhotonMomentum[iNbEntries]   = {6.91*eV, 6.98*eV, 7.05*eV};
  G4double pdGXeScintillation[iNbEntries]    = {0.1,     1.0,     0.1};
  G4double pdGXeRefractiveIndex[iNbEntries]  = {1.00,    1.00,    1.00};
  G4double pdGXeAbsorbtionLength[iNbEntries] = {100*m,   100*m,   100*m};
  G4double pdGXeScatteringLength[iNbEntries] = {100*m,   100*m,   100*m};
 
  G4MaterialPropertiesTable *pGXePropertiesTable = new G4MaterialPropertiesTable(); 
 
  pGXePropertiesTable->AddProperty("FASTCOMPONENT", pdGXePhotonMomentum, pdGXeScintillation, iNbEntries);
  pGXePropertiesTable->AddProperty("SLOWCOMPONENT", pdGXePhotonMomentum, pdGXeScintillation, iNbEntries);
  pGXePropertiesTable->AddProperty("RINDEX", pdGXePhotonMomentum, pdGXeRefractiveIndex, iNbEntries);
  pGXePropertiesTable->AddProperty("ABSLENGTH", pdGXePhotonMomentum, pdGXeAbsorbtionLength, iNbEntries);
  pGXePropertiesTable->AddProperty("RAYLEIGH", pdGXePhotonMomentum, pdGXeScatteringLength, iNbEntries);

  pGXePropertiesTable->AddConstProperty("SCINTILLATIONYIELD", 0./(keV));
  pGXePropertiesTable->AddConstProperty("RESOLUTIONSCALE", 0);
  pGXePropertiesTable->AddConstProperty("FASTTIMECONSTANT", 3.*ns);
  pGXePropertiesTable->AddConstProperty("SLOWTIMECONSTANT", 27.*ns);
  pGXePropertiesTable->AddConstProperty("YIELDRATIO", 1.0);

  GXe->SetMaterialPropertiesTable(pGXePropertiesTable); 

  //----------------------------------- Quartz ------------------------------------
  // ref: http://www.sciner.com/Opticsland/FS.htm
  G4Material *Quartz = new G4Material("Quartz", 2.201*g/cm3, 2, kStateSolid, 168.15*kelvin, 1.5*atmosphere);
  Quartz->AddElement(Si, 1);
  Quartz->AddElement(O, 2);

  const  G4int iNbEntriesMatch = 3;
  G4double pdQuartzPhotonMomentum[iNbEntriesMatch]   = {6.91*eV, 6.98*eV, 7.05*eV}; 
//  G4double pdQuartzRefractiveIndex[iNbEntriesMatch]  = {1.50,    1.56,    1.60};
  G4double pdQuartzRefractiveIndex[iNbEntriesMatch]  = {1.60,    1.60,    1.60};
  G4double pdQuartzAbsorbtionLength[iNbEntriesMatch] = {5.7*cm,    5.7*cm,    5.7*cm};
  G4double pdQuartzReflectivity[iNbEntriesMatch]    = {0.95,    0.95,    0.95};  

  G4MaterialPropertiesTable *pQuartzPropertiesTable = new G4MaterialPropertiesTable(); 

  pQuartzPropertiesTable->AddProperty("RINDEX", pdQuartzPhotonMomentum, pdQuartzRefractiveIndex, iNbEntriesMatch);
  pQuartzPropertiesTable->AddProperty("ABSLENGTH", pdQuartzPhotonMomentum, pdQuartzAbsorbtionLength, iNbEntriesMatch);
  pQuartzPropertiesTable->AddProperty("REFLECTIVITY", pdQuartzPhotonMomentum, pdQuartzReflectivity, iNbEntriesMatch);
  
  Quartz->SetMaterialPropertiesTable(pQuartzPropertiesTable);
////----------------------------------- MgF2 ------------------------------------
//  G4Material *MgF2 = new G4Material("MgF2", 3.177*g/cm3, 2, kStateSolid, 168.15*kelvin, 1.5*atmosphere);
//  MgF2->AddElement(Mg, 1);
//  MgF2->AddElement(F, 2);
//
//  
//  G4double pdMgF2PhotonMomentum[iNbEntriesMatch]   = {6.91*eV, 6.98*eV, 7.05*eV}; 
//  G4double pdMgF2RefractiveIndex[iNbEntriesMatch]  = {1.44,    1.44,    1.44};
//  G4double pdMgF2AbsorbtionLength[iNbEntriesMatch] = {30*m,    30*m,    30*m};  //<XXXXXXX
//  G4double pdMgF2Reflectivity[iNbEntriesMatch]    = {0.95,    0.95,    0.95};  //<XXXXXXX
//
//  G4MaterialPropertiesTable *pMgF2PropertiesTable = new G4MaterialPropertiesTable(); 
//
//  pMgF2PropertiesTable->AddProperty("RINDEX", pdMgF2PhotonMomentum, pdMgF2RefractiveIndex, iNbEntriesMatch);
//  pMgF2PropertiesTable->AddProperty("ABSLENGTH", pdMgF2PhotonMomentum, pdMgF2AbsorbtionLength, iNbEntriesMatch);
//  pMgF2PropertiesTable->AddProperty("REFLECTIVITY", pdMgF2PhotonMomentum, pdMgF2Reflectivity, iNbEntriesMatch);
//  
//  MgF2->SetMaterialPropertiesTable(pMgF2PropertiesTable);
  //------------------------------------ teflon -----------------------------------
  G4Material* Teflon = new G4Material("Teflon AF", 2.2*g/cm3, 2, kStateSolid);
  Teflon->AddElement(C, 0.240183);
  Teflon->AddElement(F, 0.759817);

  G4double pdTeflonPhotonMomentum[iNbEntries]  = {6.91*eV, 6.98*eV, 7.05*eV};
  G4double pdTeflonRefractiveIndex[iNbEntries] = {1.34,    1.34,    1.34};
  G4double pdTeflonReflectivity[iNbEntries]    = {0.95,    0.95,    0.95};
  G4double pdTeflonAbsLength[iNbEntries]       = {0.4*mm,    0.4*mm,    0.4*mm};
  G4double pdTeflonScatteringLength[iNbEntries] = {30*cm,   30*cm,   30*cm};
//  
//  G4double pdTeflonSpecularLobe[iNbEntries]    = {0.01,    0.01,    0.01};
//  G4double pdTeflonSpecularSpike[iNbEntries]   = {0.01,    0.01,    0.01};
//  G4double pdTeflonBackscatter[iNbEntries]     = {0.01,    0.01,    0.01};
//  G4double pdTeflonEfficiency[iNbEntries]      = {1.0,     1.0,     1.0};
  G4MaterialPropertiesTable *pTeflonPropertiesTable = new G4MaterialPropertiesTable();

  pTeflonPropertiesTable->AddProperty("RINDEX", pdTeflonPhotonMomentum, pdTeflonRefractiveIndex, iNbEntries);
  pTeflonPropertiesTable->AddProperty("ABSLENGTH", pdTeflonPhotonMomentum, pdTeflonAbsLength, iNbEntries);  
  pTeflonPropertiesTable->AddProperty("RAYLEIGH", pdTeflonPhotonMomentum, pdTeflonScatteringLength, iNbEntries);
  pTeflonPropertiesTable->AddProperty("REFLECTIVITY", pdTeflonPhotonMomentum, pdTeflonReflectivity, iNbEntries);
//  pTeflonPropertiesTable->AddProperty("SPECULARLOBECONSTANT", pdTeflonPhotonMomentum, pdTeflonSpecularLobe, iNbEntries);
//  pTeflonPropertiesTable->AddProperty("SPECULARSPIKECONSTANT", pdTeflonPhotonMomentum, pdTeflonSpecularSpike, iNbEntries);
//  pTeflonPropertiesTable->AddProperty("BACKSCATTERCONSTANT", pdTeflonPhotonMomentum, pdTeflonBackscatter, iNbEntries);
//  pTeflonPropertiesTable->AddProperty("EFFICIENCY", pdTeflonPhotonMomentum, pdTeflonEfficiency, iNbEntries);
  Teflon->SetMaterialPropertiesTable(pTeflonPropertiesTable);
  
  //----------------------------------- NeCH4 ------------------------------------
  G4Material *NeCH4 = new G4Material("NeCH4", 0.0008999*g/cm3, 1, kStateGas, 300.0*kelvin, 1.*atmosphere);
  NeCH4->AddElement(Ne,1);
//  NeCH4->AddElement(Ne, fractionmass=90*perCent);
//  NeCH4->AddElement(C, 2);
//  NeCH4->AddElement(H, 2);

  G4double pNeCH4PhotonMomentum[iNbEntriesMatch]   = {6.91*eV, 6.98*eV, 7.05*eV}; 
  G4double pNeCH4RefractiveIndex[iNbEntriesMatch]  = {1.000072227,    1.000072227,    1.000072227};
  G4double pNeCH4AbsorbtionLength[iNbEntriesMatch] = {100*m,    100*m,    100*m};
  G4double pNeCH4Reflectivity[iNbEntriesMatch]    = {0.95,    0.95,    0.95};  

  G4MaterialPropertiesTable *pNeCH4PropertiesTable = new G4MaterialPropertiesTable(); 

  pNeCH4PropertiesTable->AddProperty("RINDEX", pNeCH4PhotonMomentum, pNeCH4RefractiveIndex, iNbEntriesMatch);
  pNeCH4PropertiesTable->AddProperty("ABSLENGTH", pNeCH4PhotonMomentum, pNeCH4AbsorbtionLength, iNbEntriesMatch);
  pNeCH4PropertiesTable->AddProperty("REFLECTIVITY", pNeCH4PhotonMomentum, pNeCH4Reflectivity, iNbEntriesMatch);
  
  NeCH4->SetMaterialPropertiesTable(pNeCH4PropertiesTable);
  
  //----------------------------------- Polyethylene ------------------------------------
  G4Material *Polyethylene = new G4Material("Polyethylene", 0.94*g/cm3, 2, kStateSolid);
  Polyethylene->AddElement(C, 2);
  Polyethylene->AddElement(H, 4);
     //----------------------------------- Tungsten ------------------------------------
  G4Material *Tungsten = new G4Material("Tungsten", 19.25*g/cm3, 1, kStateSolid);
  Tungsten->AddElement(W, 1);
   //----------------------------------- Lead ------------------------------------
  G4Material *Lead = new G4Material("Lead", 11.34*g/cm3, 1, kStateSolid);
  Lead->AddElement(Pb, 1);
   //----------------------------------- Ferrum ------------------------------------
  G4Material *Ferrum = new G4Material("Ferrum", 7.874*g/cm3, 1, kStateSolid);
  Ferrum->AddElement(Fe, 1);
//----------------------------------- Uranium ------------------------------------
  G4Material *Uranium = new G4Material("Uranium", 19.1*g/cm3, 1, kStateSolid);
  Uranium->AddElement(U, 1);
//----------------------------------- PETN ------------------------------------
  G4Material *PETN = new G4Material("PETN", 1.77*g/cm3, 4, kStateSolid);
  PETN->AddElement(C, 5);
  PETN->AddElement(H, 8);
  PETN->AddElement(N, 4);
  PETN->AddElement(O, 12);
//----------------------------------- Graphite ------------------------------------
  G4Material *Graphite = new G4Material("Graphite", 2.15*g/cm3, 1, kStateSolid);
  Graphite->AddElement(C, 1);
////----------------------------------- Plutonium ------------------------------------
//  G4Material *Plutonium = new G4Material("Plutonium", 19.816*g/cm3, 1, kStateSolid);
//  Plutonium->AddElement(Pu, 1);

//----------------------------------- Silicon ------------------------------------
  G4Material *Silicon = new G4Material("Silicon", 2.329*g/cm3, 1, kStateSolid);
  Silicon->AddElement(Si, 1);
//----------------------------------- Aluminium ------------------------------------
  G4Material *Aluminium = new G4Material("Aluminium", 2.7*g/cm3, 1, kStateSolid);
  Aluminium->AddElement(Al, 1);
}

void PAR_LXe_MASK1_TANK1_LARGE_1DC::ConstructLaboratory()
{
	G4Material *Air = G4Material::GetMaterial("G4_AIR");
	G4Material *LXe = G4Material::GetMaterial("LXe");
	G4Material *Polyethylene = G4Material::GetMaterial("Polyethylene");
	G4Material *Teflon = G4Material::GetMaterial("Teflon AF");
	G4Material *Tefzel = G4Material::GetMaterial("Tefzel");
	G4Material *Quartz = G4Material::GetMaterial("Quartz");
	G4Material *NeCH4 = G4Material::GetMaterial("NeCH4");
	G4Material *Tungsten = G4Material::GetMaterial("Tungsten");
        G4Material *Ferrum = G4Material::GetMaterial("Ferrum");
        G4Material *Lead = G4Material::GetMaterial("Lead");
        G4Material *PETN = G4Material::GetMaterial("PETN");
        G4Material *Graphite = G4Material::GetMaterial("Graphite");
//        G4Material *Plutonium = G4Material::GetMaterial("Plutonium");
        G4Material *Silicon = G4Material::GetMaterial("Silicon");
        G4Material *Aluminium = G4Material::GetMaterial("Aluminium");
        G4Material *Uranium = G4Material::GetMaterial("Uranium");



//	===================================LXe Volume===========================================================================
//	========================================================================================================================

// Experimental hall (world volume) --------------
  G4double expHall_x = 6.0*m;
  G4double expHall_y = 30.0*cm;//10.0*cm;
  G4double expHall_z = 30.0*cm;//10.0*cm;
  G4Box* experimentalHall_box = new G4Box("expHall_box",expHall_x,expHall_y,expHall_z);
  experimentalHall_log = new G4LogicalVolume(experimentalHall_box,Air,"expHall_log",0,0,0);
  experimentalHall_phys = new G4PVPlacement(0,G4ThreeVector(),experimentalHall_log,"expHall",0,false,0);
  //experimentalHall_log->SetVisAttributes(G4VisAttributes::Invisible);

  // LXe TANK -----------------------------
  G4double bias1=-0.9*cm;
  G4double TANK_x = 20.0*cm;//2.5*cm;
  G4double TANK_y = 29.0*cm;//9.0*cm//5*cm;
  G4double TANK_z = 29.0*cm;//9.0*cm//5*cm;
  G4Box* TANK_box = new G4Box("expHall_box",TANK_x,TANK_y,TANK_z);
  TANK_log = new G4LogicalVolume(TANK_box,LXe,"TANK_log",0,0,0);
  TANK_phys = new G4PVPlacement(0,G4ThreeVector(bias1,0.0,0.0),TANK_log,"LXe TANK",experimentalHall_log,false,0);

 // Quartz Windows -----------------------------
  G4double wi_x = 0.5*cm;
  G4double wi_y = 29.0*cm;//9.0*cm//5*cm;
  G4double wi_z = 29.0*cm;//9.0*cm//5*cm;
  G4Box* wi_box = new G4Box("wi_box",wi_x,wi_y,wi_z);
  wi_log = new G4LogicalVolume(wi_box,Quartz,"wi_log",0,0,0);
  //wi_phys = new G4PVPlacement(0,G4ThreeVector(2.0*cm,0.0,0.0),wi_log,"Windows_Quartz",experimentalHall_log,false,0);
  wi_phys = new G4PVPlacement(0,G4ThreeVector(bias1+TANK_x+wi_x,0.0,0.0),wi_log,"Windows_Quartz",experimentalHall_log,false,0);
  
  // (90%)Ne (10%)CH4 Layer -----------------------------
  G4double NeCH4_wi_x = 2.5*mm;
  G4double NeCH4_wi_y = 29.0*cm;//9.0*cm//5*cm;
  G4double NeCH4_wi_z = 29.0*cm;//9.0*cm//5*cm;
  G4Box* NeCH4_wi_box = new G4Box("NeCH4_wi_box",NeCH4_wi_x,NeCH4_wi_y,NeCH4_wi_z);
  NeCH4_wi_log = new G4LogicalVolume(NeCH4_wi_box,NeCH4,"NeCH4_wi_log",0,0,0);
  NeCH4_wi_phys = new G4PVPlacement(0,G4ThreeVector(bias1+TANK_x+2*wi_x+NeCH4_wi_x,0.0,0.0),NeCH4_wi_log,"NeCH4_Window",experimentalHall_log,false,0); 

  //  GPM_Position
  GPM_Position=bias1+TANK_x+2*wi_x+2*NeCH4_wi_x;

  // Transmission Tester (I use the sizes of the Quartz Windows)-----------------------------
  TT_log = new G4LogicalVolume(wi_box,Air,"TT_log",0,0,0);
  TT_phys = new G4PVPlacement(0,G4ThreeVector(bias1-TANK_x-wi_x-1.1*cm,0.0,0.0),TT_log,"TT",experimentalHall_log,false,0);

  //  TT_Position
  TT_Position=bias1-TANK_x-1.1*cm;

//  // Polyethylene MASK ---------------------------------------
//  G4double  p_MASK_RMin = 20.*mm;//5.0*mm;
//G4double  p_MASK_RMax = 40.*mm;//10.0*mm;
//  G4double  p_MASK_Dz = 2.0*cm;
//  G4double  p_MASK_SPhi = 0*rad;
//  G4double  p_MASK_DPhi = twopi*rad;
//  G4Material *Polyethylene = G4Material::GetMaterial("Polyethylene");
//  G4Tubs* MASK1 = new G4Tubs("Polyethylene MASK",p_MASK_RMin,p_MASK_RMax,p_MASK_Dz,p_MASK_SPhi,p_MASK_DPhi);
//  MASK1_log = new G4LogicalVolume(MASK1,Polyethylene,"MASK1_log",0,0,0);
//  G4RotationMatrix* y_MASK_Rot1 = new G4RotationMatrix; 
//  y_MASK_Rot1->rotateY(90*deg); 
//  MASK1_phys = new G4PVPlacement(y_MASK_Rot1,G4ThreeVector(-5*m,0.0,0.0),MASK1_log,"MASK1",experimentalHall_log,false,0);
//  // Tungsten MASK ---------------------------------------
//  G4double  p_MASK_RMin = 20.*mm;
//  G4double  p_MASK_RMax = 40.*mm;
//  G4double  p_MASK_Dz = 0.5*cm;
//  G4double  p_MASK_SPhi = 0*rad;
//  G4double  p_MASK_DPhi = twopi*rad;
//  G4Material *Tungsten = G4Material::GetMaterial("Tungsten");
//  G4Tubs* MASK1 = new G4Tubs("Tungsten MASK",p_MASK_RMin,p_MASK_RMax,p_MASK_Dz,p_MASK_SPhi,p_MASK_DPhi);
//  MASK1_log = new G4LogicalVolume(MASK1,Tungsten,"MASK1_log",0,0,0);
//  G4RotationMatrix* y_MASK_Rot1 = new G4RotationMatrix; 
//  y_MASK_Rot1->rotateY(90*deg); 
//  MASK1_phys = new G4PVPlacement(y_MASK_Rot1,G4ThreeVector(-5*m,0.0,0.0),MASK1_log,"MASK1",experimentalHall_log,false,0);
//// Lead MASK ---------------------------------------
//  G4double  p_MASK_RMin = 20.*mm;
//  G4double  p_MASK_RMax = 40.*mm;
//  G4double  p_MASK_Dz = 0.5*cm;
//  G4double  p_MASK_SPhi = 0*rad;
//  G4double  p_MASK_DPhi = twopi*rad;
//  G4Material *Lead = G4Material::GetMaterial("Lead");
//  G4Tubs* MASK1 = new G4Tubs("Lead MASK",p_MASK_RMin,p_MASK_RMax,p_MASK_Dz,p_MASK_SPhi,p_MASK_DPhi);
//  MASK1_log = new G4LogicalVolume(MASK1,Lead,"MASK1_log",0,0,0);
// G4RotationMatrix* y_MASK_Rot1 = new G4RotationMatrix; 
//  y_MASK_Rot1->rotateY(90*deg); 
//  MASK1_phys = new G4PVPlacement(y_MASK_Rot1,G4ThreeVector(-5*m,0.0,0.0),MASK1_log,"MASK1",experimentalHall_log,false,0);
//// Ferrum MASK ---------------------------------------
//  G4double  p_MASK_RMin = 20.*mm;
//  G4double  p_MASK_RMax = 40.*mm;
//  G4double  p_MASK_Dz = 0.5*cm;
//  G4double  p_MASK_SPhi = 0*rad;
//  G4double  p_MASK_DPhi = twopi*rad;
//  G4Material *Ferrum = G4Material::GetMaterial("Ferrum");
//  G4Tubs* MASK1 = new G4Tubs("Ferrum MASK",p_MASK_RMin,p_MASK_RMax,p_MASK_Dz,p_MASK_SPhi,p_MASK_DPhi);
//  MASK1_log = new G4LogicalVolume(MASK1,Ferrum,"MASK1_log",0,0,0);
//  G4RotationMatrix* y_MASK_Rot1 = new G4RotationMatrix; 
//  y_MASK_Rot1->rotateY(90*deg); 
// MASK1_phys = new G4PVPlacement(y_MASK_Rot1,G4ThreeVector(-5*m,0.0,0.0),MASK1_log,"MASK1",experimentalHall_log,false,0);
 
//// Multi material MASK ---------------------------------------
//  G4double MASK_x = 10.0*mm;
//  G4double MASK_y = 10.0*mm;
//  G4double MASK_z = 30.0*mm;//10.0*mm;//30.0*mm; //5.0*mm;
//  G4Material *Tungsten = G4Material::GetMaterial("Tungsten");
//  G4Material *Ferrum = G4Material::GetMaterial("Ferrum");
//  G4Material *Lead = G4Material::GetMaterial("Lead");
//  G4Material *Polyethylene = G4Material::GetMaterial("Polyethylene");
//  G4Material *PETN = G4Material::GetMaterial("PETN");
//  G4Material *Graphite = G4Material::GetMaterial("Graphite");
////  G4Material *Plutonium = G4Material::GetMaterial("Plutonium");
//  G4Material *Silicon = G4Material::GetMaterial("Silicon");
//  G4Material *Aluminium = G4Material::GetMaterial("Aluminium");
//  G4Material *Uranium = G4Material::GetMaterial("Uranium");
//  G4Box* MASK1 = new G4Box("Multi material MASK",MASK_x,MASK_y,MASK_z);
//  MASK1_log = new G4LogicalVolume(MASK1,PETN,"MASK1_log",0,0,0);
//  MASK2_log = new G4LogicalVolume(MASK1,Polyethylene,"MASK2_log",0,0,0);
//  MASK3_log = new G4LogicalVolume(MASK1,Lead,"MASK3_log",0,0,0);
//  MASK4_log = new G4LogicalVolume(MASK1,Ferrum,"MASK4_log",0,0,0);
//  MASK5_log = new G4LogicalVolume(MASK1,Graphite,"MASK5_log",0,0,0);
//  MASK6_log = new G4LogicalVolume(MASK1,Tungsten,"MASK6_log",0,0,0);
//  MASK7_log = new G4LogicalVolume(MASK1,Silicon,"MASK7_log",0,0,0);
////  MASK8_log = new G4LogicalVolume(MASK1,Plutonium,"MASK8_log",0,0,0); //<==============================
//  MASK8_log = new G4LogicalVolume(MASK1,Aluminium,"MASK8_log",0,0,0);
//  MASK9_log = new G4LogicalVolume(MASK1,Uranium,"MASK9_log",0,0,0);
//  G4RotationMatrix* y_MASK_Rot1 = new G4RotationMatrix;
//  y_MASK_Rot1->rotateY(90*deg);
//  MASK1_phys = new G4PVPlacement(y_MASK_Rot1,G4ThreeVector(-5*m,-60*mm,-60*mm),MASK1_log,"MASK1_1",experimentalHall_log,false,0);
//  MASK2_phys = new G4PVPlacement(y_MASK_Rot1,G4ThreeVector(-5*m,-60*mm,0.0),MASK2_log,"MASK1_2",experimentalHall_log,false,0);
//  MASK3_phys = new G4PVPlacement(y_MASK_Rot1,G4ThreeVector(-5*m,-60*mm,60*mm),MASK3_log,"MASK1_3",experimentalHall_log,false,0);
//  MASK4_phys = new G4PVPlacement(y_MASK_Rot1,G4ThreeVector(-5*m,0.0,-60*mm),MASK4_log,"MASK1_4",experimentalHall_log,false,0);
//  MASK5_phys = new G4PVPlacement(y_MASK_Rot1,G4ThreeVector(-5*m,0.0,0.0),MASK5_log,"MASK1_5",experimentalHall_log,false,0);
//  MASK6_phys = new G4PVPlacement(y_MASK_Rot1,G4ThreeVector(-5*m,0.0,60*mm),MASK6_log,"MASK1_6",experimentalHall_log,false,0);
//  MASK7_phys = new G4PVPlacement(y_MASK_Rot1,G4ThreeVector(-5*m,60*mm,-60*mm),MASK7_log,"MASK1_7",experimentalHall_log,false,0);
//  MASK8_phys = new G4PVPlacement(y_MASK_Rot1,G4ThreeVector(-5*m,60*mm,0.0),MASK8_log,"MASK1_8",experimentalHall_log,false,0);
//  MASK9_phys = new G4PVPlacement(y_MASK_Rot1,G4ThreeVector(-5*m,60*mm,60*mm),MASK9_log,"MASK1_9",experimentalHall_log,false,0);

  
 
  // ------------------------------- Surfaces -----------------------------------------------
  // ------------------------- Optical Propertiers ------------------------------------------
  G4OpticalSurface* OpTANKWindow = new G4OpticalSurface("TANKWindow");
  OpTANKWindow->SetModel(glisur);
  OpTANKWindow->SetType(dielectric_dielectric);
  OpTANKWindow->SetFinish(polished);
  G4LogicalBorderSurface* TANKWindow = new G4LogicalBorderSurface("TANKWindow",TANK_phys,wi_phys,OpTANKWindow);
  
  G4OpticalSurface* OpWindow_NeCh4 = new G4OpticalSurface("Window_NeCh4");
  OpWindow_NeCh4->SetModel(glisur);
  OpWindow_NeCh4->SetType(dielectric_dielectric);
  OpWindow_NeCh4->SetFinish(polished);
//  G4LogicalBorderSurface* Window_NeCh4 = new G4LogicalBorderSurface("LayerSupport",wi_phys,NeCh4_wi_phys,OpWindow_NeCh4);

}

void PAR_LXe_MASK1_TANK1_LARGE_1DC::SensitiveDete()
{
  // ------------------------------------------------------------------------------------------
  // sensitive detectors -----------------------------------------------------
  G4SDManager* SDman = G4SDManager::GetSDMpointer();
  SDman->SetVerboseLevel(1);
  //--------------------------------------------------------------------------------------------
  //Define Multi-Detector and Register 
  //--------------------------------------------------------------------------------------------
  G4MultiFunctionalDetector* det = new G4MultiFunctionalDetector("IonPro");
  SDman->AddNewDetector(det);
  TANK_log->SetSensitiveDetector(det);
  //--------------------------------------------------------------------------------------------
  //Primitive Score
  //--------------------------------------------------------------------------------------------
  G4VPrimitiveScorer* primitive;
  primitive = new G4PSEnergyDeposit("nproton");
  //--------------------------------------------------------------------------------------------
  //Filter
  //--------------------------------------------------------------------------------------------
  G4String filterName,particleName;
  //-- neutron filter
  //G4SDParticleFilter* epFilter = new G4SDParticleFilter(filterName="epFilter");
  //epFilter->add(particleName="e-");
  //epFilter->add(particleName="neutron");
  //primitive->SetFilter(epFilter);
  //epFilter->show();
  //-- Register Sensitive Detector Run Action 
  det->RegisterPrimitive(primitive);
  //@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ 
}
