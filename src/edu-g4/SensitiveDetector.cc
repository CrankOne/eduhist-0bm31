#include "edu-g4/SensitiveDetector.hh"

namespace edu0bm31 {

SensitiveDetector::SensitiveDetector(const G4String& name)
        : G4VSensitiveDetector(name) {
}

SensitiveDetector::~SensitiveDetector() {}

void
SensitiveDetector::Initialize(G4HCofThisEvent* hitCollection) {
}

G4bool
SensitiveDetector::ProcessHits(G4Step* step, G4TouchableHistory* history) {
    // energy deposit
    auto edep = step->GetTotalEnergyDeposit();

    // Get (1st level) replica number
    auto touchable = (step->GetPreStepPoint()->GetTouchable());
    auto yLayerNumber = touchable->GetReplicaNumber(1);
    auto xLayerNumber = touchable->GetReplicaNumber(0);


    printf("XXX energy deposition: %e at %d, %d\n", edep, xLayerNumber, yLayerNumber);

    #if 0
    // step length
    G4double stepLength = 0.;
    if ( step->GetTrack()->GetDefinition()->GetPDGCharge() != 0. ) {
        stepLength = step->GetStepLength();
    }
    if ( edep==0. && stepLength == 0. ) return false;
    auto touchable = (step->GetPreStepPoint()->GetTouchable());
    auto layerNumber = touchable->GetReplicaNumber(1);
    #endif

    return true;
}

void
SensitiveDetector::EndOfEvent(G4HCofThisEvent* hitCollection) {
}

}


