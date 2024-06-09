#pragma once

#include <G4VSensitiveDetector.hh>

namespace edu0bm31 {

class SensitiveDetector : public G4VSensitiveDetector {
public:
    SensitiveDetector(const G4String& name);
    ~SensitiveDetector();

    // methods from base class
    void   Initialize(G4HCofThisEvent* hitCollection) override;
    G4bool ProcessHits( G4Step * step, G4TouchableHistory* history ) override;
    void   EndOfEvent(G4HCofThisEvent* hitCollection) override;
};

}

