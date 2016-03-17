// --------------------------------------------------------------
//      GEANT 4 - LXe.cc
// --------------------------------------------------------------
//-------- GEANT4
#include "G4RunManager.hh"
#include "G4UImanager.hh"
#include "Randomize.hh"
//-------- User
#include "PAR_LXe_MASK1_TANK1_LARGE_1DC.hh"
#include "PAR_LXe_MASK1_TANK1_LARGE_1PhysicsList.hh"
#include "PAR_LXe_MASK1_TANK1_LARGE_1PG.hh"
#include "PAR_LXe_MASK1_TANK1_LARGE_1RA.hh"
#include "PAR_LXe_MASK1_TANK1_LARGE_1SA.hh"
//
#include <sys/time.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
//

//-------- Visualization Manager
#ifdef G4VIS_USE
#include "G4VisExecutive.hh"
#endif
//-------- Execution Manager
#ifdef G4UI_USE
#include "G4UIExecutive.hh"
#endif

void usage();
FILE *out_file;

int main(int argc,char** argv)
{
  G4int interattivo=0;   //If interattivo==0 then do not be in interactive mode. If interattivo==1 then be in interactive mode
  
  G4long myseed = 0;
  G4long number_of_events = 1 ;
	
  if (interattivo==0)
      {
	G4String My_fileName = " " ;

	if ( argc < 4 ) {  // not enough args
        G4cout << "Usage: test12 seed numof_events text_in_out_file_name  [mac_file ]" << G4endl ;
        exit (-1) ;
	}
	
  // Choose the Random engine
   myseed = atoi(argv[1]) ;
  G4cout << "  myseed= " << myseed << G4endl;

  CLHEP::HepRandom::setTheSeed(myseed);

  number_of_events = atoi(argv[2]) ;
  G4cout << "  number_of_events= " << number_of_events << G4endl;
  
  //CLHEP::HepRandom::setTheEngine(new CLHEP::RanecuEngine);
  
 // struct timeval hTimeValue;
//  gettimeofday(&hTimeValue, NULL);
 // CLHEP::HepRandom::setTheEngine(new CLHEP::DRand48Engine);
 // CLHEP::HepRandom::setTheSeed(hTimeValue.tv_usec);
char  outfile_name[256] ;
 
  sprintf(outfile_name,"%s_%d.txt",argv[3], (int) myseed) ;
   G4cout << "outfile_name= [" << outfile_name << "] " << G4endl;
  out_file = fopen(outfile_name,"w" ) ;
  if ( out_file == NULL) {
    G4cout << " !!!!!!!!!!!!!  can not open out_file_text= [" << outfile_name << "] " << G4endl;
    return (-1) ;
  }
  
         }  //end of if (interattivo==0)
    if (interattivo==1) 
    {    
         // Choose the Random engine
  CLHEP::HepRandom::setTheEngine(new CLHEP::RanecuEngine);
  
  struct timeval hTimeValue;
  gettimeofday(&hTimeValue, NULL);
  CLHEP::HepRandom::setTheEngine(new CLHEP::DRand48Engine);
  CLHEP::HepRandom::setTheSeed(hTimeValue.tv_usec);
     }//end of if (interattivo==1)

  // Construct the default run manager
  G4RunManager* runManager = new G4RunManager;

  // set mandatory initialization classes
  G4VUserDetectorConstruction* detector = new PAR_LXe_MASK1_TANK1_LARGE_1DC;
  runManager->SetUserInitialization(detector);
  //
  G4VUserPhysicsList* physics = new PAR_LXe_MASK1_TANK1_LARGE_1PhysicsList;
  runManager->SetUserInitialization(physics);

  // set mandatory user action class
  G4VUserPrimaryGeneratorAction* gen_action = new PAR_LXe_MASK1_TANK1_LARGE_1PG;
  runManager->SetUserAction(gen_action);
  //
  G4UserRunAction* run_action = new PAR_LXe_MASK1_TANK1_LARGE_1RA;
  runManager->SetUserAction(run_action);

  G4UserSteppingAction* stepping_action = new PAR_LXe_MASK1_TANK1_LARGE_1SA;
  runManager->SetUserAction(stepping_action);

  // Initialize G4 kernel
  runManager->Initialize();

if (interattivo==0)
    {
  // --------------------------------- Start a run
//  G4int numberOfEvent = 10000;
G4int numberOfEvent = number_of_events;
//  G4int numberOfEvent = 1000;
  runManager->BeamOn(numberOfEvent);
  // ----------------------------------Fine run
    }
if (interattivo==1)
    {

	// **********************************************************
	//---------------------------------- interattivo
	// **********************************************************
	  #ifdef G4VIS_USE
	    G4VisManager* visManager = new G4VisExecutive;
	    visManager->Initialize();
	  #endif
	
	  // Get the pointer to the User Interface manager
	  G4UImanager * UImanager = G4UImanager::GetUIpointer();  
	
	  if (argc!=1)   // batch mode  
	  {
	    G4String command = "/run/beamOn ";
	    G4String fileName = argv[1];
	    UImanager->ApplyCommand("/run/verbose 0");
	    UImanager->ApplyCommand("/event/verbose 0");  
	    UImanager->ApplyCommand("/tracking/verbose 0");
	    UImanager->ApplyCommand("/hits/verbose 0");
	    UImanager->ApplyCommand(command+fileName);
	  }
	  else           // interactive mode : define UI session
	  {
	  #ifdef G4UI_USE
	     G4UIExecutive * ui = new G4UIExecutive(argc,argv);
	  #ifdef G4VIS_USE
	    UImanager->ApplyCommand("/run/verbose 0");
	    UImanager->ApplyCommand("/event/verbose 0");  
	    UImanager->ApplyCommand("/tracking/verbose 0");
	    UImanager->ApplyCommand("/hits/verbose 0");
	    //UImanager->ApplyCommand("/control/execute vis.mac");     
	  #endif
	      ui->SessionStart();
	      delete ui;
	  #endif
	
	  #ifdef G4VIS_USE
	      delete visManager;
	  #endif
	  }
	// **********************************************************
	//---------------------------------- interattivo
	// **********************************************************
    } // end of if (interattivo==1)

  // Free the store: user actions, physics_list and detector_description are
  //                 owned and deleted by the run manager, so they should not
  //                 be deleted in the main() program !
  fclose(out_file);
  delete runManager;
  return 0;
}


