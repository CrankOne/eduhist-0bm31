#include "edu-g4/ActionInitialization.hh"
#include "edu-g4/PrimaryGeneratorAction.hh"
//#include "RunAction.hh"
//#include "EventAction.hh"
//#include "SteppingAction.hh"

namespace edu0bm31 {

void ActionInitialization::BuildForMaster() const {
  //auto runAction = new RunAction;
  //SetUserAction(runAction);
}

void ActionInitialization::Build() const {
  SetUserAction(new PrimaryGeneratorAction);

  //auto runAction = new RunAction;
  //SetUserAction(runAction);

  //auto eventAction = new EventAction(runAction);
  //SetUserAction(eventAction);

  //SetUserAction(new SteppingAction(eventAction));
}

}
