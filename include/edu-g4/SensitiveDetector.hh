#pragma once

#include <G4VSensitiveDetector.hh>

#include "histogram2d.hh"

namespace edu0bm31 {

class SensitiveDetector : public G4VSensitiveDetector {
private:
    /// Histogram of primary particle energy losses with respect
    /// to particle energy
    Histogram2D _primaryParticleLosses;
public:
    SensitiveDetector(const G4String& name);
    ~SensitiveDetector();

    // methods from base class
    void   Initialize(G4HCofThisEvent* hitCollection) override;
    G4bool ProcessHits( G4Step * step, G4TouchableHistory* history ) override;
    void   EndOfEvent(G4HCofThisEvent* hitCollection) override;
};

}

