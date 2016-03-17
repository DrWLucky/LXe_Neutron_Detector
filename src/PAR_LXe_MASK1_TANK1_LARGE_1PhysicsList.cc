#include "PAR_LXe_MASK1_TANK1_LARGE_1PhysicsList.hh"

#include "globals.hh"
#include "G4ProcessManager.hh"
#include "G4ProcessVector.hh"
#include "G4ParticleDefinition.hh"
#include "G4ParticleWithCuts.hh"
#include "G4ParticleTypes.hh"
#include "G4ParticleTable.hh"
#include "G4ios.hh"
#include <iomanip>  
#include "G4UserLimits.hh"
#include "G4MesonConstructor.hh"
#include "G4BaryonConstructor.hh"
#include "G4IonConstructor.hh"

PAR_LXe_MASK1_TANK1_LARGE_1PhysicsList::PAR_LXe_MASK1_TANK1_LARGE_1PhysicsList() : G4VUserPhysicsList() 
{
  defaultCutValue = 1e-6*mm;
  cutForGamma = defaultCutValue;
  cutForElectron = defaultCutValue;
  cutForPositron = defaultCutValue;
  cutForProton = 0.001*mm;
  VerboseLevel = 0;
  OpVerbLevel = 0;
  SetVerboseLevel(VerboseLevel);
}

PAR_LXe_MASK1_TANK1_LARGE_1PhysicsList::~PAR_LXe_MASK1_TANK1_LARGE_1PhysicsList() 
{;}

void PAR_LXe_MASK1_TANK1_LARGE_1PhysicsList::ConstructParticle() 
{
  ConstructMyBosons();
  ConstructMyLeptons();
  ConstructMyHadrons();
  ConstructMyShortLiveds();
}

void PAR_LXe_MASK1_TANK1_LARGE_1PhysicsList::ConstructMyBosons()
{
  G4Gamma::GammaDefinition();
  G4OpticalPhoton::OpticalPhotonDefinition();
}

void PAR_LXe_MASK1_TANK1_LARGE_1PhysicsList::ConstructMyLeptons()
{
  G4Electron::ElectronDefinition();
  G4Positron::PositronDefinition();
  G4NeutrinoE::NeutrinoEDefinition();
  G4AntiNeutrinoE::AntiNeutrinoEDefinition();
  G4NeutrinoMu::NeutrinoMuDefinition();
  G4AntiNeutrinoMu::AntiNeutrinoMuDefinition();
}

void PAR_LXe_MASK1_TANK1_LARGE_1PhysicsList::ConstructMyHadrons()
{
 //  mesons
  G4MesonConstructor mConstructor;
  mConstructor.ConstructParticle();
 //  baryons
  G4BaryonConstructor bConstructor;
  bConstructor.ConstructParticle();
 //  ions
  G4IonConstructor iConstructor;
  iConstructor.ConstructParticle();
}

void PAR_LXe_MASK1_TANK1_LARGE_1PhysicsList::ConstructMyShortLiveds()
{;}

void PAR_LXe_MASK1_TANK1_LARGE_1PhysicsList::ConstructProcess() 
{
  AddTransportation();
  ConstructEM();
  ConstructOp();
  ConstructHad();
  ConstructGeneral();
}

void PAR_LXe_MASK1_TANK1_LARGE_1PhysicsList::AddTransportation() 
{
  G4VUserPhysicsList::AddTransportation();  
}

// Electromagnetic Processes ////////////////////////////////////////////////
// all charged particles

// gamma
#include "G4PhotoElectricEffect.hh"
#include "G4LivermorePhotoElectricModel.hh"
#include "G4ComptonScattering.hh"
#include "G4LivermoreComptonModel.hh"
#include "G4GammaConversion.hh"
#include "G4LivermoreGammaConversionModel.hh"
#include "G4RayleighScattering.hh" 
#include "G4LivermoreRayleighModel.hh"

// e+-
#include "G4eMultipleScattering.hh"
#include "G4UniversalFluctuation.hh"
#include "G4eIonisation.hh"
#include "G4LivermoreIonisationModel.hh"
#include "G4eBremsstrahlung.hh"
#include "G4LivermoreBremsstrahlungModel.hh"
#include "G4eplusAnnihilation.hh"
#include "G4hLowEnergyIonisation.hh"
#include "G4hMultipleScattering.hh"

// alpha and GenericIon and deuterons, triton, He3:
// hIonisation #include "G4hLowEnergyIonisation.hh" -> moved to G4hIonisation
#include "G4EnergyLossTables.hh"
// hLowEnergyIonisation uses Ziegler 1988 as the default

//OTHERS:
#include "G4hIonisation.hh" 
#include "G4hMultipleScattering.hh"
#include "G4hBremsstrahlung.hh"
#include "G4ionIonisation.hh"
#include "G4IonParametrisedLossModel.hh"

//Options
#include "G4LossTableManager.hh"
#include "G4EmProcessOptions.hh"

// msc models
#include "G4UrbanMscModel93.hh"
#include "G4WentzelVIModel.hh"
#include "G4CoulombScattering.hh"

void PAR_LXe_MASK1_TANK1_LARGE_1PhysicsList::ConstructEM() 
{
  G4EmProcessOptions opt;
  opt.SetMaxEnergy(100*GeV);
  opt.SetDEDXBinning(200);
  opt.SetLambdaBinning(200);
  theParticleIterator->reset();
  while((*theParticleIterator)())
  {
    G4ParticleDefinition* particle = theParticleIterator->value();
    G4ProcessManager* pmanager = particle->GetProcessManager();
    G4String particleName = particle->GetParticleName();
    G4String particleType = particle->GetParticleType();
    G4double charge = particle->GetPDGCharge();
    if (particleName == "gamma")
    {
      // gamma         
      // PhotoElectricEffect
      G4PhotoElectricEffect* thePhotoElectricEffect = new G4PhotoElectricEffect();
      G4LivermorePhotoElectricModel* theLivermorePhotoElectricModel = new G4LivermorePhotoElectricModel();
      theLivermorePhotoElectricModel->ActivateAuger(true);
      theLivermorePhotoElectricModel->SetCutForLowEnSecPhotons(0.010 * keV);
      theLivermorePhotoElectricModel->SetCutForLowEnSecElectrons(0.010 * keV);
      thePhotoElectricEffect->AddEmModel(0, theLivermorePhotoElectricModel);
      pmanager->AddDiscreteProcess(thePhotoElectricEffect);
      // ComptonScattering
      G4ComptonScattering* theComptonScattering = new G4ComptonScattering();
      G4LivermoreComptonModel* theLivermoreComptonModel = new G4LivermoreComptonModel();
      theComptonScattering->AddEmModel(0, theLivermoreComptonModel);
      pmanager->AddDiscreteProcess(theComptonScattering);
      // GammaConversion
      G4GammaConversion* theGammaConversion = new G4GammaConversion();
      G4LivermoreGammaConversionModel* theLivermoreGammaConversionModel = new G4LivermoreGammaConversionModel();
      theGammaConversion->AddEmModel(0, theLivermoreGammaConversionModel);
      pmanager->AddDiscreteProcess(theGammaConversion);
      // RayleighScattering
      G4RayleighScattering* theRayleigh = new G4RayleighScattering();
      G4LivermoreRayleighModel* theRayleighModel = new G4LivermoreRayleighModel();
      theRayleigh->AddEmModel(0,theRayleighModel);
      pmanager->AddDiscreteProcess(theRayleigh);
    } 
    else if (particleName == "e-") 
    {
      //electron
      // Scattering
      G4eMultipleScattering* msc = new G4eMultipleScattering();
      msc->AddEmModel(0,new G4UrbanMscModel93());
      msc->SetStepLimitType(fUseDistanceToBoundary);
      pmanager->AddProcess(msc,-1, 1, 1);
      // Ionisation
      G4eIonisation* eIoni = new G4eIonisation();
      G4LivermoreIonisationModel* theLivermoreIonisationModel = new G4LivermoreIonisationModel();
      theLivermoreIonisationModel->ActivateAuger(true);
      eIoni->SetEmModel(theLivermoreIonisationModel);
      eIoni->SetStepFunction(0.2,1.0*nm);      
      pmanager->AddProcess(eIoni,-1, 2, 2);
      // Bremsstrahlung
      G4eBremsstrahlung* eBrem = new G4eBremsstrahlung();
      eBrem->SetEmModel(new G4LivermoreBremsstrahlungModel());
      pmanager->AddProcess(eBrem,-1,-3, 3);
    }
    else if (particleName == "e+") 
    {
      //positron 
      // Scattering
      G4eMultipleScattering* msc = new G4eMultipleScattering();
      msc->SetStepLimitType(fUseDistanceToBoundary);
      pmanager->AddProcess(msc,-1,1,1);
      // Ionisation
      G4eIonisation* eIonisation = new G4eIonisation();
      eIonisation->SetStepFunction(0.2,100*um); //     
      pmanager->AddProcess(eIonisation,-1, 2, 2);
      //Bremsstrahlung (use default, no low-energy available)
      pmanager->AddProcess(new G4eBremsstrahlung(),-1,-1,3);
      //Annihilation
      pmanager->AddProcess(new G4eplusAnnihilation(),0,-1,4);      
    } 
    else if (particleName == "proton")
    {
      //multiple scattering
      pmanager->AddProcess(new G4hMultipleScattering,-1,1,1);
      //ionisation
      G4hIonisation* hIonisation = new G4hIonisation();
      hIonisation->SetStepFunction(0.2, 50*um);
      pmanager->AddProcess(hIonisation,-1,2,2);
      //bremmstrahlung
      pmanager->AddProcess(new G4hBremsstrahlung,-1,-3,3);
    }
    else if(particleName == "alpha" || particleName == "deuteron"   || 
            particleName == "triton" || particleName == "He3")
    {
      //multiple scattering
      G4eMultipleScattering* msc = new G4eMultipleScattering();
      msc->SetStepLimitType(fUseDistanceToBoundary);
      pmanager->AddProcess(msc,-1,1,1);
      //ionisation
      G4ionIonisation* ionIoni = new G4ionIonisation();
      ionIoni->SetStepFunction(0.1,20*um);
      pmanager->AddProcess(ionIoni,-1,2,2);
    }
    else if (particleName == "GenericIon")
    {
      // OBJECT may be dynamically created as either a GenericIon or nucleus
      // G4Nucleus exists and therefore has particle type nucleus
      // genericIon:
      //multiple scattering
      pmanager->AddProcess(new G4hMultipleScattering,-1,1,1);
      //ionisation
      G4ionIonisation* ionIoni = new G4ionIonisation();
      ionIoni->SetEmModel(new G4IonParametrisedLossModel());
      ionIoni->SetStepFunction(0.1,20*um);
      pmanager->AddProcess(ionIoni,-1, 2, 2);
    }
    else if ((!particle->IsShortLived()) && (charge != 0.0) && (particle->GetParticleName() != "chargedgeantino")) 
    {
      //all others charged particles except geantino
      G4hMultipleScattering* aMultipleScattering = new G4hMultipleScattering();
      G4hIonisation* ahadronIon = new G4hIonisation();
      //multiple scattering
      pmanager->AddProcess(aMultipleScattering,-1,1,1);
      //ionisation
      pmanager->AddProcess(ahadronIon,-1,2,2);      
    }
  }
  // turn off msc step-limitation - especially as electron cut 1nm
  opt.SetMscStepLimitation(fMinimal);
}

// Optical Processes ////////////////////////////////////////////////////////
#include "G4Scintillation.hh"
#include "G4OpAbsorption.hh"
//#include "G4OpRayleigh.hh"
#include "G4OpBoundaryProcess.hh"
void PAR_LXe_MASK1_TANK1_LARGE_1PhysicsList::ConstructOp() 
{
  // default scintillation process
  G4Scintillation* theScintProcessDef = new G4Scintillation("Scintillation");
  // theScintProcessDef->DumpPhysicsTable();
  theScintProcessDef->SetTrackSecondariesFirst(true);
  theScintProcessDef->SetScintillationYieldFactor(1.0); //
  theScintProcessDef->SetScintillationExcitationRatio(0.0); //
  theScintProcessDef->SetVerboseLevel(OpVerbLevel);
 
  // scintillation process for alpha:
  G4Scintillation* theScintProcessAlpha = new G4Scintillation("Scintillation");
  // theScintProcessNuc->DumpPhysicsTable();
  theScintProcessAlpha->SetTrackSecondariesFirst(true);
  theScintProcessAlpha->SetScintillationYieldFactor(1.1);
  theScintProcessAlpha->SetScintillationExcitationRatio(1.0);
  theScintProcessAlpha->SetVerboseLevel(OpVerbLevel);
  
  // scintillation process for heavy nuclei
  G4Scintillation* theScintProcessNuc = new G4Scintillation("Scintillation");
  // theScintProcessNuc->DumpPhysicsTable();
  theScintProcessNuc->SetTrackSecondariesFirst(true);
  theScintProcessNuc->SetScintillationYieldFactor(0.2);
  theScintProcessNuc->SetScintillationExcitationRatio(1.0);
  theScintProcessNuc->SetVerboseLevel(OpVerbLevel);
  
  // scintillation process for proton:
  G4Scintillation* theScintProcessProton = new G4Scintillation("Scintillation");
  theScintProcessProton->SetTrackSecondariesFirst(true);
  theScintProcessProton->SetScintillationYieldFactor(1.47);  //  HAVE TO FIGURE OUT THE CORRECT VALUE    
  theScintProcessProton->SetScintillationExcitationRatio(1.0);
  
  // optical processes
  G4OpAbsorption* theAbsorptionProcess = new G4OpAbsorption();
  //  G4OpRayleigh* theRayleighScatteringProcess = new G4OpRayleigh();
  G4OpBoundaryProcess* theBoundaryProcess = new G4OpBoundaryProcess();
  //  theAbsorptionProcess->DumpPhysicsTable();
  //  theRayleighScatteringProcess->DumpPhysicsTable();
  theAbsorptionProcess->SetVerboseLevel(OpVerbLevel);
  // theRayleighScatteringProcess->SetVerboseLevel(OpVerbLevel);
  theBoundaryProcess->SetVerboseLevel(OpVerbLevel);
  G4OpticalSurfaceModel themodel = unified;
  theBoundaryProcess->SetModel(themodel);
  theParticleIterator->reset();
  while( (*theParticleIterator)() )
  {
    G4ParticleDefinition* particle = theParticleIterator->value();
    G4ProcessManager* pmanager = particle->GetProcessManager();
    G4String particleName = particle->GetParticleName();
    if (theScintProcessDef->IsApplicable(*particle)) 
    {
      //      if(particle->GetPDGMass() > 5.0*GeV) 
      if(particle->GetParticleName() == "GenericIon") 
      {
        pmanager->AddProcess(theScintProcessNuc); // AtRestDiscrete
        pmanager->SetProcessOrderingToLast(theScintProcessNuc,idxAtRest);
        pmanager->SetProcessOrderingToLast(theScintProcessNuc,idxPostStep);
      }   
      else if(particle->GetParticleName() == "alpha") 
      {
        pmanager->AddProcess(theScintProcessAlpha);
        pmanager->SetProcessOrderingToLast(theScintProcessAlpha,idxAtRest);
        pmanager->SetProcessOrderingToLast(theScintProcessAlpha,idxPostStep);
      }
      else if(particle->GetParticleName() == "proton") 
      {
        pmanager->AddProcess(theScintProcessProton);
        pmanager->SetProcessOrderingToLast(theScintProcessProton,idxAtRest);
        pmanager->SetProcessOrderingToLast(theScintProcessProton,idxPostStep);
      }
      else 
      {
        pmanager->AddProcess(theScintProcessDef);
        pmanager->SetProcessOrderingToLast(theScintProcessDef,idxAtRest);
        pmanager->SetProcessOrderingToLast(theScintProcessDef,idxPostStep);
      }
    }
    if (particleName == "opticalphoton") 
    {
      pmanager->AddDiscreteProcess(theAbsorptionProcess);
      // pmanager->AddDiscreteProcess(theRayleighScatteringProcess);
      pmanager->AddDiscreteProcess(theBoundaryProcess);
    }
  }
}

// Hadronic processes ////////////////////////////////////////////////////////
// Elastic processes:
#include "G4HadronElasticProcess.hh"
// Inelastic processes:
#include "G4ProtonInelasticProcess.hh"
#include "G4AntiProtonInelasticProcess.hh"
#include "G4NeutronInelasticProcess.hh"
#include "G4AntiNeutronInelasticProcess.hh"
#include "G4DeuteronInelasticProcess.hh"
#include "G4TritonInelasticProcess.hh"
#include "G4AlphaInelasticProcess.hh"
// Low-energy Models: < 20GeV
#include "G4LElastic.hh"
#include "G4LEPionPlusInelastic.hh"
#include "G4LEPionMinusInelastic.hh"
#include "G4LEKaonPlusInelastic.hh"
#include "G4LEKaonZeroSInelastic.hh"
#include "G4LEKaonZeroLInelastic.hh"
#include "G4LEKaonMinusInelastic.hh"
#include "G4LEProtonInelastic.hh"
#include "G4LEAntiProtonInelastic.hh"
#include "G4LENeutronInelastic.hh"
#include "G4LEAntiNeutronInelastic.hh"
#include "G4LEDeuteronInelastic.hh"
#include "G4LETritonInelastic.hh"
#include "G4LEAlphaInelastic.hh"
#include "G4HadronCaptureProcess.hh"
// High-energy Models: >20 GeV
#include "G4HEPionPlusInelastic.hh"
#include "G4HEPionMinusInelastic.hh"
#include "G4HEKaonPlusInelastic.hh"
#include "G4HEKaonZeroInelastic.hh"
#include "G4HEKaonZeroInelastic.hh"
#include "G4HEKaonMinusInelastic.hh"
#include "G4HEProtonInelastic.hh"
#include "G4HEAntiProtonInelastic.hh"
#include "G4HENeutronInelastic.hh"
#include "G4HEAntiNeutronInelastic.hh"

// Neutron high-precision models: <20 MeV
#include "G4NeutronHPElastic.hh"
#include "G4NeutronHPElasticData.hh"
#include "G4NeutronHPCapture.hh"
#include "G4NeutronHPCaptureData.hh"
#include "G4NeutronHPInelastic.hh"
#include "G4NeutronHPInelasticData.hh"
#include "G4LCapture.hh"
#include "G4BGGNucleonElasticXS.hh"
#include "G4NeutronHPJENDLHEInelasticData.hh"

// Stopping processes
#include "G4PiMinusAbsorptionAtRest.hh"
#include "G4KaonMinusAbsorptionAtRest.hh"
#include "G4AntiProtonAnnihilationAtRest.hh"
#include "G4AntiNeutronAnnihilationAtRest.hh"

// ConstructHad()
void PAR_LXe_MASK1_TANK1_LARGE_1PhysicsList::ConstructHad() 
{
  G4HadronElasticProcess* theElasticProcess = new G4HadronElasticProcess;
  G4LElastic* theElasticModel = new G4LElastic;
  theElasticProcess->RegisterMe(theElasticModel);
  theParticleIterator->reset();
  while ((*theParticleIterator)()) 
  {
    G4ParticleDefinition* particle = theParticleIterator->value();
    G4ProcessManager* pmanager = particle->GetProcessManager();
    G4String particleName = particle->GetParticleName();
    if (particleName == "proton") 
    {
      pmanager->AddDiscreteProcess(theElasticProcess);
      G4ProtonInelasticProcess* theInelasticProcess = 
      new G4ProtonInelasticProcess("inelastic");
      G4LEProtonInelastic* theLEInelasticModel = new G4LEProtonInelastic;
      theInelasticProcess->RegisterMe(theLEInelasticModel);
      G4HEProtonInelastic* theHEInelasticModel = new G4HEProtonInelastic;
      theInelasticProcess->RegisterMe(theHEInelasticModel);
      pmanager->AddDiscreteProcess(theInelasticProcess);
    }
    else if (particleName == "anti_proton") 
    {
      pmanager->AddDiscreteProcess(theElasticProcess);
      G4AntiProtonInelasticProcess* theInelasticProcess = new G4AntiProtonInelasticProcess("inelastic");
      G4LEAntiProtonInelastic* theLEInelasticModel = 
      new G4LEAntiProtonInelastic;
      theInelasticProcess->RegisterMe(theLEInelasticModel);
      G4HEAntiProtonInelastic* theHEInelasticModel = 
      new G4HEAntiProtonInelastic;
      theInelasticProcess->RegisterMe(theHEInelasticModel);
      pmanager->AddDiscreteProcess(theInelasticProcess);
    }
    else if (particleName == "neutron") 
    {
      // elastic scattering
      /*G4HadronElasticProcess* theNeutronElasticProcess = new G4HadronElasticProcess;
      G4LElastic* theElasticModel1 = new G4LElastic;
      G4NeutronHPElastic * theElasticNeutron = new G4NeutronHPElastic;
      theNeutronElasticProcess->RegisterMe(theElasticModel1);
      theElasticModel1->SetMinEnergy(19*MeV);
      theNeutronElasticProcess->RegisterMe(theElasticNeutron);
      G4NeutronHPElasticData * theNeutronData = new G4NeutronHPElasticData;
      theNeutronElasticProcess->AddDataSet(theNeutronData);
      pmanager->AddDiscreteProcess(theNeutronElasticProcess);*/
      // ------------------------------------------------------------------------------------
      G4bool HPN;
      if (getenv("G4NEUTRONHPDATA")) 
      {
        G4cout << "physics list: Constructing high precision neutron models" << G4endl;
        G4cout << "              using cross sections in " << getenv("G4NEUTRONHPDATA") << G4endl;
        HPN = true;
      } 
      else 
      {
        G4cout << "physics list: Constructing non-high-precision neutron models" << G4endl;
        HPN = false;
      }
      G4double HPNLimit = 19.9*MeV;
      // Elastic Scattering
      G4HadronElasticProcess* theElasticProcess = new G4HadronElasticProcess();
      G4LElastic* theLElasticModel = new G4LElastic();
      G4BGGNucleonElasticXS* elastic_XC_0 = new G4BGGNucleonElasticXS( G4Neutron::Neutron() );
      theElasticProcess->AddDataSet( elastic_XC_0 );
      if (HPN)
      {
        // Use JENDL HE model 20 MeV ~ 3GeV
        G4NeutronHPJENDLHEInelasticData* elastic_XC_1 = new G4NeutronHPJENDLHEInelasticData();
        theElasticProcess->AddDataSet( elastic_XC_1 );
        theLElasticModel->SetMinEnergy(HPNLimit);
        G4NeutronHPElastic* theHPElasticModel = new G4NeutronHPElastic();
        G4NeutronHPElasticData* theHPElasticData = new G4NeutronHPElasticData();
        theElasticProcess->RegisterMe(theHPElasticModel);
        theElasticProcess->AddDataSet(theHPElasticData);
      }
      theElasticProcess->RegisterMe(theLElasticModel);
      pmanager->AddDiscreteProcess(theElasticProcess);
      // inelastic scattering
      G4NeutronInelasticProcess* theInelasticProcess = new G4NeutronInelasticProcess("inelastic");
      G4LENeutronInelastic* theInelasticModel = new G4LENeutronInelastic;
      theInelasticModel->SetMinEnergy(19*MeV);
      theInelasticProcess->RegisterMe(theInelasticModel);
      G4NeutronHPInelastic * theLENeutronInelasticModel = new G4NeutronHPInelastic;
      theInelasticProcess->RegisterMe(theLENeutronInelasticModel);
      G4NeutronHPInelasticData * theNeutronData1 = 
      new G4NeutronHPInelasticData;
      theInelasticProcess->AddDataSet(theNeutronData1);
      pmanager->AddDiscreteProcess(theInelasticProcess);
      // capture
      G4HadronCaptureProcess* theCaptureProcess =
      new G4HadronCaptureProcess;
      G4LCapture* theCaptureModel = new G4LCapture;
      theCaptureModel->SetMinEnergy(19*MeV);
      theCaptureProcess->RegisterMe(theCaptureModel);
      G4NeutronHPCapture * theLENeutronCaptureModel = new G4NeutronHPCapture;
      theCaptureProcess->RegisterMe(theLENeutronCaptureModel);
      G4NeutronHPCaptureData * theNeutronData3 = new G4NeutronHPCaptureData;
      theCaptureProcess->AddDataSet(theNeutronData3);
      pmanager->AddDiscreteProcess(theCaptureProcess);
      //  G4ProcessManager* pmanager = G4Neutron::Neutron->GetProcessManager();
      //  pmanager->AddProcess(new G4UserSpecialCuts(),-1,-1,1);
    }
    else if (particleName == "anti_neutron") 
    {
      pmanager->AddDiscreteProcess(theElasticProcess);
      G4AntiNeutronInelasticProcess* theInelasticProcess = 
      new G4AntiNeutronInelasticProcess("inelastic");
      G4LEAntiNeutronInelastic* theLEInelasticModel = 
      new G4LEAntiNeutronInelastic;
      theInelasticProcess->RegisterMe(theLEInelasticModel);
      G4HEAntiNeutronInelastic* theHEInelasticModel = 
      new G4HEAntiNeutronInelastic;
      theInelasticProcess->RegisterMe(theHEInelasticModel);
      pmanager->AddDiscreteProcess(theInelasticProcess);
    }
    else if (particleName == "deuteron") 
    {
      pmanager->AddDiscreteProcess(theElasticProcess);
      G4DeuteronInelasticProcess* theInelasticProcess = 
      new G4DeuteronInelasticProcess("inelastic");
      G4LEDeuteronInelastic* theLEInelasticModel = 
      new G4LEDeuteronInelastic;
      theInelasticProcess->RegisterMe(theLEInelasticModel);
      pmanager->AddDiscreteProcess(theInelasticProcess);
    }
    else if (particleName == "triton") 
    {
      pmanager->AddDiscreteProcess(theElasticProcess);
      G4TritonInelasticProcess* theInelasticProcess = 
      new G4TritonInelasticProcess("inelastic");
      G4LETritonInelastic* theLEInelasticModel = 
      new G4LETritonInelastic;
      theInelasticProcess->RegisterMe(theLEInelasticModel);
      pmanager->AddDiscreteProcess(theInelasticProcess);
    }
    else if (particleName == "alpha") 
    {
      pmanager->AddDiscreteProcess(theElasticProcess);
      G4AlphaInelasticProcess* theInelasticProcess = 
      new G4AlphaInelasticProcess("inelastic");
      G4LEAlphaInelastic* theLEInelasticModel = 
      new G4LEAlphaInelastic;
      theInelasticProcess->RegisterMe(theLEInelasticModel);
      pmanager->AddDiscreteProcess(theInelasticProcess);
    }
  }
}


// Decays ///////////////////////////////////////////////////////////////////
#include "G4Decay.hh"
#include "G4RadioactiveDecay.hh"
#include "G4IonTable.hh"
#include "G4Ions.hh"

void PAR_LXe_MASK1_TANK1_LARGE_1PhysicsList::ConstructGeneral() 
{
  // Add Decay Process
  G4Decay* theDecayProcess = new G4Decay();
  theParticleIterator->reset();
  while( (*theParticleIterator)() )
  {
    G4ParticleDefinition* particle = theParticleIterator->value();
    G4ProcessManager* pmanager = particle->GetProcessManager();
    if (theDecayProcess->IsApplicable(*particle) && !particle->IsShortLived()) 
    { 
      pmanager ->AddProcess(theDecayProcess);
      // set ordering for PostStepDoIt and AtRestDoIt
      pmanager ->SetProcessOrdering(theDecayProcess, idxPostStep);
      pmanager ->SetProcessOrdering(theDecayProcess, idxAtRest);
    }
  }
  // Declare radioactive decay to the GenericIon in the IonTable.
  const G4IonTable *theIonTable = 
  G4ParticleTable::GetParticleTable()->GetIonTable();
  G4RadioactiveDecay *theRadioactiveDecay = new G4RadioactiveDecay();
  for (G4int i=0; i<theIonTable->Entries(); i++) 
  {
    G4String particleName = theIonTable->GetParticle(i)->GetParticleName();
    G4String particleType = theIonTable->GetParticle(i)->GetParticleType();
    if (particleName == "GenericIon") 
    {
      G4ProcessManager* pmanager = theIonTable->GetParticle(i)->GetProcessManager();
      pmanager->SetVerboseLevel(VerboseLevel);
      pmanager ->AddProcess(theRadioactiveDecay);
      pmanager ->SetProcessOrdering(theRadioactiveDecay, idxPostStep);
      pmanager ->SetProcessOrdering(theRadioactiveDecay, idxAtRest);
    } 
  }
}

// Cuts /////////////////////////////////////////////////////////////////////
void PAR_LXe_MASK1_TANK1_LARGE_1PhysicsList::SetCuts() 
{
  if (verboseLevel >1) 
    G4cout << "PAR_LXe_MASK1_TANK1_LARGE_1PhysicsList::SetCuts:"; 
  if (verboseLevel>0){
    G4cout << "PAR_LXe_MASK1_TANK1_LARGE_1PhysicsList::SetCuts:";
    G4cout << "CutLength : " << G4BestUnit(defaultCutValue,"Length") << G4endl;
  }
  //special for low energy physics
  G4double lowlimit=10*eV;  
  G4ProductionCutsTable::GetProductionCutsTable()->SetEnergyRange(lowlimit,100.*GeV);
  // set cut values for gamma at first and for e- second and next for e+,
  // because some processes for e+/e- need cut values for gamma 
//  SetCutValue(cutForGamma, "gamma");
//  SetCutValue(cutForElectron, "e-");
//  SetCutValue(cutForPositron, "e+");
//  SetCutValue(cutForProton, "proton");
//********************
  G4double cutValue = 2.0*mm;
  SetCutValue(cutValue,"gamma");
  SetCutValue(cutValue,"e-");
  SetCutValue(cutValue,"e+");
  //******************
  if (verboseLevel>0) DumpCutValuesTable();
}

//// Cuts /////////////////////////////////////////////////////////////////////
//#include "G4Region.hh"
//#include "G4RegionStore.hh"
//#include "G4ProductionCuts.hh"
//
//void PAR_LXe_MASK1_TANK1_LARGE_1PhysicsList::SetCuts() {
//
//  // low energy limit
//  G4double lowlimit=250*eV;
//  G4ProductionCutsTable::GetProductionCutsTable()
//    ->SetEnergyRange(lowlimit, 100.*GeV);
//
//  // default cuts for world volume
//  G4double cutValue = 2.0*mm;
//  SetCutValue(cutValue,"gamma");
//  SetCutValue(cutValue,"e-");
//  SetCutValue(cutValue,"e+");
//
//  // cuts per region: inertial sensor (250 eV for gamma, e-, e+)
//  //  G4Region* region = G4RegionStore::GetInstance()->GetRegion("sensor");
//  G4ProductionCuts* cuts = new G4ProductionCuts();
//  cuts->SetProductionCut(0.050*micrometer);
//  //region->SetProductionCuts(cuts);
//  
//  if (verboseLevel>0) DumpCutValuesTable();
//
//}
