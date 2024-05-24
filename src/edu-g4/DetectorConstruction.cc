#include "edu-g4/DetectorConstruction.hh"

#include "G4RunManager.hh"
#include "G4NistManager.hh"
#include "G4Box.hh"
#include "G4Cons.hh"
#include "G4Orb.hh"
#include "G4Sphere.hh"
#include "G4ThreeVector.hh"
#include "G4Trd.hh"
#include "G4LogicalVolume.hh"
#include "G4PVPlacement.hh"
#include "G4SystemOfUnits.hh"

namespace edu0bm31 {

G4VPhysicalVolume* DetectorConstruction::Construct() {
    // Get nist material manager
    G4NistManager * nist = G4NistManager::Instance();
    // Option to switch on/off checking of volumes overlaps
    const G4bool checkOverlaps = true;

    // Create world (box)
    const double worldDims[] = {1*m, 1*m, 3*m};  // full world dimensions
    auto solidWorld = new G4Box("World",
            worldDims[0]/2, worldDims[1]/2, worldDims[2]/2);  // its size
    auto logicWorld = new G4LogicalVolume(solidWorld,  // its solid
            nist->FindOrBuildMaterial("G4_AIR"),     // its material
            "World");                                // its name
    auto physWorld = new G4PVPlacement(nullptr,  // no rotation
        G4ThreeVector(),                           // at (0,0,0)
        logicWorld,                                // its logical volume
        "World",                                   // its name
        nullptr,                                   // its mother  volume
        false,                                     // no boolean operation
        0,                                         // copy number
        checkOverlaps );                           // overlaps checking

    //
    // User geometry

    auto solidCalo = new G4Box("Calo", 12.5*cm, 12.5*cm, 25*cm);
    auto logicCalo = new G4LogicalVolume(solidCalo
            , nist->FindOrBuildMaterial("G4_CESIUM_IODIDE"), "Calo");
    auto physCalo = new G4PVPlacement(nullptr
            , G4ThreeVector(0, 0, -.5*m)
            , logicCalo
            , "Calo", logicWorld, false, 0, checkOverlaps);

    return physWorld;
}

}
